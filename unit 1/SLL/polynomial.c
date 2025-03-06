#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int coeff;
    int px;
    int py;
    int flag;
    struct node *link;
} NODE;

typedef struct list
{
    struct node *head;
} LIST;

void init_list(LIST *l)
{
    l->head = NULL;
}

void create_poly(LIST *p);
void insert_poly(LIST *l, int coeff, int px, int py);
void display(LIST *l);
void add(LIST *l1, LIST *l2, LIST *l3);
void append_poly(LIST *l1, LIST *l2, LIST *l3);
int main()
{
    LIST p1, p2, p3;
    init_list(&p1);
    init_list(&p2);
    init_list(&p3);
    printf("enter the elements of 1st polynomial\n");
    create_poly(&p1);
    printf("polynomial 1:\n");
    display(&p1);
    printf("enter the elements of 2nd polynomial\n");
    create_poly(&p2);
    printf("polynomial 2:\n");
    display(&p2);
    add(&p1,&p2,&p3);
    append_poly(&p1,&p2,&p3);
    printf("the final LL after adding p1 and p2\n");
    display(&p3);

}

void create_poly(LIST *p)
{
    while (1)
    {
        int coeff;
        int px;
        int py;
        printf("enter the coeff of the term\n");
        printf("enter 0 to exit\n");
        scanf("%d", &coeff);
        if (coeff == 0)
            break;
        printf("enter the powers of x and y\n");
        scanf("%d %d", &px, &py);
        insert_poly(p, coeff, px, py);
    }
}
void insert_poly(LIST *l, int coeff, int px, int py)
{
    NODE *temp = (NODE *)malloc(sizeof(NODE));
    temp->coeff = coeff;
    temp->px = px;
    temp->py = py;
    temp->flag = 1;
    temp->link = NULL;
    if (l->head == NULL)
        l->head = temp;
    else
    {
        NODE *p = l->head;
        while (p->link != NULL)
        {
            p = p->link;
        }
        p->link = temp;
    }
}
void display(LIST *l)
{
    printf("entering the display function\n");
    if (l->head == NULL)
        printf("empty list\n");
    else
    {
        NODE *p = l->head;
        while (p != NULL)
        {
            printf("%dx^%dy^%d  +  ", p->coeff, p->px, p->py);
            p = p->link;
        }
    }
    printf("\n");
}
void add(LIST *l1, LIST *l2, LIST *l3)
{
    NODE *i = l1->head;
    NODE *j = l2->head;
    printf("entering add function\n");
    for (i = l1->head; i != NULL; i = i->link)
    {
        for (j = l2->head; j != NULL; j = j->link)
        {
            if (i->px == j->px)
            {
                if (i->py == j->py)
                {
                    int k = ((i->coeff) + (j->coeff));
                    i->flag = 0;
                    j->flag = 0;
                    insert_poly(l3,k,i->px,i->py);
                }
            }
        }
    }
}
void append_poly(LIST *l1, LIST *l2, LIST *l3)
{
    NODE *i = l1->head;
    NODE *j = l2->head;
    printf("entering append function\n");
    while( i != NULL)
    {
        if (i->flag ==1)
        {
            insert_poly(l3,i->coeff,i->px,i->py);
            
        }
        i = i->link;
    }
    while( j != NULL)
    {
        if (j->flag ==1)
        {
            insert_poly(l3,j->coeff,j->px,j->py);
            
        }
        j=j->link;
    }
}

