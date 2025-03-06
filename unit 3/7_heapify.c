//bottom up approach = HEAPIFY
//used recurrsion preferably
//takes order of n times (top down takes order of nlogn times)
//comparision starts from right(leaf nodes)

/* ex:    max heap using bottom down approach                    
                            10
                        ___/ \
                        __20  18
                        _/ \  / \
                        12 40 25 15
now this gets changed to  ->
                            10
                        ___/ \
                        __20  25
                        _/ \  / \
                        12 40 18 15   //the child are compared and greater one is swapped as parent

                            10
                        ___/ \
                        __40  25
                        _/ \  / \
                        12 20 18 15

                            40
                        ___/ \
                        __10  25
                        _/ \  / \
                        12 20 18 15   //here the comparision is to be done with all other nodes(notice 10 is smaller than 12 and 20 hence swapping needs to be done)

                            40
                        ___/ \
                        __20  25
                        _/ \  / \
                        12 10 18 15 */

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//max heap using heapify(bottom up approach)
/* #include<stdio.h>
#include<stdlib.h>
#include<limits.h>
void buildheap(int arr[],int n);
void heapify(int arr[],int n,int i);
void display(int arr[],int n);
int main()
{
    int arr[] = {0,4,10,3,5,1};
    int size = sizeof(arr)/sizeof(arr[0])-1;
    buildheap(arr,size);
    display(arr,size);
    return 0;
}
void buildheap(int arr[],int n)
{
    int startindex = n/2; //first parent node from right
    for(int i=startindex;i>=1;i--)
    {
        heapify(arr,n,i);
    }
}
void heapify(int arr[],int n,int i)
{
    int largest = i; //initialize largest as root
    int left = 2*i;
    int right = (2*i)+1;
    //comparision with left and right child
    if(arr[left] > arr[largest] && left <= n)
        largest = left;
    if(arr[right] > arr[largest] && right <= n)
        largest = right;
    if(largest != i)   //swapping if i doesnt remain as the largest
    {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr,n,largest);
    }
}
void display(int arr[],int n)
{
    for(int i = 1;i <= n;i++)
    {
        printf("%d\t",arr[i]);
    }
    printf("\n");
} */


//min-heap using heapify
#include<stdio.h>
#include<stdio.h>

void buildheap(int arr[],int n);
void heapify(int arr[],int n,int i);
void display(int arr[],int n);
int main()
{
    int arr[]={0,9,10,1,4,7,8};
    int size = sizeof(arr)/sizeof(arr[0]) - 1;
    buildheap(arr,size);
    printf("the rearranged array = \n");
    display(arr,size);
    return 0;
}

void buildheap(int arr[],int n)
{
    int parent = n/2;
    for(int i= parent;i>=1;i--)
        heapify(arr,n,i);
}
void heapify(int arr[],int n,int i)
{
    int smallest = i;
    int left = 2*i;
    int right = 2*i +1;
    if(left <= n && arr[left] < arr[smallest])
        smallest = left;
    if(right <= n && arr[right] < arr[smallest])
        smallest = right;
    if(smallest != i)
    {
        int temp = arr[i];
        arr[i] = arr[smallest];
        arr[smallest] = temp;

        heapify(arr,n,smallest);
    }
}
void display(int arr[],int n)
{
    for(int i=1;i<=n;i++)
        printf("%d\t",arr[i]);
    printf("\n");
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//priority queues using min heap and max heap
/*  min heap = priority = smaller element
    max heap = priority = larger element*/

