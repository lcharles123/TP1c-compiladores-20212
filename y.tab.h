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
    STRING = 259,
    NIL = 260,
    ABREPAR = 261,
    FECHAPAR = 262,
    ABRECHAV = 263,
    FECHACHAV = 264,
    ABRECOL = 265,
    FECHACOL = 266,
    MENOS = 267,
    MAIS = 268,
    VEZES = 269,
    DIVIDIR = 270,
    IGUAL = 271,
    DIFERENTE = 272,
    MENOR = 273,
    MENORIG = 274,
    MAIOR = 275,
    MAIORIG = 276,
    E = 277,
    OU = 278,
    OF = 279,
    ATRIBUI = 280,
    IF = 281,
    THEN = 282,
    ELSE = 283,
    WHILE = 284,
    DO = 285,
    FOR = 286,
    TO = 287,
    BREAK = 288,
    LET = 289,
    IN = 290,
    END = 291,
    TIPO = 292,
    DOISPONTOS = 293,
    VAR = 294,
    FUNCTION = 295,
    PONTO = 296,
    PONTOVIRG = 297,
    VIRG = 298,
    ID = 299,
    ARRAY = 300
  };
#endif
/* Tokens.  */
#define NUM 258
#define STRING 259
#define NIL 260
#define ABREPAR 261
#define FECHAPAR 262
#define ABRECHAV 263
#define FECHACHAV 264
#define ABRECOL 265
#define FECHACOL 266
#define MENOS 267
#define MAIS 268
#define VEZES 269
#define DIVIDIR 270
#define IGUAL 271
#define DIFERENTE 272
#define MENOR 273
#define MENORIG 274
#define MAIOR 275
#define MAIORIG 276
#define E 277
#define OU 278
#define OF 279
#define ATRIBUI 280
#define IF 281
#define THEN 282
#define ELSE 283
#define WHILE 284
#define DO 285
#define FOR 286
#define TO 287
#define BREAK 288
#define LET 289
#define IN 290
#define END 291
#define TIPO 292
#define DOISPONTOS 293
#define VAR 294
#define FUNCTION 295
#define PONTO 296
#define PONTOVIRG 297
#define VIRG 298
#define ID 299
#define ARRAY 300

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 45 "tiger.y"

    int intVal; //acessível por yyval.intVal 
    char* strVal;
    
    Exp_n* exp, expList;
    
    Var_n* var;
    Dec_n* dec, decList, varDec, tyDec, funDec, argsDec;
    Tipo_n* tid, ty, tyList;

#line 158 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
