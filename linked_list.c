#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int info;
    struct node *next;
} NODE;

NODE *insert_list(NODE *);
void display_list(NODE *);

int main()
{
    NODE *header = NULL, *new;
    char ch, n;
    int i;
    do
    {
        printf("\nFunction:\n");
        printf("1.Insert \n2.Display\n3.Exit\n");
        printf("Enter Your Choice:");
        scanf(" %c", &ch);
        switch (ch)
        {
        case '1':
            header = insert_list(header);
            break;
        case '2':
            display_list(header);
            break;
        case '3':
            break;
        default:
            printf("Wrong Input\n");
            break;
        }
    } while (ch != '3');
}

NODE *insert_list(NODE *h)
{
    NODE *new_n, *trav_n, *prev_n;
    char ch;
    int pos;
    do
    {
        new_n = (NODE *)malloc(sizeof(NODE));
        printf("\nWhere You Want To Insert:\n1.FRONT\n2.LAST\n3.AFTER POSITION\n4.Exit\n");
        printf("Enter Your Choice:");
        getchar();
        scanf(" %c", &ch);
        printf("\n");
        switch (ch)
        {
        case '1':
            printf("Information:");
            scanf("%d", &new_n->info);
            new_n->next = h;
            h = new_n;
            break;
        case '2':
            printf("Information:");
            scanf("%d", &new_n->info);
            trav_n = h;
            while (trav_n->next != NULL)
                trav_n = trav_n->next;
            new_n->next = NULL;
            trav_n->next = new_n;
            break;
        case '3':
            printf("Information:");
            scanf("%d", &new_n->info);
            printf("After Which Position:");
            scanf("%d", &pos);
            trav_n = h;
            for (int i = 1; i < pos; i++)
                trav_n = trav_n->next;
            new_n->next = trav_n->next;
            trav_n->next = new_n;
            break;
        case '4':
            break;
        default:
            printf("Wrong Input");
            break;
        }
    } while (ch != '4');
    return h;
}

void display_list(NODE *h)
{
    NODE *trav_n;
    trav_n = h;
    if (h == NULL)
        printf("\nLinked List Is Empty\n");
    else
    {
        printf("\nDisplaying Ressult:\n");
        while (trav_n != NULL)
        {
            printf("%d\n", trav_n->info);
            trav_n = trav_n->next;
        }
    }
}