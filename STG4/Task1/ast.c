/*
Leaf nodes are of two types
constant
variables
*/

/*
Three data types
Integer
String
Bool
*/

struct Gsymbol * GsymbolHead = NULL;
struct Gsymbol * GsymbolTail = NULL;
int addrs = 4095;

struct Gsymbol *makeSymbolNode(char *name, int type, int size,int class){
    struct Gsymbol* temp = (struct Gsymbol*)malloc(sizeof(struct Gsymbol));

    temp->name = strdup(name);
    temp->type = type;
    temp->class = class;
    temp->size = size;
    temp->binding = addrs+1;
    addrs += size;
    temp->next = NULL;
    return temp;
}

struct Gsymbol *Lookup(char* name){
// Returns a pointer to the symbol table entry for the variable, returns NULL otherwise.
    struct Gsymbol* temp = GsymbolHead;
    // printf("%s ",name);
    while(temp != NULL){
        // printf("%s ",temp->name);
        if(strcmp(temp->name, name) == 0) return temp;
        temp = temp->next;
    }
    return NULL;
}

void Install(char *name, int type, int size,int class){
// Creates a symbol table entry.
    if(Lookup(name) == NULL){
        struct Gsymbol* temp = makeSymbolNode(name,type,size,class);
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

struct astnode* makeConstIntLeafNode(int val){
    struct astnode* temp = (struct astnode*)malloc(sizeof(struct astnode));
    temp->val = val;
    temp->type = _INT;
    temp->varname = NULL;
    temp->nodetype = _CONST;
    temp->left = temp->right = NULL;
    return temp;
}

struct astnode* makeConstStringLeafNode(char *c){
    struct astnode* temp = (struct astnode*)malloc(sizeof(struct astnode));
    temp->str = strdup(c);
    temp->type = _STRING;
    temp->nodetype = _CONST;
    temp->left = temp->right = NULL;
    return temp;
}

struct astnode* makeVarLeafNode(char *c,int var_type,int section){
    struct Gsymbol* Gentry = Lookup(c);
    if(section == 2){
        if(Gentry == NULL){
            yyerror("Undeclared Variable\n");
            exit(1);
        }
        // if(Gentry->class != _VAR){
        //     yyerror("Type not normal var\n");
        //     exit(1);
        // }
    }

    struct astnode* temp = (struct astnode*)malloc(sizeof(struct astnode));
    temp->varname = strdup(c);
    if(section == 1) temp->type = var_type;
    else temp->type = Gentry->type;
    temp->nodetype = _VAR;
    temp->left = temp->right = NULL;
    return temp;
}

struct astnode* makeArrayLeafNode(struct astnode* id,struct astnode* index){
    struct Gsymbol* Gentry = Lookup(id->varname);
    if(Gentry == NULL){
        yyerror("Undeclared Variable\n");
        exit(1);
    }
    if(Gentry->class != _ARRAY){
        yyerror("Type not array\n");
        exit(1);
    }
    struct astnode* temp = (struct astnode*)malloc(sizeof(struct astnode));
    temp->varname = NULL;
    temp->type = id->type;
    temp->nodetype = _ARRAY;
    temp->left = id;
    temp->right = index;
    return temp;
}

struct astnode* makeOperatorNode(int type, int nodetype, struct astnode* l, struct astnode* r){
    struct astnode* temp = (struct astnode*)malloc(sizeof(struct astnode));
    temp->type = type;
    temp->varname = NULL;
    temp->nodetype = nodetype;
    temp->left = l;
    temp->right = r;
    checkTypeMismatch(temp);
    return temp;
}

struct astnode* makeAsgtNode(struct astnode* l, struct astnode* r){
    struct astnode* temp = (struct astnode*)malloc(sizeof(struct astnode));
    temp->type = _INT;
    temp->varname = NULL;
    temp->nodetype = _ASGT;
    temp->left = l;
    temp->right = r;
    checkTypeMismatch(temp);
    return temp;
}

struct astnode* makeReadNode(struct astnode* l){
    struct astnode* temp = (struct astnode*)malloc(sizeof(struct astnode));
    temp->varname = NULL;
    temp->nodetype = _READ;
    temp->left = l;
    temp->right = NULL;
    return temp;
}

struct astnode* makeWriteNode(struct astnode* l){
    struct astnode* temp = (struct astnode*)malloc(sizeof(struct astnode));
    temp->varname = NULL;
    temp->nodetype = _WRITE;
    temp->left = l;
    temp->right = NULL;
    return temp;
}

struct astnode* makeconnectorNode(struct astnode* l, struct astnode* r){
    struct astnode* temp = (struct astnode*)malloc(sizeof(struct astnode));
    temp->varname = NULL;
    temp->nodetype = _CNT;
    temp->left = l;
    temp->right = r;
    return temp;
}

struct astnode* makeCondNode(struct astnode* cond, struct astnode* true_stmt, struct astnode* false_stmt){
    struct astnode * temp = (struct astnode*)malloc(sizeof(struct astnode));
    temp->varname = NULL;
    temp->nodetype = _IF;
    temp->left = cond;

    struct astnode* temp2 = (struct astnode*)malloc(sizeof(struct astnode));
    temp2->varname = NULL;
    temp2->nodetype = _IFBODY;
    temp2->left = true_stmt;
    temp2->right = false_stmt;

    temp->right = temp2;

    return temp;
}

struct astnode* makeLoopNode(struct astnode* cond, struct astnode* while_body){
    struct astnode * temp = (struct astnode*)malloc(sizeof(struct astnode));
    temp->varname = NULL;
    temp->nodetype = _WHILE;
    temp->left = cond;
    temp->right = while_body;
    return temp;
}

struct astnode* makeBreakNode(){
    struct astnode* temp = (struct astnode*)malloc(sizeof(struct astnode));
    temp->varname = NULL;
    temp->nodetype = _BREAK;
    temp->left = temp->right = NULL;
    return temp;
}

struct astnode* makeContinueNode(){
    struct astnode* temp = (struct astnode*)malloc(sizeof(struct astnode));
    temp->varname = NULL;
    temp->nodetype = _CONTINUE;
    temp->left = temp->right = NULL;
    return temp;
}

//global variable denoting free register count number
int regCount = 0;

int getReg(){
  return ++regCount;
}

void freeReg(){
  regCount--;
  // if(freeReg<-1) printf("FREE<-1\n");
}

int labelCount = -1;

int getLabel(){
    return ++labelCount;
}

//nested while count
int nested_while=-1;

int label_jmp[1000][2];

void print(FILE *fp,int reg1){
  int reg2 = getReg();
  for (int i=1;i<reg2;i++)
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
  for (int i=reg2-1;i>0;i--)
    fprintf(fp, "POP R%d\n", i);
  freeReg();
}

void reading(FILE *fp,int arg2){
    int reg2 = getReg();
    for (int i=1;i<reg2;i++)
      fprintf(fp, "PUSH R%d\n", i);
    fprintf(fp, "MOV R%d,\"Read\"\n", reg2);
    fprintf(fp, "PUSH R%d\n", reg2);
    fprintf(fp, "MOV R%d,-1\n", reg2);
    fprintf(fp, "PUSH R%d\n", reg2);
    // int x = getReg();
    // fprintf(fp, "MOV R%d, %d\n", x,addrs);
    // freeReg();
    fprintf(fp, "PUSH R%d\n", arg2);
    fprintf(fp, "PUSH R%d\n", reg2);
    fprintf(fp, "PUSH R%d\n", reg2);
    fprintf(fp, "CALL 0\n");
    fprintf(fp, "POP R%d\n", reg2);
    fprintf(fp, "POP R%d\n", reg2);
    fprintf(fp, "POP R%d\n", reg2);
    fprintf(fp, "POP R%d\n", reg2);
    fprintf(fp, "POP R%d\n", reg2);
    // fprintf(fp, "POP R%d\n", reg2);
    for (int i=reg2-1;i>0;i--)
      fprintf(fp, "POP R%d\n", i);
    freeReg();
}

int findaddress(char* node){
    struct Gsymbol *temp = Lookup(node);
    return temp->binding;
}

void checkTypeMismatch(struct astnode* root){
    // return 1;
    if(root->nodetype == _ASGT){
        if(!((root->left->type == _INT && root->right->type == _INT) || (root->left->type == _STRING && root->right->type == _STRING))){
            yyerror("Type Mismatch\n");
            exit(1);
        }
    }
    else{
        if(!(root->left->type == _INT && root->right->type == _INT)){
            yyerror("Type Mismatch\n");
            exit(1);
        }
    }
}

int codeGen(struct astnode* root,FILE *fp){
  if(root->nodetype == _CONST || root->nodetype == _VAR || root->nodetype == _ARRAY){
      int reg = getReg();
      if(root->nodetype == _CONST){
          if(root->type == _INT){
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
          struct Gsymbol* Gentry = Lookup(root->left->varname);
          // printf("hi\n");

          int baseaddrs = Gentry->binding;
          fprintf(fp, "MOV R%d, %d\n", reg,baseaddrs);
          fprintf(fp, "ADD R%d, R%d\n", reg,index);
          freeReg();
      }
      else{
          int addrs = findaddress(root->varname);
          fprintf(fp, "MOV R%d, %d\n", reg,addrs);
      }
      return reg;
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
      return l;
  }
  else if(root->nodetype == _IF){
      int label1 = getLabel();
      int label2 = getLabel();
      // fprintf(fp, "L%d:\n", label1);

      int l = codeGen(root->left,fp);
      fprintf(fp, "JZ R%d, L%d\n", l,label1);

      int r = codeGen(root->right->left,fp);
      fprintf(fp, "JMP L%d\n", label2);
      fprintf(fp, "L%d:\n", label1);

      if(root->right->right != NULL){
          r = codeGen(root->right->right,fp);
          freeReg();
      }
      fprintf(fp, "L%d:\n", label2);
      freeReg();
      return l;
  }
  else if(root->nodetype == _BREAK){
      if(nested_while>=0){
        fprintf(fp, "JMP L%d\n", label_jmp[nested_while][1]);
      }
      return -1;
  }
  else if(root->nodetype == _CONTINUE){
      if(nested_while>=0){
        fprintf(fp, "JMP L%d\n", label_jmp[nested_while][0]);
      }
      return -1;
  }
  else{
    int l = codeGen(root->left,fp);
    int r;
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
    if(root->nodetype != _CNT) freeReg();
    // freeReg();
    return l;
  }

}

void genxsm(struct astnode *root){
  FILE *fp;
  fp = fopen("xsm1.xsm","w");
  //Header of xsm FILE
  //XEXE file format
  fprintf(fp, "0\n");
  //entry point
  fprintf(fp, "2056\n");
  for(int i=0;i<6;i++) fprintf(fp, "0\n");
  fprintf(fp, "MOV SP, %d\n",addrs);
  int reg = codeGen(root,fp);

  //print(fp,reg);

  fprintf(fp ,"INT 10");
  fclose(fp);
}

void preorder(struct astnode *root){
    printf("(");
    if(root != NULL){
        printf("%d,%d ", root->nodetype,root->type);
        preorder(root->left);
        preorder(root->right);
    }
    printf(")");
}

void print_Gsymbol_table(){
    struct Gsymbol* temp = GsymbolHead;
    while(temp != NULL){
        printf("%s ", temp->name);
        if(temp->type == _INT) printf("Int ");
        else if(temp->type == _STRING) printf("Str ");
        printf("%d %d\n", temp->size,temp->binding);
        temp = temp->next;
    }
}
