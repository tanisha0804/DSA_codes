
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *link;
} NODE;

NODE *tail = NULL;

NODE *create_node(int data);
void insert_front(int data);
void display();
void insert_end(int data);
void insert_at_pos(int data, int pos);
int delete_front();
int delete_end();
int delete_node(int data);
void menu()
{
    while (1)
    {
        int choice, data, pos, value, k;
        printf("1.insert_at front\n");
        printf("2. display\n");
        printf("3.insert at end \n");
        printf("4.insert at position\n");
        printf("5. delete at front\n");
        printf("6.delete at end\n");
        printf("7.delete particular node");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("enter data to be entered\n");
            scanf("%d", &data);
            insert_front(data);
            break;
        case 2:
            display();
            break;
        case 3:
            printf("enter data to be entered\n");
            scanf("%d", &data);
            insert_end(data);
            break;
        case 4:
            printf("enter data to be inserted\n");
            scanf("%d", &data);
            printf("insert position\n");
            scanf("%d", &pos);
            insert_at_pos(data, pos);
            break;
        case 5:
            k = delete_front();
            printf("deleted element is %d\n", k);
            break;
        case 6:
            k = delete_end();
            printf("deleted element is %d\n", k);
            break;
        case 7:
            printf("eneter the element you want to delete\n");
            scanf("%d", &data);
            int k = delete_node(data);
            printf("%d element got deleted\n", k);
            break;
        default:
            exit(0);
        }
    }
}
int main()
{
    menu();
    return 0;
}

NODE *create_node(int data)
{
    NODE *temp = (NODE *)malloc(sizeof(NODE));
    temp->data = data;
    temp->link = temp;
}

void insert_front(int data)
{
    NODE *temp = create_node(data);
    NODE *p = tail;
    if (p == NULL)
        tail = temp;
    else
    {

        temp->link = p->link;
        p->link = temp;
    }
}

void display()
{
    if (tail == NULL)
        printf("empty list\n");
    else
    {
        NODE *p = tail->link; // the first element
        while (p != tail)
        {
            printf("%d ->", p->data);
            p = p->link;
        }
        printf("%d", p->data);
    }
    printf("\n");
}

void insert_end(int data)
{
    NODE *temp = create_node(data);
    NODE *p = tail;
    if (p == NULL)
        tail = temp;
    else
    {
        temp->link = p->link;
        p->link = temp;
        tail = temp;
    }
}

void insert_at_pos(int data, int pos)
{
    int p = 1;
    NODE *temp = create_node(data);
    NODE *pres = tail->link;
    while (p < pos - 1 && pres != tail)
    {
        p++;
        pres = pres->link;
    }
    if (tail == NULL && pos == 1) // if no elements present in LL
        tail = temp;
    if (pos == 1)
        insert_front(data); // if the element to be entered is 1st one
    temp->link = pres->link;
    pres->link = temp; // anywhere between 1st and last
    if (pres == tail)  // last element to be entered
        insert_end(data);
}

int delete_front()
{
    if (tail == NULL)
    {
        printf("the list is empty\n");
        return -1;
    }
    else
    {
        NODE *p = tail->link;
        int d = p->data;
        if (tail == p)
        {
            tail = NULL;
        }
        else
        {
            tail->link = p->link;
        }
        free(p);
        return d;
    }
}

int delete_end()
{
    if (tail == NULL)
    {
        printf("the list is empty\n");
        return -1;
    }
    else
    {
        int d = tail->data;
        NODE *p = tail->link;
        if (p == tail)
        {
            free(tail);
            tail = NULL;
            return d;
        }
        while (p->link != tail)
            p = p->link;
        p->link = tail->link;
        free(tail);
        tail = p;
        return d;
    }
}

int delete_node(int data)
{
    if (tail == NULL)
    {
        printf("empty list\n");
        return -1;
    }
    NODE *prev = tail;
    NODE *pres = tail->link;
    while (pres->data != data && pres != tail)
    {
        prev = pres;
        pres = pres->link;
    }
    if (pres->data == data)
    {
        int d = pres->data;
        if (pres->link == pres) // only 1 element present in ll and that matches the data
            tail = NULL;
        else
        {
            prev->link = pres->link; // incrementing links
            if (pres == tail)
                tail = prev; // change the last node to the previous one
            free(pres);
            return (d);
        }
    }
    else
    {
            printf("data you want isnt found\n");
    }
}



/* void insert_front(int data)
{
    NODE *temp = (NODE *)malloc(sizeof(NODE));
    temp->data = data;
    temp->link = temp;
    NODE *p = tail;
    if(tail == NULL)
        tail = temp;
    else
    {
        tail->link = p->link;
        p->link = temp;
    }
}

void insert_tail(int data)
{
    NODE *temp = (NODE *)malloc(sizeof(NODE));
    temp->data = data;
    temp->link = temp;
    NODE *p = tail;
    if(tail == NULL)
        tail = temp;
    else
    {
        tail->link = p->link;
        p->link = temp;
        tail = temp;
    }
}

void insert_at_pos(int data,int pos)
{
    int i=1;
    NODE *temp = (NODE *)malloc(sizeof(NODE));
    temp->data = data;
    temp->link = temp;
    NODE *pres = tail->link;
    if(tail == NULL)
        tail = temp;
    while((i<pos-1) && (pres != tail))
    {
        i++;
        pres = pres->link;
    }
    if(pos==1)   //insert at first
    {
        NODE *p = tail;
        temp->link = p->link;
        p->link = temp;
    }
    if(pres == tail)
    {
        NODE *p = tail;
        temp->link = p->link;
        p->link = temp;
        tail = temp;
    }
    else
    {
        temp->link = pres->link;
        pres->link = temp;
    }
} */


