//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ MY UNDERSTANDING WITH CODE ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *link;
} NODE;
NODE *header = NULL; // global variable header assigned to null


void insert_front(int data);
void insert_end(int data);
void insert_pos(int data, int pos);
void display();
int count_node();
int count_node_reccursion(NODE *ptr);
void print_reverse_order_recurr(NODE *ptr);
void delete_node(int data);
void delete_node_pos(int pos);

void delete_alt();

NODE *getnode() // function to create a new node
{
    return (NODE *)malloc(sizeof(NODE));
}
void menu()
{
    while (1)
    {
        int choice, x, pos, count;
        printf("input ---> enter 1 for inserting element at starting\n");
        printf("input ---> enter 2 for inserting element at end\n");
        printf("input ---> enter 3 for inserting element at a particular position\n");
        printf("enter 4 to display all the elements\n");
        printf("enter 5 to count the nodes\n");
        printf("enter 6 for printing reverse order using recursion\n");
        printf("enter 7 for deleting the element when data is given\n");
        printf("enter 8 for deleting the element when position is given\n");
        printf("enter 9 for deleting alternate elements of LL\n");

        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("enter element to be inserted at the beginning\n");
            scanf("%d", &x);
            insert_front(x);
            break;
        case 2:
            printf("enter element to be inserted at the end\n");
            scanf("%d", &x);
            insert_end(x);
            break;
        case 3:
            printf("enter element to be inserted\n");
            scanf("%d", &x);
            printf("enter the position where it needs to be inserted\n");
            scanf("%d", &pos);
            insert_pos(x, pos);
            break;
        case 4:
            printf("displaying elements\n");
            display();
            break;
        case 5:
            printf("counting the number of nodes\n");
            // count = count_node();
            count = count_node_reccursion(header);
            printf("the no of nodes = %d\n", count);
            break;
        case 6:
            printf("printing elements in reverse order\n");
            print_reverse_order_recurr(header);
            break;
        case 7:
            printf("enter the element to be deleted\n");
            scanf("%d", &x);
            delete_node(x);
            display();
            printf("required element got deleted\n");
            break;
        case 8:
            printf("enter the position of node to be deleted\n");
            scanf("%d", &pos);
            delete_node_pos(pos);
            display();
            printf("required element got deleted\n");
            break;
        case 9: 
            printf("deleting alternate elements of LL\n");
            delete_alt();
            display();
            printf("required elements got deleted\n");
            break;

        default:
            exit(1);
            break;
        }
    }
}
int main()
{

    menu();

    return 0;
}

void insert_front(int data)
{
    NODE *temp = (NODE *)getnode();
    temp->data = data;
    temp->link = NULL;
    if (temp == NULL) // case 0
        printf("insufficent memory\n");
    else
    {
        if (header == NULL) // case 1
            header = temp;
        else // case 2
        {
            temp->link = header;
            header = temp;
        }
    }
}

void insert_end(int data)
{
    NODE *temp = (NODE *)getnode();
    temp->data = data;
    temp->link = NULL;
    if (temp == NULL) // case 0
        printf("insufficent memory\n");
    else
    {
        if (header == NULL) // case 1
            header = temp;
        else
        {
            NODE *p = header;
            while (p->link != NULL)
                p = p->link;
            p->link = temp;
        }
    }
}

void insert_pos(int data, int pos)
{
    int x = 1;
    NODE *temp = (NODE *)getnode();
    temp->data = data;
    temp->link = NULL;
    NODE *prev = NULL;
    NODE *pres = header;
    if (temp == NULL) // case 0
        printf("insufficent memory\n");
    else
    {
        // if pos given is 1 only then it would skip all this while loop and go directly to if cases
        while ((x < pos) && (pres != NULL))
        {
            x++;         // to get value of (pos-1)
            prev = pres; // prev and pres moving together until they encounter pos-1
            pres = pres->link;
        }
        if (pres != NULL)
        {
            if (prev == NULL) // the given position by user is 1(element to be inserted at the beginning of LL)
            {
                temp->link = header;
                header = temp;
            }
            else // element to be inserted is between the starting and end of LL
            {
                temp->link = pres;
                prev->link = temp;
            }
        }
        else // pres == NULL (element to be inserted at the end of LL)
        {
            if (x == pos)
                prev->link = temp;
            else
                printf("invalid position given\n");
        }
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
            printf("%d==>", p->data);
            p = p->link;
        }
        printf("\n");
    }
}

int count_node()
{
    int i = 0;
    NODE *p = header;
    if (p == NULL)
        return i;
    else
    {
        while (p != NULL)
        {
            i++;
            p = p->link;
        }
        return i;
    }
}

int count_node_reccursion(NODE *ptr)
{
    int i = 0;
    NODE *p = ptr;
    if (p == NULL)
        return i;
    else
    {
        while (p != NULL)
        {
            i = 1 + count_node_reccursion(p->link);
            return i;
        }
    }
}

void print_reverse_order_recurr(NODE *ptr)
{
    if (ptr->link != NULL)
    {
        print_reverse_order_recurr(ptr->link);
    }
    printf("%d ==> ", ptr->data);
}

void delete_node(int data)
{
    NODE *prev,*pres;
    prev = NULL;
    pres = header;
    while((pres!=NULL) && (pres->data != data))  //to traverse the LL until data is encountered
    {
        prev = pres;
        pres = pres->link;
    }
    if(pres!=NULL)  //if the data is found
    {
        if(prev == NULL)  //if the element to be deleted is the first one
            header = pres->link;
        else  //if the element to be deleted is not the first one
            prev->link = pres->link;
        free(pres);
    }
    else
        printf("node with that data is not found\n");
    
}

int deletefront()
{
    if(header == NULL)
    {
        printf("empty list\n");
        return 0;
    }
    else
    {
        NODE *p = header;
        int data = p->data;
        header = p->link;
        free(p);
        return data;
    }
}

int delete_last()
{
    if(header == NULL)
    {
        printf("empty list\n");
        return 0;
    }
    else
    {
        NODE *p = header;
        while(p->link != NULL)
            p=p->link;
        int data = p->data;
        free(p);
        return data;
    }
}
void delete_node_pos(int pos)
{
    NODE *prev,*pres;
    prev = NULL;
    pres = header;
    int i=1;
    while((pres!=NULL) && ( i < pos))  //to traverse the LL until data is encountered
    {
        i++;
        prev = pres;
        pres = pres->link;
    }
    if(pres!=NULL)  //if the data is found
    {
        if(prev == NULL)  //if the element to be deleted is the first one
            header = pres->link;
        else  //if the element to be deleted is not the first one
            prev->link = pres->link;
        free(pres);
    }
    else
        printf("node with that data is not found\n");
    
}

/* void delete_alt()
{
    NODE *p = header;
    while(p!=NULL){
        p->link=p->link->link;
        free(p);
    }
} */

void delete_alt()
{
    NODE *prev = NULL;
    NODE *pres = header;
    while(pres!=NULL)
    {
        if(prev == NULL)
            header = pres->link;
        else
            prev->link = pres->link;
        prev = pres->link;
        if(prev !=NULL)
            pres = prev->link;
        else
            pres = NULL;
    }
}
