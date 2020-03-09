%{
  #include "ast.h"
  #include "ast.c"
  int yylex(void);

  FILE * yyin;
%}

%union{
  struct astnode *node;
  struct Paramstruct *node2;
  struct Fieldlist *node3;
  struct Typetable *node4;
};

%type <node4> TypeDefBlock TypeDefList TypeDef
%type <node3> FieldDeclList FieldDecl
%type <node2> Param ParamList
%type <node> program GDeclBlock GDeclList GDecl Type INT STR GidList Gid FDefBlock Fdef MainBlock MAIN LdeclBlock LDecList LDecl IdList Body Retstmt Slist Stmt Whilestmt Ifstmt InputStmt READ OutputStmt WRITE AsgStmt BrkStmt ContStmt E NUM STRING ID Identifier ArgList
%type <node> Field
%token _BEGIN END READ WRITE PLUS MINUS MUL DIV MOD NUM ID NEWLINE IF THEN ELSE ENDIF GT LT GE LE NE EQ WHILE DO ENDWHILE BREAK CONTINUE DECL ENDDECL INT STR IDD STRING MAIN RETURN
%token  _TYPE ENDTYPE ALLOC FREE INITIALIZE __NULL
%left GT LT GE LE NE EQ
%left PLUS MINUS
%left MUL DIV MOD

%start program

%%

program     :   TypeDefBlock GDeclBlock FDefBlock MainBlock                     {printf("PARSED\n");}
            |   TypeDefBlock GDeclBlock MainBlock                               {printf("PARSED\n");}
            ;

TypeDefBlock:   _TYPE TypeDefList ENDTYPE                                       {print_type_table();}
            |                                                                   {}
            ;

TypeDefList :   TypeDefList TypeDef
            |   TypeDef
            ;

TypeDef     :   ID '{' FieldDeclList '}'                                        {$$ = TInstall($1->varname,0,$3);}
            ;

FieldDeclList:  FieldDeclList FieldDecl                                         {$$ = makeFieldlist($1,$2);}
            |   FieldDecl                                                       {$$ = makeFieldlist(NULL,$1);}
            ;

FieldDecl   :   Type ID ';'                                                     {$$ = makeFieldlistNode($2->varname,TYPE,typeinfo);TypeStackPop();}
            ;

Type        :   INT                                                             {TYPE = TypeStackPush(TLookup("int"));}
            |   STR                                                             {TYPE = TypeStackPush(TLookup("str"));}
            |   ID                                                              {
                                                                                    if(TLookup($1->varname) == NULL){
                                                                                        if(typeflag==0){
                                                                                            yyerror("Undeclared user-defined type\n");
                                                                                            exit(1);
                                                                                        }
                                                                                        else{
                                                                                            TYPE = TypeStackPush(NULL);
                                                                                            typeinfo = strdup($1->varname);
                                                                                        }

                                                                                    }
                                                                                    else TYPE = TypeStackPush(TLookup($1->varname));
                                                                                }
            ;

GDeclBlock  :   DECL GDeclList ENDDECL                                          {print_Gsymbol_table();global_declaration_code();}
            |                                                                   {global_declaration_code();}
            ;

GDeclList   :   GDeclList GDecl
            |   GDecl
            ;

GDecl       :   Type GidList ';'                                                {TypeStackPop();}
            ;

GidList     :   GidList ',' Gid
            |   Gid
            ;

Gid         :   ID '[' NUM ']'                                                  {
                                                                                    if(!(TYPE == TLookup("int") || TYPE == TLookup("str"))){
                                                                                        yyerror("Invalid arraytype\n");
                                                                                        exit(1);
                                                                                    }
                                                                                    GInstall($1->varname,TYPE,$3->val,_ARRAY,NULL);
                                                                                }
            |   ID                                                              {GInstall($1->varname,TYPE,1,_VAR,NULL);}
            |   ID '(' ParamList ')'                                            {GInstall($1->varname,TYPE,-1,_FUNCTION,$3);ParamHead=NULL;}
            ;

FDefBlock   :   FDefBlock Fdef
            |   Fdef
            ;

Fdef        :   Type ID '(' ParamList ')' '{' LdeclBlock Body '}'               {p();Function($2,$4,$8);preorder($8);printf("\n");/*gen_function_code($2,$8)*/;LsymbolHead=NULL;LsymbolTail=NULL;ParamHead=NULL;TypeStackPop();}
            ;


ParamList   :   ParamList ',' Param                                             {$$ = makeParamList($1,$3);ParamHead=$$;}
            |   Param                                                           {$$ = $1;ParamHead=$$;}
            |                                                                   {$$ = NULL;ParamHead=$$;}
            ;

Param       :   Type ID                                                         {$$ = makeParameter($2->varname,TYPE);TypeStackPop();}
            ;

MainBlock   :   INT MAIN '(' ')' '{' LdeclBlock Body '}'                        {p();Function($2,NULL,$7);preorder($7);printf("\n");/*gen_function_code($2,$7)*/;LsymbolHead=NULL;LsymbolTail=NULL;ParamHead=NULL;}
            ;

LdeclBlock  :   DECL LDecList ENDDECL                                           {$$ = $2; InstallParameter();}
            |   DECL ENDDECL                                                    {$$ = NULL;InstallParameter();}
            |                                                                   {$$ = NULL;InstallParameter();}
            ;

LDecList    :   LDecList LDecl
            |   LDecl
            ;

LDecl       :   Type IdList ';'                                                 {TypeStackPop();}
            ;

