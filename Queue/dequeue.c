#include <stdio.h>
int main(int argc, char const *argv[])
{
    int queue[5], front = -1, rear = -1,item;
    if (front!=-1)
    {
        printf("Enter a item:- ");
        scanf("%d",&item);
        if (front == -1 && rear == -1)
        {
            front = 0;
            rear = 0;
        }
        else
        {
            rear = rear + 1;
        }
        queue[rear]=item;
    }

    for(front=front;front<=rear;front++)
    printf("%d",queue[front]);

    return 0;
}
