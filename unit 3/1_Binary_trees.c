/* binary search tree
-> minimum elements -left side(value less than node)
-> maximum elements -right side(value greater than node)

implementation of binary tree   [all of them can be performed with both iteration & recurrsion]
1. insertion(level order insertion)
2. searching
3. count of nodes
4. height
5. finding the minimum node
6. finding the maximum node

implementation of binary search tree
1. insertion(level order insertion)   -- have different way of implementation logic
2. searching     -- have different way of implementation logic
3. count of nodes
4. height
5. finding the minimum node
6. finding the maximum node 
                        1
                    ___/ \
                    __2___3
                    _/ \   \
                    _4  5     6
                    /   /    / \
                    7   8   9   10
                    /       \     
                    11      12
*/

/* binary search tree creation:
using numbers 15,10,20,5,12,17,25,3,8,18,30,2,28

                                15
                            ___/  \
                            _10    20
                            /  \   / \
                        ___5   12  17  25
                        __/ \       \   \
                        _3   8      18   30
                        /                 /
                        2                28 
if i have to place 9 now....then?
place 9 to the right of 8
if i have to place 21 now....then?
place 21 to the left of 25
***if any duplicates found --put it onto left */


// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ BINARY TREE - ARRAY IMPLEMENTATION ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/* start from the root and fill the array level by level ensuring to fill it from left to right
                A
            ___/ \
            __B    C
            _/ \  / \
            D   E F  G
        ___/ \
        __H   I

array implementation of 1st tree given above ==  A  B   C  D    E   F   G   H   I
formula =  node @ ith index  .. WORKS ONLY ON COMPLETE BINARY TREE
        --> left child == (2*i)+1
        --> right child == (2*i)+2
        --> parent = floor[(i-1)/2]
IF NOT A COMPLETE BINARY TREE THEN,
fill the empty nodes with null in array
                A
            ___/ \
            __B    C
            _/ \  / \
            D   E F  G
            ___/ \
            __H   I
array implementation = A    B   C   D   E   F   G   _   _   H   I*/


/* #include<stdio.h>
#include<stdlib.h>
#define size 25

int array[size];
//functions to be implemented
void root(int ch);
void set_left(int ch, int parent);  //index of parent is given
void set_right(int ch, int parent);
void print_tree();

int main()
{
    root(5);
    set_left(7,0);
    set_right(2,0);
    set_left(8,1);
    set_right(10,1);
    set_left(11,2);
    set_right(12,2);
    set_left(15,4);
    set_right(16,4);
    set_left(18,6);
    printf("the tree made is: \n");
    print_tree();
}
void root(int ch)
{
    if(array[0] != 0)
        printf("root element already exists\n");
    else
        array[0] = ch;
}

void set_left(int ch, int parent)
{
    if(array[parent] == 0)
        printf("the parent node does not exist\n");
    else
        array[(2*parent)+1] = ch;
}

void set_right(int ch, int parent)
{
    if(array[parent] == 0)
        printf("the parent node does not exist\n");
    else
        array[(2*parent)+2] = ch;
}

void print_tree()
{
    for(int i=0;i<size;i++)
    {
        if(array[i] != 0)
            printf("%d",array[i]);
        else
            printf("_");
    }
} */



// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ BINARY TREE - LINKED LIST IMPLEMENTATION ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//using double linked list
//see notes for how it looks(JSP notes)

/* #include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
}NODE;

NODE *root = NULL;   

//FUNCTION TO COUNT THE NUMBER OF NODES RECURRSIVELY
int count(NODE *root)
{
    if(root == NULL)
        return 0;
    return 1+count(root->left)+count(root->right);
}
void inorder(NODE *root)   //<left><root><right>
{
    inorder(root->left);
    printf("%d",root->data);
    inorder(root->right);

}

void preorder(NODE *root)   //<root><left><right>
{
    printf("%d",root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(NODE *root)  //<left><right><root>
{
    postorder(root->left);
    postorder(root->right);
    printf("%d",root->data);
}

int height(NODE *root)
{
    if (root == NULL)
        return -1;
    int l = height(root->left);
    int r = height(root->right);
    if(l>r)
        return 1+l;
    else
        return 1+r;
}

int no_of_leaf_nodes(NODE *root)
{
    if(root == NULL)
        return 0;
    if(root->left == NULL && root->right == NULL)
        return 1;
    return no_of_leaf_nodes(root->left) + no_of_leaf_nodes(root->right);
} */