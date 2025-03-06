#include<stdio.h>
#include<stdlib.h>
#define size 10

typedef struct node
{
    int data;
    int flag;   // 0: empty 1:occupied
}NODE ;

NODE hashtable[size];

void initialise();
void insert(int key);
void search(int key);
void display();

int main()
{
    initialise();

    insert(5);
    insert(15);
    insert(25);
    insert(49);
    insert(59);
    display();

    search(15); // Should find the data
    search(35); // Should not find the data

    return 0;

}

void initialise()
{
    for(int i=0;i<size;i++)
    {
        hashtable[i].data = 0;
        hashtable[i].flag =0;
    }
}

void insert(int key)
{
    int hash,i=0;
    hash = ((key%size) + i)%size;
    while(hashtable[hash].flag != 0 && i<size)
    {
        i++;
        hash = ((key%size)+i)%size;
    }
    if(hashtable[hash].flag == 0)
    {
        hashtable[hash].data = key;
        hashtable[hash].flag = 1;
        printf("data %d entered at index %d",key,hash);
    }
    else
        printf("data cannot be inserted\n");
}

void search(int key)
{
    int i=0;
    int hash = ((key%size)+ i)%size;
    while(i<size)
    {
        if(hashtable[hash].data == key && hashtable[hash].flag == 1)
            printf("key %d found at index %d\n",key,hash);
        i++;
        hash = ((key%size)+i)%size;
    }
    printf("data not found\n");
}

void display()
{
    for(int i=0;i<size;i++)
    {
        if(hashtable[i].flag == 1)
            printf("index %d : %d\n",i,hashtable[i].data);
        else
            printf("empty\n");
    }
}
