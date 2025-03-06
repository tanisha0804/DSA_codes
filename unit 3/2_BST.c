//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~    BST-ARRAY IMPLEMENTATION ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/* #include <stdio.h>
#include <stdlib.h>
#define size 30
typedef struct tree
{
    int data;
    int flag;
} NODE;

void insert(NODE *bst, int data, int index);
void inorder(NODE *bst,int index);
void preorder(NODE *bst, int index);
void postorder(NODE *bst,int index);
void print(NODE *bst);
int main()
{
    printf("inserting the BST\n");
    NODE bst[size] = {};
    int data, ch;
    do
    {
        printf("enter the data to be inserted\n");
        scanf("%d", &data);
        insert(bst, data, 0);
        printf("press 1 to continue\n");
        scanf("%d", &ch);
    } while (ch == 1);
    print(bst);
    inorder(bst,0);
    preorder(bst,0);
    postorder(bst,0);
}
void insert(NODE *bst, int data, int index)
{
    if (bst[index].flag == 0 && index < size) // inserting root first & also incrementing the flag to 1
    {
        bst[index].data = data;
        bst[index].flag = 1;
    }

    else if (data < bst[index].data && index < size) // inserting as left child
    {
        index = 2 * index + 1; // increment the index and again pass it to same function so that the flag gets incremented to 1
        insert(bst, data, index);
    }

    else if (data > bst[index].data && index < size) // inserting as right child
    {
        index = 2 * index + 2; // increment the index and again pass it to same function so that the flag gets incremented to 1
        insert(bst, data, index);
    }
    else
    {
        printf("element cant be inserted in the array\n");
    }
}

void inorder(NODE *bst, int index)
{
    if (bst[index].flag == 1 && index < size)
    {
        inorder(bst, ((2 * index) + 1)); // left child
        printf("%d  ", bst[index].data);  //root node
        inorder(bst, ((2 * index) + 2));  //right child
    }
    printf("\n");
}

void preorder(NODE *bst, int index)
{
    if (bst[index].flag == 1 && index < size)
    {
        printf("%d  ", bst[index].data);  //root node
        preorder(bst, ((2 * index) + 1)); // left child
        preorder(bst, ((2 * index) + 2));  //right child
    }
    printf("\n");
}

void postorder(NODE *bst,int index)
{
    if(bst[index].flag == 1 && index < size)
    {
        postorder(bst,((2*index)+1));
        postorder(bst,((2*index)+2));
        printf("%d  ",bst[index].data);
    }
    printf("\n");
}
void print(NODE *bst)
{
    if (bst[0].flag == 0)
    {
        printf("tree isnt existing");
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            if (bst[i].flag == 0)
                printf("_  ");
            else
                printf("%d  ", bst[i].data);
        }
    }
    printf("\n");
} */

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~    BST-LL IMPLEMENTATION   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include <stdio.h>
#include <stdlib.h>

typedef struct tnode
{
    int data;
    struct tnode *left;
    struct tnode *right;
} TNODE;

TNODE *root = NULL;

TNODE *createnode(int data);
void insert(int);
TNODE *rinsert(TNODE *root, int data);
void inorder(TNODE *root);
void preorder(TNODE *root);
void postorder(TNODE *root);
int count(TNODE *root);
int leafcount(TNODE *root);
int height(TNODE *root);
int search(int);
int rsearch(TNODE *root, int);
int minimum();
int maximum();
void delete(int);
TNODE *rdelete(TNODE *root,int);

void main()
{
    int ch, num, k, n;
    while (1)
    {
        printf("\n1.Insert\n2.Preorder\n3.Postorder\n4.Inorder\n5.recurrsive insert\n");
        printf("\n6.No. of nodes\n7.No. of Leaf nodes\n8.Height of a tree\n");
        printf("\n9.search\n10.recurrsively search\n11.Delete a node\n12.Recursively delete\n");
        printf("13.Find smallest\n14.Find largest\n15.Exit\n"); 
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter the element: ");
            scanf("%d", &num);
            insert(num);
            break;
        case 2:
            preorder(root);
            break;
        case 3:
            postorder(root);
            break;
        case 4:
            inorder(root);
            break;
        case 5:
            printf("Enter the element: ");
            scanf("%d", &num);
            root = rinsert(root, num);
            break;
        case 6:
            k = count(root);
            printf("\nThe number of nodes = %d", k);
            break;
        case 7:
            k = leafcount(root);
            printf("\nThe number of leaf nodes = %d", k);
            break;
        case 8:
            k = height(root);
            printf("\nThe height of the tree = %d", k);
            break;
        case 9:
            printf("Enter the element to search: ");
            scanf("%d", &num);
            k = search(num);
            if (k)
                printf("Key found\n");
            else
                printf("Not found\n");
            break;
        case 10:
            printf("Enter the element to recursively search: ");
            scanf("%d", &num);
            k = rsearch(root, num);
            if (k)
                printf("Key found\n");
            else
                printf("Not found\n");
            break;
        case 11:
            printf("Enter the element to be deleted: ");
            scanf("%d", &num);
            delete(num);
            break;
        case 12:
            printf("Enter the element to be recursively deleted: ");
            scanf("%d", &num);
            root = rdelete(root,num);
            break;
        case 13:
            n = minimum();
            printf("\nThe smallest element = %d\n", n);
            break;
        case 14:
            n = maximum();
            printf("\nThe largest element = %d\n", n);
            break;
        case 15:
            exit(0);
        }
    }
}
TNODE *createnode(int data)
{    TNODE *temp = (TNODE *)malloc(sizeof(TNODE));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
void insert(int data)
{
    TNODE *curr = root;
    TNODE *prev = NULL;
    TNODE *temp = createnode(data);
    if (curr == NULL)
        root = temp;
    else
    {
        while (curr != NULL)
        {
            prev = curr; // to take up the place where next node is to be added
            if (data < curr->data)
                curr = curr->left;
            else
                curr = curr->right;
        }
        if (data < prev->data) // prev = parent node to which the element is added either in left or right
            prev->left = temp;
        else
            prev->right = temp;
    }
}

TNODE *rinsert(TNODE *root, int data)
{
    if (root == NULL)
    {
        TNODE *temp = createnode(data);
        return temp;
    }
    if (data < root->data)
        root->left = rinsert(root->left, data);
    else
        root->right = rinsert(root->right, data);
    return root;
}

void inorder(TNODE *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d  ", root->data);
        inorder(root->right);
    }
}

