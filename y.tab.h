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
    NIL = 259,
    ABREPAR = 260,
    FECHAPAR = 261,
    ABRECHAV = 262,
    FECHACHAV = 263,
    ABRECOL = 264,
    FECHACOL = 265,
    MENOS = 266,
    MAIS = 267,
    VEZES = 268,
    DIVIDIR = 269,
    IGUAL = 270,
    DIFERENTE = 271,
    MENOR = 272,
    MENORIG = 273,
    MAIOR = 274,
    MAIORIG = 275,
    E = 276,
    OU = 277,
    OF = 278,
    ATRIBUI = 279,
    IF = 280,
    THEN = 281,
    ELSE = 282,
    WHILE = 283,
    DO = 284,
    FOR = 285,
    TO = 286,
    BREAK = 287,
    LET = 288,
    IN = 289,
    END = 290,
    TIPO = 291,
    DOISPONTOS = 292,
    VAR = 293,
    FUNCTION = 294,
    PONTO = 295,
    PONTOVIRG = 296,
    VIRG = 297,
    ID = 298,
    REAL = 299,
    STRING = 300,
    ARRAY = 301
  };
#endif
/* Tokens.  */
#define NUM 258
#define NIL 259
#define ABREPAR 260
#define FECHAPAR 261
#define ABRECHAV 262
#define FECHACHAV 263
#define ABRECOL 264
#define FECHACOL 265
#define MENOS 266
#define MAIS 267
#define VEZES 268
#define DIVIDIR 269
#define IGUAL 270
#define DIFERENTE 271
#define MENOR 272
#define MENORIG 273
#define MAIOR 274
#define MAIORIG 275
#define E 276
#define OU 277
#define OF 278
#define ATRIBUI 279
#define IF 280
#define THEN 281
#define ELSE 282
#define WHILE 283
#define DO 284
#define FOR 285
#define TO 286
#define BREAK 287
#define LET 288
#define IN 289
#define END 290
#define TIPO 291
#define DOISPONTOS 292
#define VAR 293
#define FUNCTION 294
#define PONTO 295
#define PONTOVIRG 296
#define VIRG 297
#define ID 298
#define REAL 299
#define STRING 300
#define ARRAY 301

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 42 "tiger.y"


    //int_t mj;
    int intVal; //acessível por yyval.intVal 
    //typedef char* stringVal;
    //char* idVal;

#line 157 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
