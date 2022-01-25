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
    NIL = 258,
    ABREPAR = 259,
    FECHAPAR = 260,
    ABRECHAV = 261,
    FECHACHAV = 262,
    ABRECOL = 263,
    FECHACOL = 264,
    MENOS = 265,
    MAIS = 266,
    VEZES = 267,
    DIVIDIR = 268,
    IGUAL = 269,
    DIFERENTE = 270,
    MENOR = 271,
    MENORIG = 272,
    MAIOR = 273,
    MAIORIG = 274,
    E = 275,
    OU = 276,
    OF = 277,
    ATRIBUI = 278,
    IF = 279,
    THEN = 280,
    ELSE = 281,
    WHILE = 282,
    DO = 283,
    FOR = 284,
    TO = 285,
    BREAK = 286,
    LET = 287,
    IN = 288,
    END = 289,
    TIPO = 290,
    DOISPONTOS = 291,
    VAR = 292,
    FUNCTION = 293,
    PONTO = 294,
    PONTOVIRG = 295,
    VIRG = 296,
    ID = 297,
    NUM = 298,
    STRING = 299,
    ARRAY = 300
  };
#endif
/* Tokens.  */
#define NIL 258
#define ABREPAR 259
#define FECHAPAR 260
#define ABRECHAV 261
#define FECHACHAV 262
#define ABRECOL 263
#define FECHACOL 264
#define MENOS 265
#define MAIS 266
#define VEZES 267
#define DIVIDIR 268
#define IGUAL 269
#define DIFERENTE 270
#define MENOR 271
#define MENORIG 272
#define MAIOR 273
#define MAIORIG 274
#define E 275
#define OU 276
#define OF 277
#define ATRIBUI 278
#define IF 279
#define THEN 280
#define ELSE 281
#define WHILE 282
#define DO 283
#define FOR 284
#define TO 285
#define BREAK 286
#define LET 287
#define IN 288
#define END 289
#define TIPO 290
#define DOISPONTOS 291
#define VAR 292
#define FUNCTION 293
#define PONTO 294
#define PONTOVIRG 295
#define VIRG 296
#define ID 297
#define NUM 298
#define STRING 299
#define ARRAY 300

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
