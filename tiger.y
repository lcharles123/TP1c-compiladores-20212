%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tabela.h"
#include "absyn.h"
#include "imprimir.h" //imprime a arvore de sintaxe

#include "y.tab.h"
int yydebug = 1; 
//absyn_exp* ast;
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

Tabela* tab;//inicializado na main logo abaixo



void yyerror(const char *str)
{
    fprintf(stderr, "\n*** Erro de sintaxe: linha %i, coluna %lu, token '%s' ***\n\n", lin, col - strlen(yytext), yytext);
    exit(EXIT_FAILURE);
}

int yywrap() { return 1; }

%}

/* 
https://stackoverflow.com/questions/43882160/bison-grammar-type-and-token
palavras chave dessa seção
https://www.ibm.com/docs/en/aix/7.2?topic=information-yacc-grammar-file-declarations
*/
%union //tipos dos tokens, usar uma declaraçao por linha
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
//endereço na tabela de simbolos
// tipos de nao terminais 
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

/* ver para proxima parte */
/*https://www.gnu.org/software/bison/manual/html_node/Union-Decl.html*/
/*https://www.classes.cs.uchicago.edu/archive/2003/spring/22600-1/docs/lexyacc.pdf*/

%start inicio

%%

inicio : exp                     { printf("inicio \t-> exp\n"); astRoot=$1; imprimir_exp(astRoot); T_sair_bloco(tab);
 };

exp : lvalue                            { printf("exp \t-> lvalue\n"); puts("lv");$$=lvalue_to_exp(lvalue_t, $1, tab); } 
|     NILT                               { printf("exp \t-> NILT()\n"); $$=novo_const(tokpos, nil_t, 0, NULL);  }
|     ABREPAR expseq FECHAPAR           { printf("exp \t-> ( expseq )\n"); $$=novo_expseqpar(tokpos, expseq_t, $2);}
|     NUM                               { printf("exp \t-> NUM(%d)\n", yylval.intVal); $$=novo_const(tokpos, int_t, $1, NULL); }
|     STRINGT                            { printf("exp \t-> STRINGT(%s)\n", yyval.stringVal); $$=novo_const(tokpos, str_t, 0, $1); }
|     MENOS exp                         { printf("exp \t-> - exp\n"); $$=novo_exp_op(tokpos, neg_t, $2, NULL); }
|     ID ABREPAR args FECHAPAR          { printf("exp \t-> ID ( args )\n"); $$=novo_call(tokpos, call_t, $1, $3, tab); } //call
|     exp MAIS exp                      { printf("exp \t-> exp + exp\n"); $$=novo_exp_op(tokpos, mais_op, $1, $3);} //op inicio
|     exp MENOS exp                     { printf("exp \t-> exp - exp\n");  $$=novo_exp_op(tokpos, menos_op, $1, $3); }
|     exp VEZES exp                     { printf("exp \t-> exp * exp\n"); $$=novo_exp_op(tokpos, vezes_op, $1, $3); }
|     exp DIVIDIR exp                   { printf("exp \t-> exp / exp\n"); $$=novo_exp_op(tokpos, dividir_op, $1, $3); }  
|     exp IGUAL exp                     { printf("exp \t-> exp = exp\n");  $$=novo_exp_op(tokpos, igual_op, $1, $3);}
|     exp DIFERENTE exp                 { printf("exp \t-> exp <> exp\n");  $$=novo_exp_op(tokpos, diferente_op, $1, $3);}
|     exp MENOR exp                     { printf("exp \t-> exp < exp\n");  $$=novo_exp_op(tokpos, menor_op, $1, $3);}
|     exp MAIOR exp                     { printf("exp \t-> exp > exp\n");  $$=novo_exp_op(tokpos, maior_op, $1, $3);}
|     exp MENORIG exp                   { printf("exp \t-> exp <= exp\n"); $$=novo_exp_op(tokpos, menorig_op, $1, $3); }
|     exp MAIORIG exp                   { printf("exp \t-> exp >= exp\n"); $$=novo_exp_op(tokpos, maiorig_op, $1, $3); }
|     exp E exp                         { printf("exp \t-> exp & exp\n"); $$=novo_exp_op(tokpos, e_op, $1, $3); }
|     exp OU exp                        { printf("exp \t-> exp | exp\n"); $$=novo_exp_op(tokpos, ou_op, $1, $3);}      //op fim
|     tid                               { printf("exp \t-> tid\n"); } /* FIXME modificaçao aqui*/

