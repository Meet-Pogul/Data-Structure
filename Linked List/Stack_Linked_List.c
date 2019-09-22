#include <stdio.h>
#include <stdlib.h>
int t = -1;
typedef struct node
{
    int info;
    struct node *next;
} * NODE;
NODE head = NULL;

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

NODE createnode()
{
    NODE new_n;
    new_n = (NODE)malloc(sizeof(NODE));
    new_n->next = NULL;
    return new_n;
}

void push(int data)
{
    t++;
    NODE link = createnode();
    link->info = data;
    link->next = head;
    head = link;
}

int pop(void)
{
    if (t < 0)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        t--;
        int data;
        NODE temp = head;
        head = head->next;
        data = head->info;
        free(temp);
        return data;
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
        printf("TOP Element: %d\n", head->info);
    }
}
void display(void)
{
    NODE ptr = head;
    printf("\n[ ");
    if (head == NULL)
    {
        printf("Stack is Empty");
    }
    else
    {
        while (ptr != NULL)
        {
            if (ptr->next == NULL)
            {
                printf("%d", ptr->info);
                break;
            }
            printf("%d, ", ptr->info);
            ptr = ptr->next;
        }
    }
    printf(" ]\n");
}

void change(int pos, int data)
{
    if (t < 0)
    {
        printf("Stack is EMPTY\n");
    }
    else if (pos > t)
    {
        printf("Position Not Exist in STACK\n");
    }
    else
    {
        NODE prev = head;
        for (int i = 1; i <= pos; i++)
            prev = prev->next;
        prev->info=data;
    }
}
void peep(int pos)
{
    if (t < 0)
    {
        printf("Stack is EMPTY\n");
    }
    else if(pos>t)
    {
        printf("Position Not Exist in STACK\n");
    }
    else
    {
        NODE prev = head;
        for (int i = 1; i <= pos; i++)
            prev = prev->next;
        printf("Value at Position %d = %d\n",pos,prev->info);
    }  
}