#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int info;
    struct node *next;
} NODE;

NODE *h = NULL;

void insert_list(void);
void display_list(void);
void delete_list(void);
void dl(void);

void main()
{
    char n;
    int i, ch;
    do
    {
        printf("\nFunction:\n");
        printf("1.Insert \n2.Display\n3.Delete\n4.Exit\n");
        printf("Enter Your Choice:");
        scanf(" %d", &ch);
        switch (ch)
        {
        case 1:
            insert_list();
            break;
        case 2:
            display_list();
            break;
        case 3:
            delete_list();
            break;
        case 4:
            break;
        default:
            printf("Wrong Input\n");
            break;
        }
    } while (ch != 4);
}

void insert_list(void)
{
    NODE *new_n, *trav_n, *prev_n;
    int ch, pos;
    do
    {
        dl();
        new_n = (NODE *)malloc(sizeof(NODE));
        printf("\nWhere You Want To Insert:\n1.FRONT\n2.LAST\n3.AFTER POSITION\n4.BEFORE POSITION\n5.Exit\n");
        printf("Enter Your Choice:");
        getchar();
        scanf(" %d", &ch);
        printf("\n");
        if (ch == 2 || ch == 3 || ch == 4)
        {
            if (h == NULL)
            {
                printf("Linked List Is Empty\nFirst Insert a First NODE\n");
                goto first;
            }
        }
        switch (ch)
        {
        case 1:
        first:
            printf("Information:");
            scanf("%d", &new_n->info);
            new_n->next = h;
            h = new_n;
            break;
        case 2:
            printf("Information:");
            scanf("%d", &new_n->info);
            trav_n = h;
            while (trav_n->next != NULL)
                trav_n = trav_n->next;
            new_n->next = NULL;
            trav_n->next = new_n;
            break;
        case 3:
        after:
            printf("After Which Position:");
            scanf("%d", &pos);
            if (pos < 0)
            {
                printf("\nInvalid Input\n");
                goto after;
            }
            else if (pos == 0)
                goto first;
            else
            {
                trav_n = h;
                for (int i = 1; i < pos; i++)
                {
                    if (trav_n->next == NULL && i != pos - 1)
                    {
                        printf("Invalid Input\nList not Contain These no. Elements\n");
                        goto after;
                    }
                    trav_n = trav_n->next;
                }
            }
            printf("Information:");
            scanf("%d", &new_n->info);
            new_n->next = trav_n->next;
            trav_n->next = new_n;
            break;
        case 4:
        before:
            printf("Before Which Position:");
            scanf("%d", &pos);
            if (pos > 1)
            {
                trav_n = h;
                for (int i = 1; i < pos - 1; i++)
                {
                    if (trav_n->next == NULL)
                    {
                        printf("Invalid Input\nList not Contain These no. Elements\n");
                        goto before;
                    }
                    trav_n = trav_n->next;
                }
                printf("Information:");
                scanf("%d", &new_n->info);
                new_n->next = trav_n->next;
                trav_n->next = new_n;
            }
            else if (pos == 1)
                goto first;
            else
            {
                printf("\nInvalid Input\n");
                goto before;
            }
            break;
        case 5:
            break;
        default:
            printf("Wrong Input");
            break;
        }
    } while (ch != 5);
}

void dl(void)
{
    NODE *trav_n;
    trav_n = h;
    if (h == NULL)
        printf("\nLinked List Is Empty\n");
    else
    {
        printf("\nUpdated O/P: ");
        while (trav_n != NULL)
        {
            if (trav_n->next == NULL)
                printf("%d\n", trav_n->info);
            else
                printf("%d,", trav_n->info);
            trav_n = trav_n->next;
        }
    }
}

void display_list(void)
{
    NODE *trav_n;
    trav_n = h;
    if (h == NULL)
        printf("\nLinked List Is Empty\n");
    else
    {
        int i = 1;
        printf("\nDisplaying Ressult:\n");
        while (trav_n != NULL)
        {
            printf("%d. %d \n", i, trav_n->info);
            trav_n = trav_n->next;
            i++;
        }
    }
}

void delete_list(void)
{
    int pos, ch;

    if (h == NULL)
    {
        printf("\nLinked List is Empty\n");
    }
    else
    {
        do
        {
            dl();
            NODE *trav_n = h, *temp;
            printf("\nWhere You Want To Delete:\n1.FRONT\n2.LAST\n3.AFTER POSITION\n4.BEFORE POSITION\n5.Exit\n");
            printf("Enter Your Choice:");
            getchar();
            scanf(" %d", &ch);
            if (h == NULL)
            {
                printf("\nLinked List is Empty\nFirst Insert a Node\n");
                ch = 5;
            }
            switch (ch)
            {
            case 1:
            first:
                h = h->next;
                temp = trav_n;
                break;
            case 2:
                trav_n = h;
                if (h->next == NULL)
                {
                    temp = trav_n;
                    h = NULL;
                }
                else
                {
                    while (trav_n->next->next != NULL)
                        trav_n = trav_n->next;
                    temp = trav_n->next;
                    trav_n->next = NULL;
                }
                break;
            case 3:
            after:
                printf("After Which Position:");
                scanf("%d", &pos);
                if (pos == 0)
                    goto first;
                else if (pos > 0)
                {
                    trav_n = h;
                    for (int i = 1; i < pos; i++)
                    {
                        if (trav_n->next == NULL && i != pos - 1)
                        {
                            printf("Invalid Input\nList not Contain These no. Elements\n");
                            goto after;
                        }
                        trav_n = trav_n->next;
                    }
                    if (trav_n->next == NULL)
                    {
                        printf("Invalid Input\nList not Contain These no. Elements\n");
                        goto after;
                    }
                    temp = trav_n->next;
                    trav_n->next = trav_n->next->next;
                }
                else
                {
                    printf("\nInvalid Input\n");
                    goto after;
                }
                break;
            case 4:
            before:
                printf("Before Which Position:");
                scanf("%d", &pos);
                if (pos > 2)
                {
                    pos = pos - 2;
                    trav_n = h;
                    for (int i = 1; i < pos; i++)
                    {
                        if (trav_n->next == NULL && i != pos - 1)
                        {
                            printf("Invalid Input\nList not Contain These no. Elements\n");
                            goto after;
                        }
                        trav_n = trav_n->next;
                    }
                    if (trav_n->next == NULL)
                    {
                        printf("Invalid Input\nList not Contain These no. Elements\n");
                        goto before;
                    }
                    temp = trav_n->next;
                    trav_n->next = trav_n->next->next;
                }
                else if (pos == 2)
                    goto first;
                else
                {
                    printf("\nInvalid Input\n");
                    goto before;
                }
                break;
            case 5:
                break;
            default:
                printf("Wrong Input");
                break;
            }
            free(temp);
        } while (ch != 5);
    }
}