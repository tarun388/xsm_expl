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
#line 1 "ast.y" /* yacc.c:339  */

  #include "ast.h"
  #include "ast.c"
  int yylex(void);

  FILE * yyin;

#line 74 "y.tab.c" /* yacc.c:339  */

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
   by #include "y.tab.h".  */
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
    _BEGIN = 258,
    END = 259,
    READ = 260,
    WRITE = 261,
    PLUS = 262,
    MINUS = 263,
    MUL = 264,
    DIV = 265,
    MOD = 266,
    NUM = 267,
    ID = 268,
    NEWLINE = 269,
    IF = 270,
    THEN = 271,
    ELSE = 272,
    ENDIF = 273,
    GT = 274,
    LT = 275,
    GE = 276,
    LE = 277,
    NE = 278,
    EQ = 279,
    WHILE = 280,
    DO = 281,
    ENDWHILE = 282,
    BREAK = 283,
    CONTINUE = 284,
    DECL = 285,
    ENDDECL = 286,
    INT = 287,
    STR = 288,
    IDD = 289,
    STRING = 290,
    MAIN = 291,
    RETURN = 292
  };
#endif
/* Tokens.  */
#define _BEGIN 258
#define END 259
#define READ 260
#define WRITE 261
#define PLUS 262
#define MINUS 263
#define MUL 264
#define DIV 265
#define MOD 266
#define NUM 267
#define ID 268
#define NEWLINE 269
#define IF 270
#define THEN 271
#define ELSE 272
#define ENDIF 273
#define GT 274
#define LT 275
#define GE 276
#define LE 277
#define NE 278
#define EQ 279
#define WHILE 280
#define DO 281
#define ENDWHILE 282
#define BREAK 283
#define CONTINUE 284
#define DECL 285
#define ENDDECL 286
#define INT 287
#define STR 288
#define IDD 289
#define STRING 290
#define MAIN 291
#define RETURN 292

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 9 "ast.y" /* yacc.c:355  */

  struct astnode *node;
  struct Paramstruct *node2;

#line 193 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 210 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  13
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   262

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  67
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  152

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   292

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      42,    43,     2,     2,    39,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    38,
       2,    46,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    40,     2,    41,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    44,     2,    45,     2,     2,     2,     2,
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
      35,    36,    37
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    25,    25,    34,    35,    38,    39,    42,    43,    46,
      49,    50,    53,    54,    57,    58,    59,    62,    63,    66,
      69,    70,    71,    74,    77,    80,    81,    84,    85,    88,
      91,    92,    95,    98,   101,   102,   105,   106,   107,   108,
     109,   110,   111,   114,   122,   128,   136,   139,   142,   151,
     154,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   197,   198
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "_BEGIN", "END", "READ", "WRITE", "PLUS",
  "MINUS", "MUL", "DIV", "MOD", "NUM", "ID", "NEWLINE", "IF", "THEN",
  "ELSE", "ENDIF", "GT", "LT", "GE", "LE", "NE", "EQ", "WHILE", "DO",
  "ENDWHILE", "BREAK", "CONTINUE", "DECL", "ENDDECL", "INT", "STR", "IDD",
  "STRING", "MAIN", "RETURN", "';'", "','", "'['", "']'", "'('", "')'",
  "'{'", "'}'", "'='", "$accept", "program", "GDeclBlock", "GDeclList",
  "GDecl", "Type", "GidList", "Gid", "FDefBlock", "Fdef", "ParamList",
  "Param", "MainBlock", "LdeclBlock", "LDecList", "LDecl", "IdList",
  "Body", "Retstmt", "Slist", "Stmt", "Whilestmt", "Ifstmt", "InputStmt",
  "OutputStmt", "AsgStmt", "BrkStmt", "ContStmt", "E", "Identifier", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,    59,    44,
      91,    93,    40,    41,   123,   125,    61
};
# endif

