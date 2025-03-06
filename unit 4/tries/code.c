#include <stdio.h>
#include <stdlib.h>

typedef struct trie
{
    struct trie *child[255]; // Array of m pointers for possible values of m
    int eos;                 // End-of-string flag to mark the end of a word
}Trie;

//stack for deletion purpose
typedef struct stack
{
    struct trie *node; 
    int index;         // Character index for backtracking during deletion
}Stack;
Stack *STACK[30];      // Stack to store Trie nodes and their indices for deletion

char output[30];       // Array to store current word during traversal (for display)
int len = 0, top = -1;



void main()
{
    Trie *root = createNode(); 
    int ch;
    char word[30];
    
    do
    {
        printf("\nEnter your choice 1.Insert 2.Display 3.Search 4. Delete 5.exit:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter the word to be inserted:");
            scanf("%s", word);
            insertWord(word, root); 
            break;
        case 2:
            len = 0;
            display(root); 
            break;
        case 3:
            printf("\nEnter the word to be searched:");
            scanf("%s", word);
            search(word, root);
            break;
        case 4:
            printf("\nEnter the word to be deleted:");
            scanf("%s", word);
            deleteData(word, root);
            break;
        default:
            return; 
        }
    } while (ch); 
}

void push(Trie *t, int index)
{
    Stack *nn = (Stack *)malloc(sizeof(Stack)); 
    nn->node = t;
    nn->index = index;
    STACK[++top] = nn; 
}

Stack *pop()
{
    return STACK[top--]; 
}

int ChildCount(Trie *t)
{
    int count = 0;
    for (int i = 0; i < 256; i++) 
    {
        if (t->child[i] != NULL) // If child node exists, increment count
            count++;
    }
    return count;
}

Trie *createNode()
{
    Trie *nn = (Trie *)malloc(sizeof(Trie));
    for (int i = 0; i < 255; i++)      
        nn->child[i] = NULL;
    nn->eos = 0; 
    return nn;
}


void insertWord(char *word, Trie *root)
{
    int index;
    Trie *temp = root;  //temporary trie node
    for (int i = 0; word[i] != '\0'; i++) 
    {
        index = word[i]-'0';             // Use ASCII value as index 
        if (temp->child[index] == NULL) // If no node exists for this character, create one
            temp->child[index] = createNode();
        temp = temp->child[index]; // Move to the child node
    }
    temp->eos = 1; 
}

void display(Trie *root)
{
    Trie *t = root;
    for (int i = 0; i < 255; i++) 
    {
        if (t->child[i] != NULL) // If a child node exists
        {
            output[len++] = i;       //keeps track of current word being formatted in golobal array output   
            if (t->child[i]->eos == 1) // If this node marks the end of a word, print the word
            {
                printf("\n");
                for (int j = 0; j < len; j++)
                    printf("%c", output[j]);
            }
            display(t->child[i]); // Recursively display words starting from this node
        }
    }
    len--; // Backtrack to previous character after traversing child nodes
    return;
}


void search(char *word, Trie *root)
{
    int index;
    Trie *t = root;
    for (int i = 0; word[i] != '\0'; i++) // Traverse each character in the word
    {
        index = word[i];
        if (t->child[index] == NULL) // If character path doesn't exist, word is not found
        {
            printf("\nData not found");
            return;
        }
        t = t->child[index]; // Move to the next child node
    }
    if (t->eos == 1) // If end-of-string flag is set, word is found
        printf("\nData found");
    else
        printf("\nData not found"); // If end-of-string flag is not set, word does not exist
    return;
}

void deleteData(char *word, Trie *root)
{
    int index;
    Stack *s;
    Trie *t = root;
    for (int i = 0; word[i] != '\0'; i++) // Traverse each character in the word
    {
        index = word[i];
        if (t->child[index] == NULL) // If character path doesn't exist, word not found
        {
            printf("\nData not found");
            return;
        }
        push(t, index);      // Push the node and index to stack for backtracking
        t = t->child[index]; // Move to the child node
    }
    t->eos = 0; // Unset end-of-string to "remove" word

    if (ChildCount(t) >= 1) // If node has children, stop deletion here
        return;
    else // If no children, backtrack and delete nodes
    {
        s = pop(); // Get last visited node and index
        t = s->node;
        index = s->index;
        while (ChildCount(t) <= 1 && t->eos == 0) // Delete nodes until a branch or another word is encountered
        {
            free(t->child[index]);  // Free the child node
            t->child[index] = NULL; // Set pointer to NULL to remove reference
            s = pop();              // Move back to the previous node and repeat if necessary
            t = s->node;
            index = s->index;
        }
    }
}
