#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct UserNode {
    char id[50];
    char info[100];
    struct UserNode *next;
} Node;

Node *user_table[100] = {NULL};

int hash_user(char *key) {
    int hash = 0;
    while (*key)
        hash = (hash + *key++) % 100;
    return hash;
}

void add_user(char *user_id, char *user_info) {
    int i = hash_user(user_id);
    Node *nn = (Node *)malloc(sizeof(Node));
    strcpy(nn->id, user_id);
    strcpy(nn->info, user_info);
    nn->next = user_table[i];
    user_table[i] = nn;
}

char *get_user(char *user_id) {
    int i = hash_user(user_id);
    Node *pres = user_table[i];
    while (pres) {
        if (strcmp(pres->id, user_id) == 0)
            return pres->info;
        pres = pres->next;
    }
    return NULL;
}

void update_user(char *user_id, char *user_info) {
    int i = hash_user(user_id);
    Node *pres = user_table[i];
    while (pres) {
        if (strcmp(pres->id, user_id) == 0) {
            strcpy(pres->info, user_info);
            return;
        }
        pres = pres->next;
    }
}
