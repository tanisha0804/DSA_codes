/* circular queues = follows FIFO order, but instead of ending queue at last position it again starts from first position after the last
in simple queue - not possible to insert mpre elements even after dequeue operation until the queue is completely reset
but in case of circular queue this is possible my moving the rear back to the begining of the queue */

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ CIRCULAR QUEUE USING ARRAYS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~``
/* #include <stdio.h>
#include <stdlib.h>
#define max 10
int queue[max];
int front = -1, rear = -1;
void enqueue(int data);
int dequeue();
void display();

int main()
{
    int ch, data, res;
    while (1)
    {
        printf("\n 1. enqueue\n 2. dequeue\n 3. display\n");
        printf("enter your choice\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("enter element to the queue\n");
            scanf("%d", &data);
            enqueue(data);
            break;
        case 2:
            res = dequeue();
            if (res == 0)
                printf("queue is empty\n");
            else
                printf("deleted element is %d\n", res);
            break;
        case 3:
            display();
            break;
        default:
            exit(0);
        }
    }
    return 0;
}

void enqueue(int data)
{
    if ((front == 0 && rear == max - 1) || (front = rear+1))
 // to check is queue is full
        printf("queue is full\n");
    else
    {
        if (front == -1) // to insert 1st element of queue
        {
            front = rear =0;
            queue[rear] = data;
        }
        else if (rear == max - 1 && front != 0)// to insert elements in queue after dequeue
        {
            rear = 0;
            queue[rear] = data;
        }
        else // to insert elements in queue after 1st element
        {
            rear++;
            queue[rear] = data;
        }
    }
}

int dequeue()
{
    if (front == -1)
        return 0;
    else
    {
        int data = queue[front];
        if (front == rear) // if only 1 element is present in array
            front = rear = -1;
        else if (front == max - 1) // to bring back fron to 0 after it deleted last element of queue
            front = 0;
        else // simple traversal till end
            front++;
        return data;
    }
}

void display()
{
    if (front == -1)
        printf("empty queue\n");
    else
    {
        if (rear >= front) // normal traversal until it reaches last element of queue
        {
            for (int i = front; i <= rear; i++)
                printf("%d->", queue[i]);
        }
        else // in case of circular queue when front>rear
        // first traverse from fron to end of queue...then traverse from start of queue till it reaches front
        {
            for (int i = front; i < max; i++)
                printf("%d->", queue[i]);
            for (int i = 0; i <= rear; i++)
                printf("%d->", queue[i]);
        }
    }
} */



//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~CIRCULAR QUEUE USING LINKED LIST ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *link;
}NODE;

NODE *front = NULL;
NODE *rear = NULL;

void enqueue(int data);
int dequeue();
void display();

NODE *create_node(int data)
{
    NODE *temp = (NODE *)malloc(sizeof(NODE));
    temp->data = data;
    temp->link = NULL;
}
int main()
{
    int ch, data, res;
    while (1)
    {
        printf("\n 1. enqueue\n 2. dequeue\n 3. display\n");
        printf("enter your choice\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("enter element to the queue\n");
            scanf("%d", &data);
            enqueue(data);
            break;
        case 2:
            res = dequeue();
            if (res == 0)
                printf("queue is empty\n");
            else
                printf("deleted element is %d\n", res);
            break;
        case 3:
            display();
            break;
        default:
            exit(0);
        }
    }
    return 0;
}

void enqueue(int data)
{
    NODE *temp = create_node(data);
    if(front== NULL && rear == NULL)
    {
        front = rear = temp;   //creating a circular node having that value
        rear->link = front; 
    }
    else
    {
        rear->link = temp;
        rear = temp;
        rear->link = front;
    }
}

int dequeue()
{
    if(front == NULL)
        return 0;
    else
    {
        NODE *p = front;
        int data = p->data;
        if(front == rear)
        {
            front = rear = NULL;
        }
        else
        {
            front = front->link;
            rear->link = front;
        }
        free(p);
        return data;
    }
}

void display()
{
    if(front == NULL)
        printf("empty queue\n");
    else
    {
        NODE *p = front;
        while(p != rear)
        {
            printf("%d->",p->data);
            p=p->link;
        }
        printf("%d",p->data);
    }
}


