typedef struct tnode{
  int val;                    //value of expression tree
  char  *op;                  //indicates the operator
  struct tnode *left, *right; //left and right branches
}tnode;

/*Make a leaf tnode and set the value of val field*/
struct tnode* makeLeafNode(int n);

/*Make a tnode with opertor, left and right branches set*/
struct tnode* makeoperatorNode(char c,struct tnode *l,struct tnode *r);

/*To evaluate an expression tree*/
void evaluate_post(struct tnode* t);
void evaluate_pre(struct tnode* t);
