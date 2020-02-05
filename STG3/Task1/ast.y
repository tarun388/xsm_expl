%{

  #include <stdio.h>
  #include <stdlib.h>
  #include "ast.h"
  #include "ast.c"
  int yylex(void);

  FILE * yyin;

%}

%union{
  struct astnode *node;
};

%type <node> program Slist Stmt InputStmt OutputStmt AsgStmt ID E READ WRITE NUM Ifstmt Whilestmt BrkStmt ContStmt BREAK CONTINUE
%token _BEGIN END READ WRITE PLUS MINUS MUL DIV NUM ID NEWLINE IF THEN ELSE ENDIF GT LT GE LE NE EQ WHILE DO ENDWHILE BREAK CONTINUE
%left GT LT GE LE NE EQ
%left PLUS MINUS
%left MUL DIV

%%

program     :   _BEGIN Slist END ';'            {$$ = $2;

                                                printf("PARSED\n");
                                                genxsm($2);
                                                preorder($2);
                                                }
            |   _BEGIN END ';'                  {$$ = NULL;}
            ;



Slist       :   Slist Stmt                      {$$ = makeconnectorNode($1,$2);}
            |   Stmt                            {$$ = $1;}
            ;

Stmt        :   InputStmt                       {$$ = $1;}
            |   OutputStmt                      {$$ = $1;}
            |   AsgStmt                         {$$ = $1;}
            |   Ifstmt                          {$$ = $1;}
            |   Whilestmt                       {$$ = $1;}
            |   BrkStmt                         {$$ = $1;}
            |   ContStmt                        {$$ = $1;}
            ;

Whilestmt   :   WHILE '(' E ')' DO Slist ENDWHILE ';'                           {   if($3->type != _BOOL){
                                                                                    yyerror("type mismatch");
                                                                                    exit(1);
                                                                                    }
                                                                                    else $$ = makeLoopNode($3,$6);
                                                                                }
            ;

Ifstmt      :   IF '(' E ')' THEN Slist ELSE Slist ENDIF ';'                    {   if($3->type != _BOOL){
                                                                                    yyerror("type mismatch");
                                                                                    exit(1);
                                                                                    }
                                                                                    else $$ = makeCondNode($3,$6,$8);
                                                                                }
            |   IF '(' E ')' THEN Slist ENDIF ';'                               {   if($3->type != _BOOL){
                                                                                        yyerror("type mismatch");
                                                                                        exit(1);
                                                                                    }
                                                                                    else $$ = makeCondNode($3,$6,NULL);
                                                                                }
            ;

InputStmt   :   READ '(' ID ')' ';'             {$$ = makeReadNode($3);}
            ;

OutputStmt  :   WRITE '(' E ')' ';'             {$$ = makeWriteNode($3);}
            ;

AsgStmt     :   ID  '='  E ';'                  {   if($3->type == _BOOL){
                                                        yyerror("type mismatch");
                                                        exit(1);
                                                    }
                                                    else {$$ = makeAsgtNode($1,$3);}
                                                }
            ;

BrkStmt     :   BREAK ';'                       {$$ = makeBreakNode();}
            ;

ContStmt    :   CONTINUE ';'                    {$$ = makeContinueNode();}
            ;

E           :   E PLUS E                        {   if(($1->type == _BOOL) || ($3->type == _BOOL)){
                                                        yyerror("type mismatch");
                                                        exit(1);
                                                    }
                                                    else {$$ = makeOperatorNode(4,0,$1,$3);}
                                                }
            |   E MINUS E                       {   if(($1->type == _BOOL) || ($3->type == _BOOL)){
                                                        yyerror("type mismatch");
                                                        exit(1);
                                                    }
                                                    else $$ = makeOperatorNode(4,1,$1,$3);
                                                }
            |   E MUL E                         {   if(($1->type == _BOOL) || ($3->type == _BOOL)){
                                                        yyerror("type mismatch");
                                                        exit(1);
                                                    }
                                                    else $$ = makeOperatorNode(4,2,$1,$3);
                                                }
            |   E DIV E                         {   if(($1->type == _BOOL) || ($3->type == _BOOL)){
                                                        yyerror("type mismatch");
                                                        exit(1);
                                                    }
                                                    else $$ = makeOperatorNode(4,3,$1,$3);
                                                }
            |   E GT E                          {$$ = makeOperatorNode(16,9,$1,$3);}
            |   E LT E                          {$$ = makeOperatorNode(16,10,$1,$3);}
            |   E GE E                          {$$ = makeOperatorNode(16,11,$1,$3);}
            |   E LE E                          {$$ = makeOperatorNode(16,12,$1,$3);}
            |   E NE E                          {$$ = makeOperatorNode(16,13,$1,$3);}
            |   E EQ E                          {$$ = makeOperatorNode(16,14,$1,$3);}
            |   '(' E ')'                       {$$ = $2;}
            |   NUM                             {$$ = $1;}
            |   ID                              {$$ = $1;}
            ;


%%

void yyerror(const char *s){
    printf("yyerror %s",s);
}

int main(int argc, char *argv[]){
    if (argc > 1){
        FILE *fp = fopen(argv[1], "r");
        if(fp) yyin = fp;
    }
    yyparse();
    return 0;
}
