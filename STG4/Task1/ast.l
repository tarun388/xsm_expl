%{
  #include <stdio.h>
  #include <stdlib.h>
  #include <stdbool.h>
  #include <string.h>
  #include "y.tab.h"
  #include "ast.h"

  int number;
  bool decl_sec = false;
  bool code_sec = false;
  int var_type = -1;
%}

%%

[0-9]+      {number = atoi(yytext); yylval.node = makeConstIntLeafNode(number);return NUM;}
"+"         {return PLUS;}
"-"         {return MINUS;}
"*"         {return MUL;}
"/"         {return DIV;}
[ |\t|\n]   {}
[()]        {return *yytext;}
"begin"     {code_sec = true; return _BEGIN;}
"end"       {code_sec = false; return END;}
"read"      {return READ;}
"write"     {return WRITE;}
";"         {
                if(decl_sec == true) var_type = -1;
                return *yytext;
            }
","         {return *yytext;}
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
"decl"      {decl_sec = true; return DECL;}
"enddecl"   {decl_sec = false; return ENDDECL;}
"int"       {var_type = _INT; return INT;}
"str"       {var_type = _STRING; return STR;}
[\"](.)*[\"]    {yylval.node = makeConstStringLeafNode(yytext); return STRING;}
[a-z][a-z0-9]*       {
                if(decl_sec == true){
                    Install(yytext,var_type,1);
                    return IDD;
                }
                else if(code_sec = true){
                    yylval.node = makeVarLeafNode(yytext);
                    return ID;
                }
            }
.           {printf("%c",*yytext);yyerror("unknown character\n"); exit(1);}

%%

int yywrap(void){
    return 1;
}
