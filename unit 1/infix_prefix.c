//not sure if code is correct
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char infix[20], Stack[20], pre_rev[20], prefix[20], reverse[10];
int top = -1;

int check_oper(char c);
int input_prec(char c);
int st_prec(char c);
char peep(); // returns top most element of stack
void push(char c);
char pop();
void infix_prefix();
void reverse_string();
void reverse_final_prefix();

int main()
{
    printf("Enter a valid infix expression:\n");
    scanf("%s", infix);

    reverse_string(); // Reverse infix expression
    printf("The reversed infix expression is %s\n", reverse);

    infix_prefix(); // Convert to reversed prefix
    printf("The prefix (reversed) expression is %s\n", pre_rev);

    reverse_final_prefix(); // Reverse the reversed prefix to get final prefix
    printf("The final prefix expression is %s\n", prefix);
}

int check_oper(char c)
{
    switch (c)
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

int input_prec(char c)
{
    switch (c)
    {
    case '+':
    case '-':
        return 2;
    case '*':
    case '/':
        return 4;
    case '(':
        return 7;
    case ')':
        return 0;
    default:
        return 5; // Operands
    }
}

int st_prec(char c)
{
    switch (c)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 3;
    case '(':
        return 0;
    case '#':
        return -1;
    default:
        return 6; // Operands
    }
}

char peep()
{
    return Stack[top]; // Return top-most stack element
}

void push(char c)
{
    ++top;
    Stack[top] = c;
}

char pop()
{
    char x = Stack[top];
    top--;
    return x;
}

void reverse_string()
{
    int i = strlen(infix) - 1;
    int j = 0;
    while (i >= 0)
    {
        if (infix[i] == '(')
        {
            reverse[j++] = ')';
        }
        else if (infix[i] == ')')
        {
            reverse[j++] = '(';
        }
        else
        {
            reverse[j++] = infix[i];
        }
        i--;
    }
    reverse[j] = '\0';
}

void reverse_final_prefix()
{
    int i = strlen(pre_rev) - 1;
    int j = 0;
    while (i >= 0)
    {
        if (pre_rev[i] == '(')
        {
            prefix[j++] = ')';
        }
        else if (pre_rev[i] == ')')
        {
            prefix[j++] = '(';
        }
        else
        {
            prefix[j++] = pre_rev[i];
        }
        i--;
    }

    prefix[j] = '\0';
}

void infix_prefix()
{
    int i = 0, j = 0;
    char ch;

    while (reverse[i] != '\0')
    {
        ch = reverse[i];
        if (check_oper(ch)) // If operator
        {
            while (top != -1 && st_prec(peep()) >= input_prec(ch))
            {
                pre_rev[j++] = pop();
            }
            push(ch);
        }
        else if (ch == '(') // If opening parenthesis
        {
            push(ch);
        }
        else if (ch == ')') // If closing parenthesis
        {
            while (top != -1 && peep() != '(')
            {
                pre_rev[j++] = pop();
            }
            pop(); // Pop '(' from stack
        }
        else // If operand
        {
            pre_rev[j++] = ch;
        }
        i++;
    }

    // Pop remaining operators
    while (top != -1)
    {
        pre_rev[j++] = pop();
    }
    pre_rev[j] = '\0';
}