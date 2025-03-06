/* THREADED BINARY TREE - inorder fashion efficient search
variant of BT where the null pointers are replaced with THREADS
these threads allows a tree to be traversed efficiently in an INORDER fashion without requiring a stack or recursion

main purpose = traversal is faster
                less memory intrusive

instead of setting L & R  pointer to NULL,they are used to point to ->
    left pointer = inorder predecessor
    right pointer = inorder successor

types -->
1. single threaded BT
-> only 1 pointer replaced by threads (L | R)
        ->left threaded BT
                - left pointer pointing to inorder predecessor
        ->right threaded BT
                - right pointer pointing to inorder successor 
                
                
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
find the inorder traversal and the left threaded BT threads
                            A
                        ___/ \
                        __B    C
                        _/ \  / \
                        D   E F  G    
INORDER =  DBEAFCG
LEFT threaded BT   =    left link of G pointing to C
                        left link of F pointing to A
                        left link of E pointing to B
    TABULAR COLUMN
    
    NODE                D   E   F   G
    INORDER POINTER     -   B   A   C   

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
find inorder traversal and right threaded BT threads
                                F
                            ___/ \
                            __B   G
                            _/ \   \
                            A   D   I
                            ___/ \  /
                            __C  E  H
INORDER = ABCDEFGHI
RIGHT threaded BT =     right link of A pointing to B
                        right link of C pointing to D
                        right link of E pointing to F
                        right link of H pointing to I

find the inorder traversal and the RIGHT threaded BT threads
                            A
                        ___/ \
                        __B    C
                        _/ \  / \
                        D   E F  G    
INORDER =  DBEAFCG
RIGHT threaded BT   =   RIGHT link of D pointing to B
                        RIGHT link of E pointing to A
                        RIGHT link of F pointing to C
    TABULAR COLUMN
    
    NODE                D   E   F   G
    INORDER POINTER     B   A   C   -

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
2.DOUBLE THREADED BT
        - left pointer = inorder predecessor
        - right pointer = inorder successor

                            A
                        ___/ \
                        __B    C
                        _/ \  / \
                        D   E F  G    
INORDER =  DBEAFCG

double threaded BT =    RIGHT link of D pointing to B
                        RIGHT link of E pointing to A
                        RIGHT link of F pointing to C
                        LEFT link of G pointing to C
                        LEFT link of F pointing to A
                        LEFT link of E pointing to B

usage of flags - left flag and right flag
flag = 0 if it points to some node
flag = 1 if it doesnt point anywhere (NULL)

*/

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~    RIGHT THREADED BINARY TREE  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~`
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *Llink;
    struct node *Rlink;
    int lthread,rthread;   // gives 1 if there is a thread and 0 if it has a child
}NODE;

NODE *root = NULL;

NODE *createnode(int data);
NODE *insert_node(int data);
NODE *inorder_sucessor(NODE *t);
void inorder();
int main()
{
    int data,ch;
    do
    {
        printf("enter the data to be inserted\n");
        scanf("%d",&data);
        root = insert_node(data);
        printf("press 1 to continue\n");
        scanf("%d",&ch);
    } while (ch == 1);

    printf("inorder traversal using TBST\n");
    inorder();
    printf("\n");
    
    return 0;
}

NODE *createnode(int data)
{
    NODE *temp = (NODE *)malloc(sizeof(NODE));
    temp->data = data;
    temp->Llink = temp->Rlink = NULL;
    temp->lthread = temp->rthread = 1;  //threads present by default
    return temp;
}

NODE *insert_node(int data)
{
    NODE *p = root; 
    NODE *parent = NULL;
    NODE* temp = createnode(data);

    if(root == NULL)
    {
        root = temp;
        return root;
    } 

    while(p != NULL)
    {
        parent = p;
        if(data < p->data)
        {
            if(p->lthread == 0)
                p = p->Llink;
            else
                break;
        }
        else if (data > p->data)
        {
            if(p->rthread == 0)
                p = p->Rlink;
            else
                break;
        }
        else
        {
            printf("duplicat key\n");
            return root;
        }
    }

    if(data < parent->data)
    {
        temp->Llink = parent->Llink;    //inorder predecessor
        temp->Rlink = parent;           // inorder successor
        parent->Llink = temp;
        parent->lthread = 0;            // left child of the parent exists
    }
    else
    {
        temp->Llink = parent;
        temp->Rlink = parent->Rlink;
        parent->Rlink = temp;
        parent->rthread = 0; 
    }
}

NODE *inorder_sucessor(NODE *t)
{
    if(t->rthread == 1)
        return t->Rlink;
    t = t->Rlink;
    while(t->lthread == 1)
        t = t->Llink;

    return t;
}

void inorder()
{
    if(root == NULL)
        printf("empty tree\n");

    NODE *p = root;    
    while(p->lthread == 0)   //travel to leftmost root
        p = p->Llink;

    while(p != NULL)
    {
        printf("%d", p->data);
        p = inorder_sucessor(p);
    }
}

