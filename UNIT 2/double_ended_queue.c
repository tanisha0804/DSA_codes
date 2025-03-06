/* dequeue = allows insertion and deletion from both the ends
operations to be performed on dequeue = 
1.insertfront() = add elements on the front of queue
2.insertrear() = adds element to the rear of queue
3.deletefront() = deletes element from front of queue
4.deleterear() = deletes element from rear of queue */

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~DOUBLE ENDED QUEUES USING ARRAYS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/* #include<stdio.h>
#include<stdlib.h>
#define max 10
int queue[max];
int rear=-1,front=-1;

void insertfront(int data);
void insertrear(int data);
int deletefront();
int deleterear();
void display();
int main()
{
    int ch, data, res;
    while (1)
    {
        printf("\n 1. insertfront\n 2. insertrear\n 3. deletefront\n 4. deleterear\n 5.display\n");
        printf("enter your choice\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("enter element to the queue\n");
            scanf("%d", &data);
            insertfront(data);
            break;
        case 2:
            printf("enter element to the queue\n");
            scanf("%d", &data);
            insertrear(data);
            break;
        case 3:
            res = deletefront();
            if (res == 0)
                printf("queue is empty\n");
            else
                printf("deleted element is %d\n", res);
            break;
        case 4:
            res = deleterear();
            if (res == 0)
                printf("queue is empty\n");
            else
                printf("deleted element is %d\n", res);
            break;
        case 5:
            display();
            break;
        default:
            exit(0);
        }
    }
    return 0;
}

void insertfront(int data)
{
    if((front ==0 && rear ==max-1) || (front = rear+1))
        printf("queue is full\n");
    else
    {
        if(front == -1)
            front = rear = 0;
        if(front == 0)
            front = max-1;
        else
            front --;
        queue[front] = data;
    }
}

void insertrear(int data)
{
    if((front ==0 && rear ==max-1) || (front = rear+1))
        printf("queue is full\n");
    else
    {
        if(front == -1)
            front = rear = 0;
        if(rear == max-1)
            rear = 0;
        else
            rear++;;
        queue[rear] = data;
    }
}

int deletefront()
{
    if(front == -1)
        return 0;
    else
    {
        int data = queue[front];
        if(front == rear)
            front = rear = -1;
        else if (front == max-1)
            front = 0;
        else
            front ++;
        return data;
    }
}

int delete_rear()
{
    if(front == -1)
        return 0;
    else
    {
        int data = queue[rear];
        if(front == rear)
            front = rear =-1;
        else if(rear == 0)
            rear = max-1;
        else
            rear--;
        return data;
    }
}

void display()
{
    if (front == -1)
        printf("empty queue\n");
    else
    {
        if(rear>=front)
        {
            for(int i=front;i<=rear;i++)
                printf("%d->",queue[i]);
        }
        else
        {
            for(int i=front;i<max;i++)
                printf("%d->",queue[i]);
            for(int i=0;i<=rear;i++)
                printf("%d->",queue[i]);
        }
    }
} */


// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~DDOUBLE ENDED QUEUES USING LINKED LIST ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~`
//using doubly linked list

#include<stdio.h>
#include<stdio.h>
typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
}NODE;

NODE *front = NULL;
NODE *rear = NULL;

void insertfront(int data);
void insertrear(int data);
int deletefront();
int deleterear();
void display();

NODE *creat_node(int data)
{
    NODE *temp = (NODE *)malloc(sizeof(NODE));
    temp->data = data;
    temp->prev = temp->next = NULL;
}

int main()
{
    int ch, data, res;
    while (1)
    {
        printf("\n 1. insertfront\n 2. insertrear\n 3. deletefront\n 4. deleterear\n 5.display\n");
        printf("enter your choice\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("enter element to the queue\n");
            scanf("%d", &data);
            insertfront(data);
            break;
        case 2:
            printf("enter element to the queue\n");
            scanf("%d", &data);
            insertrear(data);
            break;
        case 3:
            res = deletefront();
            if (res == 0)
                printf("queue is empty\n");
            else
                printf("deleted element is %d\n", res);
            break;
        case 4:
            res = deleterear();
            if (res == 0)
                printf("queue is empty\n");
            else
                printf("deleted element is %d\n", res);
            break;
        case 5:
            display();
            break;
        default:
            exit(0);
        }
    }
    return 0;
}

void insertfront(int data)
{
    NODE *temp = creat_node(data);
    if(front == NULL)
        front = rear = temp;
    else
    {
        temp->next = front;
        front->prev = temp;
        front = temp;
    }
}

void insertrear(int data)
{
    NODE *temp = create_node(data);
    if(front == NULL)
        front = rear = temp;
    else
    {
        temp->prev = rear;
        rear->next = temp;
        rear = temp;
    }
}

int deletefront()
{
    if(front == NULL)
        return 0;
    else
    {
        NODE *p = front;
        int data = p->data;
        if(front == rear)
            front=rear=NULL;
        else
        {
            front = front ->next;
            front->prev = NULL;

        }
        free(p);
        return data;
    }
}

int deleterear()
{
    if(front == NULL)
        return 0;
    else
    {
        NODE *p = rear;
        int data = p->data;
        if(front == rear)
            front=rear=NULL;
        else
        {
            rear = rear->prev;
            rear->next = NULL;

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
            p=p->next;
        }
        printf("%d",p->data);
    }
}
