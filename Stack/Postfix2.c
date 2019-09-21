#include <stdio.h>
#include <string.h>
#define N 100

void postfix(char a[]);
int isOp(char a);
void putinS(char a);
void emptyS(void);
char pop(void);
int bracket(char a);
void push(char a);

int top = -1, point = 0;
char stack[N], out[N];

void main()
{
    char a[N];
    printf("Enter String:");
    gets(a);
    postfix(a);
    printf("Postfix form:%s\n", out);
}

void postfix(char a[])
{
    int n = strlen(a);
    for (int i = 0; a[i] != '\0'; i++)
    {
        if (bracket(a[i]) == 1)
        {
            n--;
        }
        else if (isOp(a[i]) != 0)
        {
            putinS(a[i]);
        }
        else
        {
            out[point++] = a[i];
        }
    }
    emptyS();
    out[n] = '\0';
}

int isOp(char a)
{
    switch (a)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '$':
    case '^':
        return 3;
    default:
        return 0;
    }
}

void putinS(char a)
{
    while(isOp(a) <= isOp(stack[top])&&isOp(a)!=3)
    {
        out[point++] = pop();
    }
    push(a);
}

void emptyS(void)
{
    while (top > -1)
    {
        out[point++] = pop();
    }
}

int bracket(char a)
{
    if (a == '(')
    {
        push(a);
    }
    else if (a == ')')
    {
        while (stack[top] != '(')
        {
            out[point++] = pop();
        }
        top--;
    }
    else
    {
        return 0;
    }
    return 1;
}

char pop(void)
{
    return stack[top--];
}
void push(char a)
{
    stack[++top] = a;
}