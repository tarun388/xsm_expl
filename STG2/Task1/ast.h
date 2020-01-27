typedef struct astnode{
  int val;                      //value for NUM
  int type;                     //type of variables
  char* varname;                //name of variables for ID nodes
  int nodetype;                 //information about non-leaf nodes -read/write/connector/+/* etc
  struct astnode *left, *right;
}astnode;

struct astnode* makeLeafNode(int val, int type,char *c);

struct astnode* makeOperatorNode(int nodetype, struct astnode* l, struct astnode* r);

struct astnode* makeAsgtNode(struct astnode* l, struct astnode* r);

struct astnode* makeReadNode(struct astnode* l);

struct astnode* makeWriteNode(struct astnode* r);

struct astnode* makeconnectorNode(struct astnode* l, struct astnode* r);

int getReg();

void freeReg();

void print(FILE *fp,int reg1);

void reading(FILE *fp,int addrs);

int codeGen(struct astnode* root,FILE *fp);

void genxsm(struct astnode *root);
