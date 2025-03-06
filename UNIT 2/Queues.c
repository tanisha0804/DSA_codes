/* queues - ordered collection of items from which follows FIFO  (first in first out)
elements inserted at rear side and removed from the front
in LL   ->insertion of elements = insert at last
        ->deleting of elements = delete at front*/
//     enqueue(insert)  = rear
//     dequeue(delete)  = front

//~~~~~~~~~~~~~~~~~  implementation of queues with arrays  ~~~~~~~~~~~~~
/* #include <stdio.h>
#include <stdlib.h>
#define max 10
int front = 0;
int rear = -1;
int queue[max];

void enqueue(int data);
int dequeue();
void display();

int main()
{
    int ch, data, res;
    while (1)
    {
        printf("1.enqueue\n2.dequeue\n3.display\n");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            printf("enter data to be inserted\n");
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
}

void enqueue(int data)
{
    if(rear == max-1)
        printf("empty queue\n");
    else
    {
        rear++;
        queue[rear] = data;
    }
}

int dequeue()
{
    if(front>rear)
        return 0;
    else
    {
        int d = queue[front];
        front = front+1;
        return d;
    }
}

void display()
{
    if(front>rear)
        printf("empty queue\n");
    else
    {
        for(int i=front;i<=rear;i++)
            printf("%d ->",queue[i]);
    }
} */

//~~~~~~~~~~~~~~~~~~~~~~~ IMPLEMENTATION OF QUEUES WITH LL  ~~~~~~~~~~~~~~~~~~~~~~~~
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *link;
} NODE;

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
    int ch, data,res;
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
    if(front == NULL  && rear == NULL)
        front=rear=temp;
    else
    {
        rear->link = temp;   //insert at end and rear should always point last element
        rear = temp;
    }
}

int dequeue()
{
    if(front == NULL  && rear == NULL)
        return 0;
    else
    {
        NODE *p = front;
        int data = p->data;
        front = p->link;
        free(p);
        return data;
    }
}

void display()
{
    if(front == NULL  && rear == NULL)
        printf("empty queue\n");
    else
    {
        NODE *p = front;
        while(p != NULL)
        {
            printf("%d->",p->data);
            p = p->link;
        }
    }
}

