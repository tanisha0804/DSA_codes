#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *link;
}NODE;
NODE *header = NULL; //global variable


void insert_order(int x);
void display();

NODE *getnode() // function to create a new node
{
    return (NODE *)malloc(sizeof(NODE));
}
int main()
{
    int x;
    while(1)
    {
        printf("ENTER the element to be inserted in LL\n");
        printf("\'enter -999 to exit \'\n");
        scanf("%d",&x);
        if(x==-999)
            break;
        insert_order(x);
        display();
    }
}
void insert_order(int x)
{
    NODE *temp = (NODE *)getnode();
    temp->data = x;
    temp->link = NULL;
    NODE *prev = NULL;
    NODE *pres = header;

    while((pres!=NULL) && (x>pres->data))  //traversing x until it reaches the order where it needs to be placed
    {
        prev = pres;
        pres = pres->link;
    }
    if(pres == NULL)
    {
        if(prev == NULL)   //if LL is empty and 1st element needs to be added in it
            header = temp;
        else //to insert the last element
            prev->link = temp;

    }
    else
    {
        if(prev == NULL)  //to insert the smallest element
        {
            temp->link = header;
            header = temp;
        } 
        else  //to insert any element between first and last
        {
            prev->link = temp;
            temp->link = pres;
        }
    }
}
void display()
{
    if(header == NULL)
        printf("empty list\n");
    else
    {
        NODE *p = header;
        while(p!=NULL)
        {
            printf("%d ==> ",p->data);
            p=p->link;
        }
    }
}
