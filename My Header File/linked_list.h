typedef struct node
{
    int info;
    struct node *next;
} * NODE;
NODE head = NULL, current = NULL, prev = NULL;

void delete_list();
void insert_list();
NODE createnode();
void printList();
void insertFirst(int data);
void deleteFirst(void);
void insertLast(int data);
void deleteLast(void);
void insertAfter(int pos, int data);
void deleteAfter(int pos);
void insertBefore(int pos, int data);
void deleteBefore(int pos);

void delete_list()
{
    int ch, pos;
    do
    {
        if (head == NULL)
        {
            printf("Linked List Is Empty\nFirst Insert a First NODE in Front\n");
            return;
        }
        printList();
        printf("\nWhere You Want To Delete:\n1.FRONT\n2.LAST\n3.AFTER POSITION\n4.BEFORE POSITION\n5.Exit\n");
        printf("Enter Your Choice:");
        scanf(" %d", &ch);
        printf("\n");
        if (ch == 2 || ch == 3 || ch == 4)
        {
            if (head == NULL)
            {
                printf("Linked List Is Empty\nFirst Insert a First NODE\n");
                return;
            }
        }
        switch (ch)
        {
        case 1:
            deleteFirst();
            break;
        case 2:
            deleteLast();
            break;
        case 3:
            do
            {
                printf("After which position:");
                scanf("%d", &pos);
            } while (pos < 0);
            if (pos == 0)
            {
                deleteFirst();
                break;
            }
            deleteAfter(pos);
            break;
        case 4:
            do
            {
                printf("Before which position:");
                scanf("%d", &pos);
            } while (pos < 2);
            if (pos == 2)
            {
                deleteFirst();
                break;
            }
            deleteBefore(pos);
            break;
        case 5:
            break;
        default:
            printf("\nWrong Input\n");
            break;
        }
    } while (ch != 5);
}

void insert_list()
{
    int ch, data, pos;
    do
    {
        printList();
        printf("\nWhere You Want To Insert:\n1.FRONT\n2.LAST\n3.AFTER POSITION\n4.BEFORE POSITION\n5.Exit\n");
        printf("Enter Your Choice:");
        scanf(" %d", &ch);
        printf("\n");
        if (ch == 2 || ch == 3 || ch == 4)
        {
            if (head == NULL)
            {
                printf("Linked List Is Empty\nFirst Insert a First NODE in Front\n");
                ch = 1;
            }
        }
        switch (ch)
        {
        case 1:
            printf("Enter Information:");
            scanf("%d", &data);
            insertFirst(data);
            break;
        case 2:
            printf("Enter Information:");
            scanf("%d", &data);
            insertLast(data);
            break;
        case 3:
            do
            {
                printf("After which position:");
                scanf("%d", &pos);
            } while (pos < 0);
            printf("Enter Information:");
            scanf("%d", &data);
            if (pos == 0)
            {
                insertFirst(data);
                break;
            }
            insertAfter(pos, data);
            break;
        case 4:
            do
            {
                printf("Before which position:");
                scanf("%d", &pos);
            } while (pos < 1);
            printf("Enter Information:");
            scanf("%d", &data);
            if (pos == 1)
            {
                insertFirst(data);
                break;
            }
            insertBefore(pos, data);
            break;
        case 5:
            break;
        default:
            printf("\nWrong Input\n");
            break;
        }
    } while (ch != 5);
}

NODE createnode()
{
    NODE new_n;
    new_n = (NODE)malloc(sizeof(NODE));
    new_n->next = NULL;
    return new_n;
}

void printList()
{
    NODE ptr = head;
    printf("\n[ ");
    if (head == NULL)
    {
        printf("Linked List is Empty");
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

void insertFirst(int data)
{
    NODE link = createnode();
    link->info = data;
    link->next = head;
    head = link;
}

void deleteFirst(void)
{
    NODE temp = head;
    head = head->next;
    free(temp);
}

void insertLast(int data)
{
    NODE link = createnode();
    NODE trav_n = head;
    while (trav_n->next != NULL)
        trav_n = trav_n->next;
    trav_n->next = link;
    link->info = data;
    link->next = NULL;
}

void deleteLast(void)
{
    NODE temp;
    current = head;
    if (head->next == NULL)
    {
        free(current);
        head = NULL;
        return;
    }
    while (current->next->next != NULL)
        current = current->next;
    temp = current->next;
    current->next = NULL;
    free(temp);
}

void insertAfter(int pos, int data)
{
    if(pos<0)
    {
        printf("\nInvalid Input\n");
        return;
    }
    else if (pos == 0)
    {
        insertFirst(data);
        return;
    }
    NODE link = createnode();
    link->info = data;
    prev = head;
    for (int i = 1; i < pos; i++)
    {
        if (prev->next == NULL && i != pos - 2)
        {
            printf("Invalid Input\nList not Contain These no. Elements\n");
            return;
        }
        prev = prev->next;
    }
    link->next = prev->next;
    prev->next = link;
}

void deleteAfter(int pos)
{
    if(pos<0)
    {
        printf("\nInvalid Input\n");
        return;
    }
    else if (pos == 0)
    {
        deleteFirst();
        return;
    }
    current = head;
    prev = head;
    for (int i = 1; i < pos; i++)
    {
        if (prev->next == NULL)
        {
            printf("Invalid Input\nList not Contain These no. Elements\n");
            return;
        }
        prev = prev->next;
    }
    if (prev->next == NULL)
    {
        printf("Invalid Input\nList not Contain These no. Elements\n");
        return;
    }
    current = prev->next;
    prev->next = current->next;
    free(current);
}

void insertBefore(int pos, int data)
{
    if(pos<1)
    {
        printf("\nInvalid Input\n");
        return;
    }
    else if (pos == 1)
    {
        insertFirst(data);
        return;
    }
    NODE link = createnode();
    link->info = data;
    current = head;
    prev = head;
    for (int i = 1; i < pos - 1; i++)
    {
        if (prev->next == NULL)
        {
            printf("Invalid Input\nList not Contain These no. Elements\n");
            return;
        }
        prev = prev->next;
    }
    if (prev->next == NULL)
    {
        printf("Invalid Input\nList not Contain These no. Elements\n");
        return;
    }
    current = prev->next;
    prev->next = link;
    link->next = current;
}

void deleteBefore(int pos)
{
    if(pos<2)
    {
        printf("\nInvalid Input\n");
        return;
    }
    else if (pos == 2)
    {
        deleteFirst();
        return;
    }
    current = head;
    prev = head;
    for (int i = 1; i < pos - 2; i++)
    {
        if (prev->next == NULL)
        {
            printf("Invalid Input\nList not Contain These no. Elements\n");
            return;
        }
        prev = prev->next;
    }
    current = prev->next;
    prev->next = current->next;
    free(current);
}
