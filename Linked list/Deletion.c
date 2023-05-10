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
    for(i=0;i<index-1 && ptr->next!=NULL;i++)
    {
        ptr=ptr->next;
    }
    struct node *ptr1;
    ptr1=ptr->next;
    ptr->next=createnode(item);
    ptr->next->next=ptr1;
}

//Deletion

void delete_front()
{
    head=head->next;
}

void delete_end()
{
    struct node *ptr=head,*ptr1;
    while(ptr->next!=NULL)
    {
        ptr1=ptr;
        ptr=ptr->next;
    }
    ptr1->next=NULL;
}

void delete_any(int index)
{
    struct node *ptr;
    ptr=head;
    int i;
    for(i=0;i<index-1 && ptr->next!=NULL;i++)
    {
        ptr=ptr->next;
    }
    ptr->next=ptr->next->next;
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
    printf("1.Insert at first\n2.Insert at any position\n3.Insert at last\n4.Delete front\n5.Delete any position\n6.Delete end\n7.Print\n8.Exit\n");
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
            delete_front();
            printf("\nDeleted!!");
            break;

            case 5:
            printf("Enter the index:- ");
            scanf("%d",&index);
            delete_any(index);
            printf("\nDeleted!!");
            break;

            case 6:
            delete_end();
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


