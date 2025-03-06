#include<stdio.h>
#include<stdlib.h>

#define size 10

typedef struct node
{
    int data;
    struct node *next;
}NODE;

typedef struct hashtable
{
    int count;
    struct node *head;
}HASHTABLE;

HASHTABLE hashtable[size] = {0};

NODE *createnode(int key);
void insertnode(int key);
void search(int key);
void delete(int key);
void display();

int main()
{
    insertnode(10);
    insertnode(20);
    insertnode(15);
    insertnode(30);
    insertnode(47);
    insertnode(65);
    //insert(60);
    display();
    search(20);
    delete(10);
    display();
    return 0;
}

NODE *createnode(int key)
{
    NODE *temp = (NODE *)malloc(sizeof(NODE));
    temp->data = key;
    temp->next = NULL;
    return temp;
}

void insertnode(int key)
{
    int hash = key%size; //defining hash function
    NODE *temp = createnode(key);
    temp->next = hashtable[hash].head;  // if more than one collision occurs this is used to link all nodes together using infront front
    hashtable[hash].head = temp;
    hashtable[hash].count++;
}

void search(int key)
{
    int hash = key%size;
    int pos = 1;
    NODE *temp = hashtable[hash].head;
    while(temp != NULL)
    {
        if(temp->data == key)
            printf("element %d found at index %d at position %d",key,hash,pos);
        temp = temp->next;
        pos++;
    }
    printf("data not found\n");
}

void delete(int key)
{
    int hash = key%size;
    NODE *temp = hashtable[hash].head;
    NODE *prev = NULL;
    while(temp != NULL)
    {
        if(temp->data == key)
        {
            if(prev == NULL)
                hashtable[hash].head = temp->next;
            else
                prev->next = temp->next;
            free(temp);
            hashtable[hash].count--;
            printf("data deleted successfully\n");
        }
        prev = temp;
        temp = temp->next;
    }
    printf("data to be deleted not found\n");
}

void display()
{
    for(int i=0;i<size;i++)
    {
        if(hashtable[i].count != 0)
        {
            printf("index :%d ->", i);
            NODE *temp = hashtable[i].head;
            while(temp)
            {
            printf("%d->",temp->data);
            temp = temp->next;
            }
            printf("NULL");
        }
        
    }
    printf("\n");
}


