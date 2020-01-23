struct tnode* makeLeafNode(int n)
{
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->op = NULL;
    temp->val = n;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

struct tnode* makeOperatorNode(char c,struct tnode *l,struct tnode *r){
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->op = malloc(sizeof(char));
    *(temp->op) = c;
    temp->left = l;
    temp->right = r;
    return temp;
}

void evaluate_post(struct tnode *t){
    if(t->op == NULL)
    {
        printf("%d ",t->val);
        // return t->val;
    }
    else{
        evaluate_post(t->left);
        evaluate_post(t->right);
        printf("%s ",t->op);
        // switch(*(t->op)){
        //     case '+' : return evaluate(t->left) + evaluate(t->right);
        //                break;
        //     case '-' : return evaluate(t->left) - evaluate(t->right);
        //                break;
        //     case '*' : return evaluate(t->left) * evaluate(t->right);
        //                break;
        //     case '/' : return evaluate(t->left) / evaluate(t->right);
        //                break;
        // }
    }
}

void evaluate_pre(struct tnode *t){
    if(t->op == NULL)
    {
        printf("%d ",t->val);
        // return t->val;
    }
    else{
        printf("%s ",t->op);
        evaluate_pre(t->left);
        evaluate_pre(t->right);
        // switch(*(t->op)){
        //     case '+' : return evaluate(t->left) + evaluate(t->right);
        //                break;
        //     case '-' : return evaluate(t->left) - evaluate(t->right);
        //                break;
        //     case '*' : return evaluate(t->left) * evaluate(t->right);
        //                break;
        //     case '/' : return evaluate(t->left) / evaluate(t->right);
        //                break;
        // }
    }
}
