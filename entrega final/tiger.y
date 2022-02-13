%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tabela.h"
#include "absyn.h"      //contem a arvore de sintaxe abstrata
#include "imprimir.h"  //imprime a arvore de sintaxe
#include "y.tab.h"


int yydebug = 1; 
extern int tokpos;
extern int col;

/* Declarações para fazer interface entre o lexer e este arquivo, são compartilhadas entre o código do lex e yacc */
extern int yylex();
extern int yyparse();
extern FILE *yyin;
extern int posAtual;
extern int lin;      /* conta as linhas */
extern int col;      /* conta as colunas */
extern char* yytext; /* valor do token na entrada */
extern int yyval;    /* valor de variaveis, atribuído no .l */

Exp_n* astRoot; /** Árvore de derivação */
Tabela* tab; // inicializado na main logo abaixo

void yyerror(const char *str)
{
    fprintf(stderr, "\n*** Erro de sintaxe: linha %i, coluna %lu, token '%s' ***\n\n", lin, col - strlen(yytext), yytext);
    exit(EXIT_FAILURE);
}

int yywrap() { return 1; }

%}

%union //tipos dos simbolos da gramatica, usar uma declaraçao por linha
{
    int intVal;
    char* tabend; 
    char* stringVal;
    Exp_n* exp;
    ExpSeq* expseq;
    ExpSeq* argsDec;    
    Var_n* var;
    
    Dec_n* dec;

    DecList* declist;
    
    Tipo_n* tid;
    Tipo_n* ty;
    DecList* tyList;
    Tabela* tab; // tabela de simbolos, typeid é o retorno do nome do id
}

/*%type 	Identifies the type of nonterminals. Type-checking is performed when this construct is present. */
/* para checar tipos, usar %type , quando declarado o token na forma
%type <tag> nome [numero] [...]
para chegar tipos, o yacc testa se nome é do mesmo tipo de tag: uma variável presente na %union acima
em %type, a tag é obrigatória ; nas outras %keywords, ela é opcional
*/
/* POSIX yacc reserves %type to nonterminals  protanto para os terminais usar diretamente em %token */
//tipos retornados pelos não terminais em $n através de $$

%token <intVal> NUM 
%token <exp> NILT
%token <stringVal> STRINGT ID
%type <exp> exp
%type <expseq> expseq expseq1 idexps 
%type <var> lvalue 
%type <stringVal> typeid
%type <dec> dec vardec tydec fundec
%type <declist> decs tyfields tyfields1 ty 
%type <argsDec> args args1
%type <tid> tid

%token ABREPAR FECHAPAR ABRECHAV FECHACHAV ABRECOL FECHACOL MENOS MAIS VEZES DIVIDIR IGUAL DIFERENTE MENOR MENORIG MAIOR MAIORIG E OU OF ATRIBUI IF THEN ELSE WHILE DO FOR TO BREAK LET IN END TIPO DOISPONTOS VAR FUNCTION PONTO PONTOVIRG VIRG ARRAY

%nonassoc OF IF THEN WHILE DO FOR TO ATRIBUI TIPO FUNCTION          /* menor precedencia */
%nonassoc OU
%nonassoc E
%nonassoc IGUAL DIFERENTE MAIOR MENOR MAIORIG MENORIG 
%left MAIS MENOS /* MENOS unário deve ter maior precedencia de todos*/
%left VEZES DIVIDIR
%left ELSE                                                          /*  maior precedencia */

%start inicio

%%

inicio : exp                            { astRoot=$1; imprimir_exp(astRoot);};

exp : lvalue                            { $$=lvalue_to_exp(lvalue_t, $1, tab); } 
|     NILT                              { $$=novo_const(tokpos, nil_t, 0, NULL);  }
|     ABREPAR expseq FECHAPAR           { $$=novo_expseqpar(tokpos, expseq_t, $2);}
|     NUM                               { $$=novo_const(tokpos, int_t, $1, NULL); }
|     STRINGT                           { $$=novo_const(tokpos, str_t, 0, $1); }
|     MENOS exp                         { $$=novo_exp_op(tokpos, neg_t, $2, NULL); }
|     ID ABREPAR args FECHAPAR          { $$=novo_call(tokpos, call_t, $1, $3, tab); } //call
|     exp MAIS exp                      { $$=novo_exp_op(tokpos, mais_op, $1, $3);} //op inicio
|     exp MENOS exp                     { $$=novo_exp_op(tokpos, menos_op, $1, $3); }
|     exp VEZES exp                     { $$=novo_exp_op(tokpos, vezes_op, $1, $3); }
|     exp DIVIDIR exp                   { $$=novo_exp_op(tokpos, dividir_op, $1, $3); }  
|     exp IGUAL exp                     { $$=novo_exp_op(tokpos, igual_op, $1, $3);}
|     exp DIFERENTE exp                 { $$=novo_exp_op(tokpos, diferente_op, $1, $3);}
|     exp MENOR exp                     { $$=novo_exp_op(tokpos, menor_op, $1, $3);}
|     exp MAIOR exp                     { $$=novo_exp_op(tokpos, maior_op, $1, $3);}
|     exp MENORIG exp                   { $$=novo_exp_op(tokpos, menorig_op, $1, $3); }
|     exp MAIORIG exp                   { $$=novo_exp_op(tokpos, maiorig_op, $1, $3); }
|     exp E exp                         { $$=novo_exp_op(tokpos, e_op, $1, $3); }
|     exp OU exp                        { $$=novo_exp_op(tokpos, ou_op, $1, $3);}      //op fim
|     tid                               { printf("exp \t-> tid\n"); } /* FIXME faltou fazer essa parte */
|     lvalue ATRIBUI exp                { $$=novo_atribuicao(tokpos, atribui_t, $1, $3, tab); }
|     IF exp THEN exp ELSE exp          { $$=novo_ifthenelse(tokpos, ifthen_t, $2, $4, $6); }
|     IF exp THEN exp                   { $$=novo_ifthen(tokpos, if_t, $2, $4); }
|     WHILE exp DO exp                  { $$=novo_while(tokpos, while_t, $2, $4); }
|     FOR ID ATRIBUI exp TO exp DO exp  { $$=novo_for(tokpos, for_t, $2, $4, $6, $8, tab); }
|     BREAK                             { $$=NULL; }
|     LET decs IN expseq END	        { $$=novo_let(tokpos, let_t, $2, $4, tab);};

