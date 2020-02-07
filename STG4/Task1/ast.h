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
#define _STRING 20
#define _CONST 21
#define _VAR 22
#define _IFBODY 23
#define _ARRAY 24
#define _MOD 25

typedef struct Gsymbol{
    char* name;                 // name of the variable
    int type;                   // type of the variable
    int class;                  // class i.e. array or not
    int size;                   // size of the type of the variable
    int binding;                // stores the static memory address allocated to the variable
    struct Gsymbol *next;
}Gsymbol;

typedef struct astnode{
  int val;                      //value for NUM
  char* str;
  int type;                     //type of variables
  char* varname;                //name of variables for ID nodes
  int nodetype;                 //information about non-leaf nodes -read/write/connector/+/* etc
  struct Gsymbol *Gentry;       //pointer to GST entry for global variables and functions
  struct astnode *left, *right;
}astnode;

void checkTypeMismatch(struct astnode* root);

struct Gsymbol *makeSymbolNode(char *name, int type, int size,int class);

struct Gsymbol *Lookup(char* name);

void Install(char *name, int type, int size, int class);

struct astnode* makeConstIntLeafNode(int val);

struct astnode* makeConstStringLeafNode(char *c);

struct astnode* makeVarLeafNode(char *c,int var_type,int section);

struct astnode* makeArrayLeafNode(struct astnode* id,struct astnode* index);

struct astnode* makeOperatorNode(int typ, int nodetype, struct astnode* l, struct astnode* r);

struct astnode* makeAsgtNode(struct astnode* l, struct astnode* r);

struct astnode* makeReadNode(struct astnode* l);

struct astnode* makeWriteNode(struct astnode* r);

struct astnode* makeconnectorNode(struct astnode* l, struct astnode* r);

struct astnode* makeCondNode(struct astnode* cond, struct astnode* true_stmt, struct astnode* false_stmt);

struct astnode* makeLoopNode(struct astnode* cond, struct astnode* while_body);

struct astnode* makeBreakNode();

struct astnode* makeContinueNode();

int getReg();

void freeReg();

int getLabel();

void print(FILE *fp,int reg1);

void reading(FILE *fp,int addrs);

int findaddress(char* node);

int codeGen(struct astnode* root,FILE *fp);

void genxsm(struct astnode *root);

void preorder(struct astnode *root);

void print_Gsymbol_table();
