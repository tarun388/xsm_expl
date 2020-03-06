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

[0-9]+      {number = atoi(yytext);
            yylval.node = makeConstIntLeafNode(number);
            return NUM;}
"+"         {return PLUS;}
"-"         {return MINUS;}
"*"         {return MUL;}
"/"         {return DIV;}
"%"         {return MOD;}
[ |\t|\n]   {}
"("         {param_on = 1;
            return *yytext;}
")"         {param_on = 0;
            return *yytext;}
"main"      {GInstall(yytext,_INT,-1,_FUNCTION,NULL);
            yylval.node = makeVarLeafNode(yytext);
            yylval.node->type = _INT;
            return MAIN;}
"return"    {return RETURN;}
"begin"     {return _BEGIN;}
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
"decl"      {return DECL;}
"enddecl"   {return ENDDECL;}
"int"       {return INT;}
"str"       {return STR;}
[\"](.)*[\"]            {yylval.node = makeConstStringLeafNode(yytext);
                        return STRING;}
[A-Za-z][A-Za-z0-9]*          {yylval.node = makeVarLeafNode(yytext);
                        return ID;}
.                       {printf("%c",*yytext);
                        yyerror("unknown character\n");
                        exit(1);}

%%

int yywrap(void){
    return 1;
}
