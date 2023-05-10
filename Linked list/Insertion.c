#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *head;

struct node *createnode(int item)
{
    struct node *new_node;
    new_node=(struct node *) malloc(sizeof(struct node));
    new_node->data=item;
    new_node->next=NULL;
}

void insert_at_first(int item)
{
    if(head==NULL)
    {
        head=createnode(item);
        return;
    }
    struct node *ptr;
    ptr=createnode(item);
    ptr->next=head;
    head=ptr;
}

void insert_at_last(int item)
{
    if(head==NULL)
    {
        head=createnode(item);
        return;
    }
    struct node *ptr=head;
    while(ptr->next!=NULL)
    {
       ptr=ptr->next;
    }
    ptr->next=createnode(item);
}

void insert_at_any(int item,int index)
{
    if(head==NULL)
    {
        head=createnode(item);
        return;
    }
    struct node *ptr=head;
    int i;
    for(i=0;i<index-2 && ptr->next!=NULL;i++)
    {
        ptr=ptr->next;
    }
    struct node *ptr1;
    ptr1=ptr->next;
    ptr->next=createnode(item);
    ptr->next->next=ptr1;
}

void print()
{
    struct node *ptr;
    ptr=head;
    printf("Element is:- ");
    while(ptr!=NULL)
    {
        printf("\n%d",ptr->data);
        ptr=ptr->next;
    }
}

int main(int argc, char const *argv[])
{
    head=NULL;
    int data,item,index;
    printf("1.Insert at first\n2.Insert at any position\n3.Insert at last\n4.Print\n5.Exit\n");
    while(1)
    {
        printf("\nEnter your opinion:- ");
        scanf("%d",&data);
        switch(data)
        {
            case 1:
            printf("Enter any integer:- ");
            scanf("%d",&item);
            insert_at_first(item);
            printf("Inserted!!");
            break;

            case 2:
            printf("Enter any integer:- ");
            scanf("%d",&item);
            printf("Enter the index:- ");
            scanf("%d", &index);
            insert_at_any(item, index);
            printf("Inserted!!");
            break;

            case 3:
            printf("Enter any integer:- ");
            scanf("%d",&item);
            insert_at_last(item);
            printf("Inserted!!");
            break;

            case 4:
            print();
            break;

            case 5:
            printf("\n Bye");
            return 0;
            
            default:
            printf("\nError");
            break;
        }
    }
    return 0;
}
