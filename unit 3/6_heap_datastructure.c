/* HEAP - binary tree with certain properties
                            A
                        ___/ \
                        __B    C
                        _/ \  / \
                        D   E F  G
-> array representation =  [A,B,C,D,E,F,G]
                INDEX       0 1 2 3 4 5 6

                            A
                        ___/ \
                        __B    C
                            __/ \
                            __D  E
-> array representation =  [A,B,C,-,-,D,E]
                INDEX       0 1 2 3 4 5 6

        node with index i
        ->parent =[(i-1)/2]floor
        ->left child = (2*i)+1
        ->right child = (2*i)+2

--> if the height of full binary tree starts with 0 and the height = 2
then the total number of nodes of the BT = 2^(n+1) - 1
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//if indexing from 1
                            A
                        ___/ \
                        __B    C
                        _/ \
                        D   E
-> array representation =  [A,B,C,D,E]
                INDEX       1 2 3 4 5

        node with index i
        ->parent =[i/2]floor
        ->left child = (2*i)
        ->right child = (2*i)+1
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
HEAPS
heap memory and heap data structure are 2 different things
heap data structure = complete binary tree
types:
1.min heap
    for every nodde x,x's decendent will be larger than x
                            1                           10
                        ___/ \                          / \
                        __2   3                        50  20
                        _/ \                          / \   /
                        4   5                        55 60  30               //CBT ->heap
                                                -> array representation =  [10,50,20,55,60,30]
                                                                INDEX       1  2  3  4  5  6
2.max heap
    for every node x, x's decendents will be smaller than x
                            5                           50
                        ___/ \                          / \
                        __4   3                        30  20
                        _/ \                          / \   /
                        2   1                        15 10  16              //CBT ->heap
                                                -> array representation =  [50,30,20,15,10,16]
                                                                INDEX       1  2  3  4  5  6


heap construction
-> top-down approach
-> bottom-up approach
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
TOP-DOWN approach of MIN-HEAP construction
rules   -> insert element to the first space available
        -> rearrange the elements so that heap properties are followed

inserting 1 element =  depends on no of swaps
                        depends on tree height
height of a CBT = order of (log n) = o(log n)
space coplexity = o(log n)
time complexity = o(nlog n)
--> heap deletion = always root element
        1. replace root with last element
        2. rearrange(swap) only when requiredn
    min heap = swap parent with smaller child
    max heap = swap parent with larger child

*/

// max heap implementation using top-down approach(UP HEAP BUBBLING)

/* #include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define size 10
typedef struct heap
{
    int heap[size];
    int hsize;
} HEAP;

void insert(HEAP *h, int data);
void swap(int *a, int *b);
int deletemax(HEAP *h);
void display(HEAP *h);
void init(HEAP *h)
{
    h->hsize = 0;         // start with empty heap
    h->heap[0] = INT_MAX; // fixint the 0th index to a fixed value(placeholder value)
    // index 0 isnt used in heap operations - heap index starts with 1
}
int main()
{
    int data, ch;
    HEAP *heap = (HEAP *)malloc(sizeof(HEAP));
    init(heap);
    do
    {
        printf("enter the data to insert in heap\n");
        scanf("%d", &data);
        insert(heap, data);
        printf("heap after insertion:\n");
        display(heap);
        printf("press 1 to continue or 0 to continue\n");
        scanf("%d", &ch);
    } while (ch == 1);
    printf("deleting the element\n");
    int del = deletemax(heap);
    printf("the deleted element is: %d\n",del);
    printf("the heap after:\n");
    display(heap);
    return 0;
}

void insert(HEAP *h, int data) // insert at end of an array function
{
    h->heap[++(h->hsize)] = data;  //inserting at 1st position available
    int current = h->hsize;
    int parent = current / 2;
    // rearranging(swapping) the inserted element to maintain max heap property
    while (h->heap[parent] < h->heap[current] && current > 1) // if the parent node is smaller than child
    {
        swap(&h->heap[parent], &h->heap[current]); // swapping the element
        current = parent;
        parent = current / 2;
    }
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int deletemax(HEAP *h)
{
    int max = h->heap[1];               // root element is deleted
    h->heap[1] = h->heap[(h->hsize)--]; // move last element to root
    int current = 1;
    int child = 2 * current; // left child
    // checking of heap properties
    while (child <= h->hsize)
    {
        // select larger child
        if (h->heap[child + 1] > h->heap[child]) // comparing between left and right child to check which is greater
            child++;

        // if current is smaller than the child then swapping needs to be done
        if (h->heap[current] < h->heap[child])
        {
            swap(&h->heap[current], &h->heap[child]);
            current = child;
            child = 2 * current;
        }
        else
        {
            break;
        }
    }
    return max;
}
void display(HEAP *h)
{
    printf("HEAP:");
    for (int i = 1; i <= h->hsize; i++)
        printf("%d->", h->heap[i]);
    printf("\n");
} */

