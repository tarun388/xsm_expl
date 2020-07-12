%{
    #include "ast.h"
    #include "y.tab.h"

  int number;

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
"("         {return *yytext;}
")"         {return *yytext;}
"main"      {yylval.node = makeVarLeafNode(yytext);
            yylval.node->type = TLookup("int");
            return MAIN;}
"return"    {return RETURN;}
"begin"     {return _BEGIN;}
"end"       {return END;}
"read"      {return READ;}
"write"     {return WRITE;}
"type"      {typeflag=1;        //for type declaration
            return _TYPE;}
"endtype"   {typeflag=0;        //for type declaration
            return ENDTYPE;}
"alloc"     {return ALLOC;}
"free"      {return FREE;}
"initialize" {return INITIALIZE;}
"null"      {return __NULL;}
"."         {return *yytext;}
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
[\"][A-Za-z0-9]*[\"]            {yylval.node = makeConstStringLeafNode(yytext);
                                return STRING;}
[A-Za-z][A-Za-z0-9]*            {yylval.node = makeVarLeafNode(yytext);
                                return ID;}

.                       {printf("%c",*yytext);
                        yyerror("unknown character\n");
                        exit(1);}

%%

int yywrap(void){
    return 1;
}
