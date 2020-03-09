
Typetable * TypeStackPush(Typetable * type){
    // printf("push\n");
    TypeStack[++TopTypeStack] = type;
    return type;
}

void TypeStackPop(){
    // printf("pop\n");
    --TopTypeStack;
    if(TopTypeStack > -1) TYPE = TypeStack[TopTypeStack];
}

Fieldlist * makeNewFieldlistNode(){
    Fieldlist * temp = (Fieldlist *)malloc(sizeof(struct Fieldlist));
    temp->name = NULL;
    temp->type = NULL;
    temp->typeinfo = NULL;
    temp->next = NULL;
    return temp;
}

Fieldlist * makeFieldlistNode(char * name,Typetable * type,char * typeinfo){
    Fieldlist * temp = makeNewFieldlistNode();
    temp->name = strdup(name);
    temp->type = type;
    if(type == NULL) temp->typeinfo = typeinfo;
    return temp;
}

Fieldlist * makeFieldlist(Fieldlist * fieldlist,Fieldlist * field){
    Fieldlist * temp = fieldlist;
    if(temp == NULL){
        return field;
    }
    else{
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = field;
    }
    return fieldlist;
}

Fieldlist * FLookup(Typetable * type,char * name){
    Fieldlist * temp = type->fields;
    while(temp != NULL){
        if(strcmp(temp->name,name) == 0) return temp;
        temp = temp->next;
    }
    return NULL;
}

Typetable * makeNewTypeTableNode(){
    Typetable * temp = (Typetable *)malloc(sizeof(struct Typetable));
    temp->name = NULL;
    temp->fields = NULL;
    temp->next = NULL;
    return temp;
}

Typetable * TLookup(char * name){
    Typetable * temp = TypetableHead;
    while(temp != NULL){
        if(strcmp(temp->name,name)==0) return temp;
        temp = temp->next;
    }
    return NULL;
}

Typetable * TInstall(char *name,int size,Fieldlist * fields){
    Typetable * temp = TLookup(name);
    if(temp == NULL){
        temp = makeNewTypeTableNode();
        temp->name = strdup(name);
        temp->size = size;
        temp->fields = fields;
        if(TypetableHead == NULL){
            TypetableHead = TypetableTail = temp;
        }
        else{
            TypetableTail->next = temp;
            TypetableTail = temp;
        }
        int fieldindex=1;
        Fieldlist * temp1 = fields;
        Fieldlist * temp2;
        while(temp1 != NULL){
            //checking for redeclaration
            temp2 = fields;
            while(temp2 != temp1){
                if(strcmp(temp2->name,temp1->name)==0){
                    yyerror("Multiple declaration of fields.\n");
                    exit(1);
                }
                temp2 = temp2->next;
            }
            if(temp1->type == NULL){
                if(strcmp(temp1->typeinfo,name)==0){
                    temp1->type = temp;
                }
                else{
                    yyerror("Undefined type\n");
                    exit(1);
                }
            }
            temp1->fieldindex = fieldindex;
            fieldindex++;
            temp1 = temp1->next;
        }
    }
    else{
        yyerror("Multiple Declaration\n");
        exit(1);
    }
    return temp;
}

void TypeTableCreate(){
    Typetable * temp = TInstall("int",1,NULL);
    temp = TInstall("str",1,NULL);
    temp = TInstall("bool",1,NULL);
    temp = TInstall("void",0,NULL);
}

struct Lsymbol *makeNewLsymbol(){
    struct Lsymbol * temp = (struct Lsymbol*)malloc(sizeof(struct Lsymbol));
    temp->name = NULL;
    temp->type = NULL;
    temp->next = NULL;
    return temp;
}

struct Lsymbol *makeLsymbolNode(char *name,Typetable * type){
    struct Lsymbol *temp = makeNewLsymbol();
    temp->name = strdup(name);
    temp->type = type;
    return temp;
}

struct Lsymbol *LLookup(char *name){
// Returns a pointer to the symbol table entry for the variable, returns NULL otherwise.
    struct Lsymbol* temp = LsymbolHead;
    while(temp != NULL){
        if(strcmp(temp->name, name) == 0) return temp;
        temp = temp->next;
    }
    return NULL;
}

struct Lsymbol * LInstall(char *name,Typetable * type){
    if(LLookup(name) == NULL){
        struct Lsymbol* temp = makeLsymbolNode(name,type);
        if(LsymbolHead == NULL){
            LsymbolHead = LsymbolTail = temp;
        }
        else{
            LsymbolTail->next = temp;
            LsymbolTail = temp;
        }
    }
    else{
        yyerror("Multiple declarations\n");
        exit(1);
    }
}

