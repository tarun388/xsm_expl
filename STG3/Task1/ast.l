%{

  #include <stdio.h>
  #include <stdlib.h>
  #include "y.tab.h"
  #include "ast.h"

  int number;

%}

%%

[0-9]+  {number = atoi(yytext); yylval.node = makeLeafNode(number, 0, NULL);return NUM;}
"+"     {return PLUS;}
"-"     {return MINUS;}
"*"     {return MUL;}
"/"     {return DIV;}
[ |\t|\n]   {}
[()]    {return *yytext;}
[a-z]   {yylval.node = makeLeafNode(0,1,yytext); return ID;}
"begin" {return _BEGIN;}
"end"   {return END;}
"read"  {return READ;}
"write" {return WRITE;}
";"     {return *yytext;}
"="     {return *yytext;}
"if"    {return IF;}
"then"  {return THEN;}
"else"  {return ELSE;}
"endif" {return ENDIF;}
"while" {return WHILE;}
"do"    {return DO;}
"endwhile"  {return ENDWHILE;}
">"     {return GT;}
"<"     {return LT;}
">="    {return GE;}
"<="    {return LE;}
"!="    {return NE;}
"=="    {return EQ;}
"break" {return BREAK;}
"continue"  {return CONTINUE;}
.       {yyerror("unknown character\n"); exit(1);}

%%

int yywrap(void){
    return 1;
}
