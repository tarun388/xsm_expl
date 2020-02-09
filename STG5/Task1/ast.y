%{
  #include "ast.h"
  #include "ast.c"
  int yylex(void);

  FILE * yyin;
%}

%union{
  struct astnode *node;
  struct Paramstruct *node2;
};

%type <node2> Param ParamList
%type <node> program GDeclBlock GDeclList GDecl Type INT STR GidList Gid FDefBlock Fdef MainBlock MAIN LdeclBlock LDecList LDecl IdList Body Retstmt Slist Stmt Whilestmt Ifstmt InputStmt READ OutputStmt WRITE AsgStmt BrkStmt ContStmt E NUM STRING ID Identifier
%token _BEGIN END READ WRITE PLUS MINUS MUL DIV MOD NUM ID NEWLINE IF THEN ELSE ENDIF GT LT GE LE NE EQ WHILE DO ENDWHILE BREAK CONTINUE DECL ENDDECL INT STR IDD STRING MAIN RETURN
%left GT LT GE LE NE EQ
%left PLUS MINUS
%left MUL DIV MOD

%start program

%%

program     :   GDeclBlock FDefBlock MainBlock                                  {
                                                                                    print_Gsymbol_table();
                                                                                    printf("PARSED\n");
                                                                                    //genxsm($3);
                                                                                    preorder($2);
                                                                                    printf("\n");
                                                                                    preorder($3);
                                                                                    printf("\n");
                                                                                }
            |   GDeclBlock MainBlock                                            {printf("PARSED\n"); $$ = NULL; print_Gsymbol_table(); preorder($2);}
            |   MainBlock                                                       {printf("PARSED\n"); $$ = NULL; print_Gsymbol_table(); preorder($1);}
            ;

GDeclBlock  :   DECL GDeclList ENDDECL                                          {$$ = $2;}
            |   DECL ENDDECL                                                    {$$ = NULL;}
            ;

GDeclList   :   GDeclList GDecl
            |   GDecl
            ;

GDecl       :   Type GidList ';'
            ;

Type        :   INT
            |   STR
            ;

GidList     :   GidList ',' Gid
            |   Gid
            ;

Gid         :   ID '[' NUM ']'                                                  {GInstall($1->varname,$1->type,$3->val,_ARRAY,NULL);}
            |   ID                                                              {GInstall($1->varname,$1->type,1,_VAR,NULL);}
            |   ID '(' ParamList ')'                                            {GInstall($1->varname,$1->type,-1,_FUNCTION,$3);}
            ;

FDefBlock   :   FDefBlock Fdef
            |   Fdef
            ;

Fdef        :   Type ID '(' ParamList ')' '{' LdeclBlock Body '}'               {Function($2,$4,$8);/*codeGen($8)*/;LsymbolHead=NULL;LsymbolTail=NULL;}
            ;

ParamList   :   ParamList ',' Param                                             {$$ = makeParamList($1,$3);}
            |   Param                                                           {$$ = $1;}
            |                                                                   {$$ = NULL;}
            ;

Param       :   Type ID                                                         {$$ = makeArgs($2->varname,$1->type);}
            ;

MainBlock   :   INT MAIN '(' ')' '{' LdeclBlock Body '}'                        {Function($2,NULL,$7);/*codeGen($7)*/;LsymbolHead=NULL;LsymbolTail=NULL;}
            ;

LdeclBlock  :   DECL LDecList ENDDECL                                           {$$ = $2;}
            |   DECL ENDDECL                                                    {$$ = NULL;}
            ;

LDecList    :   LDecList LDecl
            |   LDecl
            ;

LDecl       :   Type IdList ';'
            ;

IdList      :   IdList ',' ID
            |   ID                                                              {LInstall($1->varname,$1->type);}
            ;

Body        :   _BEGIN Slist Retstmt END                                        {$$ = makeconnectorNode($2,$3);}
            ;

Retstmt     :   RETURN E ';'                                                    {$$ = $2;}
            ;

Slist       :   Slist Stmt                                                      {$$ = makeconnectorNode($1,$2);}
            |   Stmt                                                            {$$ = $1;}
            ;

Stmt        :   InputStmt                                                       {$$ = $1;}
            |   OutputStmt                                                      {$$ = $1;}
            |   AsgStmt                                                         {$$ = $1;}
            |   Ifstmt                                                          {$$ = $1;}
            |   Whilestmt                                                       {$$ = $1;}
            |   BrkStmt                                                         {$$ = $1;}
            |   ContStmt                                                        {$$ = $1;}
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

InputStmt   :   READ '(' E ')' ';'                                              {$$ = makeReadNode($3);}
            ;

OutputStmt  :   WRITE '(' E ')' ';'                                             {$$ = makeWriteNode($3);}
            ;

AsgStmt     :   Identifier  '='  E ';'                                          {
                                                                                    if($1->nodetype != _VAR && $1->nodetype != _ARRAY){
                                                                                        yyerror("LHS should be memory location\n");
                                                                                        exit(1);
                                                                                    }
                                                                                    $$ = makeAsgtNode($1,$3);
                                                                                }
            ;

BrkStmt     :   BREAK ';'                                                       {$$ = makeBreakNode();}
            ;

ContStmt    :   CONTINUE ';'                                                    {$$ = makeContinueNode();}
            ;

/* Declarations    :   DECL DecList ENDDECL        {print_Gsymbol_table();}
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

IdList          :   ID '[' NUM ']'
                |   ID
                ; */

E           :   E PLUS E                                                        {$$ = makeOperatorNode(_INT,_PLUS,$1,$3);}
            |   E MINUS E                                                       {$$ = makeOperatorNode(_INT,_MINUS,$1,$3);}
            |   E MUL E                                                         {$$ = makeOperatorNode(_INT,_MUL,$1,$3);}
            |   E DIV E                                                         {$$ = makeOperatorNode(_INT,_DIV,$1,$3);}
            |   E MOD E                                                         {$$ = makeOperatorNode(_INT,_MOD,$1,$3);}
            |   E GT E                                                          {$$ = makeOperatorNode(_BOOL,_GT,$1,$3);}
            |   E LT E                                                          {$$ = makeOperatorNode(_BOOL,_LT,$1,$3);}
            |   E GE E                                                          {$$ = makeOperatorNode(_BOOL,_GE,$1,$3);}
            |   E LE E                                                          {$$ = makeOperatorNode(_BOOL,_LE,$1,$3);}
            |   E NE E                                                          {$$ = makeOperatorNode(_BOOL,_NE,$1,$3);}
            |   E EQ E                                                          {$$ = makeOperatorNode(_BOOL,_EQ,$1,$3);}
            |   '(' E ')'                                                       {$$ = $2;}
            |   NUM                                                             {$$ = $1;}
            |   STRING                                                          {$$ = $1;}
            |   Identifier                                                      {$$ = $1;}
            ;

Identifier  :  ID '[' E ']'                                                     {checkTypeMismatchVar($1,_ARRAY); $$ = makeArrayLeafNode($1,$3);}
            |  ID                                                               {checkTypeMismatchVar($1,_VAR); $$ = $1;}
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
    FILE *fp;
    fp = fopen("xsm1.xsm","w");
    //Header of xsm FILE
    //XEXE file format
    fprintf(fp, "0\n");
    //entry point
    fprintf(fp, "main\n");
    for(int i=0;i<6;i++) fprintf(fp, "0\n");
    fprintf(fp, "MOV SP, %d\n",addrs);

    yyparse();

    fprintf(fp ,"INT 10");
    fclose(fp);
    return 0;
}
