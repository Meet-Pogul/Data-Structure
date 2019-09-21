#include <stdio.h>
int top = -1;
char stack[100];
void push(char k);
char pop(void);
void postfix(char *a);
void main()
{
    int n;
    char a[100];
    printf("Enter String:");
    gets(a);
    postfix(a);
}
void postfix(char *a)
{
    for (int i = 0; *(a + i) != '\0'; i++);
    for (int i = 0; *(a + i) != '\0'; i++)
    {
        if (*(a + i) == '(' || *(a + i) == ')')
        {
            if (*(a + i) == ')')
            {
                while (stack[top] != '(')
                {
                    printf("%c", pop());
                }
                top--;
            }
            else
            {
                push(*(a + i));
            }
        }
        else if (*(a + i) == '^' || *(a + i) == '$' || *(a + i) == '*' || *(a + i) == '/' || *(a + i) == '+' || *(a + i) == '-')
        {
            if(*(a + i) == '^' || *(a + i) == '$')
            {
                push(*(a + i));
            }
            else if (*(a + i) == '*' || *(a + i) == '/')
            {
                if (stack[top] == '^' || stack[top] == '$')
                {
                    printf("%c", pop());
                }
                push(*(a + i));
            }
            else if (*(a + i) == '+' || *(a + i) == '-')
            {
                if (stack[top] == '*' || stack[top] == '/')
                {
                    printf("%c", pop());
                }
                push(*(a + i));
            }
            else
            {
                push(*(a + i));
            }
        }
        else
        {
            printf("%c", *(a + i));
        }
    }
    while (top >= 0)
    {
        printf("%c", pop());
    }
}
void push(char a)
{
    if (top > 100)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        top++;
        stack[top] = a;
    }
}
char pop(void)
{
    if (top < 0)
    {
        printf("Stack UnderFlow\n");
    }
    else
    {
        return stack[top--];
    }
}
