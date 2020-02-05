#define _PLUS 0
#define _MINUS 1
#define _MUL 2
#define _DIV 3
#define _INT 4
#define _CNT 5
#define _ASGT 6
#define _WRITE 7
#define _READ 8
#define _GT 9
#define _LT 10
#define _GE 11
#define _LE 12
#define _NE 13
#define _EQ 14
#define _IF 15
#define _BOOL 16
#define _WHILE 17
#define _BREAK 18
#define _CONTINUE 19

/*
Leaf nodes are of two types
0 - constant integer numbers
1 - integer variables
*/

struct astnode* makeLeafNode(int val, int type,char *c){
    struct astnode* temp = (struct astnode*)malloc(sizeof(struct astnode));
    temp->val = val;
    temp->type = type;
    temp->varname = NULL;
    if(type == 1){
        temp->varname = malloc(sizeof(char));
        *(temp->varname) = *c;
    }
    temp->nodetype = _INT;
    temp->left = temp->right = NULL;
    return temp;
}

struct astnode* makeOperatorNode(int typ, int nodetype, struct astnode* l, struct astnode* r){
    struct astnode* temp = (struct astnode*)malloc(sizeof(struct astnode));
    temp->type = typ;
    temp->varname = NULL;
    temp->nodetype = nodetype;
    temp->left = l;
    temp->right = r;
    return temp;
}

