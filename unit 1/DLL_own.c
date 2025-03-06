#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    struct node *prev;
    int data;
    struct node *next;
} NODE;

NODE *header = NULL;
NODE *create_node(int);
void insert_head(int);
void display();
void insert_tail(int);
void delete_first();
void delete_last();
void delete_node(int);
void delete_pos(int);
void insert_pos(int, int);
void insert_after(int, int);
void insert_before(int, int);

void menu()
{
    int ch, data, pos, value;
    while (1)
    {
        printf("\n1..insert_head");
        printf("\n2..insert_tail");
        printf("\n3..Display");
        printf("\n4.delete first node");
        printf("\n5. Delete Last Node..");
        printf("\n6 .Delete a node given value");
        printf("\n7.Delete at a position");
        printf("\n8.Insert at a Given Position");
        printf("\n9. Insert after given value..\n");
        printf("\n10. Insert before given value..\n");
        printf("\n11.Exit");

        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter the data...");
            scanf("%d", &data);
            insert_head(data);
            break;
        case 2:
            printf("\nEnter the data...");
            scanf("%d", &data);
            insert_tail(data);
            break;
        case 3:
            display();
            break;
        case 4:
            delete_first();
            break;
        case 5:
            delete_last();
            break;
        case 6:
            printf("\nEnter the data...");
            scanf("%d", &data);
            delete_node(data);
            break;
        case 7:
            printf("\nEnter the position");
            scanf("%d", &pos);
            delete_pos(pos);
            break;
        case 8:
            printf("\nEnter the data and position");
            scanf("%d", &data);
            scanf("%d", &pos);
            insert_pos(data, pos);
            break;
        case 9:
            printf("\nEnter the value and data");
            scanf("%d %d", &value, &data);
            insert_after(value, data);
            break;

        case 10:
            printf("\nEnter the value and data");
            scanf("%d %d", &value, &data);
            insert_before(value, data);
            break;
        case 11:
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
    temp->prev = temp->next = NULL;
}
void insert_head(int data)
{
    NODE *temp = (NODE *)create_node(data);
    if (header == NULL)
        header = temp;
    else
    {
        NODE *p = header;
        temp->next = p;
        p->prev = temp;
        header = temp;
    }
}

void display()
{
    if (header == NULL)
        printf("empty list\n");
    else
    {
        NODE *p = header;
        while (p != NULL)
        {
            printf("%d ==> ", p->data);
            p = p->next;
        }
    }
    printf("\n");
}

void insert_tail(int data)
{
    NODE *temp = create_node(data);
    if (header == NULL)
        header = temp;
    else
    {
        NODE *p = header;
        while (p->next != NULL)
        {
            p = p->next;
        }
        temp->prev = p;
        p->next = temp;
    }
}

void insert_pos(int data, int pos)
{
    NODE *temp = create_node(data);
    NODE *p = header;
    int i = 1;
    while ((i < pos) && (p->next != NULL)) // position to be placed is found
    {
        i++;
        p = p->next;
    }
    if (p->next == NULL)
    {
        if (p->prev == NULL) // inserting 1st element of LL
            header = temp;
        else if (i == (pos - 1)) // inserting element at last position of LL
        {
            temp->prev = p;
            p->next = temp;
        }
        else // position not found
            printf("invalid position\n");
    }
    else // p->next != NULL
    {
        if (p->prev == NULL) // inserting the element at 1st position
        {
            temp->next = p;
            p->prev = temp;
            header = temp;
        }
        else // position to be inserted is somewhere in between
        {
            temp->prev = p->prev;
            p->prev->next = temp;
            temp->next = p;
            p->prev = temp;
        }
    }
}

void insert_after(int value, int data)
{
    NODE *temp = create_node(data);
    NODE *p = header;
    while ((p->next != NULL) && (value != p->data))
        p = p->next;
    if (p->next != NULL)
    {
        temp->prev = p;
        temp->next = p->next;
        p->next->prev = temp;
        p->next = temp;
    }
    else
    {
        if (value == p->data) // to insert at last position(after ke liye there is no insert at 1st pos)
        {
            temp->prev = p;
            p->next = temp;
        }
        else
            printf("node with value not found\n");
    }
}

void insert_before(int value, int data)
{
    NODE *temp = create_node(data);
    NODE *p = header;
    while ((p->next != NULL) && (value != p->data))
        p = p->next;
    if (p->next != NULL)
    {
        temp->prev = p->prev;
        temp->next = p;
        p->prev->next = temp;
        p->prev = temp;
    }
    else
    {
        if (value == p->data) // to insert at 1st pos(before ke liye there is no insert at last pos)
        {
            temp->next = p;
            p->prev = temp;
            header = temp;
        }
        else
            printf("node with value not found\n");
    }
}
void delete_first()
{
    if (header == NULL)
        printf("empty list\n");
    else
    {
        NODE *p = header;
        if (p->next == NULL) // IF ONLY ONE ELEMENT IN LL
            header = NULL;
        else
        {
            p->next->prev = NULL; // traverse through p and free p...never free header
            header = p->next;
        }
        free(p);
        printf("first element deleted successfully\n");
    }
}

void delete_last()
{
    if (header == NULL)
        printf("empty list\n");
    else
    {
        NODE *p = header;
        if (p->next == NULL) // IF ONLY ONE ELEMENT IN LL
            header = NULL;
        else
        {
            while (p->next != NULL) // traverse till last element of LL
            {
                p = p->next;
            }
            p->prev->next = NULL; // make the prev node's next = NULL
            printf("last node deleted successfully\n");
        }
        free(p);
    }
}

void delete_node(int data)
{
    NODE *p = header;
    if (header == NULL)
        printf("empty list\n");
    while ((p->next != NULL) && (data != p->data))
        p = p->next;
    if (p->next != NULL) // position found
    {
        if (p->prev == NULL) // to delete 1st element of LL
        {
            p->next->prev = NULL;
            header = p->next;
        }
        else // somewhere in between
        {
            p->prev->next = p->next;
            p->next->prev = p->prev;
        }
    }
    else
    {
        if (p->prev != NULL) // last element
            p->prev->next = NULL;
        else
            printf("node not found\n");
    }
}

void delete_pos(int pos)
{
    NODE *p = header;
    if (header == NULL)
        printf("empty list\n");
    int i = 1;
    while ((p->next != NULL) && (i < pos))
    {
        i++;
        p = p->next;
    }
    if (p->next != NULL) // position found
    {
        if (p->prev == NULL) // to delete 1st element of LL
        {
            p->next->prev = NULL;
            header = p->next;
        }
        else // somewhere in between
        {
            p->prev->next = p->next;
            p->next->prev = p->prev;
        }
    }
    else
    {
        if (i == (pos)) // last element
            p->prev->next = NULL;
        else
            printf("pos not found\n");
    }
}



