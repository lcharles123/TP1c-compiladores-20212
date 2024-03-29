/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "tiger.y"

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


#line 109 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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
#line 46 "tiger.y"

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

#line 270 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  35
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   316

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  19
/* YYNRULES -- Number of rules.  */
#define YYNRULES  62
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  147

#define YYUNDEFTOK  2
#define YYMAXUTOK   300


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,   110,   110,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     140,   141,   143,   144,   146,   147,   148,   150,   152,   153,
     154,   157,   157,   160,   161,   164,   165,   168,   169,   172,
     173,   174,   176,   178,   179,   181,   182,   184,   185,   187,
     188,   190,   191
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUM", "NILT", "STRINGT", "ID",
  "ABREPAR", "FECHAPAR", "ABRECHAV", "FECHACHAV", "ABRECOL", "FECHACOL",
  "MENOS", "MAIS", "VEZES", "DIVIDIR", "IGUAL", "DIFERENTE", "MENOR",
  "MENORIG", "MAIOR", "MAIORIG", "E", "OU", "OF", "ATRIBUI", "IF", "THEN",
  "ELSE", "WHILE", "DO", "FOR", "TO", "BREAK", "LET", "IN", "END", "TIPO",
  "DOISPONTOS", "VAR", "FUNCTION", "PONTO", "PONTOVIRG", "VIRG", "ARRAY",
  "$accept", "inicio", "exp", "tid", "decs", "dec", "tydec", "ty",
  "tyfields", "tyfields1", "vardec", "fundec", "lvalue", "typeid",
  "expseq", "expseq1", "args", "args1", "idexps", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300
};
# endif

#define YYPACT_NINF (-129)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      58,  -129,  -129,  -129,    -1,    58,    13,    58,    58,    58,
      58,    27,  -129,    14,    35,   259,  -129,   -10,    58,   129,
      49,    -4,   234,   -12,   217,   162,    40,    62,    64,    66,
      38,    14,  -129,  -129,  -129,  -129,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      69,     7,    68,    58,  -129,  -129,    58,    53,    58,    58,
      58,    63,   -24,    72,    58,  -129,   -12,   -12,  -129,  -129,
     294,   294,   294,   294,   294,   294,   283,   271,   247,   259,
    -129,    58,  -129,  -129,   129,    90,    58,   200,   259,   141,
       5,    58,    77,    78,    50,  -129,     7,  -129,    83,    84,
     259,    58,    58,  -129,    91,    71,  -129,   259,  -129,    73,
      59,    92,  -129,  -129,    98,  -129,  -129,   181,    79,   110,
      58,    77,    -5,    58,    58,    77,  -129,   259,    75,    58,
      77,    90,   259,    75,   111,  -129,   259,   104,  -129,   112,
      86,    58,  -129,    77,   259,    75,  -129
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     6,     4,     7,    49,    54,     0,     0,     0,     0,
       0,     0,    28,    33,     0,     2,    22,     3,    58,    56,
       0,     0,     0,     8,     0,     0,     0,     0,     0,     0,
       0,    33,    34,    35,    36,     1,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    60,     0,     0,    53,     5,     0,     0,     0,     0,
       0,     0,     0,     0,    54,    32,    11,    10,    12,    13,
      14,    15,    16,    18,    17,    19,    20,    21,     0,    23,
      50,     0,    57,     9,    56,    62,     0,    25,    26,     0,
       0,     0,     0,    42,     0,    51,    60,    55,     0,     0,
      31,     0,     0,    38,     0,     0,    37,    45,    52,     0,
       0,     0,    29,    59,     0,    30,    24,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    40,    46,    44,     0,
       0,    62,    27,    44,     0,    41,    47,     0,    61,     0,
       0,     0,    39,     0,    48,    44,    43
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -129,  -129,     0,  -129,    95,  -129,  -129,  -129,  -129,  -128,
    -129,  -129,  -129,   -48,    67,    43,  -129,    32,     1
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    14,    19,    16,    30,    31,    32,   106,   111,   135,
      33,    34,    17,   109,    20,    54,    52,    82,    99
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      15,    48,    91,    38,    39,   139,    18,    22,    23,    24,
      25,   103,   129,    56,   104,    92,    49,   146,    51,    21,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    50,    26,   130,    35,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
     105,    81,    27,    84,    28,    29,    85,    55,    87,    88,
      89,     1,     2,     3,     4,     5,    60,     6,    61,     7,
      62,     8,    63,   128,    64,    80,    83,   133,    86,    93,
      90,    96,   137,   108,   110,     9,   100,   112,    10,   114,
      11,   107,    12,    13,   115,   145,   119,   118,   121,   120,
     122,   116,   117,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,   123,   126,   140,   125,   134,
     127,   141,   142,   131,   132,   143,    65,    97,   113,   136,
       0,    94,   138,     0,    98,     0,     0,     0,     0,     0,
       0,   144,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,     0,     0,     0,     0,
       0,     0,    53,     0,   102,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,     0,     0,     0,
       0,     0,     0,    59,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,     0,     0,     0,     0,
       0,     0,   124,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,     0,     0,     0,     0,   101,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,     0,     0,     0,    58,    57,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    95,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    -1,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    -1,    36,    37,    38,
      39,    -1,    -1,    -1,    -1,    -1,    -1
};

