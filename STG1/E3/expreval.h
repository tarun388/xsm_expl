typedef struct tnode{
  int val;
  char *op;
  struct tnode *left, *right;
}tnode;

struct tnode* makeleafNode(int n);

struct tnode* makeOperatorNode(char c,struct tnode *l,struct tnode *r);

//find a free register
int getReg();

//free a register
void freeReg();

//to generate xsm language code recursively
int codeGen(struct tnode* root,FILE *fp);

void print(FILE *fp,int reg1);

void genxsm(struct tnode *root);
