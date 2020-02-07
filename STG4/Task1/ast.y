%{
  #include <stdio.h>
  #include <stdlib.h>
  #include "ast.h"
  #include "ast.c"
  int yylex(void);

  FILE * yyin;
  /* int var_type=-1; */

%}

%union{
  struct astnode *node;
  /* struct Gsymbol *node2; */
};

/* %type <node2> */
%type <node> program Slist Stmt InputStmt OutputStmt AsgStmt ID E READ WRITE NUM Ifstmt Whilestmt BrkStmt ContStmt BREAK CONTINUE STRING Declarations DecList Decl Type Varlist INT STR IdList Identifier
%token _BEGIN END READ WRITE PLUS MINUS MUL DIV MOD NUM ID NEWLINE IF THEN ELSE ENDIF GT LT GE LE NE EQ WHILE DO ENDWHILE BREAK CONTINUE DECL ENDDECL INT STR IDD STRING
%left GT LT GE LE NE EQ
%left PLUS MINUS
%left MUL DIV MOD

%start program

%%

program     :  Declarations _BEGIN Slist END ';'            {$$ = $3;

                                                printf("PARSED\n");
                                                genxsm($3);
                                                preorder($3);
                                                }
            |  Declarations _BEGIN END ';'                  {$$ = NULL;}
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

InputStmt   :   READ '(' E ')' ';'             {$$ = makeReadNode($3);}
            ;

OutputStmt  :   WRITE '(' E ')' ';'             {$$ = makeWriteNode($3);}
            ;

AsgStmt     :   Identifier  '='  E ';'                  {
                                                    if($1->nodetype != _VAR && $1->nodetype != _ARRAY){
                                                        yyerror("LHS should be memory location\n");
                                                        exit(1);
                                                    }

                                                    $$ = makeAsgtNode($1,$3);
                                                }
            ;

BrkStmt     :   BREAK ';'                       {$$ = makeBreakNode();}
            ;

ContStmt    :   CONTINUE ';'                    {$$ = makeContinueNode();}
            ;

Declarations    :   DECL DecList ENDDECL        {print_Gsymbol_table();}
                |   DECL ENDDECL                {$$ = NULL;}
                ;

DecList         :   DecList Decl
                |   Decl
                ;

Decl            :   Type Varlist ';'
                ;

Type            :   INT                         {}
                |   STR                         {}
                ;

Varlist         :   Varlist ',' IdList
                |   IdList
                ;

IdList          :   ID '[' NUM ']'              {Install($1->varname,$1->type,$3->val,_ARRAY);}
                |   ID                          {Install($1->varname,$1->type,1,_VAR);}
                ;

E           :   E PLUS E                        {$$ = makeOperatorNode(_INT,_PLUS,$1,$3);}
            |   E MINUS E                       {$$ = makeOperatorNode(_INT,_MINUS,$1,$3);}
            |   E MUL E                         {$$ = makeOperatorNode(_INT,_MUL,$1,$3);}
            |   E DIV E                         {$$ = makeOperatorNode(_INT,_DIV,$1,$3);}
            |   E MOD E                         {$$ = makeOperatorNode(_INT,_MOD,$1,$3);}
            |   E GT E                          {$$ = makeOperatorNode(_BOOL,_GT,$1,$3);}
            |   E LT E                          {$$ = makeOperatorNode(_BOOL,_LT,$1,$3);}
            |   E GE E                          {$$ = makeOperatorNode(_BOOL,_GE,$1,$3);}
            |   E LE E                          {$$ = makeOperatorNode(_BOOL,_LE,$1,$3);}
            |   E NE E                          {$$ = makeOperatorNode(_BOOL,_NE,$1,$3);}
            |   E EQ E                          {$$ = makeOperatorNode(_BOOL,_EQ,$1,$3);}
            |   '(' E ')'                       {$$ = $2;}
            |   NUM                             {$$ = $1;}
            |   STRING                          {$$ = $1;}
            |   Identifier                           {$$ = $1;}
            ;

Identifier  :  ID '[' E ']'                    {$$ = makeArrayLeafNode($1,$3);}
            |  ID                              {$$ = $1;}
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
