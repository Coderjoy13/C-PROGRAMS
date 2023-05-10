#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int size;
    int f;
    int r;
    int *arr;
};

int insert(struct queue *ptr, int item)
{
    if (ptr->r == -1)
    {
        ptr->arr[0] = item;
        ptr->r = ptr->r + 1;
        return 0;
    }
    ptr->arr[++ptr->r]=item;
    // ptr->r = ptr->r + 1;
}



int main(int argc, char const *argv[])
{
    struct queue *q;
    q->size = 100;
    q->f = -1;
    q->r = -1;
    q->arr = (int *)malloc(q->size * sizeof(int));
    insert(q, 80);
    insert(q, 3);
    insert(q, 8);
    insert(q, 70);
    insert(q, 10);

    for(int i=0;i<=q->r;i++)
    {
        printf("\n%d",q->arr[i]);
    }

    return 0;
}
