/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
    RETURN = 292,
    _TYPE = 293,
    ENDTYPE = 294,
    ALLOC = 295,
    FREE = 296,
    INITIALIZE = 297,
    __NULL = 298
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
#define _TYPE 293
#define ENDTYPE 294
#define ALLOC 295
#define FREE 296
#define INITIALIZE 297
#define __NULL 298

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 9 "ast.y" /* yacc.c:1909  */

  struct astnode *node;
  struct Paramstruct *node2;
  struct Fieldlist *node3;
  struct Typetable *node4;

#line 147 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