#define YYPACT_NINF -123

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-123)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      13,    89,   -15,    24,    47,  -123,  -123,  -123,  -123,   120,
    -123,    31,    16,  -123,   -15,    87,    47,  -123,  -123,  -123,
    -123,   146,    54,  -123,    63,   108,  -123,  -123,   144,    53,
    -123,    31,   122,    53,   126,   168,    39,  -123,  -123,   152,
      80,  -123,  -123,    53,  -123,   132,   184,   145,  -123,  -123,
     177,   147,  -123,   233,   148,   152,  -123,    86,  -123,  -123,
     154,   155,   165,   164,   166,   156,   171,   170,  -123,  -123,
    -123,  -123,  -123,  -123,  -123,  -123,   173,  -123,   184,  -123,
     179,   142,   142,   142,   142,   142,  -123,  -123,   142,   217,
    -123,   142,   180,  -123,  -123,  -123,   142,    40,  -123,    88,
     150,    94,   119,    46,  -123,   193,  -123,   125,   142,   142,
     142,   142,   142,   142,   142,   142,   142,   142,   142,   186,
     188,  -123,   213,   206,  -123,  -123,  -123,    20,    20,  -123,
    -123,  -123,    64,    64,    64,    64,    64,    64,  -123,  -123,
     233,   233,   205,    -2,   233,   198,   203,   222,  -123,  -123,
     204,  -123
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     4,     6,    10,    11,     0,
       8,     0,     0,     1,    10,     0,     0,    18,     3,     5,
       7,    15,     0,    13,     0,     0,    17,     2,     0,    22,
       9,     0,     0,    22,     0,     0,     0,    21,    12,     0,
       0,    14,    23,     0,    16,     0,     0,     0,    20,    26,
       0,     0,    28,     0,     0,     0,    31,     0,    25,    27,
       0,     0,    67,     0,     0,     0,     0,     0,    35,    40,
      39,    36,    37,    38,    41,    42,     0,    24,     0,    29,
       0,     0,     0,     0,     0,     0,    49,    50,     0,     0,
      34,     0,     0,    30,    63,    64,     0,     0,    65,     0,
       0,     0,     0,     0,    32,     0,    19,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    66,     0,     0,    33,    48,    62,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    46,    47,
       0,     0,     0,     0,     0,     0,     0,     0,    45,    43,
       0,    44
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -123,  -123,  -123,  -123,   234,     1,  -123,   214,  -123,   228,
     216,   209,    12,   199,  -123,   202,  -123,   178,  -123,  -122,
     -66,  -123,  -123,  -123,  -123,  -123,  -123,  -123,   -76,   -53
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     3,     4,     9,    10,    35,    22,    23,    16,    17,
      36,    37,     5,    46,    51,    52,    57,    54,    89,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    97,    98
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      76,    90,    11,    60,    61,    15,    99,   100,   101,   102,
      11,    62,   103,    63,    76,   105,    18,    15,   142,   143,
     107,    12,   147,    64,    13,   146,    65,    66,    27,   110,
     111,   112,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,     1,    21,     2,    50,   108,   109,   110,
     111,   112,    50,   108,   109,   110,   111,   112,    24,   113,
     114,   115,   116,   117,   118,   113,   114,   115,   116,   117,
     118,   108,   109,   110,   111,   112,    90,    90,    43,    14,
       8,    90,    44,   119,   124,     7,     8,    76,    76,    76,
      76,    76,    30,    31,    76,   108,   109,   110,   111,   112,
      25,   108,   109,   110,   111,   112,    32,   113,   114,   115,
     116,   117,   118,   113,   114,   115,   116,   117,   118,    43,
       6,     7,     8,    47,    79,    80,   108,   109,   110,   111,
     112,   120,   108,   109,   110,   111,   112,   122,   113,   114,
     115,   116,   117,   118,   113,   114,   115,   116,   117,   118,
      33,    19,     7,     8,    94,    62,    34,   108,   109,   110,
     111,   112,   123,    49,     7,     8,    39,    41,   126,   113,
     114,   115,   116,   117,   118,    60,    61,    95,    58,     7,
       8,    42,    45,    62,    96,    63,    28,    53,    29,    55,
      56,   121,    93,    77,    86,    64,    81,    82,    65,    66,
     108,   109,   110,   111,   112,    83,    84,    88,    85,    87,
      60,    61,   113,   114,   115,   116,   117,   118,    62,    91,
      63,   104,   144,   145,   138,   106,   139,    60,    61,   140,
      64,   125,   141,    65,    66,    62,   148,    63,    60,    61,
     150,   149,   151,    20,    26,    38,    62,    64,    63,    40,
      65,    66,    48,    59,    78,     0,    92,     0,    64,     0,
       0,    65,    66
};

