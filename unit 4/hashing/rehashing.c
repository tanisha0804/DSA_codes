
#include <stdio.h>
#include <stdlib.h>

#define Size 5

typedef struct node
{
    int data;
    int flag;
} NODE;

typedef struct hash
{
    int size;
    struct node *hashtable;
} HASH;

int count = 0;

HASH *createhash(int size);
void destroyHash(HASH *hash);
void rehash(HASH **h);
void insert(int key, HASH **h);
void search(int key, HASH *h);
void display(HASH *h);

int main()
{
    HASH *hashTable = createhash(Size);
    insert(5, &hashTable);
    insert(15, &hashTable);
    insert(25, &hashTable);
    insert(35, &hashTable);
    display(hashTable);

    search(15, hashTable);
    search(35, hashTable);
    search(45, hashTable);

    destroyHash(hashTable);

    return 0;
}

HASH *createhash(int size)
{
    HASH *temp = (HASH *)malloc(sizeof(HASH));
    temp->size = size;
    temp->hashtable = (NODE *)malloc(size * sizeof(NODE));
    for (int i = 0; i < size; i++)
    {
        temp->hashtable[i].data = 0;
        temp->hashtable[i].flag = 0;
    }
    return temp;
}

void destroyHash(HASH *hash)
{
    free(hash->hashtable);
    free(hash);
}

void rehash(HASH **h)
{
    int newsize = (*h)->size * 2;
    HASH *newhash = createhash(newsize);

    for (int i = 0; i < (*h)->size; i++)
    {
        if ((*h)->hashtable[i].flag == 1)
        {
            int j = 0;
            int hash = ((*h)->hashtable[i].data % newsize + j) % newsize;
            while (newhash->hashtable[hash].flag != 0)
            {
                j++;
                hash = ((*h)->hashtable[i].data % newsize + j) % newsize;
            }
            newhash->hashtable[hash].data = (*h)->hashtable[i].data;
            newhash->hashtable[hash].flag = 1;
        }
    }
    destroyHash(*h);
    *h = newhash; 
}

void insert(int key, HASH **h)
{
    int i = 0;
    count++;
    if (count > (float)(0.75 * (*h)->size))
    {
        rehash(h);
        insert(key, h); 
        return;
    }
    int hash = ((key % (*h)->size) + i) % (*h)->size;
    while ((*h)->hashtable[hash].flag != 0 && i < (*h)->size)
    {
        i++;
        hash = ((key % (*h)->size) + i) % (*h)->size;
    }
    (*h)->hashtable[hash].data = key;
    (*h)->hashtable[hash].flag = 1;
    printf("data %d entered at position %d\n", key, hash);
}

void search(int key, HASH *h)
{
    int i = 0;
    int hash = (key % h->size + i) % h->size;
    while (i < h->size)
    {
        if (h->hashtable[hash].data == key && h->hashtable[hash].flag == 1)
        {
            printf("\nThe data %d is found at index %d\n", key, hash);
            return;
        }
        i++;
        hash = (key % h->size + i) % h->size;
    }
    printf("\nData not found\n");
}

void display(HASH *h)
{
    for (int i = 0; i < h->size; i++)
    {
        if (h->hashtable[i].flag == 1)
            printf("index %d : %d\n", i, h->hashtable[i].data);
        else
            printf("index %d : empty\n", i);
    }
}