struct Gsymbol *makeGSymbolNode(char *name, Typetable * type, int size,int class,struct Paramstruct *paramlist){
    struct Gsymbol* temp = (struct Gsymbol*)malloc(sizeof(struct Gsymbol));
    temp->name = strdup(name);
    temp->type = type;
    temp->class = class;
    temp->size = size;
    if(class == _FUNCTION){
        if(strcmp(name,"main")==0) temp->flabel = -1;
        else temp->flabel = ++flabel;
    }
    temp->paramlist = paramlist;
    temp->next = NULL;
    return temp;
}

struct Gsymbol *GLookup(char* name){
// Returns a pointer to the symbol table entry for the variable, returns NULL otherwise.
    struct Gsymbol* temp = GsymbolHead;

    while(temp != NULL){
        if(strcmp(temp->name, name) == 0) return temp;
        temp = temp->next;
    }

    return NULL;
}

void GInstall(char *name, Typetable * type, int size,int class,struct Paramstruct *paramlist){
// Creates a symbol table entry.
    if(GLookup(name) == NULL){
        struct Gsymbol* temp = makeGSymbolNode(name,type,size,class,paramlist);
        if(GsymbolHead == NULL){
            GsymbolHead = GsymbolTail = temp;
        }
        else{
            GsymbolTail->next = temp;
            GsymbolTail = temp;
        }
    }
    else{
        yyerror("Multiple declarations\n");
        exit(1);
    }
}

struct astnode *makeNewastnode(){
    struct astnode *temp = (struct astnode *)malloc(sizeof(struct astnode));
    temp->str = NULL;
    temp->type = TLookup("void");
    temp->varname = NULL;
    temp->Gentry = NULL;
    temp->paramlist = NULL;
    temp->arglist = NULL;
    temp->Lentry = NULL;
    temp->left = temp->right = NULL;
    return temp;
}

struct astnode* makeConstIntLeafNode(int val){
    struct astnode* temp = makeNewastnode();
    temp->val = val;
    temp->type = TLookup("int");
    temp->nodetype = _CONST;
    return temp;
}

struct astnode* makeConstStringLeafNode(char *c){
    struct astnode* temp = makeNewastnode();
    temp->str = strdup(c);
    temp->type = TLookup("str");
    temp->nodetype = _CONST;
    return temp;
}

struct astnode* makeVarLeafNode(char *c){
    struct astnode* temp = makeNewastnode();
    temp->varname = strdup(c);
    temp->type = TLookup("void");
    temp->nodetype = _VAR;
    return temp;
}

struct astnode* updateVarLeafNode(struct astnode* id){
    struct Lsymbol* Lentry = LLookup(id->varname);
    struct Gsymbol* Gentry = GLookup(id->varname);
    if(Lentry == NULL && Gentry == NULL){
        yyerror("Undeclared variable\n");
        exit(1);
    }
    //since in local declaration only simple variables
    //are allowed, we needn't check it's nodetype
    //bcz it will be var only in the local declaration
    if(Lentry != NULL) id->type = Lentry->type;
    else{
        //we need to check whether this var if declared
        //globally is of nodetype/class var
        if(id->nodetype != Gentry->class){
            yyerror("Undeclared variable\n");
            exit(1);
        }
        id->type = Gentry->type;
    }
    id->Gentry = Gentry;
    id->Lentry = Lentry;
    return id;
}

struct astnode* makeArrayLeafNode(struct astnode* id,struct astnode* index){
    struct Gsymbol* Gentry = GLookup(id->varname);
    if(Gentry == NULL){
        yyerror("Undeclared Variable\n");
        exit(1);
    }
    //we need to check whether
    //there is a entry under this
    //variable name as ARRAY
    if(Gentry->class != _ARRAY){
        yyerror("Undeclared Variable\n");
        exit(1);
    }
    //index type can only be Integer
    //but it can be any expression
    if(index->type != TLookup("int")){
        yyerror("Type error\n");
        exit(1);
    }

    id->type = Gentry->type;
    id->nodetype = _ARRAY;

    struct astnode* temp = makeNewastnode();
    temp->varname = NULL;
    temp->type = id->type;
    temp->nodetype = _ARRAY;
    temp->left = id;
    temp->right = index;
    return temp;
}

astnode * makeDotNode(astnode * l,astnode * r){
    if(l->nodetype != _DOT){
        l = updateVarLeafNode(l);
    }
    //check right part of dot node
    Fieldlist * temp1 = FLookup(l->type,r->varname);
    if(temp1 == NULL){
        yyerror("Undeclared field type\n");
        exit(1);
    }
    r->type = temp1->type;
    r->nodetype = _FIELD;

    astnode * temp = makeNewastnode();
    temp->nodetype = _DOT;
    temp->type = r->type;
    temp->left = l;
    temp->right = r;
    return temp;
}

