#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *link;
} NODE;

typedef struct {
    NODE *head;
} LIST;

void init_list(LIST *l);
void create_list(LIST *l);
void insert_order(LIST *l, int data);
void display(LIST *l);
void merge_list(LIST *l1, LIST *l2, LIST *mer);
void insert_tail(LIST *l, int data);

int main() {
    LIST l1, l2, l3;
    init_list(&l1);
    init_list(&l2);
    init_list(&l3);

    printf("ENTER LIST 1.....\n");
    create_list(&l1);
    display(&l1);

    printf("ENTER LIST 2.....\n");
    create_list(&l2);
    display(&l2);

    merge_list(&l1, &l2, &l3);
    printf("MERGED LIST.....\n");
    display(&l3);

    return 0;
}

void init_list(LIST *l) {
    l->head = NULL;
}

void create_list(LIST *l) {
    int x;
    while (1) {
        printf("enter the element (enter 0 to stop):\n");
        scanf("%d", &x);
        if (x == 0)
            break;
        insert_order(l, x);
    }
}

void insert_order(LIST *l, int data) {
    NODE *temp = (NODE *)malloc(sizeof(NODE));
    temp->data = data;
    temp->link = NULL;

    NODE *prev = NULL, *pres = l->head;

    while (pres != NULL && data > pres->data) {
        prev = pres;
        pres = pres->link;
    }

    if (prev == NULL) {
        temp->link = l->head;
        l->head = temp;
    } else {
        temp->link = pres;
        prev->link = temp;
    }
}

void display(LIST *l) {
    NODE *p = l->head;
    if (p == NULL) {
        printf("empty list\n");
    } else {
        while (p != NULL) {
            printf("%d --> ", p->data);
            p = p->link;
        }
    }
    printf("NULL\n");
}

void merge_list(LIST *l1, LIST *l2, LIST *mer) {
    NODE *p = l1->head, *q = l2->head;

    while (p != NULL && q != NULL) {
        if (p->data < q->data) {
            insert_tail(mer, p->data);
            p = p->link;
        } else {
            insert_tail(mer, q->data);
            q = q->link;
        }
    }

    while (p != NULL) {
        insert_tail(mer, p->data);
        p = p->link;
    }

    while (q != NULL) {
        insert_tail(mer, q->data);
        q = q->link;
    }
}

void insert_tail(LIST *l, int data) {
    NODE *temp = (NODE *)malloc(sizeof(NODE));
    temp->data = data;
    temp->link = NULL;

    if (l->head == NULL) {
        l->head = temp;
    } else {
        NODE *p = l->head;
        while (p->link != NULL) {
            p = p->link;
        }
        p->link = temp;
    }
}





//requirement of 3 LL
/* 2 LL to be filled by user and program to merge the lists in ascending order into LL3
need two structures
1. normal node structure
2. list structure containing head; 

functions required
void init_list(LIST *l);
void create_list(LIST *l);
void insert_order(LIST *l, int data);
void display(LIST *l);
void merge_list(LIST *l1, LIST *l2, LIST *mer);
void insert_tail(LIST *l, int data);*/


