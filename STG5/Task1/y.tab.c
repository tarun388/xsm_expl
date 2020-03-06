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
#define YYLAST   296

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  72
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  160

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
       0,    25,    25,    26,    27,    30,    31,    34,    35,    38,
      41,    42,    45,    46,    49,    50,    51,    54,    55,    58,
      62,    63,    64,    67,    70,    73,    74,    75,    78,    79,
      82,    85,    86,    89,    92,    95,    96,    99,   100,   101,
     102,   103,   104,   105,   108,   116,   122,   130,   133,   136,
     145,   148,   151,   152,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   174,   175
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
  "OutputStmt", "AsgStmt", "BrkStmt", "ContStmt", "ArgList", "E",
  "Identifier", YY_NULLPTR
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

#define YYPACT_NINF -134

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-134)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      38,    22,   -27,    21,    62,  -134,  -134,  -134,  -134,    43,
    -134,    32,   -13,  -134,   -27,    78,    62,  -134,  -134,  -134,
    -134,    48,    42,  -134,    65,    59,  -134,  -134,   146,    98,
    -134,    32,    70,    98,   119,   148,   -23,  -134,  -134,   129,
      13,  -134,  -134,    98,  -134,    46,   159,   120,  -134,  -134,
     150,    54,  -134,   260,   126,   129,  -134,    94,  -134,  -134,
     130,   131,   134,   143,   144,   137,   149,   178,  -134,  -134,
    -134,  -134,  -134,  -134,  -134,  -134,   142,  -134,   159,  -134,
     176,    31,    31,    31,    31,    31,  -134,  -134,    31,   186,
    -134,    31,   147,  -134,  -134,    58,  -134,    31,    39,  -134,
      96,   158,   102,   127,   201,  -134,   221,  -134,    29,   133,
      31,    31,    31,    31,    31,    31,    31,    31,    31,    31,
      31,   160,   162,  -134,   180,   171,  -134,  -134,  -134,    26,
     272,  -134,   118,   118,  -134,  -134,  -134,    16,    16,    16,
      16,    16,    16,  -134,  -134,   260,   260,    31,  -134,   243,
     189,   272,   260,   163,   167,   249,  -134,  -134,   175,  -134
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     4,     6,    10,    11,     0,
       8,     0,     0,     1,    10,     0,     0,    18,     3,     5,
       7,    15,     0,    13,     0,     0,    17,     2,     0,    22,
       9,     0,     0,    22,     0,     0,     0,    21,    12,    27,
       0,    14,    23,     0,    16,     0,     0,     0,    20,    26,
       0,     0,    29,     0,     0,    27,    32,     0,    25,    28,
       0,     0,    72,     0,     0,     0,     0,     0,    36,    41,
      40,    37,    38,    39,    42,    43,     0,    24,     0,    30,
       0,     0,     0,     0,     0,     0,    50,    51,     0,     0,
      35,     0,     0,    31,    66,    72,    67,     0,     0,    68,
       0,     0,     0,     0,     0,    33,     0,    19,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    71,     0,     0,    34,    49,    69,     0,
      53,    65,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    47,    48,     0,     0,     0,    70,     0,
       0,    52,     0,     0,     0,     0,    46,    44,     0,    45
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -134,  -134,  -134,  -134,   210,     6,  -134,   195,  -134,   211,
     200,   191,     2,   181,  -134,   184,  -134,   168,  -134,  -133,
     -66,  -134,  -134,  -134,  -134,  -134,  -134,  -134,  -134,   -80,
     -53
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     9,    10,    35,    22,    23,    16,    17,
      36,    37,     5,    46,    51,    52,    57,    54,    89,    67,
      68,    69,    70,    71,    72,    73,    74,    75,   129,    98,
      99
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      76,    90,   100,   101,   102,   103,    18,    11,   104,    12,
      15,   106,   149,   150,    76,    11,    43,   109,    27,   155,
      44,    13,    15,   110,   111,   112,   113,   114,   130,    24,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,    94,    95,    94,    95,    21,   110,   111,   112,   113,
     114,    50,    43,     6,     7,     8,    47,    50,   115,   116,
     117,   118,   119,   120,    96,   147,    96,   151,     1,   148,
       2,    97,   128,    97,    19,     7,     8,    49,     7,     8,
      30,    31,   121,    90,    90,    58,     7,     8,    28,    90,
      29,    25,    76,    76,    14,     8,    76,    76,    83,    76,
     108,    33,    76,   110,   111,   112,   113,   114,    32,   110,
     111,   112,   113,   114,    39,   115,   116,   117,   118,   119,
     120,   115,   116,   117,   118,   119,   120,   112,   113,   114,
       7,     8,    79,    80,   110,   111,   112,   113,   114,   122,
     110,   111,   112,   113,   114,   124,   115,   116,   117,   118,
     119,   120,   115,   116,   117,   118,   119,   120,    34,    45,
      41,    42,    53,    56,    55,   110,   111,   112,   113,   114,
     125,    77,    81,    82,    83,    86,   131,   115,   116,   117,
     118,   119,   120,    60,    61,    84,    85,    87,    91,    93,
     105,    62,   107,    63,    60,    61,   145,   146,   143,   123,
     144,   156,    62,    64,    63,   157,    65,    66,   110,   111,
     112,   113,   114,   159,    64,    88,   154,    65,    66,    20,
     115,   116,   117,   118,   119,   120,    38,    26,   110,   111,
     112,   113,   114,    40,    48,    59,    78,     0,     0,   126,
     115,   116,   117,   118,   119,   120,    92,     0,    60,    61,
       0,     0,     0,     0,    60,    61,    62,     0,    63,   127,
     152,   153,    62,     0,    63,    60,    61,   158,    64,     0,
       0,    65,    66,    62,    64,    63,     0,    65,    66,   110,
     111,   112,   113,   114,     0,    64,     0,     0,    65,    66,
       0,   115,   116,   117,   118,   119,   120
};

