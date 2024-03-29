%{
#include <stdio.h>
#include "y.tab.h"

int pos = 0; /* contador de caracteres */
int prox(int inc) /* retorna a posiçao do token atual e incrementa o contador de caracteres */
{ 
    int atual = pos; 
    pos += inc; 
    return atual;
}
int posAtual = 0; //posição do token atual
int lin = 1;
int col = 1;
int inicioComentario;

%}

/* ler apenas um arquivo */
/*%option noyywrap*/

%option nounput
%option noinput
/* sub-estado para ignorar os comentários */
%x COMMENTARIO

%%
[\t]      { col+=4; /* assumindo tab com 4 espaços */ }
[\r ]     { col++; }
\n        { lin++; col=1; }

"/*"                { inicioComentario = lin ; BEGIN(COMMENTARIO); }
<COMMENTARIO>\n     { lin++; } 
<COMMENTARIO>"*/"   { BEGIN(INITIAL); }
<COMMENTARIO>.      { ; }
<COMMENTARIO><<EOF>>     { printf("*** ERRO: linha %i : Comentário sem fim ***\n", inicioComentario); exit(EXIT_FAILURE); }

while   { col += yyleng; return WHILE;}
for     { col += yyleng; return FOR;}
to      { col += yyleng; return TO;}
break   { col += yyleng; return BREAK;}
let     { col += yyleng; return LET;}
in      { col += yyleng; return IN;}
end     { col += yyleng; return END;}
function {col += yyleng; return FUNCTION;}
var     { col += yyleng; return VAR;}
type    { col += yyleng; return TIPO;}
array   { col += yyleng; return ARRAY;}
if      { col += yyleng; return IF;}
then    { col += yyleng; return THEN;}
else    { col += yyleng; return ELSE;}
do      { col += yyleng; return DO;}
of      { col += yyleng; return OF;}
nil     { col += yyleng; return NIL;}

","     { col += yyleng; return VIRG;}
":"     { col += yyleng; return DOISPONTOS;}
";"     { col += yyleng; return PONTOVIRG;}
"("     { col += yyleng; return ABREPAR;}
")"     { col += yyleng; return FECHAPAR;}
"["     { col += yyleng; return ABRECOL;}
"]"     { col += yyleng; return FECHACOL;}
"{"     { col += yyleng; return ABRECHAV;}
"}"     { col += yyleng; return FECHACHAV;}
"."     { col += yyleng; return PONTO;}
"+"     { col += yyleng; return MAIS;}
"-"     { col += yyleng; return MENOS;}
"*"     { col += yyleng; return VEZES;}
"/"     { col += yyleng; return DIVIDIR;}
"="     { col += yyleng; return IGUAL;}
"<>"    { col += yyleng; return DIFERENTE;}
"<"     { col += yyleng; return MENOR;}
"<="    { col += yyleng; return MENORIG;}
">"     { col += yyleng; return MAIOR;}
">="    { col += yyleng; return MAIORIG;}
"&"     { col += yyleng; return E;}
"|"     { col += yyleng; return OU;}
":="    { col += yyleng; return ATRIBUI;}

[a-z|A-Z]+[a-z|A-Z|0-9|_]*  {  col += yyleng; return ID;}

[0-9]+        { yylval = atoi(yytext); col += yyleng; return NUM; }
\"[^\"]*\"  { col += yyleng; return STRING;}

.           { printf("*** ERRO: Símbolo desconhecido. Linha %i, Coluna %i, Símbolo: '%s'\n", lin, col, yytext); exit(EXIT_FAILURE);  } // erro se chegar até aqui


