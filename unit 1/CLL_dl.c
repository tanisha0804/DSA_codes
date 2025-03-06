
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
} NODE;

NODE *header = NULL;

void display();
void insert_front(int data);
void insert_end(int data);
void insert_position(int data, int pos);
int delete_front();
int delete_end();
int delete_node(int data);

void menu()
{
    int choice, data, pos, k;
    while (1)
    {

        printf("1..Insert Head\n");
        printf("2.Display\n");
        printf("3..Insert Tail\n");
        printf("4.insert at a position\n");
        printf("5.Delete a front..\n");
        printf("6.delete ata end\n");
        printf("7.delete a node\n");

        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the data to be entered...");
            scanf("%d", &data);
            insert_front(data);
            break;
        case 2:
            display();
            break;
        case 3:
            printf("Enter the data to be entered...");
            scanf("%d", &data);
            insert_end(data);
            break;
        case 4:
            printf("Enter the data to be entered...");
            scanf("%d", &data);
            printf("enter the position where you want it to be placed\n");
            scanf("%d", &pos);
            insert_position(data, pos);
            break;
            
        case 5:
            k=delete_front();
            printf("element deleted =  %d\n",k);
            break;
        case 6:
            k=delete_end();
            printf("element deleted =  %d\n",k);
            break;
        case 7:
            printf("enter the node you want to delete\n");
            scanf("%d",&data);
            k=delete_node(data);
            printf("%d got deleted\n",k);
            break; 
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
    temp->prev = temp->next = temp;
}

void insert_front(int data)
{
    NODE *temp = create_node(data);
    NODE *p = header;
    if (p == NULL)
        header = temp;
    else
    {
        temp->next = p;
        temp->prev = p->prev;
        p->prev->next = temp;
        p->prev = temp;
        header = temp;
    }
}

void display()
{
    NODE *p = header;
    if (header == NULL)
        printf("empty list\n");
    else
    {
        while (p->next != header)
        {
            printf("%d ->", p->data);
            p = p->next;
        }
        printf("%d", p->data);
    }
    printf("\n");
}

void insert_end(int data)
{
    NODE *temp = create_node(data);
    NODE *p = header;
    if (p == NULL)
        header = temp;
    else
    {
        while(p->next != header)
            p = p->next;
        temp->prev = p;
        temp->next = p->next;
        p->next->prev = temp;
        p->next = temp;
        /* temp->next = header;
        temp->prev = header->prev;
        header->prev->next = temp;
        header->prev = temp; */
    }
}

void insert_position(int data, int pos)
{
    NODE *temp = create_node(data);
    int i = 1;
    NODE *pres = header;
    while ((i < pos - 1) && (pres->next != header))
    {
        i++;
        pres = pres->next;
    }
    if ((header == NULL) && (pos == 1))
        header = temp;
    if (pos == 1)
        insert_front(data);
    if (pres->next == header)
        insert_end(data);
    temp->next = pres->next;
    temp->prev = pres;
    pres->next->prev = temp;
    pres->next = temp;
}

int delete_front()
{
    if (header == NULL)
    {
        printf("empty list\n");
        return -1;
    }
    else
    {
        NODE *p = header;
        int data = p->data;
        if (header->next == header) // only 1 node present in LL
        {
            header = NULL;
        }
        else
        {
            header->next->prev = header->prev;
            header->prev->next = header->next;
            header = header->next;
        }
        free(p);
        return data;
    }
}

int delete_end()
{
    if (header == NULL)
    {
        printf("empty list\n");
        return -1;
    }
    else
    {
        NODE *p = header->prev;
        int data = p->data;
        if (header->next == header) // only 1 node present in LL
        {
            header = NULL;
        }
        else
        {
            p->prev->next = header;
            p->next->prev = p->prev;
            header->prev = p->prev;
        }
        free(p);
        return data;
    }
}

int delete_node(int data)
{
    NODE *pres = header;
    if(pres == NULL)
    {
        printf("empty list\n");
        return -1;
    }

    while((pres->data != data) && pres->next != header)
    {
        pres = pres->next;
    }
    if(pres->data == data)
    {
        int data = pres->data;
        if(pres->next == header)
            pres = NULL;
        else
        {
            pres->next->prev = pres->prev;
            pres->prev->next = pres->next;
            if(pres == header)
                header = pres->next;
        }
        free(pres);
        return data;
    }
    else
        printf("node with particular data not found\n");
}

