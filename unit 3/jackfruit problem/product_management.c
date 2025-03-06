#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ProductNode {
    char id[50];
    char data[100];
    struct ProductNode *next;
} PNODE;

PNODE *product_table[100] = {NULL};

int hash_product(char *key) {
    int hash = 0;
    while (*key) {
        hash = (hash + *key++) % 100;
    }
    return hash;
}

void add_product(char *product_id, char *product_data) {
    int i = hash_product(product_id);
    PNODE *nn = (PNODE *)malloc(sizeof(PNODE));
    strcpy(nn->id, product_id);
    strcpy(nn->data, product_data);
    nn->next = product_table[i];
    product_table[i] = nn;
}

char *get_product(char *product_id) {
    int i = hash_product(product_id);
    PNODE *temp = product_table[i];
    while (temp) {
        if (strcmp(temp->id, product_id) == 0)
            return temp->data;
        temp = temp->next;
    }
    return NULL;
}

void update_product(char *product_id, char *product_data) {
    int i = hash_product(product_id);
    PNODE *temp = product_table[i];
    while (temp) {
        if (strcmp(temp->id, product_id) == 0) {
            strcpy(temp->data, product_data);
            return;
        }
        temp = temp->next;
    }
}