IdList      :   IdList ',' ID                                                   {LInstall($3->varname,TYPE);}
            |   ID                                                              {LInstall($1->varname,TYPE);}
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

Whilestmt   :   WHILE '(' E ')' DO Slist ENDWHILE ';'                           {$$ = makeLoopNode($3,$6);}
            ;

Ifstmt      :   IF '(' E ')' THEN Slist ELSE Slist ENDIF ';'                    {$$ = makeCondNode($3,$6,$8);}
            |   IF '(' E ')' THEN Slist ENDIF ';'                               {$$ = makeCondNode($3,$6,NULL);}
            ;

InputStmt   :   READ '(' Identifier ')' ';'                                     {$$ = makeReadNode($3);}
            ;

OutputStmt  :   WRITE '(' E ')' ';'                                             {$$ = makeWriteNode($3);}
            ;

AsgStmt     :   Identifier '=' E ';'                                            {$$ = makeAsgtNode($1,$3);}
            |   Identifier '=' ALLOC '(' ')' ';'                                {$$ = makeAllocNode($1);}
            |   Identifier '=' FREE '(' Identifier ')' ';'                      {$$ = makeFreeNode($1,$5);}
            |   Identifier '=' INITIALIZE '(' ')' ';'                           {$$ = makeInitializeNode($1);}
            |   Identifier '=' __NULL ';'                                       {$$ = makeAsgtNode($1,GNULL);}
            ;

BrkStmt     :   BREAK ';'                                                       {$$ = makeBreakNode();}
            ;

ContStmt    :   CONTINUE ';'                                                    {$$ = makeContinueNode();}
            ;

Field       :   Field '.' ID                                                    {$$ = makeDotNode($1,$3);}
            |   ID '.' ID                                                       {$$ = makeDotNode($1,$3);}
            ;

ArgList         :   ArgList ',' E                                               {$$ = makeArgList($1,$3);}
                |   E                                                           {$$ = makeArgList(NULL,$1);}
                ;

E           :   E PLUS E                                                        {$$ = makeOperatorNode(TLookup("int"),_PLUS,$1,$3);}
            |   E MINUS E                                                       {$$ = makeOperatorNode(TLookup("int"),_MINUS,$1,$3);}
            |   E MUL E                                                         {$$ = makeOperatorNode(TLookup("int"),_MUL,$1,$3);}
            |   E DIV E                                                         {$$ = makeOperatorNode(TLookup("int"),_DIV,$1,$3);}
            |   E MOD E                                                         {$$ = makeOperatorNode(TLookup("int"),_MOD,$1,$3);}
            |   E GT E                                                          {$$ = makeOperatorNode(TLookup("bool"),_GT,$1,$3);}
            |   E LT E                                                          {$$ = makeOperatorNode(TLookup("bool"),_LT,$1,$3);}
            |   E GE E                                                          {$$ = makeOperatorNode(TLookup("bool"),_GE,$1,$3);}
            |   E LE E                                                          {$$ = makeOperatorNode(TLookup("bool"),_LE,$1,$3);}
            |   E NE E                                                          {$$ = makeOperatorNode(TLookup("bool"),_NE,$1,$3);}
            |   E EQ E                                                          {$$ = makeOperatorNode(TLookup("bool"),_EQ,$1,$3);}
            |   E NE __NULL                                            {$$ = makeOperatorNode(TLookup("bool"),_NE,$1,GNULL);}/*giving shift/reduce conflict
            |   __NULL NE E                                            {$$ = makeOperatorNode(TLookup("bool"),_NE,GNULL,$3);}*/
            |   E EQ __NULL                                            {$$ = makeOperatorNode(TLookup("bool"),_EQ,$1,GNULL);}/*giving shift/reduce conflict
            |   __NULL EQ E                                          {$$ = makeOperatorNode(TLookup("bool"),_EQ,GNULL,$3);}*/
            |   '(' E ')'                                                       {$$ = $2;}
            |   NUM                                                             {$$ = $1;}
            |   STRING                                                          {$$ = $1;}
            |   Identifier                                                      {$$ = $1;}
            |   ID '(' ')'                                                      {$$ = makeFunctionNode($1,NULL);}
            |   ID '(' ArgList ')'                                              {$$ = makeFunctionNode($1,$3);}
            ;

Identifier  :  ID '[' E ']'                                                     {$$ = makeArrayLeafNode($1,$3);}
            |  ID                                                               {$$ = updateVarLeafNode($1);}
            |   Field                                                           {$$ = $1;}
            ;


%%

void yyerror(const char *s){
    printf("yyerror %s",s);
}

int main(int argc, char *argv[]){
    if (argc > 1){
        fp = fopen(argv[1], "r");
        if(fp) yyin = fp;
    }

    flabel=-1;
    global_var_addrs_limit=4095;
    regCount=-1;
    labelCount=-1;
    nested_while=-1;
    GsymbolHead=NULL;


    //Initialize type table
    TypeTableCreate();

    GNULL = makeNullNode();

    GInstall("main",TLookup("int"),-1,_FUNCTION,NULL);

    fp = fopen("xsm1.xsm","w");
    //Header of xsm FILE
    //XEXE file format
    fprintf(fp, "0\n");
    //entry point
    fprintf(fp, "2056\n");
    for(int i=0;i<6;i++) fprintf(fp, "0\n");
    //fprintf(fp, "MOV SP, %d\n",addrs);

    TopTypeStack = -1;

    yyparse();

    fprintf(fp ,"INT 10");
    fclose(fp);
    return 0;
}
