/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parser.y" /* yacc.c:339  */

	#include <bits/stdc++.h>
	#include "ast.h"
	using namespace std;
	extern "C" FILE *yyin;
	extern int yylineno;
	extern "C" int yyparse();
	extern "C" int yylex();
	extern  ASTProgram * programhead;
	void yyerror (char const *s);
	#define YYSTYPE_IS_DECLARED

#line 79 "parser.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.tab.h".  */
#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
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
    INTEGER = 258,
    ID = 259,
    INT_TYPE = 260,
    VOID = 261,
    code_block = 262,
    decl_block = 263,
    STOP = 264,
    AND = 265,
    OR = 266,
    NOT = 267,
    LE = 268,
    GE = 269,
    DO_EQL = 270,
    NOT_EQL = 271,
    FOR = 272,
    WHILE = 273,
    STRING = 274,
    PRINT = 275,
    PRINTLN = 276,
    READ = 277,
    IF = 278,
    ELSE = 279,
    GOTO = 280
  };
#endif

/* Value type.  */


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 151 "parser.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   179

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  17
/* YYNRULES -- Number of rules.  */
#define YYNRULES  57
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  138

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   280

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    17,     2,     2,
       2,     2,    15,    13,    33,    14,     2,    16,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    36,     2,
      38,    37,    39,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    34,     2,    35,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    31,     2,    32,     2,     2,     2,     2,
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
       5,     6,     7,     8,     9,    10,    11,    12,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    64,    64,    66,    67,    69,    71,    72,    73,    74,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    94,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   119,
     120,   123,   124,   125,   126,   127,   129,   130
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INTEGER", "ID", "INT_TYPE", "VOID",
  "code_block", "decl_block", "STOP", "AND", "OR", "NOT", "'+'", "'-'",
  "'*'", "'/'", "'%'", "LE", "GE", "DO_EQL", "NOT_EQL", "FOR", "WHILE",
  "STRING", "PRINT", "PRINTLN", "READ", "IF", "ELSE", "GOTO", "'{'", "'}'",
  "','", "'['", "']'", "':'", "'='", "'<'", "'>'", "$accept", "program",
  "dec_states", "dec_state", "declare_var", "statement_seg", "statement",
  "expr", "expr1", "TERM", "TERM1", "FIRST_COMP", "single_expr",
  "FINALTERM", "IF_ELSE", "print_expr", "read_state", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,    43,    45,    42,    47,    37,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   123,   125,    44,    91,    93,    58,    61,    60,    62
};
# endif

#define YYPACT_NINF -32

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-32)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      19,   -15,    30,    36,   -32,    70,    48,    36,   -19,    74,
      83,   -32,    70,    92,   -32,    71,   -32,    72,    59,    73,
      96,     0,   -32,   104,    51,   106,   106,   107,    51,   110,
      87,    59,   -32,   -32,    70,   -32,   -32,    51,    90,    51,
      95,   -32,    99,   103,   -32,   129,   -32,   131,   108,   -32,
     109,   125,   134,   150,    -1,   130,    -2,   -32,   -32,   -32,
       4,    -5,    59,   122,    51,    51,    59,    51,    51,    51,
      51,    51,    51,    51,    51,    51,    51,    51,    51,    51,
      51,   106,   106,   -32,   -32,   -32,    51,    59,   -32,    51,
     123,   -32,   -32,   132,    56,   136,   -32,   -32,     8,    50,
      84,   145,   -32,   140,   140,   140,   140,   140,   140,   140,
     -32,   -32,    62,   137,   154,    51,    51,   -32,   -32,   155,
     138,   -32,   135,   -20,   -32,   139,   -32,    59,    51,    59,
     141,   143,   144,   -32,    59,   -32,   146,   -32
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     3,     1,     0,     0,     3,     8,     0,
       0,     4,     0,     0,     5,     0,     6,     0,    10,     9,
       0,     0,    13,     0,     0,    55,    55,     0,     0,     0,
       0,    10,    26,    25,     0,    20,    19,     0,     0,     0,
       0,    47,    46,     0,    27,    29,    30,    32,     0,    45,
      53,    54,     0,     0,     0,     0,     0,     2,    11,     7,
       0,     0,    10,     0,     0,     0,    10,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    55,    55,    23,    24,    56,     0,    10,    21,     0,
       0,    12,    17,     0,     0,     0,    28,    31,    40,    41,
      42,    43,    44,    33,    34,    35,    36,    39,    37,    38,
      52,    51,     0,     0,     0,     0,     0,    48,    16,     0,
      50,    22,     0,     0,    57,     0,    18,    10,     0,    10,
       0,     0,     0,    15,    10,    49,     0,    14
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -32,   -32,   159,   -32,    -6,   -31,   133,   -25,   105,   -32,
     111,   -32,   -27,   -24,   -32,   -21,   -32
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     6,     7,     9,    30,    31,    43,    44,    45,
      46,    47,    48,    49,    32,    52,    33
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      58,    51,    51,    55,    36,    53,    16,    88,    85,    36,
      60,   127,    63,   128,    12,    13,     3,    69,    70,    71,
      72,    73,    70,    71,    72,    73,    89,     1,    59,    37,
       4,    91,    39,    86,    37,    95,    38,    39,    94,    90,
      93,     5,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,    41,    42,   113,    51,    51,   112,
     110,   111,    20,    21,   114,    71,    72,    73,    22,    69,
      70,    71,    72,    73,     8,    69,    70,    71,    72,    73,
      10,    23,    24,    14,    25,    26,    27,    28,   122,    29,
      15,   117,   123,    20,    61,    17,   130,   119,   132,    22,
      72,    73,    18,   136,   131,    35,    34,    19,    40,    41,
      42,    54,    23,    24,    56,    25,    26,    27,    28,    57,
      29,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      50,    92,    64,    65,    66,    69,    70,    71,    72,    73,
      67,    68,    81,    83,   126,    78,    79,    80,    69,    70,
      71,    72,    73,    69,    70,    71,    72,    73,    82,    84,
     115,    87,    73,   121,   124,   116,    11,   125,   118,   120,
     129,    62,    96,   133,   134,     0,   135,     0,   137,    97
};

