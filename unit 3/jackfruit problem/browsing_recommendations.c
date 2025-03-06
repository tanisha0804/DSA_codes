#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 50

typedef struct Node {
    char key[max];   // unique id for every browsing and purchasing - easier to recommend
    char type[max]; //  whether its browsing or purchasing
    char user[max];
    char product[max];
    struct Node *left;
    struct Node *right;
} NODE;

NODE *create_node(char *key, char *type, char *user, char *product) {
    NODE *temp = (NODE *)malloc(sizeof(NODE));
    strcpy(temp->key, key);
    strcpy(temp->type, type);
    strcpy(temp->user, user);
    strcpy(temp->product, product);
    temp->left = temp->right = NULL;
    return temp;
}

NODE *insert_node(NODE *root, char *key, char *type, char *user, char *product)   // implementing  BST
{
    if (root == NULL)
        return create_node(key, type, user, product);

    if (strcmp(key, root->key) < 0)
        root->left = insert_node(root->left, key, type, user, product);
    else if (strcmp(key, root->key) > 0)
        root->right = insert_node(root->right, key, type, user, product);

    return root;
}

NODE *browsing(NODE *root, char *user, char *product) 
{
    char key[max];
    snprintf(key, max, "%s_%s", user, product);  // Create a unique key based on user and product
    printf("%s browsing %s\n", user, product);
    return insert_node(root, key, "browsing", user, product);
}

NODE *purchasing(NODE *root, char *user, char *product) 
{
    char key[max];
    snprintf(key, max, "%s_%s", user, product);  // Create a unique key based on user and product
    printf("%s purchase %s\n", user, product);
    return insert_node(root, key, "purchase", user, product);
}


void user_history(NODE *root, char *user) 
{
    if (root != NULL) 
    {
        user_history(root->left, user);
        if (strcmp(root->user, user) == 0)
            printf("Type: %s, Product: %s\n", root->type, root->product);
        user_history(root->right, user);
    }
}

void collect_data(NODE *root, const char *user, char viewed[][max], int *v_index, char purchased[][max], int *p_index) 
{
    if (root) 
    {
        collect_data(root->left, user, viewed, v_index, purchased, p_index);
        if (strcmp(root->user, user) == 0) 
        {
            if (strcmp(root->type, "browsing") == 0)
                strcpy(viewed[(*v_index)++], root->product);
            else if (strcmp(root->type, "purchase") == 0)
                strcpy(purchased[(*p_index)++], root->product);
        }
        collect_data(root->right, user, viewed, v_index, purchased, p_index);
    }
}

void generate_recommendations(NODE *root, const char *user) 
{
    char viewed[max][max], purchased[max][max];
    int v_index = 0, p_index = 0;

    collect_data(root, user, viewed, &v_index, purchased, &p_index);

    printf("\nRecommendations for %s:\n", user);
    for (int i = 0; i < v_index; i++) {
        int isPurchased = 0;
        for (int j = 0; j < p_index; j++) {
            if (strcmp(viewed[i], purchased[j]) == 0) {
                isPurchased = 1;
                break;
            }
        }
        if (!isPurchased)
            printf("%s\n", viewed[i]);
    }
}
