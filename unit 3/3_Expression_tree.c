// expression tree - used to represent expressions via binary tree
/* has operands as leaf nodes and operators as internal nodes
traditionally unary operators have one of the subtrees empty
some of them (operators are filled to left of operands) like +,-,log,cos
and oher the operators are filled to the right of operand -> ex: factorial,square of number etc..
ex:                 log //operator to the left of operand                        !  //operator to the right of operand
                    _\                                                          /
                    __x                                                        n
ex of expression tree   =>  (a<b) or (c<d)
                                                            or
                                                        ___/  \
                                                        __<    <
                                                        _/ \   / \
                                                        a  b  c   d
its immutable - to change expression to another new tree must be constructed
postfix expression is used for ex: a+b*c  = a+(bc*) = abc*+
the arrangement and evaluation given in slides(see that)
the final tree =                        +
                                    ___/ \
                                    __a   *
                                        _/ \
                                        b   c


*/

/* #include <stdio.h>
#include <stdlib.h>
#define max 20
typedef struct enode
{
    int isOperator; // 0 for operator & 1 for operand
    char operator;  //+,-,log,,sin,!...
    float operand;  // numbers to perform operations on
    struct enode *left;
    struct enode *right;
} ENODE;
static int top = -1;


ENODE *temp = NULL;
ENODE *stack[max];


int isDigit(char exp);
void push(ENODE *temp,ENODE *stack[]);
ENODE *pop(ENODE *stack[]);
ENODE *construct(char exp[]);
void inorder(ENODE *bst);
float calculate(float x, float y, char op);
float evaluate(ENODE *bst);

int main()
{
    ENODE *bst;
    char exp[max] = "567*+";
    bst = construct(exp);

    if (bst == NULL)
        printf("unable to construct\n");
    printf("inorder traversal of Expression tree\n");
    inorder(bst);
    printf("\n");
    printf("evaluation of the expression: %f\n", evaluate(bst));
    return 0;
}

int isDigit(char exp)
{
    switch(exp)
    {
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
        case '0':
            return 1;
        default:
            return 0;

    }

}
void push(ENODE *temp,ENODE *stack[])
{
    if (top < max - 1)
        stack[++top] = temp; // to insert the node into top element of stack
    else
        printf("stack is full\n");
}

ENODE *pop(ENODE *stack[])
{
    if (top == -1)
    {
        printf("stack is empty\n");
        return NULL;
    }
    else
        return stack[top--]; // to remove the top most element of the stack
}

ENODE *construct(char exp[])
{
    int i = 0;
    while (exp[i])
    {
        temp = (ENODE *)malloc(sizeof(ENODE));
        if(isDigit(exp[i]))
        {
            temp->isOperator = 0;
            temp->operand = exp[i] - '0';  //gives the integer value of the operand
            temp->left = temp->right = NULL;
            push(temp,stack);
        }
        else
        {
            temp->isOperator = 1;
            temp->operator = exp[i];  //the oparator
            temp->right = pop(stack); //popping the last operands/nodes put into the stack and fixing them to right & left respectively
            temp->left = pop(stack);
            push(temp,stack);
        }
        i++;
    }
    return pop(stack); //this gives put the root of the tree
}

void inorder(ENODE *bst)
{
    if(bst != NULL)
    {
        inorder(bst->left);

        if(bst->isOperator == 0)
            printf("%f",bst->operand);
        else
            printf("%c",bst->operator);
        inorder(bst->right);
    }
}

float calculate(float x,float y,char op)
{
    switch(op)
    {
        case '+':
            return x+y;
        case '-':
            return x-y;
        case '*':
            return x*y;
        case '/':
            if(y != 0)
                return x/y;
            else
                printf("zero division error\n");
        default:
            printf("invalid operator\n");
    }
}

float evaluate(ENODE *bst)
{
    if(bst->isOperator == 0)
        return bst->operand;
    else
    {
        float x = evaluate(bst->left);
        float y = evaluate(bst->right);
        return calculate(x,y,bst->operator);
    }
}   */

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  EXPRESSION TREE - USING UNIONS[user defined structure]  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/* #include <stdio.h>
#include <stdlib.h>
#define max 20
typedef struct enode
{
    int utype; // 0 for operator & 1 for operand
    union
    {
        char operator; //+,-,log,,sin,!...
        float operand; // numbers to perform operations on
    }u;
    struct enode *left;
    struct enode *right;
} ENODE;
static int top = -1;

ENODE *temp = NULL;
ENODE *stack[max];

int isDigit(char exp);
void push(ENODE *temp, ENODE *stack[]);
ENODE *pop(ENODE *stack[]);
ENODE *construct(char exp[]);
void inorder(ENODE *bst);
float calculate(float x, float y, char op);
float evaluate(ENODE *bst);

int main()
{
    ENODE *bst;
    char exp[max] = "567*+";
    bst = construct(exp);

    if (bst == NULL)
        printf("unable to construct\n");
    printf("inorder traversal of Expression tree\n");
    inorder(bst);
    printf("\n");
    printf("evaluation of the expression: %f\n", evaluate(bst));
    return 0;
}

int isDigit(char exp)
{
    switch (exp)
    {
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
    case '0':
        return 1;
    default:
        return 0;
    }
}
void push(ENODE *temp, ENODE *stack[])
{
    if (top < max - 1)
        stack[++top] = temp; // to insert the node into top element of stack
    else
        printf("stack is full\n");
}

ENODE *pop(ENODE *stack[])
{
    if (top == -1)
    {
        printf("stack is empty\n");
        return NULL;
    }
    else
        return stack[top--]; // to remove the top most element of the stack
}

ENODE *construct(char exp[])
{
    int i = 0;
    while (exp[i])
    {
        temp = (ENODE *)malloc(sizeof(ENODE));
        if (isDigit(exp[i]))
        {
            temp->utype = 1;
            temp->u.operand = exp[i] - '0'; // gives the integer value of the operand
            temp->left = temp->right = NULL;
            push(temp, stack);
        }
        else
        {
            temp->utype = 2;
            temp->u.operator= exp[i];   // the oparator
            temp->right = pop(stack); // popping the last operands/nodes put into the stack and fixing them to right & left respectively
            temp->left = pop(stack);
            push(temp, stack);
        }
        i++;
    }
    return pop(stack); // this gives put the root of the tree
}

void inorder(ENODE *bst)
{
    if (bst != NULL)
    {
        inorder(bst->left);

        if (bst->utype == 1)
            printf("%f", bst->u.operand);
        else
            printf("%c", bst->u.operator);
        inorder(bst->right);
    }
}

float calculate(float x, float y, char op)
{
    switch (op)
    {
    case '+':
        return x + y;
        break;
    case '-':
        return x - y;
        break;
    case '*':
        return x * y;
        break;
    case '/':
        if (y != 0)
            return x / y;
        else
            printf("zero division error\n");
        break;
    default:
        printf("invalid operator\n");
        break;
    }
}

float evaluate(ENODE *bst)
{
    if (bst->utype == 1)
        return bst->u.operand;
    else
    {
        float x = evaluate(bst->left);
        float y = evaluate(bst->right);
        return calculate(x, y, bst->u.operator);
    }
} */