static const yytype_int16 yycheck[] =
{
      31,    25,    26,    28,     9,    26,    12,     9,     9,     9,
      37,    31,    39,    33,    33,    34,    31,    13,    14,    15,
      16,    17,    14,    15,    16,    17,    28,     8,    34,    34,
       0,    62,    37,    34,    34,    66,    36,    37,    65,    35,
      64,     5,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,     3,     4,    87,    81,    82,    86,
      81,    82,     3,     4,    89,    15,    16,    17,     9,    13,
      14,    15,    16,    17,     4,    13,    14,    15,    16,    17,
      32,    22,    23,     9,    25,    26,    27,    28,   115,    30,
       7,    35,   116,     3,     4,     3,   127,    35,   129,     9,
      16,    17,    31,   134,   128,     9,    33,    35,     4,     3,
       4,     4,    22,    23,     4,    25,    26,    27,    28,    32,
      30,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      24,     9,    37,    34,    31,    13,    14,    15,    16,    17,
      11,    10,    33,     9,     9,    37,    38,    39,    13,    14,
      15,    16,    17,    13,    14,    15,    16,    17,    33,     9,
      37,    31,    17,     9,     9,    33,     7,    29,    32,    32,
      31,    38,    67,    32,    31,    -1,    32,    -1,    32,    68
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     8,    41,    31,     0,     5,    42,    43,     4,    44,
      32,    42,    33,    34,     9,     7,    44,     3,    31,    35,
       3,     4,     9,    22,    23,    25,    26,    27,    28,    30,
      45,    46,    54,    56,    33,     9,     9,    34,    36,    37,
       4,     3,     4,    47,    48,    49,    50,    51,    52,    53,
      24,    53,    55,    55,     4,    47,     4,    32,    45,    44,
      52,     4,    46,    52,    37,    34,    31,    11,    10,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    37,    38,
      39,    33,    33,     9,     9,     9,    34,    31,     9,    28,
      35,    45,     9,    53,    52,    45,    48,    50,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    52,
      55,    55,    52,    45,    47,    37,    33,    35,    32,    35,
      32,     9,    52,    53,     9,    29,     9,    31,    33,    31,
      45,    53,    45,    32,    31,    32,    45,    32
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    40,    41,    42,    42,    43,    44,    44,    44,    44,
      45,    45,    45,    46,    46,    46,    46,    46,    46,    46,
      46,    46,    46,    46,    46,    46,    46,    47,    48,    48,
      49,    50,    50,    51,    51,    51,    51,    51,    51,    51,
      52,    52,    52,    52,    52,    52,    53,    53,    53,    54,
      54,    55,    55,    55,    55,    55,    56,    56
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     8,     0,     2,     3,     3,     6,     1,     4,
       0,     2,     4,     1,    11,     9,     5,     4,     7,     2,
       2,     3,     5,     3,     3,     1,     1,     1,     3,     1,
       1,     3,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     1,     1,     1,     4,     9,
       5,     3,     3,     1,     1,     0,     3,     6
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
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
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
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
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
            /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
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
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

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
      int yyn = yypact[*yyssp];
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
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
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
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
          yyp++;
          yyformat++;
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

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
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
#line 64 "parser.y" /* yacc.c:1646  */
    {(yyval.program) = new ASTProgram((yyvsp[-5].dec_states) , (yyvsp[-1].statement_seg));programhead = (yyval.program);}
#line 1318 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 66 "parser.y" /* yacc.c:1646  */
    {(yyval.dec_states) = new std::vector<ASTDeclBlock *> ;}
#line 1324 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 67 "parser.y" /* yacc.c:1646  */
    {(yyvsp[0].dec_states)->push_back((yyvsp[-1].dec_state)); (yyval.dec_states)=(yyvsp[0].dec_states);}
#line 1330 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 69 "parser.y" /* yacc.c:1646  */
    {(yyval.dec_state) = new ASTDeclBlock(datatype::int_type , (yyvsp[-1].declare_var));}
#line 1336 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 71 "parser.y" /* yacc.c:1646  */
    {(yyvsp[0].declare_var)->push_back(new ASTidvariable("id" , (yyvsp[-2].stringval) , 0)); (yyval.declare_var)=(yyvsp[0].declare_var);}
#line 1342 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 72 "parser.y" /* yacc.c:1646  */
    {(yyvsp[0].declare_var)->push_back(new ASTidvariable("array" ,(yyvsp[-5].stringval), (yyvsp[-3].intval))); (yyval.declare_var)=(yyvsp[0].declare_var);}
#line 1348 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 73 "parser.y" /* yacc.c:1646  */
    {(yyval.declare_var) = new std::vector<ASTidvariable *>; (yyval.declare_var)->push_back(new ASTidvariable("id",(yyvsp[0].stringval) , 0)); }
#line 1354 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 74 "parser.y" /* yacc.c:1646  */
    {(yyval.declare_var) = new std::vector<ASTidvariable *>; (yyval.declare_var)->push_back(new ASTidvariable("array",(yyvsp[-3].stringval), (yyvsp[-1].intval)));}
#line 1360 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 76 "parser.y" /* yacc.c:1646  */
    {(yyval.statement_seg) = new std::vector<pair<ASTstatement* , string> >;}
#line 1366 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 77 "parser.y" /* yacc.c:1646  */
    {(yyvsp[0].statement_seg)->push_back(make_pair((yyvsp[-1].statement) , "")); (yyval.statement_seg)=(yyvsp[0].statement_seg);}
#line 1372 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 78 "parser.y" /* yacc.c:1646  */
    {(yyvsp[0].statement_seg)->push_back(make_pair((yyvsp[-1].statement) , (yyvsp[-3].stringval))); (yyval.statement_seg)=(yyvsp[0].statement_seg);}
#line 1378 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 79 "parser.y" /* yacc.c:1646  */
    {(yyval.statement)=NULL;}
#line 1384 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 80 "parser.y" /* yacc.c:1646  */
    {(yyval.statement) = new ASTforloop((yyvsp[-9].stringval) , (yyvsp[-7].FINALTERM) , (yyvsp[-5].FINALTERM) , (yyvsp[-3].FINALTERM) , (yyvsp[-1].statement_seg));}
#line 1390 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 81 "parser.y" /* yacc.c:1646  */
    {(yyval.statement) = new ASTforloop((yyvsp[-7].stringval) , (yyvsp[-5].FINALTERM) , (yyvsp[-3].FINALTERM) , new ASTvalue("int" , 1) , (yyvsp[-1].statement_seg));}
#line 1396 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 82 "parser.y" /* yacc.c:1646  */
    {(yyval.statement) = new ASTwhileloop((yyvsp[-3].expr) , (yyvsp[-1].statement_seg)); }
#line 1402 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 83 "parser.y" /* yacc.c:1646  */
    {(yyval.statement) = new ASTassignment( "id" , (yyvsp[-3].stringval) , (yyvsp[-1].single_expr));}
#line 1408 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 84 "parser.y" /* yacc.c:1646  */
    {(yyval.statement) = new ASTassignment("array" , (yyvsp[-6].stringval) , (yyvsp[-4].single_expr) , (yyvsp[-1].single_expr));}
#line 1414 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 85 "parser.y" /* yacc.c:1646  */
    {(yyval.statement) = NULL;}
#line 1420 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 86 "parser.y" /* yacc.c:1646  */
    {(yyval.statement) = NULL;}
#line 1426 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 87 "parser.y" /* yacc.c:1646  */
    {(yyval.statement) = new ASTgoto((yyvsp[-1].stringval) , NULL);}
#line 1432 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 88 "parser.y" /* yacc.c:1646  */
    {(yyval.statement) = new ASTgoto((yyvsp[-3].stringval) , (yyvsp[-1].expr));}
#line 1438 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 89 "parser.y" /* yacc.c:1646  */
    {(yyval.statement) = new ASTprint((yyvsp[-1].print_expr));}
#line 1444 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 90 "parser.y" /* yacc.c:1646  */
    {(yyval.statement) = new ASTprintln((yyvsp[-1].print_expr)); }
#line 1450 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 91 "parser.y" /* yacc.c:1646  */
    {(yyval.statement) = (yyvsp[0].read_state);}
#line 1456 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 92 "parser.y" /* yacc.c:1646  */
    {(yyval.statement)=(yyvsp[0].IF_ELSE);}
#line 1462 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 94 "parser.y" /* yacc.c:1646  */
    {(yyval.expr) = new ASTexpression((yyvsp[0].expr1));}
#line 1468 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 96 "parser.y" /* yacc.c:1646  */
    {(yyvsp[0].expr1)->push_back((yyvsp[-2].TERM)); (yyval.expr1)=(yyvsp[0].expr1);}
#line 1474 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 97 "parser.y" /* yacc.c:1646  */
    {(yyval.expr1) = new vector<ASTtermexpr *>; (yyval.expr1)->push_back((yyvsp[0].TERM));}
#line 1480 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 98 "parser.y" /* yacc.c:1646  */
    {(yyval.TERM) = new ASTtermexpr((yyvsp[0].TERM1));}
#line 1486 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 99 "parser.y" /* yacc.c:1646  */
    {(yyvsp[0].TERM1)->push_back((yyvsp[-2].FIRST_COMP));(yyval.TERM1)=(yyvsp[0].TERM1);}
#line 1492 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 100 "parser.y" /* yacc.c:1646  */
    {(yyval.TERM1) = new vector<ASTfirstexpr *>; (yyval.TERM1)->push_back((yyvsp[0].FIRST_COMP));}
#line 1498 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 101 "parser.y" /* yacc.c:1646  */
    {(yyval.FIRST_COMP) = new ASTfirstexpr((yyvsp[-2].single_expr) , relative_op::less_than_equal , (yyvsp[0].single_expr));}
#line 1504 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 102 "parser.y" /* yacc.c:1646  */
    {(yyval.FIRST_COMP) = new ASTfirstexpr((yyvsp[-2].single_expr) , relative_op::greater_than_equal , (yyvsp[0].single_expr));}
#line 1510 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 103 "parser.y" /* yacc.c:1646  */
    {(yyval.FIRST_COMP) = new ASTfirstexpr((yyvsp[-2].single_expr) , relative_op::double_equal , (yyvsp[0].single_expr));}
#line 1516 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 104 "parser.y" /* yacc.c:1646  */
    {(yyval.FIRST_COMP) = new ASTfirstexpr((yyvsp[-2].single_expr) , relative_op::not_equal , (yyvsp[0].single_expr));}
#line 1522 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 105 "parser.y" /* yacc.c:1646  */
    {(yyval.FIRST_COMP) = new ASTfirstexpr((yyvsp[-2].single_expr) , relative_op::less_than , (yyvsp[0].single_expr));}
#line 1528 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 106 "parser.y" /* yacc.c:1646  */
    {(yyval.FIRST_COMP) = new ASTfirstexpr((yyvsp[-2].single_expr) , relative_op::greater_than , (yyvsp[0].single_expr));}
#line 1534 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 107 "parser.y" /* yacc.c:1646  */
    {(yyval.FIRST_COMP) = new ASTfirstexpr((yyvsp[-2].single_expr) , relative_op::equal , (yyvsp[0].single_expr));}
#line 1540 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 109 "parser.y" /* yacc.c:1646  */
    {(yyval.single_expr) = new ASTbinaryexpr((yyvsp[-2].single_expr) ,arithematic_op::plus , (yyvsp[0].single_expr));}
#line 1546 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 110 "parser.y" /* yacc.c:1646  */
    {(yyval.single_expr) = new ASTbinaryexpr((yyvsp[-2].single_expr) ,arithematic_op::sub  , (yyvsp[0].single_expr));}
#line 1552 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 111 "parser.y" /* yacc.c:1646  */
    {(yyval.single_expr) = new ASTbinaryexpr((yyvsp[-2].single_expr) ,arithematic_op::mult  , (yyvsp[0].single_expr));}
#line 1558 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 112 "parser.y" /* yacc.c:1646  */
    {(yyval.single_expr) = new ASTbinaryexpr((yyvsp[-2].single_expr) ,arithematic_op::div  , (yyvsp[0].single_expr));}
#line 1564 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 113 "parser.y" /* yacc.c:1646  */
    {(yyval.single_expr) = new ASTbinaryexpr((yyvsp[-2].single_expr) ,arithematic_op::mod  , (yyvsp[0].single_expr));}
#line 1570 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 114 "parser.y" /* yacc.c:1646  */
    {(yyval.single_expr) = (yyvsp[0].FINALTERM);}
#line 1576 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 115 "parser.y" /* yacc.c:1646  */
    {(yyval.FINALTERM) = new ASTvalue("id" , (yyvsp[0].stringval));}
#line 1582 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 116 "parser.y" /* yacc.c:1646  */
    {(yyval.FINALTERM) = new ASTvalue("int" , (yyvsp[0].intval));}
#line 1588 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 117 "parser.y" /* yacc.c:1646  */
    {(yyval.FINALTERM) = new ASTvalue("array" , (yyvsp[-3].stringval) , (yyvsp[-1].single_expr));}
#line 1594 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 119 "parser.y" /* yacc.c:1646  */
    {(yyval.IF_ELSE) = new ASTifelse((yyvsp[-7].expr) , (yyvsp[-5].statement_seg) , (yyvsp[-1].statement_seg));}
#line 1600 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 120 "parser.y" /* yacc.c:1646  */
    {(yyval.IF_ELSE) = new ASTif((yyvsp[-3].expr) , (yyvsp[-1].statement_seg));}
#line 1606 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 123 "parser.y" /* yacc.c:1646  */
    {(yyvsp[0].print_expr)->push_back(new ASTprintexpr((yyvsp[-2].FINALTERM) , "")) , (yyval.print_expr) = (yyvsp[0].print_expr);}
#line 1612 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 124 "parser.y" /* yacc.c:1646  */
    {(yyvsp[0].print_expr)->push_back(new ASTprintexpr(NULL , (yyvsp[-2].stringval))) , (yyval.print_expr) = (yyvsp[0].print_expr);}
#line 1618 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 125 "parser.y" /* yacc.c:1646  */
    {(yyval.print_expr) = new std::vector<ASTprintexpr*> ;  (yyval.print_expr)->push_back(new ASTprintexpr(NULL , (yyvsp[0].stringval)));}
#line 1624 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 126 "parser.y" /* yacc.c:1646  */
    {	(yyval.print_expr) = new std::vector<ASTprintexpr*> ;  (yyval.print_expr)->push_back(new ASTprintexpr( (yyvsp[0].FINALTERM) , ""));}
#line 1630 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 127 "parser.y" /* yacc.c:1646  */
    {	(yyval.print_expr) = new std::vector<ASTprintexpr*> ; }
#line 1636 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 129 "parser.y" /* yacc.c:1646  */
    {(yyval.read_state) = new ASTread("int" , (yyvsp[-1].stringval));}
#line 1642 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 130 "parser.y" /* yacc.c:1646  */
    {(yyval.read_state) = new ASTread("array" , (yyvsp[-4].stringval) , (yyvsp[-2].single_expr));}
#line 1648 "parser.tab.c" /* yacc.c:1646  */
    break;


#line 1652 "parser.tab.c" /* yacc.c:1646  */
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

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

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
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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
                  yystos[*yyssp], yyvsp);
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
#line 131 "parser.y" /* yacc.c:1906  */


void yyerror (char const *s)
{
       std::cerr << "Line : " << yylineno <<" "<< "Error : " << s << std::endl;
}
