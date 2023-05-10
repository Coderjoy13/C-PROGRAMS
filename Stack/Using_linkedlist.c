#include <stdio.h>
#include <stdlib.h>

struct node
{
    int item;
    struct node *next;
};
struct node *top;

int isFull()
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
        return 1;
    else
        return 0;
}

int isEmpty()
{
    if (top == NULL)
        return 1;
    else
        return 0;
}

int push(int item)
{
    if (isFull())
        printf("stack is full");
    else
    {
        struct node *ptr = (struct node *)malloc(sizeof(struct node));
        ptr->item = item;
        ptr->next = NULL;

        if (top != NULL)
            ptr->next = top;

        top = ptr;
        printf("Inserted");
    }
}

int pop()
{
    if (isEmpty())
        printf("Stack is empty");
    else
    {
        struct node *item=top;
        int x=item->item;
        top=top->next;
        return x;
    }
}

int print()
{
    if (isEmpty())
        printf("Stack is empty");
    else
    {
        struct node *temp = top;
        while (temp)
        {
            printf("%d -> ", temp->item);
            temp = temp->next;
        }
    }
}

int main(int argc, char const *argv[])
{
    int choice, item;
    top = NULL;

    printf("\n== STACK OPERATIONS ==\n");
    printf("\n1. Print Stack"
           "\n2. Push"
           "\n3. Pop"
           "\n0. Exit");

    while (1)
    {
        printf("\n> ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 0:
            printf("Bye!\n");
            return 0;
            break;

        case 1:
            print();
            break;

        case 2:
            printf("Enter an item to be pushed: ");
            scanf("%d", &item);
            push(item);
            break;

            case 3:
            	if (isEmpty())
            	{
            		printf("Stack Underflow! No pop possible.\n");
            		continue;
            	}
            	item = pop();
            	printf("Popped item: %d\n", item);
            	break;

        default:
            printf("Invalid choice! Try again...\n");
            break;
        }
    }

    return 0;
}