struct astnode* makeOperatorNode(Typetable * type, int nodetype, struct astnode* l, struct astnode* r){
    struct astnode* temp = makeNewastnode();
    temp->type = type;
    temp->nodetype = nodetype;
    temp->left = l;
    temp->right = r;
    checkTypeMismatch(temp);
    return temp;
}

astnode * makeAllocNode(astnode * l){
    if(l->nodetype != _VAR && l->nodetype != _DOT){
        yyerror("Alloc cannot be to array\n");
        exit(1);
    }
    if(l->type == TLookup("int") || l->type == TLookup("str")){
        yyerror("Alloc can't be used with primitive datatype\n");
        exit(1);
    }
    astnode * temp = makeNewastnode();
    temp->nodetype = _ALLOC;
    temp->left = l;
    return temp;
}

astnode * makeFreeNode(astnode * l, astnode * r){
    if(l->type != TLookup("int")){
        yyerror("Free return var should be int\n");
        exit(1);
    }
    if(r->nodetype != _VAR && r->nodetype != _DOT){
        yyerror("Free cannot be to array\n");
        exit(1);
    }
    if(r->type == TLookup("int") || r->type == TLookup("str")){
        yyerror("Free can't be used with primitive datatype\n");
        exit(1);
    }
    astnode * temp = makeNewastnode();
    temp->nodetype = _FREE;
    temp->left = l;
    temp->right = r;
    return temp;
}

astnode * makeInitializeNode(astnode * l){
    if(l->type != TLookup("int")){
        yyerror("Initialize return var should be int\n");
        exit(1);
    }
    astnode * temp = makeNewastnode();
    temp->nodetype = _INITIALIZE;
    temp->left = l;
    return temp;
}

astnode * makeNullNode(){
    astnode * temp = makeNewastnode();
    temp->nodetype = _NULL;
    return temp;
}

struct astnode* makeAsgtNode(struct astnode* l, struct astnode* r){
    if(l->nodetype != _VAR && l->nodetype != _ARRAY && l->nodetype != _DOT){
        yyerror("LHS should be memory location\n");
        exit(1);
    }
    if(r->type == TLookup("bool")){
        yyerror("can't assign bool\n");
        exit(1);
    }
    struct astnode* temp = makeNewastnode();
    temp->type = l->type;
    temp->nodetype = _ASGT;
    temp->left = l;
    temp->right = r;
    checkTypeMismatch(temp);
    return temp;
}

struct astnode* makeReadNode(struct astnode* l){
    struct astnode* temp = makeNewastnode();
    temp->nodetype = _READ;
    temp->left = l;
    return temp;
}

struct astnode* makeWriteNode(struct astnode* l){
    if(l->type == TLookup("bool")){
        yyerror("cannot write bool\n");
        exit(1);
    }
    struct astnode* temp = makeNewastnode();
    temp->nodetype = _WRITE;
    temp->left = l;
    return temp;
}

struct astnode* makeconnectorNode(struct astnode* l, struct astnode* r){
    struct astnode* temp = makeNewastnode();
    temp->nodetype = _CNT;
    temp->left = l;
    temp->right = r;
    return temp;
}

struct astnode* makeCondNode(struct astnode* cond, struct astnode* true_stmt, struct astnode* false_stmt){
    if(cond->type != TLookup("bool")){
        yyerror("Type Mismatch(cond)\n");
        exit(1);
    }
    struct astnode * temp = makeNewastnode();
    temp->nodetype = _IF;
    temp->left = cond;

    struct astnode* temp2 = makeNewastnode();
    temp2->nodetype = _IFBODY;
    temp2->left = true_stmt;
    temp2->right = false_stmt;

    temp->right = temp2;

    return temp;
}

struct astnode* makeLoopNode(struct astnode* cond, struct astnode* while_body){
    if(cond->type != TLookup("bool")){
        yyerror("Type Mismatch(loop)\n");
        exit(1);
    }
    struct astnode * temp = makeNewastnode();
    temp->nodetype = _WHILE;
    temp->left = cond;
    temp->right = while_body;
    return temp;
}

struct astnode* makeBreakNode(){
    struct astnode* temp = makeNewastnode();
    temp->nodetype = _BREAK;
    return temp;
}

struct astnode* makeContinueNode(){
    struct astnode* temp = makeNewastnode();
    temp->nodetype = _CONTINUE;
    return temp;
}

struct Paramstruct *makeParameter(char *name,Typetable * type){
    struct Paramstruct *temp = (struct Paramstruct*)malloc(sizeof(struct Paramstruct));
    temp->name = strdup(name);
    temp->type = type;
    temp->next = NULL;
    return temp;
}