|     lvalue ATRIBUI exp                { printf("exp \t-> lvalue := exp\n");$$=novo_atribuicao(tokpos, atribui_t, $1, $3, tab); }
|     IF exp THEN exp ELSE exp          { printf("exp \t-> IF exp THEN exp ELSE exp\n");$$=novo_ifthenelse(tokpos, ifthen_t, $2, $4, $6); }
|     IF exp THEN exp                   { printf("exp \t-> IF exp THEN exp\n");$$=novo_ifthen(tokpos, if_t, $2, $4); }
|     WHILE exp DO exp                  { printf("exp \t-> WHILE exp DO exp\n");$$=novo_while(tokpos, while_t, $2, $4); }
|     FOR ID ATRIBUI exp TO exp DO exp  { printf("exp \t-> FOR ID := exp TO exp DO exp\n");$$=novo_for(tokpos, for_t, $2, $4, $6, $8, tab); }
|     BREAK                             { printf("exp \t-> BREAK\n");$$=NULL; }
|     LET decs IN expseq END	        {printf("exp \t-> LET decs IN expseq END\n");$$=novo_let(tokpos, let_t, $2, $4, tab);};


tid:  
      ABRECHAV  ID IGUAL exp idexps FECHACHAV { printf("tid \t-> typeid { ID = exp idexps }\n");}
|     ABRECOL  exp FECHACOL OF exp     { printf("tid \t-> typeid [ exp ] OF exp\n");};



decs :
    dec decs                            { printf("decs \t-> dec decs\n"); $$=novo_declist(tokpos, 0, $1, $2); }
    |                                   { printf("decs \t-> ''\n");$$=NULL;};

dec : 
      tydec                             { printf("dec \t-> tydec\n");$$=$1;}
|     vardec                            { printf("dec \t-> vardec\n");$$=$1;}
|     fundec                            { printf("dec \t-> fundec\n");$$=$1;};

tydec : 
    TIPO ID IGUAL ty                    { printf("tydec \t-> TYPE ID = ty\n");$$=novo_tipodec(tokpos, tydec_t, $2, $4, tab);};

ty : 
      ID                                { printf("ty \t-> ID\n"); T_instalar(tab, $1, tydec_t, NULL); 
      $$=NULL;}                        
|     ABRECHAV ID DOISPONTOS typeid tyfields1 FECHACHAV { printf("{ ty \t-> ID : typeid tyfields1 }\n");
$$=novo_varlist(tokpos, ty_record, $2, $4, $5, tab);} //records
|     ARRAY OF ID                    { printf("ty \t-> ARRAY OF ID = ty\n"); T_instalar(tab, $3, ty_arranjo, NULL); 
      $$=NULL; };

tyfields : 
    ID DOISPONTOS typeid tyfields1      { printf("tyfields \t-> ID : typeid tyfields1\n");$$=novo_varlist(tokpos, ty_record, $1, $3, $4, tab);}
    |                                   { printf("tyfields \t-> ''\n");$$=NULL;}; //colocar null em varlist

tyfields1 : 
    VIRG ID DOISPONTOS typeid tyfields1 { printf("tyfields1 \t-> , ID : typeid tyfields1\n");$$=novo_varlist(tokpos, ty_record, $2, $4, $5, tab);}
    |                                   { printf("tyfields1 \t-> ''\n"); $$=NULL; };

//printf(">>>%s<<<  ", $2);

vardec : 
     VAR ID ATRIBUI exp             { printf("vardec \t-> VAR ID := exp\n"); $$=novo_vardec(tokpos, vardec_t, $2, "0", $4, tab);}  //var sem tipo declarado
     
|    VAR ID DOISPONTOS typeid ATRIBUI exp { printf("vardec \t-> VAR ID : typeid := exp\n");
    $$=novo_vardec(tokpos, vardec_t, $2, $4, $6, tab);}; //var com tipo

fundec : 
    FUNCTION ID ABREPAR tyfields FECHAPAR IGUAL exp { printf("fundec \t-> FUNCTION ID ( tyfields ) = exp\n");
    $$=novo_fundec(tokpos, fundec_t, $2, $4, NULL, $7, tab); } 