static const yytype_int16 yycheck[] =
{
      53,    67,    82,    83,    84,    85,     4,     1,    88,    36,
       4,    91,   145,   146,    67,     9,    39,    97,    16,   152,
      43,     0,    16,     7,     8,     9,    10,    11,   108,    42,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,    12,    13,    12,    13,    13,     7,     8,     9,    10,
      11,    45,    39,    31,    32,    33,    43,    51,    19,    20,
      21,    22,    23,    24,    35,    39,    35,   147,    30,    43,
      32,    42,    43,    42,    31,    32,    33,    31,    32,    33,
      38,    39,    43,   149,   150,    31,    32,    33,    40,   155,
      42,    13,   145,   146,    32,    33,   149,   150,    40,   152,
      42,    42,   155,     7,     8,     9,    10,    11,    43,     7,
       8,     9,    10,    11,    44,    19,    20,    21,    22,    23,
      24,    19,    20,    21,    22,    23,    24,     9,    10,    11,
      32,    33,    38,    39,     7,     8,     9,    10,    11,    43,
       7,     8,     9,    10,    11,    43,    19,    20,    21,    22,
      23,    24,    19,    20,    21,    22,    23,    24,    12,    30,
      41,    13,     3,    13,    44,     7,     8,     9,    10,    11,
      43,    45,    42,    42,    40,    38,    43,    19,    20,    21,
      22,    23,    24,     5,     6,    42,    42,    38,    46,    13,
       4,    13,    45,    15,     5,     6,    16,    26,    38,    41,
      38,    38,    13,    25,    15,    38,    28,    29,     7,     8,
       9,    10,    11,    38,    25,    37,    27,    28,    29,     9,
      19,    20,    21,    22,    23,    24,    31,    16,     7,     8,
       9,    10,    11,    33,    43,    51,    55,    -1,    -1,    38,
      19,    20,    21,    22,    23,    24,    78,    -1,     5,     6,
      -1,    -1,    -1,    -1,     5,     6,    13,    -1,    15,    38,
      17,    18,    13,    -1,    15,     5,     6,    18,    25,    -1,
      -1,    28,    29,    13,    25,    15,    -1,    28,    29,     7,
       8,     9,    10,    11,    -1,    25,    -1,    -1,    28,    29,
      -1,    19,    20,    21,    22,    23,    24
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
      69,    70,    71,    72,    73,    74,    77,    45,    60,    38,
      39,    42,    42,    40,    42,    42,    38,    38,    37,    65,
      67,    46,    64,    13,    12,    13,    35,    42,    76,    77,
      76,    76,    76,    76,    76,     4,    76,    45,    42,    76,
       7,     8,     9,    10,    11,    19,    20,    21,    22,    23,
      24,    43,    43,    41,    43,    43,    38,    38,    43,    75,
      76,    43,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    38,    38,    16,    26,    39,    43,    66,
      66,    76,    17,    18,    27,    66,    38,    38,    18,    38
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    47,    48,    48,    48,    49,    49,    50,    50,    51,
      52,    52,    53,    53,    54,    54,    54,    55,    55,    56,
      57,    57,    57,    58,    59,    60,    60,    60,    61,    61,
      62,    63,    63,    64,    65,    66,    66,    67,    67,    67,
      67,    67,    67,    67,    68,    69,    69,    70,    71,    72,
      73,    74,    75,    75,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    77,    77
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     2,     1,     3,     2,     2,     1,     3,
       1,     1,     3,     1,     4,     1,     4,     2,     1,     9,
       3,     1,     0,     2,     8,     3,     2,     0,     2,     1,
       3,     3,     1,     4,     3,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     8,    10,     8,     5,     5,     4,
       2,     2,     3,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     1,     1,     1,     3,
       4,     4,     1
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
    {printf("PARSED\n");}
#line 1422 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 26 "ast.y" /* yacc.c:1646  */
    {printf("PARSED\n");}
#line 1428 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 27 "ast.y" /* yacc.c:1646  */
    {printf("PARSED\n");}
#line 1434 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 30 "ast.y" /* yacc.c:1646  */
    {print_Gsymbol_table();global_declaration_code();}
#line 1440 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 31 "ast.y" /* yacc.c:1646  */
    {global_declaration_code();}
#line 1446 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 38 "ast.y" /* yacc.c:1646  */
    {TypeStackPop();}
#line 1452 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 41 "ast.y" /* yacc.c:1646  */
    {TYPE = TypeStackPush(_INT);}
#line 1458 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 42 "ast.y" /* yacc.c:1646  */
    {TYPE = TypeStackPush(_STRING);}
#line 1464 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 49 "ast.y" /* yacc.c:1646  */
    {GInstall((yyvsp[-3].node)->varname,TYPE,(yyvsp[-1].node)->val,_ARRAY,NULL);}
#line 1470 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 50 "ast.y" /* yacc.c:1646  */
    {GInstall((yyvsp[0].node)->varname,TYPE,1,_VAR,NULL);}
#line 1476 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 51 "ast.y" /* yacc.c:1646  */
    {GInstall((yyvsp[-3].node)->varname,TYPE,-1,_FUNCTION,(yyvsp[-1].node2));ParamHead=NULL;}
#line 1482 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 58 "ast.y" /* yacc.c:1646  */
    {p();Function((yyvsp[-7].node),(yyvsp[-5].node2),(yyvsp[-1].node));preorder((yyvsp[-1].node));printf("\n");gen_function_code((yyvsp[-7].node),(yyvsp[-1].node));LsymbolHead=NULL;LsymbolTail=NULL;ParamHead=NULL;}
#line 1488 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 62 "ast.y" /* yacc.c:1646  */
    {(yyval.node2) = makeParamList((yyvsp[-2].node2),(yyvsp[0].node2));ParamHead=(yyval.node2);}
#line 1494 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 63 "ast.y" /* yacc.c:1646  */
    {(yyval.node2) = (yyvsp[0].node2);ParamHead=(yyval.node2);}
#line 1500 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 64 "ast.y" /* yacc.c:1646  */
    {(yyval.node2) = NULL;ParamHead=(yyval.node2);}
#line 1506 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 67 "ast.y" /* yacc.c:1646  */
    {(yyval.node2) = makeParameter((yyvsp[0].node)->varname,TYPE);TypeStackPop();}
#line 1512 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 70 "ast.y" /* yacc.c:1646  */
    {p();Function((yyvsp[-6].node),NULL,(yyvsp[-1].node));preorder((yyvsp[-1].node));printf("\n");gen_function_code((yyvsp[-6].node),(yyvsp[-1].node));LsymbolHead=NULL;LsymbolTail=NULL;ParamHead=NULL;}
#line 1518 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 73 "ast.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[-1].node);p(); InstallParameter();p();}
#line 1524 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 74 "ast.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;p();InstallParameter();p();}
#line 1530 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 75 "ast.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;p();InstallParameter();p();}
#line 1536 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 82 "ast.y" /* yacc.c:1646  */
    {TypeStackPop();}
#line 1542 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 85 "ast.y" /* yacc.c:1646  */
    {LInstall((yyvsp[0].node)->varname,TYPE);}
#line 1548 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 86 "ast.y" /* yacc.c:1646  */
    {LInstall((yyvsp[0].node)->varname,TYPE);}
#line 1554 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 89 "ast.y" /* yacc.c:1646  */
    {(yyval.node) = makeconnectorNode((yyvsp[-2].node),(yyvsp[-1].node));}
#line 1560 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 92 "ast.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[-1].node);}
#line 1566 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 95 "ast.y" /* yacc.c:1646  */
    {(yyval.node) = makeconnectorNode((yyvsp[-1].node),(yyvsp[0].node));}
#line 1572 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 96 "ast.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1578 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 99 "ast.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1584 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 100 "ast.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1590 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 101 "ast.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1596 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 102 "ast.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1602 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 103 "ast.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1608 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 104 "ast.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1614 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 105 "ast.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1620 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 108 "ast.y" /* yacc.c:1646  */
    {   if((yyvsp[-5].node)->type != _BOOL){
                                                                                    yyerror("type mismatch");
                                                                                    exit(1);
                                                                                    }
                                                                                    (yyval.node) = makeLoopNode((yyvsp[-5].node),(yyvsp[-2].node));
                                                                                }
#line 1631 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 116 "ast.y" /* yacc.c:1646  */
    {   if((yyvsp[-7].node)->type != _BOOL){
                                                                                    yyerror("type mismatch");
                                                                                    exit(1);
                                                                                    }
                                                                                    (yyval.node) = makeCondNode((yyvsp[-7].node),(yyvsp[-4].node),(yyvsp[-2].node));
                                                                                }
#line 1642 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 122 "ast.y" /* yacc.c:1646  */
    {   if((yyvsp[-5].node)->type != _BOOL){
                                                                                        yyerror("type mismatch");
                                                                                        exit(1);
                                                                                    }
                                                                                    (yyval.node) = makeCondNode((yyvsp[-5].node),(yyvsp[-2].node),NULL);
                                                                                }
#line 1653 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 130 "ast.y" /* yacc.c:1646  */
    {(yyval.node) = makeReadNode((yyvsp[-2].node));}
#line 1659 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 133 "ast.y" /* yacc.c:1646  */
    {(yyval.node) = makeWriteNode((yyvsp[-2].node));}
#line 1665 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 136 "ast.y" /* yacc.c:1646  */
    {
                                                                                    if((yyvsp[-3].node)->nodetype != _VAR && (yyvsp[-3].node)->nodetype != _ARRAY){
                                                                                        yyerror("LHS should be memory location\n");
                                                                                        exit(1);
                                                                                    }
                                                                                    (yyval.node) = makeAsgtNode((yyvsp[-3].node),(yyvsp[-1].node));
                                                                                }
#line 1677 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 145 "ast.y" /* yacc.c:1646  */
    {(yyval.node) = makeBreakNode();}
#line 1683 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 148 "ast.y" /* yacc.c:1646  */
    {(yyval.node) = makeContinueNode();}
#line 1689 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 151 "ast.y" /* yacc.c:1646  */
    {(yyval.node) = makeArgList((yyvsp[-2].node),(yyvsp[0].node));}
#line 1695 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 152 "ast.y" /* yacc.c:1646  */
    {(yyval.node) = makeArgList(NULL,(yyvsp[0].node));}
#line 1701 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 155 "ast.y" /* yacc.c:1646  */
    {(yyval.node) = makeOperatorNode(_INT,_PLUS,(yyvsp[-2].node),(yyvsp[0].node));}
#line 1707 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 156 "ast.y" /* yacc.c:1646  */
    {(yyval.node) = makeOperatorNode(_INT,_MINUS,(yyvsp[-2].node),(yyvsp[0].node));}
#line 1713 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 157 "ast.y" /* yacc.c:1646  */
    {(yyval.node) = makeOperatorNode(_INT,_MUL,(yyvsp[-2].node),(yyvsp[0].node));}
#line 1719 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 158 "ast.y" /* yacc.c:1646  */
    {(yyval.node) = makeOperatorNode(_INT,_DIV,(yyvsp[-2].node),(yyvsp[0].node));}
#line 1725 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 159 "ast.y" /* yacc.c:1646  */
    {(yyval.node) = makeOperatorNode(_INT,_MOD,(yyvsp[-2].node),(yyvsp[0].node));}
#line 1731 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 160 "ast.y" /* yacc.c:1646  */
    {(yyval.node) = makeOperatorNode(_BOOL,_GT,(yyvsp[-2].node),(yyvsp[0].node));}
#line 1737 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 161 "ast.y" /* yacc.c:1646  */
    {(yyval.node) = makeOperatorNode(_BOOL,_LT,(yyvsp[-2].node),(yyvsp[0].node));}
#line 1743 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 162 "ast.y" /* yacc.c:1646  */
    {(yyval.node) = makeOperatorNode(_BOOL,_GE,(yyvsp[-2].node),(yyvsp[0].node));}
#line 1749 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 163 "ast.y" /* yacc.c:1646  */
    {(yyval.node) = makeOperatorNode(_BOOL,_LE,(yyvsp[-2].node),(yyvsp[0].node));}
#line 1755 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 164 "ast.y" /* yacc.c:1646  */
    {(yyval.node) = makeOperatorNode(_BOOL,_NE,(yyvsp[-2].node),(yyvsp[0].node));}
#line 1761 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 165 "ast.y" /* yacc.c:1646  */
    {(yyval.node) = makeOperatorNode(_BOOL,_EQ,(yyvsp[-2].node),(yyvsp[0].node));}
#line 1767 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 166 "ast.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[-1].node);}
#line 1773 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 167 "ast.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1779 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 168 "ast.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1785 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 169 "ast.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1791 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 170 "ast.y" /* yacc.c:1646  */
    {(yyval.node) = makeFunctionNode((yyvsp[-2].node),NULL);}
#line 1797 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 171 "ast.y" /* yacc.c:1646  */
    {(yyval.node) = makeFunctionNode((yyvsp[-3].node),(yyvsp[-1].node));}
#line 1803 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 174 "ast.y" /* yacc.c:1646  */
    {(yyval.node) = makeArrayLeafNode((yyvsp[-3].node),(yyvsp[-1].node));}
#line 1809 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 175 "ast.y" /* yacc.c:1646  */
    {(yyval.node) = updateVarLeafNode((yyvsp[0].node));}
#line 1815 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1819 "y.tab.c" /* yacc.c:1646  */
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
#line 179 "ast.y" /* yacc.c:1906  */


void yyerror(const char *s){
    printf("yyerror %s",s);
}

int main(int argc, char *argv[]){
    if (argc > 1){
        fp = fopen(argv[1], "r");
        if(fp) yyin = fp;
    }
    //FILE *fp;
    /* printf("cdddd"); */
    fp = fopen("xsm1.xsm","w");
    //Header of xsm FILE
    //XEXE file format
    fprintf(fp, "0\n");
    //entry point
    fprintf(fp, "2056\n");
    for(int i=0;i<6;i++) fprintf(fp, "0\n");
    //fprintf(fp, "MOV SP, %d\n",addrs);

    TopTypeStack = -1;

    yyparse();

    fprintf(fp ,"INT 10");
    fclose(fp);
    return 0;
}