struct Paramstruct *makeParamList(struct Paramstruct *head,struct Paramstruct *newParam){
    struct Paramstruct *temp = head;
    while(temp->next != NULL){printf("qwer\n");
        temp = temp->next;
    }
    temp->next = newParam;
    //ParamHead = head;
    return head;
}

void InstallParameter(){
    struct Paramstruct *temp = ParamHead;
    struct Lsymbol *temp2;
    int i=-3;
    while(temp != NULL){
        // printf("%s\n", temp->name);
        temp2 = LInstall(temp->name,temp->type);
        temp2->binding = i--;
        temp = temp->next;
    }
}

void Function(struct astnode *head,struct Paramstruct *paramlist,struct astnode *body){
    if(strcmp(head->varname,"main") != 0) head->type = TYPE;
    struct Gsymbol *Gentry = GLookup(head->varname);
    if(Gentry == NULL){
        yyerror("Undeclared Function\n");
        exit(1);
    }
    if(Gentry->type != head->type){
        // printf("%s %s\n",head->varname,head->type->name);
        yyerror("Function def does not match declaration\n");
        exit(1);
    }

    int i=1;
    struct Lsymbol *temp = LsymbolHead;
    while(temp != NULL){
        if(temp->binding > -1) temp->binding = i++;
        temp = temp->next;
    }

    struct Paramstruct *paramhead = Gentry->paramlist;
    while(paramhead != NULL){
        if(paramlist == NULL || paramhead->type != paramlist->type || strcmp(paramhead->name,paramlist->name) != 0){
            yyerror("Function def does not match declaration\n");
            exit(1);
        }
        paramlist = paramlist->next;
        paramhead = paramhead->next;
    }
    if(paramlist != NULL){
        yyerror("Function def does not match declaration\n");
        exit(1);
    }

    if(Gentry->type != body->right->type){
        yyerror("Return type does not match declaration\n");
        exit(1);
    }

    head->nodetype = _FUNCTION;
    head->Gentry = Gentry;
    Gentry->Lsymbollist = LsymbolHead;
}

struct astnode * makeArgList(struct astnode * head,struct astnode *arg){
    struct astnode * temp = head;
    if(head == NULL){
        head = arg;
    }
    else{
        while(temp->arglist != NULL){
            temp = temp->arglist;
        }
        temp->arglist = arg;
    }
    return head;
}

struct astnode * makeFunctionNode(struct astnode *name, struct astnode *arglist){
    struct Gsymbol *Gentry = GLookup(name->varname);
    if(Gentry == NULL){
        yyerror("Use of undeclared function");
        exit(1);
    }
    //check if declared as a function globally
    if(Gentry->class != _FUNCTION){
        yyerror("Use of undeclared function");
        exit(1);
    }

    struct Paramstruct *temp = Gentry->paramlist;
    struct astnode *arg = arglist;
    while(temp != NULL && arg != NULL){

        if(temp->type != arg->type){
            yyerror("Argument type doesn't match\n");
            exit(1);
        }
        temp = temp->next;
        arg = arg->arglist;
    }
    if((temp != NULL && arg == NULL) || (temp == NULL && arg != NULL)){
        yyerror("Argument list doesn't match as defined\n");
        exit(1);
    }

    name->type = Gentry->type;
    name->Gentry = Gentry;
    name->nodetype = _FUNCTION;
    name->left = arglist;
    return name;
}

void checkTypeMismatch(struct astnode* root){
    if(root->nodetype == _ASGT){
        if(root->right->nodetype == _NULL){
            if(root->left->type == TLookup("int") || root->left->type == TLookup("str")){
                yyerror("NULL can only be assigned to user-define\n");
                exit(1);
            }
        }
        else if(root->left->type != root->right->type){
            yyerror("1Type Mismatch\n");
            exit(1);
        }
    }
    else if(root->nodetype == _PLUS || root->nodetype == _MINUS || root->nodetype == _MUL || root->nodetype == _DIV || root->nodetype == _MOD){
        //only integer arithmetic allowed
        if(!(root->left->type == TLookup("int") && root->right->type == TLookup("int"))){
            yyerror("2Type Mismatch\n");
            exit(1);
        }
    }
    else if(root->nodetype == _EQ || root->nodetype == _NE){
        if(root->left->nodetype == _NULL){
            if(root->right->type == TLookup("int") || root->right->type == TLookup("str")){
                yyerror("NULL can only be compared with user-defined\n");
                exit(1);
            }
        }
        else if(root->right->nodetype == _NULL){
            if(root->left->type == TLookup("int") || root->left->type == TLookup("str")){
                yyerror("NULL can only be compared with user-defined\n");
                exit(1);
            }
        }
        else if(root->left->type != root->right->type){
            yyerror("3Type Mismatch\n");
            exit(1);
        }
    }
    else{
        if((root->left->type != root->right->type) || (root->left->type != TLookup("int") && root->left->type != TLookup("str"))){
            yyerror("4Type Mismatch\n");
            exit(1);
        }
    }
}

