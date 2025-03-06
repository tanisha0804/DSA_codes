#include<stdio.h>
#include<stdlib.h>
#define size 10

typedef struct node
{
    int data;
    int flag;
}NODE;

NODE hashtable[size];
void initialize();
void insert(int key);
void search(int key);
void display();

int main()
{
    initialize();

    insert(5);
    insert(15);
    insert(25);
    display();

    search(15); // Should find the data
    search(35); // Should not find the data

    return 0;
}

void initialize()
{
    for(int i=0;i<size;i++)
    {
        hashtable[i].data = 0;
        hashtable[i].data = 0;
    }
}

void insert(int key)
{
    int hash2 = (7 - (key%7));
    int i=0;
    int hash = ((key%size) + i *hash2)%size;

    while(hashtable[hash].flag != 0 && i<size)
    {
        i++;
        hash = ((key%size) + i *hash2)%size;
    }
    if(hashtable[hash].flag == 0)
    {
        hashtable[hash].data = key;
        hashtable[hash].flag = 1;
        printf("data %d inserted at %d position\n",key,hash);
    }
    else
    {
        printf("data not found\n");
    }
}

void search(int key)
{
    int hash2 = (7 - (key%7));
    int i=0;
    int hash = ((key%size) + i *hash2)%size;
    while(i<size)
    {
        if (hashtable[hash].data == key && hashtable[hash].flag == 1)
        {
            printf("data %d found at location %d\n",key,hash);
            return;
        }
        i++;
        hash = ((key%size) + i *hash2)%size;;
    }
    printf("data not found\n");
}

void display()
{
    for(int i=0;i<size;i++)
    {
        if(hashtable[i].flag == 1)
            printf("index: %d : %d",i,hashtable[i].data);
        else
            printf("empty\n");
    }
}