// elements inserted in the order
/* 8,5,7,12,3,4,9
the max heap obtained = 12,8,9,5,3,4,7
                        12
                        / \
                    ___8   9
                    __/ \  / \
                    _5  3 4   7   --> max heap
after deleting the root node:
                        _9
                        / \
                    ___8   7
                    __/ \  /
                    _5  3 4    --> max heap
*/

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~`
// min heap implementation using top-down approach
/* #include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define size 10
typedef struct heap
{
    int heap[size];
    int hsize;
}HEAP;

void insert(HEAP *h,int data);
void swap(int *a,int *b);
int deletemin(HEAP *h);
void display(HEAP *h);
void init(HEAP *h)
{
    h->hsize =0;   //start with empty heap
    h->heap[0] = INT_MAX;  //fixint the 0th index to a fixed value(placeholder value)
    //index 0 isnt used in heap operations - heap index starts with 1
}
int main()
{
    int data,ch;
    HEAP *heap = (HEAP *)malloc(sizeof(HEAP));
    init(heap);
    do
    {
        printf("enter the data to insert in heap\n");
        scanf("%d",&data);
        insert(heap,data);
        printf("heap after insertion:\n");
        display(heap);
        printf("press 1 to continue or 0 to continue\n");
        scanf("%d",&ch);
    } while (ch == 1);
    printf("deleting the element\n");
    int del = deletemin(heap);
    printf("the deleted element is: %d\n",del);
    printf("the heap after:\n");
    display(heap);
    return 0;

}

void insert(HEAP *h,int data)  //insert at end of an array function
{
    h->heap[++(h->hsize)] = data;
    int current = h->hsize;
    int parent = current/2;
    //rearranging(swapping) the inserted element to maintain max heap property
    while(h->heap[parent] > h->heap[current] && current>1)  //if the parent node is smaller than child
    {
        swap(&h->heap[parent],&h->heap[current]);  //swapping the element
        current = parent;
        parent = current/2;
    }
}

void swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int deletemin(HEAP *h)
{
    int min = h->heap[1];               // root element is deleted
    h->heap[1] = h->heap[(h->hsize)--]; // move last element to root
    int current = 1;
    int child = 2 * current; // left child
    // checking of heap properties
    while (child <= h->hsize)
    {
        // select larger child
        if (h->heap[child + 1] < h->heap[child]) // comparing between left and right child to check which is greater
            child++;

        // if current is smaller than the child then swapping needs to be done
        if (h->heap[current] > h->heap[child])
        {
            swap(&h->heap[current], &h->heap[child]);
            current = child;
            child = 2 * current;
        }
        else
        {
            break;
        }
    }
    return min;
}
void display(HEAP *h)
{
    printf("HEAP:");
    for(int i=1;i<= h->hsize;i++)
        printf("%d->",h->heap[i]);
    printf("\n");
} */

// elements inserted in the order
/* 8,5,7,12,3,4,9
the max heap obtained = 3->5->4->12->8->7->9->
                        _3
                        / \
                    ___5   4
                    __/ \  / \
                    _12  8 7  9   --> min heap
after deleting the root node:
                        _4
                        / \
                    ___5   7
                    __/ \  /
                    _12  8 9    --> max heap
*/