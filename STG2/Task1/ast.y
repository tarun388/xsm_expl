%{

  #include <stdio.h>
  #include <stdlib.h>
  #include "ast.h"
  #include "ast.c"
  int yylex(void);

%}

%union{
  struct astnode *node;
};

%type <node> program Slist Stmt InputStmt OutputStmt AsgStmt ID E READ WRITE NUM
%token _BEGIN END READ WRITE PLUS MINUS MUL DIV NUM ID NEWLINE
%left PLUS MINUS
%left MUL DIV

%%

program     :   _BEGIN Slist END ';'            {$$ = $2;
                                                genxsm($2);
                                                }
            |   _BEGIN END ';'                  {$$ = NULL;}
            ;

Slist       :   Slist Stmt                      {$$ = makeconnectorNode($1,$2);}
            |   Stmt                            {$$ = $1;}
            ;

Stmt        :   InputStmt                       {$$ = $1;}
            |   OutputStmt                      {$$ = $1;}
            |   AsgStmt                         {$$ = $1;}
            ;

InputStmt   :   READ '(' ID ')' ';'             {$$ = makeReadNode($3);}

OutputStmt  :   WRITE '(' E ')' ';'             {$$ = makeWriteNode($3);}

AsgStmt     :   ID  '='  E ';'                  {$$ = makeAsgtNode($1,$3);}

E           :   E PLUS E                        {$$ = makeOperatorNode(0,$1,$3);}
            |   E MINUS E                       {$$ = makeOperatorNode(1,$1,$3);}
            |   E MUL E                         {$$ = makeOperatorNode(2,$1,$3);}
            |   E DIV E                         {$$ = makeOperatorNode(3,$1,$3);}
            |   '(' E ')'                       {$$ = $2;}
            |   NUM                             {$$ = $1;}
            |   ID                              {$$ = $1;}
            ;


%%

void yyerror(const char *s){
    printf("yyerror %s",s);
}

int main(int argc, char *argv[]){
    //if (arg > 1){
    //    FILE *fp = fopen(argv[1], "r");
    //    if(fp) yyin = fp;
    //}
    yyparse();
    return 0;
}
