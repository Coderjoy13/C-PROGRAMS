#include<stdio.h>
#define size 100

int stack[size];
int top;

int full(int top)
{
    if(top==size)
    return 1;
    else
    return 0;
}

int empty(int top)
{
    if(top==-1)
    return 1;
    else
    return 0;
}

int push(int item)
{
    if(full(top)!=1)
    stack[++top]=item;

    printf("\ninserted");

}

int pop()
{
    if(empty(top)!=1)
    stack[--top];

    printf("\nDeleted");
}

int print()
{
    printf("\nStack element is:- ");
    for(int i=0;i<=top;i++)
    {
        printf("\n%d",stack[i]);
    }
}

int main(int argc, char const *argv[])
{
    int item,data;
    top=-1;
    printf("1.Push\n2.Pop\n3.Print\n4.Exit");

    while(1)
    {
        printf("\nGive your opinion:- ");
        scanf("%d",&item);
        switch(item)
        {
            case 1:
            if(full(top)==1)
            printf("\nStack is full");
            else{
                printf("Enter the data which you want to enter in stack:- ");
                scanf("%d",&data);
                push(data);
            }
            break;

            case 2:
            if(empty(top)==1)
            printf("\nStack is Empty");
            else{
                pop();
            }
            break;

            case 3:
            print();
            break;

            case 4:
            printf("Bye!!");
            return 0;

            default :
            printf("Please enter approprite data");

        }
    }
    return 0;
}