int getReg(){
    printf("R%d\n",regCount+1);
    if(regCount > 19) printf("Register overuse\n");
    return ++regCount;
}

void freeReg(){
    printf("FREE R%d\n",regCount);
    regCount--;
    if(regCount < -1) printf("FREE < %d\n",regCount);
}

int getLabel(){
    return ++labelCount;
}

void print(FILE *fp,int reg1){
  int reg2 = getReg();
  for (int i=0;i<reg2;i++)
    fprintf(fp, "PUSH R%d\n", i);
  fprintf(fp, "MOV R%d,\"Write\"\n", reg2);
  fprintf(fp, "PUSH R%d\n", reg2);
  fprintf(fp, "MOV R%d,-2\n", reg2);
  fprintf(fp, "PUSH R%d\n", reg2);
  fprintf(fp, "PUSH R%d\n", reg1);
  fprintf(fp, "PUSH R%d\n", reg2);
  fprintf(fp, "PUSH R%d\n", reg2);
  fprintf(fp, "CALL 0\n");
  fprintf(fp, "POP R%d\n", reg2);
  fprintf(fp, "POP R%d\n", reg2);
  fprintf(fp, "POP R%d\n", reg2);
  fprintf(fp, "POP R%d\n", reg2);
  fprintf(fp, "POP R%d\n", reg2);
  for (int i=reg2-1;i>=0;i--)
    fprintf(fp, "POP R%d\n", i);
  freeReg();
}

void reading(FILE *fp,int arg2){
    int reg2 = getReg();
    for (int i=0;i<reg2;i++)
      fprintf(fp, "PUSH R%d\n", i);
    fprintf(fp, "MOV R%d,\"Read\"\n", reg2);
    fprintf(fp, "PUSH R%d\n", reg2);
    fprintf(fp, "MOV R%d,-1\n", reg2);
    fprintf(fp, "PUSH R%d\n", reg2);
    fprintf(fp, "PUSH R%d\n", arg2);
    fprintf(fp, "PUSH R%d\n", reg2);
    fprintf(fp, "PUSH R%d\n", reg2);
    fprintf(fp, "CALL 0\n");
    fprintf(fp, "POP R%d\n", reg2);
    fprintf(fp, "POP R%d\n", reg2);
    fprintf(fp, "POP R%d\n", reg2);
    fprintf(fp, "POP R%d\n", reg2);
    fprintf(fp, "POP R%d\n", reg2);
    for (int i=reg2-1;i>=0;i--)
      fprintf(fp, "POP R%d\n", i);
    freeReg();
}

void checkTypeMismatchVar(struct astnode* root, int var_type){
    struct Lsymbol *entry = LLookup(root->varname);
    struct Gsymbol* Gentry = GLookup(root->varname);
    if(entry == NULL){
        if(Gentry->class != var_type){
            yyerror("Type error\n");
            exit(1);
        }
    }
}



int evaluate_argument(FILE *fp,struct astnode *arg){

    if(arg == NULL) return 0;
    printf("+++++++++++\n");
    int count_arg = evaluate_argument(fp,arg->arglist);
    int reg = codeGen(arg,fp);
    if(arg->nodetype == _VAR || arg->nodetype == _ARRAY){
        fprintf(fp, "MOV R%d, [R%d]\n",reg,reg);
    }
    fprintf(fp, "PUSH R%d\n", reg);
    freeReg();
    printf("-----------\n");
    return count_arg+1;
}

