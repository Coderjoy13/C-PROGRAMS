#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
void traversal(struct node *ptr)
{
    while(ptr!=NULL)
    {
       printf("\n%d",ptr->data);
        ptr=ptr->next;
    }
}

int main(struct node argc, char const *argv[])
{
  struct node *head;
  struct node *second;
  struct node *third;
  struct node *forth;

  head=(struct node *) malloc(sizeof(struct node));
  second=(struct node *) malloc(sizeof(struct node));
  third=(struct node *) malloc(sizeof(struct node));
  forth=(struct node *) malloc(sizeof(struct node));
  head->data=7;
  head->next=second;

  
  second->data=12;
  second->next=third;

  
  third->data=15;
  third->next=forth;

 
  forth->data=20;
  forth->next=NULL; 
  traversal(head);
    return 0;
}


