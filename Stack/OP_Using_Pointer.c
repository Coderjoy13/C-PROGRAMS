#include <stdio.h>
int stack[10], top = -1;

int push()
{
    if (top == 10)
        printf("Stack is full");
    else
    {
        printf("Enter any number to insert in the stack:- ");
        int item;
        scanf("%d", &item);
        top = top + 1;
        stack[top] = item;
        printf("Inserted");
    }
}

int push()
{
    if (top == -1)
        printf("Stack is empty!");
    else
    {
        stack[--top];
        printf("Deleted");
    }
}

int print()
{
    int i;
    for (i = 0; i <= top; i++)
    {
        printf("%d", stack[i]);
    }
}

int main(int argc, char const *argv[])
{
    printf("1.Push\n2.Pop\n3.Print\n4.Exit");

    while (1)
    {
        printf("\nGive your opinion:- ");
        scanf("%d", &item);
        switch (item)
        {
        case 1:
            push();
            break;

        case 2:
                pop();
            break;

        case 3:
            print();
            break;

        case 4:
            printf("Bye!!");
            return 0;

        default:
            printf("Please enter approprite data");
        }
    }
    return 0;
}