int codeGen(struct astnode* root,FILE *fp){
    //if(root == NULL) printf("dfwrfrferfgrtgregtrgr\n");
    printf("@@@@@@%d\n", root->nodetype);
  if(root->nodetype == _CONST || root->nodetype == _VAR || root->nodetype == _ARRAY){
      int reg = getReg();
      if(root->nodetype == _CONST){
          printf("deew%d\n",reg);
          if(root->type == TLookup("int")){
              fprintf(fp, "MOV R%d, %d\n", reg,root->val);
          }
          else{
              fprintf(fp, "MOV R%d, %s\n", reg,root->str);
          }
      }
      else if(root->nodetype == _ARRAY){
          int index = codeGen(root->right,fp);
          if(root->right->nodetype == _VAR){
              fprintf(fp, "MOV R%d,[R%d]\n", index,index);
          }
          struct Gsymbol* Gentry = GLookup(root->left->varname);

          int baseaddrs = Gentry->binding;
          fprintf(fp, "MOV R%d, %d\n", reg,baseaddrs);
          fprintf(fp, "ADD R%d, R%d\n", reg,index);
          freeReg();
      }
      else{
          struct Lsymbol *temp = LLookup(root->varname);
          if(temp != NULL){
              fprintf(fp, "MOV R%d, BP\n",reg);
              fprintf(fp, "ADD R%d, %d\n",reg,temp->binding );
          }
          else{
              struct Gsymbol *temp1 = GLookup(root->varname);
              fprintf(fp, "MOV R%d, %d\n", reg,temp1->binding);
          }
      }
      printf("$$$$$%d\n",root->nodetype );
      return reg;
  }
  else if(root->nodetype == _FUNCTION){
      //push the registers in use
      for(int i=0;i<=regCount;i++){
          fprintf(fp, "PUSH R%d\n", i);
      }

      //evaluate arguments and push it onto the stack in reverse manner
      int count_arg=0;
      //struct astnode *arg = root->left;
      count_arg = evaluate_argument(fp,root->left);

      //push empty space for return value
      fprintf(fp, "PUSH R0\n");

      //call the function
      fprintf(fp, "CALL F%d\n", GLookup(root->varname)->flabel);

      int ret = getReg();
      //save return value
      fprintf(fp, "POP R%d\n",ret);

      //pop all the arguments from stack
      int reg = getReg();
      for(int i=0;i<count_arg;i++){
          fprintf(fp, "POP R%d\n", reg);
      }
      freeReg();

      //restore registers
      for(int i=regCount-1;i>=0;i--){
          fprintf(fp, "POP R%d\n", i);
      }
printf("$$$$$%d\n",root->nodetype );
      return ret;
  }
  else if(root->nodetype == _WHILE){
      int label1 = getLabel();
      int label2 = getLabel();

      nested_while++;
      label_jmp[nested_while][0] = label1;
      label_jmp[nested_while][1] = label2;

      fprintf(fp, "L%d:\n", label1);

      int l = codeGen(root->left,fp);
      fprintf(fp, "JZ R%d, L%d\n", l,label2);

      int r = codeGen(root->right,fp);

      fprintf(fp, "JMP L%d\n", label1);
      fprintf(fp, "L%d:\n", label2);

      nested_while--;

      freeReg();
      printf("$$$$$%d\n",root->nodetype );
      return l;
  }
  else if(root->nodetype == _IF){
      int label1 = getLabel();
      int label2 = getLabel();

      int l = codeGen(root->left,fp);
      fprintf(fp, "JZ R%d, L%d\n", l,label1);
      printf("wqdwqdwqdq%d\n",l );
      int r = codeGen(root->right->left,fp);
      fprintf(fp, "JMP L%d\n", label2);
      fprintf(fp, "L%d:\n", label1);
      freeReg();

      if(root->right->right != NULL){
          r = codeGen(root->right->right,fp);
          freeReg();
      }
      fprintf(fp, "L%d:\n", label2);
      printf("$$$$$%d\n",root->nodetype );
      return l;
  }
  else if(root->nodetype == _BREAK){
      if(nested_while>=0){
        fprintf(fp, "JMP L%d\n", label_jmp[nested_while][1]);
      }
      printf("$$$$$%d\n",root->nodetype );
      return -1;
  }
  else if(root->nodetype == _CONTINUE){
      if(nested_while>=0){
        fprintf(fp, "JMP L%d\n", label_jmp[nested_while][0]);
      }
      printf("$$$$$%d\n",root->nodetype );
      return -1;
  }
  else{
    int l = codeGen(root->left,fp);
    int r;
    if(root->nodetype == _CNT) printf("dwdfdf\n" );
    if(root->nodetype != _READ && root->nodetype != _WRITE){

        r = codeGen(root->right,fp);
    }
    switch (root->nodetype){
        case _PLUS  :
                    if(root->right->nodetype == _VAR || root->right->nodetype == _ARRAY){
                        fprintf(fp, "MOV R%d, [R%d]\n", r,r);
                    }
                    if(root->left->nodetype == _VAR || root->left->nodetype == _ARRAY){
                        fprintf(fp, "MOV R%d, [R%d]\n", l,l);
                    }
                    fprintf(fp, "ADD R%d, R%d\n", l,r);
                    break;
        case _MINUS :
                    if(root->right->nodetype == _VAR || root->right->nodetype == _ARRAY){
                        fprintf(fp, "MOV R%d, [R%d]\n", r,r);
                    }
                    if(root->left->nodetype == _VAR || root->left->nodetype == _ARRAY){
                        fprintf(fp, "MOV R%d, [R%d]\n", l,l);
                    }
                    fprintf(fp, "SUB R%d, R%d\n", l,r);
                    break;
        case _MUL   :
                    if(root->right->nodetype == _VAR || root->right->nodetype == _ARRAY){
                        fprintf(fp, "MOV R%d, [R%d]\n", r,r);
                    }
                    if(root->left->nodetype == _VAR || root->left->nodetype == _ARRAY){
                        fprintf(fp, "MOV R%d, [R%d]\n", l,l);
                    }
                    fprintf(fp, "MUL R%d, R%d\n", l,r);
                    break;
        case _DIV   :
                    if(root->right->nodetype == _VAR || root->right->nodetype == _ARRAY){
                        fprintf(fp, "MOV R%d, [R%d]\n", r,r);
                    }
                    if(root->left->nodetype == _VAR  || root->left->nodetype == _ARRAY){
                        fprintf(fp, "MOV R%d, [R%d]\n", l,l);
                    }
                    fprintf(fp, "DIV R%d, R%d\n", l,r);
                    break;
        case _MOD   :
                    if(root->right->nodetype == _VAR || root->right->nodetype == _ARRAY){
                        fprintf(fp, "MOV R%d, [R%d]\n", r,r);
                    }
                    if(root->left->nodetype == _VAR  || root->left->nodetype == _ARRAY){
                        fprintf(fp, "MOV R%d, [R%d]\n", l,l);
                    }
                    fprintf(fp, "MOD R%d, R%d\n", l,r);
                    break;
        case _ASGT  :
                    if(root->right->nodetype == _VAR || root->right->nodetype == _ARRAY){
                        fprintf(fp, "MOV R%d, [R%d]\n", r,r);
                    }
                    fprintf(fp, "MOV [R%d], R%d\n", l,r);
                    break;
        case _READ  :
                    // l = findaddress(root->left);
                    printf("read%d\n",l );
                    reading(fp,l);
                    break;
        case _WRITE :
                    if(root->left->nodetype == _VAR || root->left->nodetype == _ARRAY){
                        fprintf(fp, "MOV R%d, [R%d]\n", l,l);
                    }
                    print(fp,l);
                    break;
        case _LT    :
                    if(root->left->nodetype == _VAR || root->left->nodetype == _ARRAY){
                        fprintf(fp, "MOV R%d,[R%d]\n", l,l);
                    }
                    if(root->right->nodetype == _VAR || root->right->nodetype == _ARRAY){
                        fprintf(fp, "MOV R%d,[R%d]\n", r,r);
                    }
                    fprintf(fp, "LT R%d, R%d\n", l,r);
                    break;
        case _GT    :
                    if(root->left->nodetype == _VAR || root->left->nodetype == _ARRAY){
                        fprintf(fp, "MOV R%d,[R%d]\n", l,l);
                    }
                    if(root->right->nodetype == _VAR || root->right->nodetype == _ARRAY){
                        fprintf(fp, "MOV R%d,[R%d]\n", r,r);
                    }
                    fprintf(fp, "GT R%d, R%d\n", l,r);
                    break;
        case _GE    :
                    if(root->left->nodetype == _VAR || root->left->nodetype == _ARRAY){
                        fprintf(fp, "MOV R%d,[R%d]\n", l,l);
                    }
                    if(root->right->nodetype == _VAR || root->right->nodetype == _ARRAY){
                        fprintf(fp, "MOV R%d,[R%d]\n", r,r);
                    }
                    fprintf(fp, "GE R%d, R%d\n", l,r);
                    break;
        case _LE    :
                    if(root->left->nodetype == _VAR || root->left->nodetype == _ARRAY){
                        fprintf(fp, "MOV R%d,[R%d]\n", l,l);
                    }
                    if(root->right->nodetype == _VAR || root->right->nodetype == _ARRAY){
                        fprintf(fp, "MOV R%d,[R%d]\n", r,r);
                    }
                    fprintf(fp, "LE R%d, R%d\n", l,r);
                    break;
        case _NE    :
                    if(root->left->nodetype == _VAR || root->left->nodetype == _ARRAY){
                        fprintf(fp, "MOV R%d,[R%d]\n", l,l);
                    }
                    if(root->right->nodetype == _VAR || root->right->nodetype == _ARRAY){
                        fprintf(fp, "MOV R%d,[R%d]\n", r,r);
                    }
                    fprintf(fp, "NE R%d, R%d\n", l,r);
                    break;
        case _EQ    :
                    if(root->left->nodetype == _VAR || root->left->nodetype == _ARRAY){
                        fprintf(fp, "MOV R%d,[R%d]\n", l,l);
                    }
                    if(root->right->nodetype == _VAR || root->right->nodetype == _ARRAY){
                        fprintf(fp, "MOV R%d,[R%d]\n", r,r);
                    }
                    fprintf(fp, "EQ R%d, R%d\n", l,r);
                    break;

    }
    if((root->nodetype >= 0 && root->nodetype <= 3) || (root->nodetype >= 9 && root->nodetype <= 14) || (root->nodetype == _MOD) || (root->nodetype == _ASGT) || (root->nodetype == _CNT)) freeReg();
    //if(root->nodetype == _CNT) return r;
    printf("$$$$$%d\n",root->nodetype );
    return l;
  }

}

