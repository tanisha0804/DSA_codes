//  performing preorder, inorder, and postorder traversals using an iterative approach (with the help of stacks).
/*
                                15
                            ___/  \
                            _10    20
                            /  \   / \
                        ___5   12 17  25
                        __/ \      \   \
                        _3   8     18   30
                        /               /
                        2              28
inorder = 2,3,5,8,10,12,15,17,18,20,28,30,25
*/
#include <stdio.h>
#include <stdlib.h>
#define max 100

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} NODE;

typedef struct stack
{
    NODE *stack[max];
    int top;
} STACK;

NODE *root = NULL;

void push(NODE *n, STACK *s);
NODE *pop(STACK *s);
NODE *createnode(int data);
NODE *insert_node(NODE *n, int data);
void inorder(NODE *t);
void preorder(NODE *t);
void postorder(NODE *t);

int main()
{
    int n, d;
    printf("enter the number of nodes\n");
    scanf("%d", &n);
    printf("enter the data\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &d);
        root = insert_node(root, d);
    }

    printf("inorder traversal\n");
    inorder(root);
    return 0;
}

void push(NODE *n, STACK *s)
{
    if (s->top == max - 1)
        printf("stack overloaded\n");
    else
        s->stack[++(s->top)] = n;
}

NODE *pop(STACK *s)
{
    if (s->top == -1)
    {
        printf("empty stack\n");
        return NULL;
    }
    else
    {
        return s->stack[s->top--];
    }
}

NODE *createnode(int data)
{
    NODE *temp = (NODE *)malloc(sizeof(NODE));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

NODE *insert_node(NODE *n, int data)
{
    if (n == NULL)
        n = createnode(data);
    else if (data < n->data)
        n->left = insert_node(n->left, data);
    else
        n->right = insert_node(n->right, data);
    return n;
}

void inorder(NODE *t)
{
    if (t == NULL)
    {
        printf("the tree is empty\n");
        return;
    }
    STACK *s = (STACK *)malloc(sizeof(STACK));
    s->top = -1;

    NODE *temp = t; // temporary node

    while (temp != NULL || s->top != -1)
    {
        while (temp != NULL)
        {
            push(temp, s);
            temp = temp->left; // pushing all the left elements onto stack
        }

        temp = pop(s);
        if (temp != NULL)
        {
            printf("%d\t", temp->data);
            temp = temp->right;
        }
    }
    free(s);
}

void preorder (NODE *t)  //preorder = root,left,right ->print root first then put right into stack then left into stack so while popping it would be root left right
{
    if( t == NULL)
    {
        printf("empty tree\n");
        return;
    }

    STACK *s = (STACK *)malloc(sizeof(STACK));
    s->top = -1;
    NODE *temp = t;
    push(t,s);

    while(s->top != -1)
    {
        temp = pop(s);
        printf("%d\t",temp->data);

        if(temp->right != NULL)
            push(temp->right,s);
        if(temp->left != NULL)
            push(temp->left,s);
    }
    free(s);
}

void postorder(NODE *t)
{
    if(t == NULL)
    {
        printf("the tree is empty\n");
        return;
    }

    STACK *s1 = (STACK *)malloc(sizeof(STACK));
    STACK *s2 = (STACK *)malloc(sizeof(STACK));
    s1->top = -1;
    s2->top = -1;

    NODE *temp = t;
    push(t,s1);

    while(s1->top != -1)
    {
        temp = pop(s1);
        push(temp,s2);
        if(temp->left != NULL)
            push(temp->left,s1);
        if(temp->right != NULL)
            push(temp->right,s1);
    }

    while(s2->top != -1)
    {
        temp = pop(s2);
        printf("%d\t",temp->data);

    }
    free(s1);
    free(s2);

}

