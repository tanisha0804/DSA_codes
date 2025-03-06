 // functions required = 
/*
1. to check if stack is null
2. to check if one paranthesis matches the other one or not
3.push element to stack
4.pop element from stack
5. to check_balance
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 30
typedef struct stack
{
    char par[max];
    int top;
}stack;

int check_empty(stack *st);
int check_pair(char first,char second);
void push(stack *st,char x);
char pop(stack *s);
int check_balance(char *exp);

void init_stack (stack *st)
{
    st->top = -1;
}

int main()
{
    char exp[max];
    printf("enter an expression\n");
    scanf("%s",exp);
    if(check_balance(exp))
        printf("balanced string\n");
    else
        printf("not balanced\n");
    return 0;
}


int check_empty(stack *st)
{
    return st->top == -1;
}

int check_pair(char first,char second)
{
    if ((first == '(' && second == ')') ||
        (first == '[' && second == ']') ||
        (first == '{' && second == '}'))
        return 1;
    else 
        return 0;
}

void push(stack *st,char x)
{
    if(st->top == max-1)
        printf("the stack is overloaded\n");
    else{
        st->top++;
        st->par[st->top] = x;
    }
}

char pop(stack *st)
{
    if(check_empty(st))
    {
        printf("stack is empty\n");
        return '\0';
    }
    else
    {
        char temp = (st->par[st->top]);
        st->top--;
        return temp;
        
    }
}

char topmost(stack *s)
{
    if(!check_empty(s))
        return s->par[s->top];
    return '\0';
}

int check_balance(char *exp)
{
    stack s;
    init_stack(&s);
    for(int i=0;i<strlen(exp);i++)
    {
        if(exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
            push(&s,exp[i]);
        else if (exp[i] == ')' || exp[i]== ']' || exp[i] == '}')
        {
            if(check_empty(&s) || !check_pair(topmost(&s),exp[i]))
                return 0;
            else
            {
                pop(&s);
            }
        }
    }
    return check_empty(&s);
} 



/*Application of stacks:
1. Infix to postfix
2. Evaluate an postfix
3. Parenthesis matching - compiler uses stack as the data structure 
    to keep track of opened and closed paranthesis.
{},(),[]
Eg: 
(A+B) - Balanced
{(A+B)*(A-B)} - Balanced
[(2+3)* 5]] - Not balanced.

)( - 
[()()]
[(])*/

/* Check_balance_parenthesis(exp)
{
    n <- length of the exp
    create a stack s; // char array
    for i->0 to n-1;
        if exp[i] is '(' or '{' or '[':
            push(exp[i],s);
        else if exp[i] is ')' or '}' or ']':
            {
                if (s is empty) || (top does not match with exp[i])
                    return false;
            }
        else
        {
            pop(s) // LIFO the top moast element is popped.
        }
    return s is empty? true:false;
} */


