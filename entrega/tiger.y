%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "y.tab.h"

/* Declarações para fazer interface entre o lexer e este arquivo, são compartilhadas entre o código do lex e yacc */
extern int yylex();
extern int yyparse();
extern FILE *yyin;
extern int posAtual;
extern int lin;      /* conta as linhas */
extern int col;      /* conta as colunas */
extern char* yytext; /* valor do token na entrada */
extern int yyval;    /* valor de variaveis, atribuído no .l */

void yyerror(const char *str)
{
    fprintf(stderr, "\n*** Erro de sintaxe: linha %i, coluna %lu, token '%s' ***\n\n", lin, col - strlen(yytext), yytext);
    exit(EXIT_FAILURE);
}

int yywrap() { return 1; }

%}

%token NIL ABREPAR FECHAPAR ABRECHAV FECHACHAV ABRECOL FECHACOL MENOS MAIS VEZES DIVIDIR IGUAL DIFERENTE MENOR MENORIG MAIOR MAIORIG E OU OF ATRIBUI IF THEN ELSE WHILE DO FOR TO BREAK LET IN END TIPO DOISPONTOS VAR FUNCTION PONTO PONTOVIRG VIRG ID NUM STRING ARRAY

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

inicio : exp                            { printf("inicio \t-> exp\n");}  ;


exp : lvalue                            { printf("exp \t-> lvalue\n");} 
|     NIL                               { printf("exp \t-> NIL()\n");/** Term*/}
|     ABREPAR expseq FECHAPAR           { printf("exp \t-> ( expseq )\n");/** Term*/}
|     NUM                               { printf("exp \t-> NUM(%i)\n", yyval);/** Term*/}
|     STRING                            { printf("exp \t-> STRING(%s)\n", yytext);/** Term*/}
|     MENOS exp                         { printf("exp \t-> - exp\n");}
|     ID ABREPAR args FECHAPAR          { printf("exp \t-> ID ( args )\n");}
|     exp MAIS exp                      { printf("exp \t-> exp + exp\n");}
|     exp MENOS exp                     { printf("exp \t-> exp - exp\n");}
|     exp VEZES exp                     { printf("exp \t-> exp * exp\n");}
|     exp DIVIDIR exp                   { printf("exp \t-> exp / exp\n");}
|     exp IGUAL exp                     { printf("exp \t-> exp = exp\n");}
|     exp DIFERENTE exp                 { printf("exp \t-> exp <> exp\n");}
|     exp MENOR exp                     { printf("exp \t-> exp < exp\n");}
|     exp MAIOR exp                     { printf("exp \t-> exp > exp\n");}
|     exp MENORIG exp                   { printf("exp \t-> exp <= exp\n");}
|     exp MAIORIG exp                   { printf("exp \t-> exp >= exp\n");}
|     exp E exp                         { printf("exp \t-> exp & exp\n");}
|     exp OU exp                        { printf("exp \t-> exp | exp\n");}
|     tid                               { printf("exp \t-> tid\n");} /*modificação aqui*/
|     lvalue ATRIBUI exp                { printf("exp \t-> lvalue := exp\n");}
|     IF exp THEN exp ELSE exp          { printf("exp \t-> IF exp THEN exp ELSE exp\n");}
|     IF exp THEN exp                   { printf("exp \t-> IF exp THEN exp\n");}
|     WHILE exp DO exp                  { printf("exp \t-> WHILE exp DO exp\n");}
|     FOR ID ATRIBUI exp TO exp DO exp  { printf("exp \t-> FOR ID := exp TO exp DO exp\n");}
|     BREAK                             { printf("exp \t-> BREAK\n");}
|     LET decs IN expseq END	        { printf("exp \t-> LET decs IN expseq END\n");};

tid:  
      ABRECHAV ID IGUAL exp idexps FECHACHAV { printf("tid \t-> typeid { ID = exp idexps }\n");}
|     ABRECOL exp FECHACOL OF exp       { printf("tid \t-> typeid [ exp ] OF exp\n");};

decs :
    dec decs                            { printf("decs \t-> dec decs\n");}
    |                                   { printf("decs \t-> ''\n");};

dec : 
      tydec                             { printf("dec \t-> tydec\n");}
|     vardec                            { printf("dec \t-> vardec\n");}
|     fundec                            { printf("dec \t-> fundec\n");};

tydec : 
    TIPO ID IGUAL ty                    { printf("tydec \t-> TYPE ID = ty\n");};

ty : 
      ID                                { printf("ty \t-> ID\n");}                        
|     ABRECHAV ID DOISPONTOS typeid tyfields1 FECHACHAV { printf("{ ty \t-> ID : typeid tyfields1 }\n");} 
|     ARRAY OF ID                       { printf("ty \t-> ARRAY OF ID = ty\n");};

tyfields : 
    ID DOISPONTOS typeid tyfields1      { printf("tyfields \t-> ID : typeid tyfields1\n");}
    |                                   { printf("tyfields \t-> ''\n");};

tyfields1 : 
    VIRG ID DOISPONTOS typeid tyfields1 { printf("tyfields1 \t-> , ID : typeid tyfields1\n");}
    |                                   { printf("tyfields1 \t-> ''\n");};

vardec : 
     VAR ID ATRIBUI exp                 { printf("vardec \t-> VAR ID := exp\n");} 
|    VAR ID DOISPONTOS typeid ATRIBUI exp { printf("vardec \t-> VAR ID : typeid := exp\n");};

fundec : 
    FUNCTION ID ABREPAR tyfields FECHAPAR IGUAL exp { printf("fundec \t-> FUNCTION ID ( tyfields ) = exp\n");} 
|   FUNCTION ID ABREPAR tyfields FECHAPAR DOISPONTOS typeid IGUAL exp { printf("fundec \t-> FUNCTION ID ( tyfields ) : typeid = exp\n");} ;

lvalue : 
    ID                                  { printf("lvalue \t-> ID\n");}
|   lvalue PONTO ID                     { printf("lvalue \t-> lvalue . ID\n");}
|   lvalue ABRECOL exp FECHACOL         { printf("lvalue \t-> lvalue [ exp ]\n");};

typeid : 
    ID                                  { printf("typeid \t-> ID\n");};

expseq : 
    exp expseq1                         { printf("expseq \t-> exp expseq1\n");}
    |                                   { printf("expseq \t-> ''\n");};  

expseq1 :
    PONTOVIRG exp expseq1               { printf("expseq1 \t-> ; exp expseq1\n");}
    |                                   { printf("expseq1 \t-> ''\n");};

args : 
    exp args1                           { printf("args \t-> exp args1\n");}
    |                                   { printf("args \t-> ''\n");}; 

args1 : 
    VIRG exp args1                      { printf("args1 \t-> , exp args1\n");}
    |                                   { printf("args1 \t-> ''\n");}; 

idexps : 
    VIRG ID IGUAL exp idexps            { printf("idexps \t-> , ID = exp idexps\n");}
    |                                   { printf("idexps \t-> ''\n");};

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
    
    char c = fgetc(yyin);
    printf("Listagem do código fonte:\n");
    while (c != EOF)
    {
        printf ("%c", c);
        c = fgetc(yyin);
    }
    rewind(yyin);
    
    //while(yylex()) printf("%s\n", yytext); ;
    printf("Listagem das regras de derivação para acompanhamento:\n");
    yyparse(); //fica chamando o yylex(), vulgo "pedindo tokens"
    printf("\nACEITO!\n"); // linguagem reconhecida
    
    fclose(yyin);
    
    return 0;
}