static const yytype_int16 yycheck[] =
{
      53,    67,     1,     5,     6,     4,    82,    83,    84,    85,
       9,    13,    88,    15,    67,    91,     4,    16,   140,   141,
      96,    36,   144,    25,     0,    27,    28,    29,    16,     9,
      10,    11,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,    30,    13,    32,    45,     7,     8,     9,
      10,    11,    51,     7,     8,     9,    10,    11,    42,    19,
      20,    21,    22,    23,    24,    19,    20,    21,    22,    23,
      24,     7,     8,     9,    10,    11,   142,   143,    39,    32,
      33,   147,    43,    43,    38,    32,    33,   140,   141,   142,
     143,   144,    38,    39,   147,     7,     8,     9,    10,    11,
      13,     7,     8,     9,    10,    11,    43,    19,    20,    21,
      22,    23,    24,    19,    20,    21,    22,    23,    24,    39,
      31,    32,    33,    43,    38,    39,     7,     8,     9,    10,
      11,    43,     7,     8,     9,    10,    11,    43,    19,    20,
      21,    22,    23,    24,    19,    20,    21,    22,    23,    24,
      42,    31,    32,    33,    12,    13,    12,     7,     8,     9,
      10,    11,    43,    31,    32,    33,    44,    41,    43,    19,
      20,    21,    22,    23,    24,     5,     6,    35,    31,    32,
      33,    13,    30,    13,    42,    15,    40,     3,    42,    44,
      13,    41,    13,    45,    38,    25,    42,    42,    28,    29,
       7,     8,     9,    10,    11,    40,    42,    37,    42,    38,
       5,     6,    19,    20,    21,    22,    23,    24,    13,    46,
      15,     4,    17,    18,    38,    45,    38,     5,     6,    16,
      25,    38,    26,    28,    29,    13,    38,    15,     5,     6,
      18,    38,    38,     9,    16,    31,    13,    25,    15,    33,
      28,    29,    43,    51,    55,    -1,    78,    -1,    25,    -1,
      -1,    28,    29
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    30,    32,    48,    49,    59,    31,    32,    33,    50,
      51,    52,    36,     0,    32,    52,    55,    56,    59,    31,
      51,    13,    53,    54,    42,    13,    56,    59,    40,    42,
      38,    39,    43,    42,    12,    52,    57,    58,    54,    44,
      57,    41,    13,    39,    43,    30,    60,    43,    58,    31,
      52,    61,    62,     3,    64,    44,    13,    63,    31,    62,
       5,     6,    13,    15,    25,    28,    29,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    76,    45,    60,    38,
      39,    42,    42,    40,    42,    42,    38,    38,    37,    65,
      67,    46,    64,    13,    12,    35,    42,    75,    76,    75,
      75,    75,    75,    75,     4,    75,    45,    75,     7,     8,
       9,    10,    11,    19,    20,    21,    22,    23,    24,    43,
      43,    41,    43,    43,    38,    38,    43,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    38,    38,
      16,    26,    66,    66,    17,    18,    27,    66,    38,    38,
      18,    38
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    47,    48,    48,    48,    49,    49,    50,    50,    51,
      52,    52,    53,    53,    54,    54,    54,    55,    55,    56,
      57,    57,    57,    58,    59,    60,    60,    61,    61,    62,
      63,    63,    64,    65,    66,    66,    67,    67,    67,    67,
      67,    67,    67,    68,    69,    69,    70,    71,    72,    73,
      74,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    76,    76
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     2,     1,     3,     2,     2,     1,     3,
       1,     1,     3,     1,     4,     1,     4,     2,     1,     9,
       3,     1,     0,     2,     8,     3,     2,     2,     1,     3,
       3,     1,     4,     3,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     8,    10,     8,     5,     5,     4,     2,
       2,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     1,     1,     1,     4,     1
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
#line 25 "ast.y" /* yacc.c:1646  */
    {
                                                                                    print_Gsymbol_table();
                                                                                    printf("PARSED\n");
                                                                                    //genxsm($3);
                                                                                    preorder((yyvsp[-1].node));
                                                                                    printf("\n");
                                                                                    preorder((yyvsp[0].node));
                                                                                    printf("\n");
                                                                                }
#line 1418 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 34 "ast.y" /* yacc.c:1646  */
    {printf("PARSED\n"); (yyval.node) = NULL; print_Gsymbol_table(); preorder((yyvsp[0].node));}
#line 1424 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 35 "ast.y" /* yacc.c:1646  */
    {printf("PARSED\n"); (yyval.node) = NULL; print_Gsymbol_table(); preorder((yyvsp[0].node));}
#line 1430 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 38 "ast.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[-1].node);}
#line 1436 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 39 "ast.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;}
#line 1442 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 57 "ast.y" /* yacc.c:1646  */
    {GInstall((yyvsp[-3].node)->varname,(yyvsp[-3].node)->type,(yyvsp[-1].node)->val,_ARRAY,NULL);}
#line 1448 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 58 "ast.y" /* yacc.c:1646  */
    {GInstall((yyvsp[0].node)->varname,(yyvsp[0].node)->type,1,_VAR,NULL);}
#line 1454 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 59 "ast.y" /* yacc.c:1646  */
    {GInstall((yyvsp[-3].node)->varname,(yyvsp[-3].node)->type,-1,_FUNCTION,(yyvsp[-1].node2));}
#line 1460 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 66 "ast.y" /* yacc.c:1646  */
    {Function((yyvsp[-7].node),(yyvsp[-5].node2),(yyvsp[-1].node));/*codeGen($8)*/;LsymbolHead=NULL;LsymbolTail=NULL;}
#line 1466 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 69 "ast.y" /* yacc.c:1646  */
    {(yyval.node2) = makeParamList((yyvsp[-2].node2),(yyvsp[0].node2));}
#line 1472 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 70 "ast.y" /* yacc.c:1646  */
    {(yyval.node2) = (yyvsp[0].node2);}
#line 1478 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 71 "ast.y" /* yacc.c:1646  */
    {(yyval.node2) = NULL;}
#line 1484 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 74 "ast.y" /* yacc.c:1646  */
    {(yyval.node2) = makeArgs((yyvsp[0].node)->varname,(yyvsp[-1].node)->type);}
#line 1490 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 77 "ast.y" /* yacc.c:1646  */
    {Function((yyvsp[-6].node),NULL,(yyvsp[-1].node));/*codeGen($7)*/;LsymbolHead=NULL;LsymbolTail=NULL;}
#line 1496 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 80 "ast.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[-1].node);}
#line 1502 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 81 "ast.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;}
#line 1508 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 92 "ast.y" /* yacc.c:1646  */
    {LInstall((yyvsp[0].node)->varname,(yyvsp[0].node)->type);}
#line 1514 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 95 "ast.y" /* yacc.c:1646  */
    {(yyval.node) = makeconnectorNode((yyvsp[-2].node),(yyvsp[-1].node));}
#line 1520 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 98 "ast.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[-1].node);}
#line 1526 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 101 "ast.y" /* yacc.c:1646  */
    {(yyval.node) = makeconnectorNode((yyvsp[-1].node),(yyvsp[0].node));}
#line 1532 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 102 "ast.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1538 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 105 "ast.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1544 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 106 "ast.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1550 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 107 "ast.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1556 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 108 "ast.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1562 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 109 "ast.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1568 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 110 "ast.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1574 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 111 "ast.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1580 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 114 "ast.y" /* yacc.c:1646  */
    {   if((yyvsp[-5].node)->type != _BOOL){
                                                                                    yyerror("type mismatch");
                                                                                    exit(1);
                                                                                    }
                                                                                    else (yyval.node) = makeLoopNode((yyvsp[-5].node),(yyvsp[-2].node));
                                                                                }
#line 1591 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 122 "ast.y" /* yacc.c:1646  */
    {   if((yyvsp[-7].node)->type != _BOOL){
                                                                                    yyerror("type mismatch");
                                                                                    exit(1);
                                                                                    }
                                                                                    else (yyval.node) = makeCondNode((yyvsp[-7].node),(yyvsp[-4].node),(yyvsp[-2].node));
                                                                                }
#line 1602 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 128 "ast.y" /* yacc.c:1646  */
    {   if((yyvsp[-5].node)->type != _BOOL){
                                                                                        yyerror("type mismatch");
                                                                                        exit(1);
                                                                                    }
                                                                                    else (yyval.node) = makeCondNode((yyvsp[-5].node),(yyvsp[-2].node),NULL);
                                                                                }
#line 1613 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 136 "ast.y" /* yacc.c:1646  */
    {(yyval.node) = makeReadNode((yyvsp[-2].node));}
#line 1619 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 139 "ast.y" /* yacc.c:1646  */
    {(yyval.node) = makeWriteNode((yyvsp[-2].node));}
#line 1625 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 142 "ast.y" /* yacc.c:1646  */
    {
                                                                                    if((yyvsp[-3].node)->nodetype != _VAR && (yyvsp[-3].node)->nodetype != _ARRAY){
                                                                                        yyerror("LHS should be memory location\n");
                                                                                        exit(1);
                                                                                    }
                                                                                    (yyval.node) = makeAsgtNode((yyvsp[-3].node),(yyvsp[-1].node));
                                                                                }
#line 1637 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 151 "ast.y" /* yacc.c:1646  */
    {(yyval.node) = makeBreakNode();}
#line 1643 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 154 "ast.y" /* yacc.c:1646  */
    {(yyval.node) = makeContinueNode();}
#line 1649 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 180 "ast.y" /* yacc.c:1646  */
    {(yyval.node) = makeOperatorNode(_INT,_PLUS,(yyvsp[-2].node),(yyvsp[0].node));}
#line 1655 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 181 "ast.y" /* yacc.c:1646  */
    {(yyval.node) = makeOperatorNode(_INT,_MINUS,(yyvsp[-2].node),(yyvsp[0].node));}
#line 1661 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 182 "ast.y" /* yacc.c:1646  */
    {(yyval.node) = makeOperatorNode(_INT,_MUL,(yyvsp[-2].node),(yyvsp[0].node));}
#line 1667 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 183 "ast.y" /* yacc.c:1646  */
    {(yyval.node) = makeOperatorNode(_INT,_DIV,(yyvsp[-2].node),(yyvsp[0].node));}
#line 1673 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 184 "ast.y" /* yacc.c:1646  */
    {(yyval.node) = makeOperatorNode(_INT,_MOD,(yyvsp[-2].node),(yyvsp[0].node));}
#line 1679 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 185 "ast.y" /* yacc.c:1646  */
    {(yyval.node) = makeOperatorNode(_BOOL,_GT,(yyvsp[-2].node),(yyvsp[0].node));}
#line 1685 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 186 "ast.y" /* yacc.c:1646  */
    {(yyval.node) = makeOperatorNode(_BOOL,_LT,(yyvsp[-2].node),(yyvsp[0].node));}
#line 1691 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 187 "ast.y" /* yacc.c:1646  */
    {(yyval.node) = makeOperatorNode(_BOOL,_GE,(yyvsp[-2].node),(yyvsp[0].node));}
#line 1697 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 188 "ast.y" /* yacc.c:1646  */
    {(yyval.node) = makeOperatorNode(_BOOL,_LE,(yyvsp[-2].node),(yyvsp[0].node));}
#line 1703 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 189 "ast.y" /* yacc.c:1646  */
    {(yyval.node) = makeOperatorNode(_BOOL,_NE,(yyvsp[-2].node),(yyvsp[0].node));}
#line 1709 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 190 "ast.y" /* yacc.c:1646  */
    {(yyval.node) = makeOperatorNode(_BOOL,_EQ,(yyvsp[-2].node),(yyvsp[0].node));}
#line 1715 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 191 "ast.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[-1].node);}
#line 1721 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 192 "ast.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1727 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 193 "ast.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1733 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 194 "ast.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1739 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 197 "ast.y" /* yacc.c:1646  */
    {checkTypeMismatchVar((yyvsp[-3].node),_ARRAY); (yyval.node) = makeArrayLeafNode((yyvsp[-3].node),(yyvsp[-1].node));}
#line 1745 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 198 "ast.y" /* yacc.c:1646  */
    {checkTypeMismatchVar((yyvsp[0].node),_VAR); (yyval.node) = (yyvsp[0].node);}
#line 1751 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1755 "y.tab.c" /* yacc.c:1646  */
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
#line 202 "ast.y" /* yacc.c:1906  */


void yyerror(const char *s){
    printf("yyerror %s",s);
}

int main(int argc, char *argv[]){
    if (argc > 1){
        FILE *fp = fopen(argv[1], "r");
        if(fp) yyin = fp;
    }
    FILE *fp;
    fp = fopen("xsm1.xsm","w");
    //Header of xsm FILE
    //XEXE file format
    fprintf(fp, "0\n");
    //entry point
    fprintf(fp, "main\n");
    for(int i=0;i<6;i++) fprintf(fp, "0\n");
    fprintf(fp, "MOV SP, %d\n",addrs);

    yyparse();

    fprintf(fp ,"INT 10");
    fclose(fp);
    return 0;
}
