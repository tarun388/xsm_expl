%{

  #include <stdio.h>
  #include <stdlib.h>
  #include "expreval.h"
  #include "expreval.c"
  int yylex(void);

%}

%union{
  struct tnode *no;
}
%type <no> expr NUM program END
%token NUM PLUS MINUS MUL DIV END
%left PLUS MINUS
%left MUL DIV

%%

program : expr END{
  $$ = $2;
  genxsm($1);
  exit(1);
}

expr : PLUS expr expr     {$$ = makeOperatorNode('+',$2,$3);}
      | MINUS expr expr   {$$ = makeOperatorNode('-',$2,$3);}
      | MUL expr expr     {$$ = makeOperatorNode('*',$2,$3);}
      | DIV expr expr     {$$ = makeOperatorNode('/',$2,$3);}
      | '(' expr ')'      {$$ = $2;}
      | NUM               {$$ = $1;}
      ;

%%

void yyerror(char const *s){
  printf("yyerror %s",s);
}

int main(void){
  yyparse();

  return 0;
}
