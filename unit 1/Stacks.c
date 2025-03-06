/* stack = data structure in which all insertions and deletions are in one end - TOP of the stack
last element added is always popped out first = LIFO order */
// stack - follows LIFO
/*
1. isempty() - checks if stack is empty
2. push(x) x is the element
    increment the top
    insert the value
3. pop() - top most element is deleted
    decrement the top

if top = size-1   #stack is full
if top = -1       #stack is empty

-> APPLICATIONS OF STACK
1. word reversal
2. back tracking
3. function calls/recursion
4. undo operations on any text editor
5. paranthesis matching tracking
*/

// ~~~~~~~ IMPLEMENTATION OF STACK USING ARRAYS  ~~~~~~~~~~~~````

/* #include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define size 6

void push(int *, int *, int);
int pop(int *, int *);
void display(int *, int);
int main()
{
    int top = -1;
    int *stack = (int *)malloc(sizeof(int) * size);
    int ch, ele, res;
    while (1)
    {
        printf("\n1.push\n2.pop\n3.display\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("eneter element to be inserted in stack\n");
            scanf("%d", &ele);
            push(stack, &top, ele);
            break;
        case 2:
            res = pop(stack, &top);
            if (res > 0)
                printf("item got deleted successfully %d", res);
            break;
        case 3:
            display(stack, top);
            break;
        default:
            exit(0);
        }
    }
    return 0;
}

void push(int *stack, int *top, int element)
{
    if (*top == (size - 1))
        printf("stack overflow\n");
    else
    {
        ++(*top);
        stack[*top] = element;
    }
}

int pop(int *stack, int *top)
{
    if (*top == -1)
    {
        printf("stack underflow\n");
        return -1;
    }
    else
    {
        int ele = stack[*top];
        *top = *top - 1;
        return ele;
    }
}

void display(int *stack, int top)
{
    if (top == -1)
        printf("stack underflow\n");
    else
    {
        for (int i = top; i >= 0; i--)
        {
            printf("%d ->", stack[i]);
        }
    }
    printf("\n");
} */


//~~~~~~~~~~~~~~~ IMPLEMENTATION OF STACK USING LINKED LIST ~~~~~~~~~~~~~~~~~`

/* #include <stdio.h>
#include <stdlib.h>
typedef struct stack
{
    int data;
    struct stack *link;
}STACK;

STACK *top = NULL;   //tope being the global variable

void push(int ele);
int pop();
void display();

int main()
{
    int ch,ele,res;
    while(1)
    {
        printf("\n1.push\n2.pop\n3.display\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("eneter element to be inserted in stack\n");
            scanf("%d", &ele);
            push(ele);
            break;
        case 2:
            res = pop();
            if (res > 0)
                printf("item got deleted successfully %d", res);
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

void push(int ele)
{
    STACK *temp = (STACK *)malloc(sizeof(STACK));
    temp->data = ele;
    temp->link = NULL;
    if(top == NULL)
        top = temp;
    else
    {
        temp->link = top;
        top = temp;
    }
}

int pop()
{
    STACK *p=top;
    int data;
    if(p == NULL)
    {
        printf("empty stack\n");
        return -1;
    }
    else
    {
        int data = p->data;
        top=p->link;
        free(p);
        return data;
    }
}

void display()
{
    STACK *p = top;
    if(p == NULL)
        printf("empty stack\n");
    else
    {
        while (p!=NULL)
        {
            printf("%d-> ",p->data);
            p = p->link;
        }
    }
    printf("\n");
} */
