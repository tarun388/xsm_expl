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
#define _FIELD 27
#define _DOT 28
#define _ALLOC 29
#define _FREE 30
#define _INITIALIZE 31
#define _NULL 32

typedef struct Fieldlist{
    char * name;
    int fieldindex;
    struct Typetable * type;
    char * typeinfo;
    struct Fieldlist * next;
}Fieldlist;

typedef struct Typetable{
    char * name;
    int size;
    struct Fieldlist * fields;
    struct Typetable  * next;
}Typetable;

typedef struct Paramstruct{
    char* name;                 // name of argument
    Typetable * type;                   // data type
    struct Paramstruct* next;
}Paramstruct;

typedef struct Lsymbol{
    char *name;                     //name of the variable
    Typetable * type;                       //type of the variable:(Integer / String)
    int binding;                    //local binding of the variable
    struct Lsymbol *next;           //points to the next Local Symbol Table entry
}Lsymbol;

typedef struct Gsymbol{
    char* name;                     // name of the variable
    Typetable * type;                       // type of the variable
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
  Typetable * type;                         //type of variables
  char* varname;                    //name of variables for ID nodes
  int nodetype;                     //information about non-leaf nodes -read/write/connector/+/*/function etc
  struct Gsymbol *Gentry;           //pointer to GST entry for global variables and functions
  struct Paramstruct *paramlist;    //list of parameters for function
  struct Lsymbol *Lentry;
  struct astnode *arglist;
  struct astnode *left, *right;
}astnode;

FILE *fp;

struct Paramstruct *ParamHead;

int typeflag;       //for type declaration
char * typeinfo;      //for type declaration
struct Typetable * TYPE;
struct Typetable * TypeStack[100];
int TopTypeStack;

Typetable * TypetableHead;
Typetable * TypetableTail;
struct Gsymbol * GsymbolHead;
struct Gsymbol * GsymbolTail;
struct Lsymbol * LsymbolHead;
struct Lsymbol * LsymbolTail;

int global_var_addrs_limit;
int flabel;

//global variable denoting free register count number
int regCount;
int labelCount;

//nested while count
int nested_while;

int label_jmp[1000][2];

astnode * GNULL;

Typetable * TypeStackPush(Typetable * type);

void TypeStackPop();

Fieldlist * makeNewFieldlistNode();

Fieldlist * makeFieldlistNode(char * name,Typetable * type,char * typeinfo);

Fieldlist * makeFieldlist(Fieldlist * fieldlist,Fieldlist * field);

Fieldlist * FLookup(Typetable * type,char * name);

Typetable * makeNewTypeTableNode();

Typetable * TLookup(char * name);

Typetable * TInstall(char *name,int size,Fieldlist * fields);

void TypeTableCreate();

struct Lsymbol *makeNewLsymbol();

struct Lsymbol *makeLsymbolNode(char *name,Typetable * type);

struct Lsymbol *LLookup(char *name);

struct Lsymbol * LInstall(char *name,Typetable * type);

struct Gsymbol *makeGSymbolNode(char *name, Typetable * type, int size,int class,struct Paramstruct *paramlist);

struct Gsymbol *GLookup(char* name);

void GInstall(char *name, Typetable * type, int size, int class,struct Paramstruct *paramlist);

struct astnode *makeNewastnode();

struct astnode* makeConstIntLeafNode(int val);

struct astnode* makeConstStringLeafNode(char *c);

struct astnode* makeVarLeafNode(char *c);

struct astnode* updateVarLeafNode(struct astnode* id);

struct astnode* makeArrayLeafNode(struct astnode* id,struct astnode* index);

astnode * makeDotNode(astnode * l,astnode * r);

struct astnode* makeOperatorNode(Typetable * type, int nodetype, struct astnode* l, struct astnode* r);

struct astnode* makeAsgtNode(struct astnode* l, struct astnode* r);

struct astnode* makeReadNode(struct astnode* l);

struct astnode* makeWriteNode(struct astnode* r);

struct astnode* makeconnectorNode(struct astnode* l, struct astnode* r);

struct astnode* makeCondNode(struct astnode* cond, struct astnode* true_stmt, struct astnode* false_stmt);

struct astnode* makeLoopNode(struct astnode* cond, struct astnode* while_body);

struct astnode* makeBreakNode();

struct astnode* makeContinueNode();

struct Paramstruct *makeParameter(char *name,Typetable * type);

struct Paramstruct *makeParamList(struct Paramstruct *head,struct Paramstruct *newParam);

void InstallParameter();

void Function(struct astnode *head,struct Paramstruct *paramlist,struct astnode *body);

struct astnode * makeArgList(struct astnode * head,struct astnode *arg);

struct astnode * makeFunctionNode(struct astnode *name, struct astnode *arglist);

void checkTypeMismatch(struct astnode* root);

int getReg();

void freeReg();

int getLabel();

void print(FILE *fp,int reg1);

void reading(FILE *fp,int addrs);

void checkTypeMismatchVar(struct astnode* root,int var_type);

int evaluate_argument(FILE *fp,struct astnode *arg);

int codeGen(struct astnode* root,FILE *fp);

void gen_function_code(struct astnode *fhead,astnode *root);

void global_declaration_code();

void preorder(struct astnode *root);

void print_Gsymbol_table();

void p();