void gen_function_code(struct astnode *fhead,astnode *root){
    struct Gsymbol *Gentry = GLookup(fhead->varname);
    if(Gentry->flabel == -1){
        fprintf(fp, "MAIN:\n");
    }
    else{
        fprintf(fp, "F%d:\n",Gentry->flabel);
    }
    fprintf(fp, "PUSH BP\n");
    fprintf(fp, "MOV BP,SP\n");

    int r1=getReg();
    struct Lsymbol *ldecl_ptr = LsymbolHead;
    while(ldecl_ptr != NULL){
        if(ldecl_ptr->binding > 0) fprintf(fp, "PUSH R%d\n",r1);
        ldecl_ptr = ldecl_ptr->next;
    }
    freeReg();

    int temp = codeGen(root->left,fp);
    freeReg();

    printf("BODY LEFT DONE\n");

    int ret_reg = codeGen(root->right,fp);
    printf("Return R%d\n",ret_reg);
    if(root->right->nodetype == _VAR || root->right->nodetype == _ARRAY){
        fprintf(fp, "MOV R%d,[R%d]\n", ret_reg,ret_reg);
    }

    if(Gentry->flabel != -1){
        int rg1 = getReg();
        fprintf(fp, "MOV R%d, BP\n",rg1);
        fprintf(fp, "SUB R%d, 2\n",rg1);
        fprintf(fp, "MOV [R%d], R%d\n",rg1,ret_reg);
        freeReg();  //for new register used above
    }

    r1=getReg();
    ldecl_ptr = LsymbolHead;
    while(ldecl_ptr != NULL){
        if(ldecl_ptr->binding > 0)fprintf(fp, "POP R%d\n",r1);
        ldecl_ptr = ldecl_ptr->next;
    }
    freeReg();

    freeReg();  //for ret register
    //printf("%d\n",regCount);
    fprintf(fp, "POP BP\n");

    if(Gentry->flabel != -1){
        fprintf(fp, "RET\n");
    }
}