struct astnode* makeAsgtNode(struct astnode* l, struct astnode* r){
    struct astnode* temp = (struct astnode*)malloc(sizeof(struct astnode));
    temp->type = _INT;
    temp->varname = NULL;
    temp->nodetype = _ASGT;
    temp->left = l;
    temp->right = r;
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
    temp2->nodetype = _IF;
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

void reading(FILE *fp,int addrs){
    int reg2 = getReg();
    for (int i=1;i<reg2;i++)
      fprintf(fp, "PUSH R%d\n", i);
    fprintf(fp, "MOV R%d,\"Read\"\n", reg2);
    fprintf(fp, "PUSH R%d\n", reg2);
    fprintf(fp, "MOV R%d,-1\n", reg2);
    fprintf(fp, "PUSH R%d\n", reg2);
    int x = getReg();
    fprintf(fp, "MOV R%d, %d\n", x,addrs);
    freeReg();
    fprintf(fp, "PUSH R%d\n", x);
    fprintf(fp, "PUSH R%d\n", reg2);
    fprintf(fp, "PUSH R%d\n", reg2);
    fprintf(fp, "CALL 0\n");
    fprintf(fp, "POP R%d\n", reg2);
    fprintf(fp, "POP R%d\n", reg2);
    fprintf(fp, "POP R%d\n", reg2);
    fprintf(fp, "POP R%d\n", reg2);
    fprintf(fp, "POP R%d\n", reg2);
    fprintf(fp, "POP R%d\n", reg2);
    for (int i=reg2-1;i>0;i--)
      fprintf(fp, "POP R%d\n", i);
    freeReg();
}

int codeGen(struct astnode* root,FILE *fp){
  if(root->nodetype == _INT){
      int reg = getReg();
      if(root->type == 0){
          fprintf(fp, "MOV R%d, %d\n", reg,root->val);
      }
      else{
          int addrs = 4096 + *(root->varname) - 97;
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
                    if(root->right->nodetype == _INT && root->right->type == 1){
                        fprintf(fp, "MOV R%d, [R%d]\n", r,r);
                    }
                    if(root->left->nodetype == _INT && root->left->type == 1){
                        fprintf(fp, "MOV R%d, [R%d]\n", l,l);
                    }
                    fprintf(fp, "ADD R%d, R%d\n", l,r);
                    break;
        case _MINUS :
                    if(root->right->nodetype == _INT && root->right->type == 1){
                        fprintf(fp, "MOV R%d, [R%d]\n", r,r);
                    }
                    if(root->left->nodetype == _INT && root->left->type == 1){
                        fprintf(fp, "MOV R%d, [R%d]\n", l,l);
                    }
                    fprintf(fp, "SUB R%d, R%d\n", l,r);
                    break;
        case _MUL   :
                    if(root->right->nodetype == _INT && root->right->type == 1){
                        fprintf(fp, "MOV R%d, [R%d]\n", r,r);
                    }
                    if(root->left->nodetype == _INT && root->left->type == 1){
                        fprintf(fp, "MOV R%d, [R%d]\n", l,l);
                    }
                    fprintf(fp, "MUL R%d, R%d\n", l,r);
                    break;
        case _DIV   :
                    if(root->right->nodetype == _INT && root->right->type == 1){
                        fprintf(fp, "MOV R%d, [R%d]\n", r,r);
                    }
                    if(root->left->nodetype == _INT && root->left->type == 1){
                        fprintf(fp, "MOV R%d, [R%d]\n", l,l);
                    }
                    fprintf(fp, "DIV R%d, R%d\n", l,r);
                    break;
        case _ASGT  :
                    if(root->right->nodetype == _INT && root->right->type == 1){
                        fprintf(fp, "MOV R%d, [R%d]\n", r,r);
                    }
                    fprintf(fp, "MOV [R%d], R%d\n", l,r);
                    break;
        case _READ  :
                    l = 4096 + *(root->left->varname) - 97;
                    reading(fp,l);
                    break;
        case _WRITE :
                    if(root->left->nodetype == _INT && root->left->type == 1){
                        fprintf(fp, "MOV R%d, [R%d]\n", l,l);
                    }
                    print(fp,l);
                    break;
        case _LT    :
                    if(root->left->nodetype == _INT && root->left->type == 1){
                        fprintf(fp, "MOV R%d,[R%d]\n", l,l);
                    }
                    if(root->right->nodetype == _INT && root->right->type == 1){
                        fprintf(fp, "MOV R%d,[R%d]\n", r,r);
                    }
                    fprintf(fp, "LT R%d, R%d\n", l,r);
                    break;
        case _GT    :
                    if(root->left->nodetype == _INT && root->left->type == 1){
                        fprintf(fp, "MOV R%d,[R%d]\n", l,l);
                    }
                    if(root->right->nodetype == _INT && root->right->type == 1){
                        fprintf(fp, "MOV R%d,[R%d]\n", r,r);
                    }
                    fprintf(fp, "GT R%d, R%d\n", l,r);
                    break;
        case _GE    :
                    if(root->left->nodetype == _INT && root->left->type == 1){
                        fprintf(fp, "MOV R%d,[R%d]\n", l,l);
                    }
                    if(root->right->nodetype == _INT && root->right->type == 1){
                        fprintf(fp, "MOV R%d,[R%d]\n", r,r);
                    }
                    fprintf(fp, "GE R%d, R%d\n", l,r);
                    break;
        case _LE    :
                    if(root->left->nodetype == _INT && root->left->type == 1){
                        fprintf(fp, "MOV R%d,[R%d]\n", l,l);
                    }
                    if(root->right->nodetype == _INT && root->right->type == 1){
                        fprintf(fp, "MOV R%d,[R%d]\n", r,r);
                    }
                    fprintf(fp, "LE R%d, R%d\n", l,r);
                    break;
        case _NE    :
                    if(root->left->nodetype == _INT && root->left->type == 1){
                        fprintf(fp, "MOV R%d,[R%d]\n", l,l);
                    }
                    if(root->right->nodetype == _INT && root->right->type == 1){
                        fprintf(fp, "MOV R%d,[R%d]\n", r,r);
                    }
                    fprintf(fp, "NE R%d, R%d\n", l,r);
                    break;
        case _EQ    :
                    if(root->left->nodetype == _INT && root->left->type == 1){
                        fprintf(fp, "MOV R%d,[R%d]\n", l,l);
                    }
                    if(root->right->nodetype == _INT && root->right->type == 1){
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
  fprintf(fp, "MOV SP, 4111\n");
  int reg = codeGen(root,fp);

  //print(fp,reg);

  fprintf(fp ,"INT 10");
  fclose(fp);
}

void preorder(struct astnode *root){
    printf("(");
    if(root != NULL){
        printf("%d ", root->nodetype);
        preorder(root->left);
        preorder(root->right);
    }
    printf(")");
}
