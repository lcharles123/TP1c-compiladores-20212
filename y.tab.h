/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    NUM = 258,
    NILT = 259,
    STRINGT = 260,
    ID = 261,
    ABREPAR = 262,
    FECHAPAR = 263,
    ABRECHAV = 264,
    FECHACHAV = 265,
    ABRECOL = 266,
    FECHACOL = 267,
    MENOS = 268,
    MAIS = 269,
    VEZES = 270,
    DIVIDIR = 271,
    IGUAL = 272,
    DIFERENTE = 273,
    MENOR = 274,
    MENORIG = 275,
    MAIOR = 276,
    MAIORIG = 277,
    E = 278,
    OU = 279,
    OF = 280,
    ATRIBUI = 281,
    IF = 282,
    THEN = 283,
    ELSE = 284,
    WHILE = 285,
    DO = 286,
    FOR = 287,
    TO = 288,
    BREAK = 289,
    LET = 290,
    IN = 291,
    END = 292,
    TIPO = 293,
    DOISPONTOS = 294,
    VAR = 295,
    FUNCTION = 296,
    PONTO = 297,
    PONTOVIRG = 298,
    VIRG = 299,
    ARRAY = 300
  };
#endif
/* Tokens.  */
#define NUM 258
#define NILT 259
#define STRINGT 260
#define ID 261
#define ABREPAR 262
#define FECHAPAR 263
#define ABRECHAV 264
#define FECHACHAV 265
#define ABRECOL 266
#define FECHACOL 267
#define MENOS 268
#define MAIS 269
#define VEZES 270
#define DIVIDIR 271
#define IGUAL 272
#define DIFERENTE 273
#define MENOR 274
#define MENORIG 275
#define MAIOR 276
#define MAIORIG 277
#define E 278
#define OU 279
#define OF 280
#define ATRIBUI 281
#define IF 282
#define THEN 283
#define ELSE 284
#define WHILE 285
#define DO 286
#define FOR 287
#define TO 288
#define BREAK 289
#define LET 290
#define IN 291
#define END 292
#define TIPO 293
#define DOISPONTOS 294
#define VAR 295
#define FUNCTION 296
#define PONTO 297
#define PONTOVIRG 298
#define VIRG 299
#define ARRAY 300

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 47 "tiger.y"

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

#line 166 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