static const yytype_int16 yycheck[] =
{
       0,    11,    26,    15,    16,   133,     7,     7,     8,     9,
      10,     6,    17,    17,     9,    39,    26,   145,    18,     6,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    42,     6,    39,     0,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      45,    44,    38,    53,    40,    41,    56,     8,    58,    59,
      60,     3,     4,     5,     6,     7,    26,     9,     6,    11,
       6,    13,     6,   121,    36,     6,     8,   125,    25,     7,
      17,    81,   130,     6,     6,    27,    86,    37,    30,     6,
      32,    91,    34,    35,    10,   143,    25,     6,    39,    26,
       8,   101,   102,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    17,     6,     6,    39,    44,
     120,    17,    10,   123,   124,    39,    31,    84,    96,   129,
      -1,    64,   131,    -1,    44,    -1,    -1,    -1,    -1,    -1,
      -1,   141,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    -1,    -1,    -1,    -1,
      -1,    -1,    43,    -1,    33,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    -1,    -1,    -1,
      -1,    -1,    -1,    31,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    -1,    -1,    -1,    -1,
      -1,    -1,    31,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    -1,    -1,    -1,    -1,    29,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    -1,    -1,    -1,    28,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     9,    11,    13,    27,
      30,    32,    34,    35,    47,    48,    49,    58,     7,    48,
      60,     6,    48,    48,    48,    48,     6,    38,    40,    41,
      50,    51,    52,    56,    57,     0,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    11,    26,
      42,    48,    62,    43,    61,     8,    17,    12,    28,    31,
      26,     6,     6,     6,    36,    50,    48,    48,    48,    48,
      48,    48,    48,    48,    48,    48,    48,    48,    48,    48,
       6,    44,    63,     8,    48,    48,    25,    48,    48,    48,
      17,    26,    39,     7,    60,    12,    48,    61,    44,    64,
      48,    29,    33,     6,     9,    45,    53,    48,     6,    59,
       6,    54,    37,    63,     6,    10,    48,    48,     6,    25,
      26,    39,     8,    17,    31,    39,     6,    48,    59,    17,
      39,    48,    48,    59,    44,    55,    48,    59,    64,    55,
       6,    17,    10,    39,    48,    59,    55
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    46,    47,    48,    48,    48,    48,    48,    48,    48,
      48,    48,    48,    48,    48,    48,    48,    48,    48,    48,
      48,    48,    48,    48,    48,    48,    48,    48,    48,    48,
      49,    49,    50,    50,    51,    51,    51,    52,    53,    53,
      53,    54,    54,    55,    55,    56,    56,    57,    57,    58,
      58,    58,    59,    60,    60,    61,    61,    62,    62,    63,
      63,    64,    64
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     3,     1,     1,     2,     4,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     1,     3,     6,     4,     4,     8,     1,     5,
       6,     5,     2,     0,     1,     1,     1,     4,     1,     6,
       3,     4,     0,     5,     0,     4,     6,     7,     9,     1,
       3,     4,     1,     2,     0,     3,     0,     2,     0,     3,
       0,     5,     0
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 110 "tiger.y"
                                        { astRoot=(yyvsp[0].exp); imprimir_exp(astRoot);}
#line 1572 "y.tab.c"
    break;

  case 3:
#line 112 "tiger.y"
                                        { (yyval.exp)=lvalue_to_exp(lvalue_t, (yyvsp[0].var), tab); }
#line 1578 "y.tab.c"
    break;

  case 4:
#line 113 "tiger.y"
                                        { (yyval.exp)=novo_const(tokpos, nil_t, 0, NULL);  }
#line 1584 "y.tab.c"
    break;

  case 5:
#line 114 "tiger.y"
                                        { (yyval.exp)=novo_expseqpar(tokpos, expseq_t, (yyvsp[-1].expseq));}
#line 1590 "y.tab.c"
    break;

  case 6:
#line 115 "tiger.y"
                                        { (yyval.exp)=novo_const(tokpos, int_t, (yyvsp[0].intVal), NULL); }
#line 1596 "y.tab.c"
    break;

  case 7:
#line 116 "tiger.y"
                                        { (yyval.exp)=novo_const(tokpos, str_t, 0, (yyvsp[0].stringVal)); }
#line 1602 "y.tab.c"
    break;

  case 8:
#line 117 "tiger.y"
                                        { (yyval.exp)=novo_exp_op(tokpos, neg_t, (yyvsp[0].exp), NULL); }
#line 1608 "y.tab.c"
    break;

  case 9:
#line 118 "tiger.y"
                                        { (yyval.exp)=novo_call(tokpos, call_t, (yyvsp[-3].stringVal), (yyvsp[-1].argsDec), tab); }
#line 1614 "y.tab.c"
    break;

  case 10:
#line 119 "tiger.y"
                                        { (yyval.exp)=novo_exp_op(tokpos, mais_op, (yyvsp[-2].exp), (yyvsp[0].exp));}
#line 1620 "y.tab.c"
    break;

  case 11:
#line 120 "tiger.y"
                                        { (yyval.exp)=novo_exp_op(tokpos, menos_op, (yyvsp[-2].exp), (yyvsp[0].exp)); }
#line 1626 "y.tab.c"
    break;

  case 12:
#line 121 "tiger.y"
                                        { (yyval.exp)=novo_exp_op(tokpos, vezes_op, (yyvsp[-2].exp), (yyvsp[0].exp)); }
#line 1632 "y.tab.c"
    break;

  case 13:
#line 122 "tiger.y"
                                        { (yyval.exp)=novo_exp_op(tokpos, dividir_op, (yyvsp[-2].exp), (yyvsp[0].exp)); }
#line 1638 "y.tab.c"
    break;

  case 14:
#line 123 "tiger.y"
                                        { (yyval.exp)=novo_exp_op(tokpos, igual_op, (yyvsp[-2].exp), (yyvsp[0].exp));}
#line 1644 "y.tab.c"
    break;

  case 15:
#line 124 "tiger.y"
                                        { (yyval.exp)=novo_exp_op(tokpos, diferente_op, (yyvsp[-2].exp), (yyvsp[0].exp));}
#line 1650 "y.tab.c"
    break;

  case 16:
#line 125 "tiger.y"
                                        { (yyval.exp)=novo_exp_op(tokpos, menor_op, (yyvsp[-2].exp), (yyvsp[0].exp));}
#line 1656 "y.tab.c"
    break;

  case 17:
#line 126 "tiger.y"
                                        { (yyval.exp)=novo_exp_op(tokpos, maior_op, (yyvsp[-2].exp), (yyvsp[0].exp));}
#line 1662 "y.tab.c"
    break;

  case 18:
#line 127 "tiger.y"
                                        { (yyval.exp)=novo_exp_op(tokpos, menorig_op, (yyvsp[-2].exp), (yyvsp[0].exp)); }
#line 1668 "y.tab.c"
    break;

  case 19:
#line 128 "tiger.y"
                                        { (yyval.exp)=novo_exp_op(tokpos, maiorig_op, (yyvsp[-2].exp), (yyvsp[0].exp)); }
#line 1674 "y.tab.c"
    break;

  case 20:
#line 129 "tiger.y"
                                        { (yyval.exp)=novo_exp_op(tokpos, e_op, (yyvsp[-2].exp), (yyvsp[0].exp)); }
#line 1680 "y.tab.c"
    break;

  case 21:
#line 130 "tiger.y"
                                        { (yyval.exp)=novo_exp_op(tokpos, ou_op, (yyvsp[-2].exp), (yyvsp[0].exp));}
#line 1686 "y.tab.c"
    break;

  case 22:
#line 131 "tiger.y"
                                        { printf("exp \t-> tid\n"); }
#line 1692 "y.tab.c"
    break;

  case 23:
#line 132 "tiger.y"
                                        { (yyval.exp)=novo_atribuicao(tokpos, atribui_t, (yyvsp[-2].var), (yyvsp[0].exp), tab); }
#line 1698 "y.tab.c"
    break;

  case 24:
#line 133 "tiger.y"
                                        { (yyval.exp)=novo_ifthenelse(tokpos, ifthen_t, (yyvsp[-4].exp), (yyvsp[-2].exp), (yyvsp[0].exp)); }
#line 1704 "y.tab.c"
    break;

  case 25:
#line 134 "tiger.y"
                                        { (yyval.exp)=novo_ifthen(tokpos, if_t, (yyvsp[-2].exp), (yyvsp[0].exp)); }
#line 1710 "y.tab.c"
    break;

  case 26:
#line 135 "tiger.y"
                                        { (yyval.exp)=novo_while(tokpos, while_t, (yyvsp[-2].exp), (yyvsp[0].exp)); }
#line 1716 "y.tab.c"
    break;

  case 27:
#line 136 "tiger.y"
                                        { (yyval.exp)=novo_for(tokpos, for_t, (yyvsp[-6].stringVal), (yyvsp[-4].exp), (yyvsp[-2].exp), (yyvsp[0].exp), tab); }
#line 1722 "y.tab.c"
    break;

  case 28:
#line 137 "tiger.y"
                                        { (yyval.exp)=NULL; }
#line 1728 "y.tab.c"
    break;

  case 29:
#line 138 "tiger.y"
                                        { (yyval.exp)=novo_let(tokpos, let_t, (yyvsp[-3].declist), (yyvsp[-1].expseq), tab);}
#line 1734 "y.tab.c"
    break;

  case 30:
#line 140 "tiger.y"
                                              { ;}
#line 1740 "y.tab.c"
    break;

  case 31:
#line 141 "tiger.y"
                                        { ;}
#line 1746 "y.tab.c"
    break;

  case 32:
#line 143 "tiger.y"
                                        { (yyval.declist)=novo_declist(tokpos, 0, (yyvsp[-1].dec), (yyvsp[0].declist)); }
#line 1752 "y.tab.c"
    break;

  case 33:
#line 144 "tiger.y"
                                        { (yyval.declist)=NULL;}
#line 1758 "y.tab.c"
    break;

  case 34:
#line 146 "tiger.y"
                                        { (yyval.dec)=(yyvsp[0].dec);}
#line 1764 "y.tab.c"
    break;

  case 35:
#line 147 "tiger.y"
                                        { (yyval.dec)=(yyvsp[0].dec);}
#line 1770 "y.tab.c"
    break;

  case 36:
#line 148 "tiger.y"
                                        { (yyval.dec)=(yyvsp[0].dec);}
#line 1776 "y.tab.c"
    break;

  case 37:
#line 150 "tiger.y"
                                        { (yyval.dec)=novo_tipodec(tokpos, tydec_t, (yyvsp[-2].stringVal), (yyvsp[0].declist), tab);}
#line 1782 "y.tab.c"
    break;

  case 38:
#line 152 "tiger.y"
                                        { T_instalar(tab, (yyvsp[0].stringVal), tydec_t, NULL); (yyval.declist)=NULL;}
#line 1788 "y.tab.c"
    break;

  case 39:
#line 153 "tiger.y"
                                                        { (yyval.declist)=novo_varlist(tokpos, ty_record, (yyvsp[-4].stringVal), (yyvsp[-2].stringVal), (yyvsp[-1].declist), tab);}
#line 1794 "y.tab.c"
    break;

  case 40:
#line 154 "tiger.y"
                                        { T_instalar(tab, (yyvsp[0].stringVal), ty_arranjo, NULL); (yyval.declist)=NULL; }
#line 1800 "y.tab.c"
    break;

  case 41:
#line 157 "tiger.y"
                                        { (yyval.declist)=novo_varlist(tokpos, ty_record, (yyvsp[-3].stringVal), (yyvsp[-1].stringVal), (yyvsp[0].declist), tab);}
#line 1806 "y.tab.c"
    break;

  case 42:
#line 157 "tiger.y"
                                                                                                                                        { (yyval.declist)=NULL;}
#line 1812 "y.tab.c"
    break;

  case 43:
#line 160 "tiger.y"
                                        { (yyval.declist)=novo_varlist(tokpos, ty_record, (yyvsp[-3].stringVal), (yyvsp[-1].stringVal), (yyvsp[0].declist), tab);}
#line 1818 "y.tab.c"
    break;

  case 44:
#line 161 "tiger.y"
                                        { (yyval.declist)=NULL; }
#line 1824 "y.tab.c"
    break;

  case 45:
#line 164 "tiger.y"
                                        { (yyval.dec)=novo_vardec(tokpos, vardec_t, (yyvsp[-2].stringVal), "0", (yyvsp[0].exp), tab);}
#line 1830 "y.tab.c"
    break;

  case 46:
#line 165 "tiger.y"
                                          { (yyval.dec)=novo_vardec(tokpos, vardec_t, (yyvsp[-4].stringVal), (yyvsp[-2].stringVal), (yyvsp[0].exp), tab);}
#line 1836 "y.tab.c"
    break;

  case 47:
#line 168 "tiger.y"
                                                    { (yyval.dec)=novo_fundec(tokpos, fundec_t, (yyvsp[-5].stringVal), (yyvsp[-3].declist), NULL, (yyvsp[0].exp), tab); }
#line 1842 "y.tab.c"
    break;

  case 48:
#line 169 "tiger.y"
                                                                      { (yyval.dec)=novo_fundec(tokpos, fundec_t, (yyvsp[-7].stringVal), (yyvsp[-5].declist), (yyvsp[-2].stringVal), (yyvsp[0].exp), tab); }
#line 1848 "y.tab.c"
    break;

  case 49:
#line 172 "tiger.y"
                                        { (yyval.var)=acessar_lvalue(tokpos, var_nome, NULL, (yyvsp[0].stringVal), NULL, tab);}
#line 1854 "y.tab.c"
    break;

  case 50:
#line 173 "tiger.y"
                                        { (yyval.var)=acessar_lvalue(tokpos, var_interna, (yyvsp[-2].var), (yyvsp[0].stringVal), NULL, tab);}
#line 1860 "y.tab.c"
    break;

  case 51:
#line 174 "tiger.y"
                                        { (yyval.var)=acessar_lvalue(tokpos, arranjovar_t, (yyvsp[-3].var), NULL, (yyvsp[-1].exp), tab);}
#line 1866 "y.tab.c"
    break;

  case 52:
#line 176 "tiger.y"
                                        { T_instalar(tab, (yyvsp[0].stringVal), ty_nome, NULL); (yyval.stringVal)=(yyvsp[0].stringVal); }
#line 1872 "y.tab.c"
    break;

  case 53:
#line 178 "tiger.y"
                                        { (yyval.expseq)=novo_expseq(tokpos, expseq_t, (yyvsp[-1].exp), (yyvsp[0].expseq));}
#line 1878 "y.tab.c"
    break;

  case 54:
#line 179 "tiger.y"
                                        { (yyval.expseq)=NULL;}
#line 1884 "y.tab.c"
    break;

  case 55:
#line 181 "tiger.y"
                                        { (yyval.expseq)=novo_expseq(tokpos, exp_t, (yyvsp[-1].exp), (yyvsp[0].expseq));}
#line 1890 "y.tab.c"
    break;

  case 56:
#line 182 "tiger.y"
                                        { (yyval.expseq)=NULL;}
#line 1896 "y.tab.c"
    break;

  case 57:
#line 184 "tiger.y"
                                        { (yyval.argsDec)=novo_expseq(tokpos, args_t, (yyvsp[-1].exp), (yyvsp[0].argsDec));}
#line 1902 "y.tab.c"
    break;

  case 58:
#line 185 "tiger.y"
                                        { (yyval.argsDec)=NULL;}
#line 1908 "y.tab.c"
    break;

  case 59:
#line 187 "tiger.y"
                                        { (yyval.argsDec)=novo_expseq(tokpos, args_t, (yyvsp[-1].exp), (yyvsp[0].argsDec));}
#line 1914 "y.tab.c"
    break;

  case 60:
#line 188 "tiger.y"
                                        { (yyval.argsDec)=NULL;}
#line 1920 "y.tab.c"
    break;

  case 61:
#line 190 "tiger.y"
                                        { (yyval.expseq)=novo_expseq(tokpos, ideps_t, (yyvsp[-1].exp), (yyvsp[0].expseq));}
#line 1926 "y.tab.c"
    break;

  case 62:
#line 191 "tiger.y"
                                        { (yyval.expseq)=NULL;}
#line 1932 "y.tab.c"
    break;


#line 1936 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 193 "tiger.y"


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

