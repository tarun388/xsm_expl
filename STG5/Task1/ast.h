void yyerror(const char *s);
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

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
#define _FUNCTION 26

FILE *fp;

int TYPE;
struct Paramstruct *ParamHead;

typedef struct Paramstruct{
    char* name;                 // name of argument
    int type;                   // data type
    struct Paramstruct* next;
}Paramstruct;

typedef struct Lsymbol{
    char *name;                     //name of the variable
    int type;                       //type of the variable:(Integer / String)
    int binding;                    //local binding of the variable
    struct Lsymbol *next;           //points to the next Local Symbol Table entry
}Lsymbol;

typedef struct Gsymbol{
    char* name;                     // name of the variable
    int type;                       // type of the variable
    int class;                      // class i.e. array or var or function
    int size;                       // size of the type of the variable
    int binding;                    // stores the static memory address allocated to the variable
    struct Paramstruct *paramlist;  //pointer to the head of the formal parameter list
    int flabel;
    struct Lsymbol *Lsymbollist;
    struct Gsymbol *next;
}Gsymbol;

typedef struct astnode{
  int val;                          //value for NUM
  char* str;
  int type;                         //type of variables
  char* varname;                    //name of variables for ID nodes
  int nodetype;                     //information about non-leaf nodes -read/write/connector/+/*/function etc
  struct Gsymbol *Gentry;           //pointer to GST entry for global variables and functions
  struct Paramstruct *paramlist;    //list of parameters for function
  struct Lsymbol *Lentry;
  struct astnode *arglist;
  struct astnode *left, *right;
}astnode;

int TypeStack[100];
int TopTypeStack;

struct Paramstruct *makeArgs(char *name,int type);

struct Paramstruct *makeParamList(struct Paramstruct *head,struct Paramstruct *newParam);

void checkTypeMismatch(struct astnode* root);

struct Gsymbol *makeGSymbolNode(char *name, int type, int size,int class,struct Paramstruct *paramlist);

struct Gsymbol *GLookup(char* name);

void GInstall(char *name, int type, int size, int class,struct Paramstruct *paramlist);

struct astnode *makeNewastnode();

struct astnode* makeConstIntLeafNode(int val);

struct astnode* makeConstStringLeafNode(char *c);

struct astnode* makeVarLeafNode(char *c);

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

void Function(struct astnode *head,struct Paramstruct *paramlist,struct astnode *body);

struct astnode * makeFunctionNode(struct astnode *name, struct astnode *arglist);

int getReg();

void freeReg();

int getLabel();

void print(FILE *fp,int reg1);

void reading(FILE *fp,int addrs);

int findaddress(char* node);

void checkTypeMismatchVar(struct astnode* root,int var_type);

void checkTypeMismatch(struct astnode* root);

int codeGen(struct astnode* root,FILE *fp);

void genxsm();

void preorder(struct astnode *root);

void print_Gsymbol_table();
