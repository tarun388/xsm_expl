%{
  #include <stdio.h>
  #include <stdlib.h>
  #include <stdbool.h>
  #include <string.h>
  #include "y.tab.h"
  #include "ast.h"

  int number;
  int var_type=-1;
  /* 1 declarations
  2 code */
  int section;
%}

%%

[0-9]+      {number = atoi(yytext); yylval.node = makeConstIntLeafNode(number);return NUM;}
"+"         {return PLUS;}
"-"         {return MINUS;}
"*"         {return MUL;}
"/"         {return DIV;}
"%"         {return MOD;}
[ |\t|\n]   {}
[()]        {return *yytext;}
"begin"     {section = 2; return _BEGIN;}
"end"       {return END;}
"read"      {return READ;}
"write"     {return WRITE;}
";"         {return *yytext;}
","         {return *yytext;}
"["         {return *yytext;}
"]"         {return *yytext;}
"="         {return *yytext;}
"if"        {return IF;}
"then"      {return THEN;}
"else"      {return ELSE;}
"endif"     {return ENDIF;}
"while"     {return WHILE;}
"do"        {return DO;}
"endwhile"  {return ENDWHILE;}
">"         {return GT;}
"<"         {return LT;}
">="        {return GE;}
"<="        {return LE;}
"!="        {return NE;}
"=="        {return EQ;}
"break"     {return BREAK;}
"continue"  {return CONTINUE;}
"decl"      {section = 1; return DECL;}
"enddecl"   {return ENDDECL;}
"int"       {var_type = _INT; return INT;}
"str"       {var_type = _STRING; return STR;}
[\"](.)*[\"]            {yylval.node = makeConstStringLeafNode(yytext); return STRING;}
[a-z][a-z0-9]*          {yylval.node = makeVarLeafNode(yytext,var_type,section); return ID;}
.                       {printf("%c",*yytext);yyerror("unknown character\n"); exit(1);}

%%

int yywrap(void){
    return 1;
}