|   FUNCTION ID ABREPAR tyfields FECHAPAR DOISPONTOS typeid IGUAL exp { printf("fundec \t-> FUNCTION ID ( tyfields ) : typeid = exp\n");
    $$=novo_fundec(tokpos, fundec_t, $2, $4, $7, $9, tab); } ;
//Dec_n* novo_fundec(int pos, Tipo_e tipo, char* funId, TipoList* tl, char* tyId, Exp_n* e, Tabela* t);

lvalue :  //aqui temos que buscar o endereço de lvalue na tabela de simbolos
    ID                      { printf("lvalue \t-> ID\n");$$=acessar_lvalue(tokpos, var_nome, NULL, $1, NULL, tab);}
|   lvalue PONTO ID                     { printf("lvalue \t-> lvalue . ID\n");$$=acessar_lvalue(tokpos, var_interna, $1, $3, NULL, tab);}
|   lvalue ABRECOL exp FECHACOL         { printf("lvalue \t-> lvalue [ exp ]\n");$$=acessar_lvalue(tokpos, arranjovar_t, $1, NULL, $3, tab);}
;

typeid : 
    ID                                  { printf("typeid \t-> ID()\n"); T_instalar(tab, $1, ty_nome, NULL); $$=$1; }; //retornar o endereço em formato char* , evitar mexer na gramática

expseq : 
    exp expseq1                         { printf("expseq \t-> exp expseq1\n");$$=novo_expseq(tokpos, expseq_t, $1, $2);}
    |                                   { printf("expseq \t-> ''\n");$$=NULL;};  

expseq1 :
    PONTOVIRG exp expseq1               {printf("expseq1 \t-> ; exp expseq1\n");$$=novo_expseq(tokpos, exp_t, $2, $3);}
    |                                   { printf("expseq1 \t-> ''\n");$$=NULL;};

args : 
    exp args1                           { printf("args \t-> exp args1\n");$$=novo_expseq(tokpos, args_t, $1, $2);}
    |                                   { printf("args \t-> ''\n");$$=NULL;}; 

args1 : 
    VIRG exp args1                      { printf("args1 \t-> , exp args1\n");$$=novo_expseq(tokpos, args_t, $2, $3);}
    |                                   { printf("args1 \t-> ''\n");$$=NULL;}; 

idexps : 
    VIRG ID IGUAL exp idexps            { printf("idexps \t-> , ID = exp idexps\n");$$=novo_expseq(tokpos, ideps_t, $4, $5);}
    |                                   { printf("idexps \t-> ''\n");$$=NULL;};

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
    /*char c = fgetc(yyin);
    printf("Listagem do código fonte:\n");
    while (c != EOF)
    {
        printf ("%c", c);
        c = fgetc(yyin);
    }
    rewind(yyin);*/
    
    //while(yylex()) printf("%s\n", yytext); ;
    //printf("Listagem das regras de derivação para acompanhamento:\n");
    yyparse(); //fica chamando o yylex(), vulgo "pedindo tokens"
    //printf("\nACEITO!\n"); // linguagem reconhecida
    
    fclose(yyin);
    Tabela* t = T_init(); 
    T_entrar_bloco(t); //conforme aula 17 min 30 ; slide comp-06
    T_sair_bloco( t);

    T_checar_existencia(t,  "nome");

 //T_instalar( t, "nome1", 89);
 //T_instalar( t, "nome2", 55);
 //T_instalar( t, "nome3", 22);
//T_imprimir( t);
T_delete( t);

puts(""); //para nova linha

    return 0;
}

/*
Fez a análise Semântica completa [S, N, Mais ou Menos] (4 pontos)
• Gerou código intermediário para declarações [S, N, Mais ou Menos] (3 pontos)
• Gerou código intermediáriopara comandos [S, N, Mais ou Menos] (3 pontos) 
• Gerou código intermediário para expresses [S, N, Mais ou Menos] (2 pontos)
• EXTRA - 3 pontos
• Apresentou os resultados da execução do(s) programas testes (convincentes) submetido(s) ao Com-
pilador [S, N, Mais ou Menos] (2 pontos)
• Apresentou as listagens dos programas fontes submetido(s) ao Compilador? [S, N, Mais ou Menos]
(1 pontos

*/
/*
TODO
precisa de simbolos:
exp->
    chamada de funçao
    record
    for 
    array
dec->
    todas as vars e tipos
tipo-> 
    nome


*/
