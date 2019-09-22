#include <stdio.h>
int stack[100], t = -1;
void peep(int post);
int pop(void);
void push(int n);
void peek(void);
void display(void);
void change(int post,int val);
void main()
{
    int n, k, i,sw;
    do
    {
        printf("What do you want do:\n1.PUSH\t\t2.POP\n3.PEEK\t\t4.CHANGE\n5.DISPLAY\t6.PEEP\t\t7.EXIT\n");
        scanf(" %d", &sw);
        switch (sw)
        {
        case 1:
            printf("Enter no of Elements You Want Enter In STACK: ");
            scanf("%d", &k);
            for (i = 0; i < k; i++)
            {
                printf("Enter Element:");
                scanf("%d", &n);
                push(n);
            }
            break;
        case 2:
            printf("POPED RESULT:%d\n", pop());
            break;
        case 3:
            peek();
            break;
        case 4:
            printf("Enter Position :");
            scanf("%d",&k);
            printf("Enter Value :");
            scanf("%d",&n);
            change(k,n);
            break;
        case 5:
            display();
            break;
        case 6:
            printf("Enter Position :");
            scanf("%d",&k);
            peep(k);
            break;
        case 7:
            break;
        default:
            printf("Wrong Input");
            break;
        }
    } while (sw != 7);
}
int pop(void)
{
    if (t < 0)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        return stack[t--];
    }
}
void push(int n)
{
    if (t >= 100)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        t++;
        stack[t] = n;
    }
}
void peek(void)
{
    if (t < 0)
    {
        printf("Stack is EMPTY\n");
    }
    else
    {
        printf("TOP Element: %d\n", stack[t]);
    }
}
void display(void)
{
    if (t < 0)
    {
        printf("Stack is EMPTY\n");
    }
    else
    {
        printf("\nDisplaying STACK\n");
        for (int i = 0; i <= t; i++)
        {
            printf("%d\n", stack[i]);
        }
    }
}
void change(int post,int val)
{
    if (t < 0)
    {
        printf("Stack is EMPTY\n");
    }
    else if(post>t)
    {
        printf("Position Not Exist in STACK\n");
    }
    else
    {
        stack[post]=val;
    }
    
}
void peep(int post)
{
    if (t < 0)
    {
        printf("Stack is EMPTY\n");
    }
    else if(post>t)
    {
        printf("Position Not Exist in STACK\n");
    }
    else
    {
        printf("Value at Position %d = %d\n",post,stack[post]);
    }  
}
