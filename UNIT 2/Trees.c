// arrays and linked list have linear organisation of data hence random accessing isnt that easy,hence is time consuming
/*so going towards non linear organisation of data = trees
binary trees = data structure having 2 nodes max
topmost element = root
connecting links = edge
the subsets of root = left and right binary trees
every element - node
node having no children = leaf node/external node
node having children = non-leaf node/internal node
ancestors and descendants (70 is ancestor of 60,80,55 and others...60 is descendant of 70)
depth of tree = maximum leaf node to root node(bottom to top)
height of tree = height from top to bottom(from root node to deepest leaf)
depth of node = path length from that node to root
height of node = path length from that node to deepest leaf
degree = max number of nodes linked from that particuular node
strictly binary tree = the tree that has either 0 or 2 nodes from the parent node
full binary tree = each non leaf node having 2 childrem
            total number of nodes = 2^(d-1) -1 [d=depth of tree]
complete binary tree =  all levels are compeletely filled except last level
                        nodes here are filled from left to right
perfect binary tree = all the internal nodes have 2 children
                        all leaf nodes are at same level
                        perfect binary tree will always be a complete and full binary tree but not in all cases
degenerate binary tree =every internal node has only 1 child (left/right skewed binary tree)
                        performance looks exactly like SLL*/

// check out table in dsa unit 2

/* binary search tree = values of nodes of the left child is less than parent node
                        values of nodes of the right child is greater than parent node
                            70
                        __/     \
                        _60      80
                        / \     / \
                        55  68  75 85*/

/* BINARY TREE TRAVERSAL 
1.breadth first 
        1.level order traversal
2. depth first
        1.pre order
        2.in order
        3.post order 
        
preorder = follows the order of
            <root><left tree><right tree>
in order = follows the order of
            <left tree><root><right tree>
post order = follows the order of
            <left tree><right tree><root>*/

/* ordered tree = trees in which subtrees of each node forms an ordered list
N-ary tree = rooted tree in which each node has atmost n children
forest = ordered set of ordered trees */

/* conversion of n-ary tree to binary tree
rules: 1.link all the siblings
        2. delete all links except for leftmost child
left = left child 
right = right sibling  */

//NOT REQUIRED RIGHT NOW
/* #include <stdio.h>
#include <stdlib.h>

typedef struct tnode
{
    int data;
    struct tree *left;
    struct tree *right;
} Tnode;
Tnode *root = NULL;

void insert(int num);                    
int count();
int cnt();
void main()
{

    int ch, num, k, n;
    while (1)
    {
        printf("\n1.Insert");
        printf("\n2.No. of nodes");
        printf("\n3..recursively insert..");
        printf("\n4.find smallest");
        printf("\n5.find largest");
        printf("\n6..exit");
        printf("\nEnter the choice:\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter the element:");
            scanf("%d", &num);
            insert(num);
            break;
        case 2:
            k = count();
            printf("\nthe number of nodes=%d", k);
            break;
        /* case 3:
            printf("\nEnter the element");
            scanf("%d", &num);
            rinsert_t(num);
            break;
        case 4:
            n = minimum();
            printf("\nThe smallest element = %d\n", n);
            break;
        case 5:
            n = maximum();
            printf("\nthe largest element = %d\n", n);
            break; 
        case 6:
            exit(0);
        }
    }
}

Tnode *getnode(int data) // function to create a new node
{
    Tnode *temp = (Tnode *)malloc(sizeof(Tnode));
    temp->data = data;
    temp->left = temp->right = NULL;

}


void insert(int num)
{
    Tnode *temp = (Tnode *)getnode(num);
    
    Tnode *curr, *prev;
    curr = root;
    prev = NULL;
    if (curr == NULL)
        root = temp;
    else
    {
        while (curr != NULL)
        {
            if (curr->data > temp->data)
                curr = curr->left;
            else
                curr = curr->right;
        }
        if(curr->data > temp->data )
            curr->left = temp;
        else
            curr->right = temp;
    }
}

int count()
{
    int n=0;
    n = cnt(root);
    return n;
}

int cnt(Tnode *root)
{
    if(root == NULL)
        return 0;
    if(root->left == NULL && root->right == NULL)
        return 1;
    int l=cnt(root->left);
    int r=cnt(root->right);
    return (1+l+r);
} */