tid:  ABRECHAV  ID IGUAL exp idexps FECHACHAV { ;}
|     ABRECOL  exp FECHACOL OF exp      { ;};

decs : dec decs                         { $$=novo_declist(tokpos, 0, $1, $2); }
|                                       { $$=NULL;};

dec : tydec                             { $$=$1;}
|     vardec                            { $$=$1;}
|     fundec                            { $$=$1;};

tydec : TIPO ID IGUAL ty                { $$=novo_tipodec(tokpos, tydec_t, $2, $4, tab);};

ty :  ID                                { T_instalar(tab, $1, tydec_t, NULL); $$=NULL;}                        
|     ABRECHAV ID DOISPONTOS typeid tyfields1 FECHACHAV { $$=novo_varlist(tokpos, ty_record, $2, $4, $5, tab);} //records
|     ARRAY OF ID                       { T_instalar(tab, $3, ty_arranjo, NULL); $$=NULL; };

tyfields :  
      ID DOISPONTOS typeid tyfields1    { $$=novo_varlist(tokpos, ty_record, $1, $3, $4, tab);} |                                       { $$=NULL;};

tyfields1 : 
     VIRG ID DOISPONTOS typeid tyfields1{ $$=novo_varlist(tokpos, ty_record, $2, $4, $5, tab);}
|                                       { $$=NULL; };

vardec : 
      VAR ID ATRIBUI exp                { $$=novo_vardec(tokpos, vardec_t, $2, "0", $4, tab);}//var sem tipo declarado
|     VAR ID DOISPONTOS typeid ATRIBUI exp{ $$=novo_vardec(tokpos, vardec_t, $2, $4, $6, tab);}; //var com tipo

fundec : 
    FUNCTION ID ABREPAR tyfields FECHAPAR IGUAL exp { $$=novo_fundec(tokpos, fundec_t, $2, $4, NULL, $7, tab); } 
|   FUNCTION ID ABREPAR tyfields FECHAPAR DOISPONTOS typeid IGUAL exp { $$=novo_fundec(tokpos, fundec_t, $2, $4, $7, $9, tab); } ;

lvalue :  //aqui temos que buscar o endereço de lvalue na tabela de simbolos
     ID                                 { $$=acessar_lvalue(tokpos, var_nome, NULL, $1, NULL, tab);}
|    lvalue PONTO ID                    { $$=acessar_lvalue(tokpos, var_interna, $1, $3, NULL, tab);}
|    lvalue ABRECOL exp FECHACOL        { $$=acessar_lvalue(tokpos, arranjovar_t, $1, NULL, $3, tab);};

typeid : ID                             { T_instalar(tab, $1, ty_nome, NULL); $$=$1; }; //retornar o endereço em formato char* , evitar mexer na gramática

expseq :  exp expseq1                   { $$=novo_expseq(tokpos, expseq_t, $1, $2);}
|                                       { $$=NULL;};  

expseq1 : PONTOVIRG exp expseq1         { $$=novo_expseq(tokpos, exp_t, $2, $3);}
|                                       { $$=NULL;};

args :   exp args1                      { $$=novo_expseq(tokpos, args_t, $1, $2);}
|                                       { $$=NULL;}; 

args1 :  VIRG exp args1                 { $$=novo_expseq(tokpos, args_t, $2, $3);}
|                                       { $$=NULL;}; 

idexps : VIRG ID IGUAL exp idexps       { $$=novo_expseq(tokpos, ideps_t, $4, $5);}
|                                       { $$=NULL;};

%%

int main(int argc, char** argv)
{
    if(argc != 2)
    { 
        printf("Erro nos arquivos de entrada.\nModo de usar: >%s arquivo_fonte.tig\n", argv[0]); 
        return 1;
    }
    
    yyin = fopen(argv[1], "r");
    if (yyin == NULL) 
    {
        printf("Erro ao abrir arquivo fonte.\n");
        return -1;
    }
    tab = T_init(); /** Tabela de simbolos */
    char c = fgetc(yyin);
    printf("Listagem do programa fonte:\n");
    while (c != EOF)
    {
        printf ("%c", c);
        c = fgetc(yyin);
    }
    rewind(yyin);
    
    //while(yylex()) printf("%s\n", yytext); ;
    //printf("Listagem das regras de derivação para acompanhamento:\n");
    yyparse(); //funçao que fica chamando o yylex(), vulgo "pedindo tokens"
    //printf("\nACEITO!\n"); // linguagem reconhecida
    
    fclose(yyin);
    T_delete(tab);
    puts(""); //nova linha após a AST

    return 0;
}