void preorder(TNODE *root)
{
    if (root != NULL)
    {
        printf("%d  ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(TNODE *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d  ", root->data);
    }
}

int count(TNODE *root)
{
    if (root == NULL)
        return 0;
    return 1 + count(root->left) + count(root->right);
}

int leafcount(TNODE *root)
{
    if (root == NULL)
        return 0;
    while (root->left == NULL && root->right == NULL)
        return 1;
    return leafcount(root->left) + leafcount(root->right);
}

int height(TNODE *root)
{
    if (root == NULL)
        return 0;
    int l = height(root->left);
    int r = height(root->right);
    return (l > r ? l : r) + 1;
}

int search(int data)
{
    if (root == NULL)
        return 0;
    while (root != NULL)
    {
        if (data == root->data)
            return 1;
        else if (data > root->data)
            root = root->right;
        else if (data < root->data)
            root = root->left;
    }
}

int rsearch(TNODE *root, int data)
{
    if (root == NULL)
        return 0;
    if (data == root->data)
        return 1;
    if (data > root->data)
        return rsearch(root->right, data);
    if (data < root->data)
        return rsearch(root->left, data);
}

int minimum() // the leftmost element is the smallest
{
    if (root == NULL)
    {
        printf("empty tree\n");
        return -1;
    }
    while (root->left != NULL)
        root = root->left;
    return root->data;
}

int maximum() // the rightmost element is the smallest
{
    if (root == NULL)
    {
        printf("empty tree\n");
        return -1;
    }
    while (root->right != NULL)
        root = root->right;
    return root->data;
}

void delete(int data)   //did not understand
{
    if (root == NULL)
        printf("the tree is empty\n");
    TNODE *curr = root;
    TNODE *prev = NULL;
    TNODE *temp, *p, *q;

    while (curr != NULL && data != curr->data) // to find the postion of element to be deleted
    {
        prev = curr;
        if (data > curr->data)
            curr = curr->right;
        else
            curr = curr->left;
    }

    if (curr == NULL)
        printf("data not found in tree\n");

    // if the tree has atmost 1 children
    if (curr->left == NULL || curr->right == NULL)
    {
        q = (curr->left == NULL) ? curr->right : curr->left; // q = the element;s children

        if (prev == NULL)
            root = q;
        else if (curr == prev->left)
            prev->left = q;
        else
            prev->right = q;
        free(curr);
    }
    else   //performing inorder successor - replacing the node with the minimum element of the right sub tree
    { // to find smallest element of the right side
        p = NULL;
        temp = curr->right;   // temp points to right element of the node curr
        while (temp->left != NULL)  // to go to the leftmost number(smallest number) of the right sub tree
        {
            p = temp;
            temp = temp->left;
        }
        curr->data = temp->data;  // replace curr-> data with temp->data

        if (p != NULL)    
            p->left = temp->right;
        else
            curr->right = temp->right;

        free(temp);
    }
}

TNODE*  rdelete(TNODE *root,int num)  //ask maam to explain
{
    if(root == NULL)
        printf("empty tree\n");
    if(num > root->data)
        root->right = rdelete(root->right,num);
    else if (num < root->data)
        root->left = rdelete(root->left,num);
    else
    {
        //case 1 -> no chilldren
        if(root->left == NULL && root->right == NULL)
        {
            free(root);
            root=NULL;
        }
        //case 2-> left child exists
        else if(root->right == NULL)
        {
            TNODE *temp = root;
            root = root->left;
            free(temp);
        }
        //case 2-> right child exists
        else if(root->left == NULL)
        {
            TNODE *temp = root;
            root = root->right;
            free(temp);
        }

    //case 3 -> both choldren exists
        else
        {
            TNODE *temp = minimum(root->right);
            root->data = temp->data;
            root->right = rdelete(root->right,temp->data);
        }
    }
    return root;
}


