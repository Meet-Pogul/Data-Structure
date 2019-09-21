#include<stdio.h>
#define N 1000
char stack[20];
int t=-1;
void div(int a);
char pop(void);
void push(char n);
void out(void);
void binary(char c[]);
void main()
{
    char c[N];
    printf("Enter String:");
    gets(c);
    binary(c);
}
void binary(char c[])
{
    int i=0;
    while(c[i]!='\0')
        {div(c[i]);i++;out();printf(" ");}
}
void div(int a)
{
    if(a==1)
        push(1),push(0);
    else if(a%2==0)
        push(0),div(a/2);
    else
        push(1),div(a/2);
    
}
char pop(void)
{
    int k;
    if (t < 0)
        printf("Stack Underflow\n");
    else
        return stack[t--];
    
}
void push(char n)
{
    if (t >= 20)
        printf("Stack Overflow\n");
    else
        stack[++t] = n;
}

void out(void)
{
    if (t < 0)
        printf("Stack is EMPTY\n");
    else
    {
        while(t!=-1)
        {
            printf("%d", pop());
        }
    }
}
