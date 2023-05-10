#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

struct node *head;

struct node *createnode(int item)
{
    struct node *new_node;
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = item;
    new_node->next = NULL;
};

void insert_at_first(int item)
{
    if (head == NULL)
    {
        head = createnode(item);
        head->next = head;
        return;
    }

    struct node *ptr, *ptr1;
    ptr = createnode(item);
    ptr1 = head;
    while (ptr1->next != head)
    {
        ptr1 = ptr1->next;
    }
    ptr1->next = ptr;
    ptr->next = head;
    head = ptr;
}

void insert_at_any(int item, int index)
{
    if (head == NULL)
    {
        head = createnode(item);
        head->next = head;
        return;
    }

    struct node *ptr, *temp;
    ptr = head;
    int i;
    for (i = 0; i < index - 1; i++)
    {
        ptr = ptr->next;
    }
    temp = ptr->next;
    ptr->next = createnode(item);
    ptr->next->next = temp;
}

void insert_at_last(int item)
{
    if (head == NULL)
    {
        head = createnode(item);
        head->next = head;
        return;
    }

    struct node *ptr;
    ptr = head;
    while (ptr->next != head)
    {
        ptr = ptr->next;
    }
    ptr->next = createnode(item);
    ptr->next->next = head;
}

// Deletion

void delete_at_first()
{
    struct node *ptr, *ptr1;
    ptr1 = head->next;
    ptr = head;
    if (head == NULL)
        printf("List is empty!");
    else
    {
        while (ptr->next != head)
        {
            ptr = ptr->next;
        }
        ptr->next = ptr1;
        head = ptr1;
    }
}

void delete_at_any(int index)
{
    struct node *ptr;
    ptr = head;
    for (int i = 0; i < index - 1; i++)
    {
        ptr = ptr->next;
    }
    ptr->next = ptr->next->next;
}

void delete_at_last()
{
    struct node *ptr, *ptr1;
    ptr = head;
    while (ptr->next != head)
    {
        ptr1 = ptr;
        ptr = ptr->next;
    }
    ptr1->next = head;
}

void print()
{
    printf("Element is:- ");
    struct node *ptr = head;
    if (ptr == NULL)
        printf("List is empty");
    else
    {
        while (ptr->next != head)
        {
            printf("\n%d", ptr->data);
            ptr = ptr->next;
        }
        printf("\n%d", ptr->data);
    }
}

int main(int argc, char const *argv[])
{
    head = NULL;
    printf("\n1.Insert at first\n2.Insert at any position\n3.Insert at last\n4.Print\n5.Exit");
    int item, index, i, data;
    printf("1.Insert at first\n2.Insert at any position\n3.Insert at last\n4.Delete front\n5.Delete any position\n6.Delete end\n7.Print\n8.Exit\n");
    while (1)
    {
        printf("\nEnter your opinion:- ");
        scanf("%d", &data);
        switch (data)
        {
        case 1:
            printf("Enter any integer:- ");
            scanf("%d", &item);
            insert_at_first(item);
            printf("Inserted!!");
            break;

        case 2:
            printf("Enter any integer:- ");
            scanf("%d", &item);
            printf("Enter the index:- ");
            scanf("%d", &index);
            insert_at_any(item, index);
            printf("Inserted!!");
            break;

        case 3:
            printf("Enter any integer:- ");
            scanf("%d", &item);
            insert_at_last(item);
            printf("Inserted!!");
            break;

        case 4:
            delete_at_first();
            printf("\nDeleted!!");
            break;

        case 5:
            printf("Enter the index:- ");
            scanf("%d", &index);
            delete_at_any(index);
            printf("\nDeleted!!");
            break;

        case 6:
            delete_at_last();
            printf("\nDeleted!!");
            break;

        case 7:
            print();
            break;

        case 8:
            printf("Bye!!");
            return 0;

        default:
            printf("\nError");
            break;
        }
    }
    return 0;
}
