/* EXPRESSION NORMALLY FOUND IN INFIX NOTATION
    infix = human readable
    postfix = prefix = machine readable
operators = arithematic,logical,relational
operands = constants,variables,expressions
*/

/*
order of operations:
1. paranthesis
2.exponents - ^   [R->L]
3. multiplication and division   [L->R]
4.addition and subtraction      [L->R]
*/

/*
postfix and prefix - does not require
1.no paranthesis
2. no precedence
3. no associativity
4. no ambiguity
 */

/* postfix = reverse polish notation
    ->less memory space,computation time */


#include<stdio.h>
#include<stdlib.h>

char infix[10],postfix[10],stack[10];
int stack_eval[10];
int top = -1,top_eval = -1;
int check_oper(char o);
int input_prec(char ip);
int stack_prec(char st);
void push(char p);
char pop();
void inf_post();
void push_eval(char p);
int pop_eval();
void post_eval();

int main()
{
    inf_post();
    printf("the evaluated postfix expression is %s",postfix);
    post_eval();
    return 0;
}

int check_oper(char o)
{
    switch (o)
    {
        case '*':
        case '/':
        case '+':
        case '-':
            return 1;
        default:
            return 0;
    }
}

int input_prec(char ip)
{
    switch(ip)
    {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 3;
        case '(':
            return 7;
        case ')':
            return 0;
        default:
            return 5;
        
    }
}

int stack_prec(char st)
{
    switch(st)
    {
        case '+':
        case '-':
            return 2;
        case '*':
        case '/':
            return 4;
        case '(':
            return 0;
        case '#':
            return -1;
        default:
            return 6;
        
    }
}

void push(char p)
{
    stack[++top] = p;
}

char pop()
{
    char x = stack[top];
    top--;
    return x;
}

void push_eval(char p)
{
    stack_eval[++top_eval] = p;
}

int pop_eval()
{
    if(top_eval == -1)
        return 0;
    int res = stack_eval[top_eval --];
    return res;
}

void inf_post()
{
    int i=0,j=0,ch,res;
    printf("enter a valid infix expression\n");
    scanf("%s",infix);
    push('#');
    while(infix[i] != '\0')
    {
        ch = infix[i];
        if(check_oper(ch))
        {
            if(top == -1)
            {
                push(ch);
                i++;
            }
            else
            {
                if((stack_prec(stack[top]))<(input_prec(infix[i])))
                {
                    push(ch);
                    i++;
                }
                else
                {
                    while((stack_prec(stack[top]))>(input_prec(infix[i]))  && (top>=0))
                    {
                        res = pop();
                        postfix[j++] = res;
                    }
                }
            }
        }
        else
        {
            postfix[j++] = infix[i++];
        }
    }
    while(top>=0)
    {
        res = pop();
        postfix[j++] = res;
    }
    postfix[j] = '\0';
}

void post_eval()
{
    int i=0,op1,op2,res,val;
    char ch;
    while(postfix[i] != '\0')
    {
        ch = postfix[i];
        if(check_oper(ch))
        {
            op2 = pop_eval();   //if operator encountered removed 2 operands
            op1= pop_eval();
            switch (ch)
            {
                case '*':
                    res = op1*op2; 
                    push_eval(res);
                    break;
                case '/':
                    res = op1/op2;
                    push_eval(res);
                    break;
                case '+':
                    res = op1+op2;
                    push_eval(res);
                    break;
                case '-':
                    res = op1-op2;
                    push_eval(res);
                    break;
            }
        }
        else{
        printf("\nenter the vale of %c\n",ch);
        scanf("%d",&val);
        push_eval(val);
        }
        i++;
    }
    printf(" the evaluated postfix expression is %d\n",pop_eval());
}




//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~POST FIX EVALUATION ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/* #include<stdio.h>
#include<stdlib.h>
typedef struct stack
{
    int *s;
    int size;
    int top;
}STACK;

void post_eval(char *postfix);
void init_stack(STACK *s);
int isopr(char ch);
int pop(STACK *s);
int main()
{
    char postfix[20];
    printf("emter the postfix expression\n");
    scanf("%d",postfix);
    post_eval(postfix);
    return 0;
}
void post_eval(char *postfix)
{
    int i=0,op1,op2,res,val;
    char ch;
    STACK s;
    init_stack(&s);
    while(postfix[i] != '\0')
    {
        ch = postfix[i];
        if(isopr(ch))
        {
            op1 = pop(&s);
            op2 = pop(&s);
            switch(ch)
            {
                case '+': res = op1+op2;
                    push(&s,res);
                    break;
                case '-': res = op1-op2;
                    push(&s,res);
                    break;
                case '*': res = op1*op2;
                    push(&s,res);
                    break;
                case '/': res = op1/op2;
                    push(&s,res);
                    break;
            }
        }
        else
        {
            printf("%c",ch);
            scanf("%d",val);
            push(&s,val);
        }

    }
}
void init_stack(STACK *s)
{
    s->size = 20;
    
}

int isopr(char ch)
{
    if(ch == '+' || ch == '-' || ch == '*' || ch == '/')
        return 1;
    else
        return 0;
}

int pop(STACK *s)
{
    int k;
} */
