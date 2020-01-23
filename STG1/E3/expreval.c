struct tnode* makeleafNode(int n){
  struct tnode *temp = (struct tnode*)malloc(sizeof(struct tnode));
  temp->op = NULL;
  temp->val = n;
  temp->left = temp->right = NULL;
  return temp;
}

struct tnode* makeOperatorNode(char c,struct tnode *l,struct tnode *r){
  struct tnode* temp = (struct tnode*)malloc(sizeof(struct tnode));
  temp->op = malloc(sizeof(char));
  *temp->op = c;
  temp->left = l;
  temp->right = r;
  return temp;
}

//global variable denoting free register count number
int regCount = -1;

int getReg(){
  return ++regCount;
}

void freeReg(){
  regCount--;
}

int codeGen(struct tnode* root,FILE *fp){
  if(root->op == NULL){
    return getReg();
  }
  else{
    int l = codeGen(root->left,fp);
    if(root->left->op == NULL){
      fprintf(fp, "MOV R%d, %d\n", l,root->left->val);
    }
    int r = codeGen(root->right,fp);
    if(root->right->op == NULL){
      fprintf(fp, "MOV R%d, %d\n", r,root->right->val);
    }
    switch (*(root->op)){
      case '+' :fprintf(fp, "ADD R%d, R%d\n", l,r);
                break;
      case '-' :fprintf(fp, "SUB R%d, R%d\n", l,r);
                break;
      case '*' :fprintf(fp, "MUL R%d, R%d\n", l,r);
                break;
      case '/' :fprintf(fp, "DIV R%d, R%d\n", l,r);
                break;
    }

    freeReg();
    return l;
  }

}

void print(FILE *fp,int reg1){
  int reg2 = getReg();
  fprintf(fp, "MOV R%d,Write\n", reg2);
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
  freeReg();
}

void genxsm(struct tnode *root){
  FILE *fp;
  fp = fopen("xsm1.xsm","w");
  //Header of xsm FILE
  //XEXE file format
  fprintf(fp, "0\n");
  //entry point
  fprintf(fp, "2056\n");
  for(int i=0;i<6;i++) fprintf(fp, "0\n");
  int reg = codeGen(root,fp);

  print(fp,reg);

  fprintf(fp ,"INT 10");
  fclose(fp);
}
