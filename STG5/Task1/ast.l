%{
  #include "y.tab.h"
  #include "ast.h"

  int number;
  int var_type=-1;
  int param_type=-1;
  /* 1 declarations
  2 code */
  int section;
  /* type is for function parameter or not
  0 normal
  1 paramater */
  int param_on = 0;
%}

%%

[0-9]+      {number = atoi(yytext); yylval.node = makeConstIntLeafNode(number);return NUM;}
"+"         {return PLUS;}
"-"         {return MINUS;}
"*"         {return MUL;}
"/"         {return DIV;}
"%"         {return MOD;}
[ |\t|\n]   {}
"("         {param_on = 1; return *yytext;}
")"         {param_on = 0; return *yytext;}
"main"      {GInstall(yytext,_INT,-1,_FUNCTION,NULL); yylval.node = makeVarLeafNode(yytext,_INT,2,param_on); return MAIN;}
"return"    {return RETURN;}
"begin"     {section = 2; return _BEGIN;}
"end"       {return END;}
"read"      {return READ;}
"write"     {return WRITE;}
";"         {return *yytext;}
","         {return *yytext;}
"["         {return *yytext;}
"]"         {return *yytext;}
"{"         {return *yytext;}
"}"         {return *yytext;}
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
"int"       {param_type = _INT; if(param_on==0) var_type = _INT; return INT;}
"str"       {param_type = _STRING; if(param_on==0) var_type = _STRING; return STR;}
[\"](.)*[\"]            {yylval.node = makeConstStringLeafNode(yytext); return STRING;}
[a-z][a-z0-9]*          {if(param_on==0) yylval.node = makeVarLeafNode(yytext,var_type,section,param_on); else yylval.node = makeVarLeafNode(yytext,param_type,section,param_on); return ID;}
.                       {printf("%c",*yytext);yyerror("unknown character\n"); exit(1);}

%%

int yywrap(void){
    return 1;
}