void global_declaration_code(){
    global_var_addrs_limit=4095;

    struct Gsymbol *gdecl_ptr = GsymbolHead;
    while(gdecl_ptr != NULL){
        if(gdecl_ptr->class == _VAR){
            global_var_addrs_limit++;
            gdecl_ptr->binding = global_var_addrs_limit;
        }
        if(gdecl_ptr->class == _ARRAY){
            gdecl_ptr->binding = global_var_addrs_limit+1;
            global_var_addrs_limit += gdecl_ptr->size;

        }
        gdecl_ptr = gdecl_ptr->next;
    }

    fprintf(fp, "MOV SP, %d\n",global_var_addrs_limit);
    fprintf(fp, "JMP MAIN\n");
}

void preorder(struct astnode *root){
    printf("(");
    if(root != NULL){
        printf("%d,%s ", root->nodetype,root->type->name);
        preorder(root->left);
        preorder(root->right);
    }
    printf(")");
}

void print_Gsymbol_table(){
    struct Gsymbol* temp = GsymbolHead;
    while(temp != NULL){
        printf("%s %s ", temp->name,temp->type->name);
        printf("%d\n", temp->size);
        if(temp->class == _FUNCTION){
            struct Paramstruct *cur = temp->paramlist;
            while(cur != NULL){
                printf("    %s %s\n", cur->name,cur->type->name);
                cur = cur->next;
            }
        }
        temp = temp->next;
    }
}

void p(){
    struct Lsymbol* t = LsymbolHead;
    printf("#####Lsymbol####\n");
    while(t!=NULL){
        printf("%s %s\n",t->name,t->type->name);
        t = t->next;
    }
    printf("\n");
}

void print_type_table(){
    Typetable * temp = TypetableHead;
    Fieldlist * t1;
    while(temp != NULL){
        printf("%s\n",temp->name);
        t1 = temp->fields;
        while(t1 != NULL){
            printf("     %s %s\n",t1->name,t1->type->name);
            t1 = t1->next;
        }
        temp = temp->next;
    }
}
