#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* prev;
    struct node* next;
};
struct node *head = NULL;

void insertBegin()
{
    struct node *newNode;
    newNode = (struct node*)malloc(sizeof(struct node));
    if(newNode==NULL)
    {
        printf("Overflow. \n");
        return;
    }
    printf("Enter the data: \n");
    int data;
    scanf("%d", &data);
    newNode->data = data;
    newNode->next = head;
    newNode->prev = NULL;
    if(head!=NULL)
    {
        head->prev = newNode;
    }
    head = newNode;
}


void insertEnd()
{
    struct node *newNode;
    newNode = (struct node*)malloc(sizeof(struct node));
    if(newNode==NULL)
    {
        printf("Overflow. \n");
        return;
    }
    printf("Enter the value: \n");
    int data;
    scanf("%d", &data);
    newNode->data = data;
    newNode->next = NULL;
    if(head==NULL)
    {
        newNode->prev = NULL;
        head = newNode;
    }
    else
    {
        struct node *temp = head;
        while(temp->next!=NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
        printf("Node inserted. \n");
    }
}


void insertMiddle()
{
    struct node *newNode, *temp;
    int loc;
    printf("Enter the location after which you want to insert: \n");
    scanf("%d", &loc);
    temp=head;
    for(int i=0; i<loc; i++)
    {
        if(temp==NULL)
        {
            printf("Overflow. \n");
            return;
        }
        temp=temp->next;
    }

    newNode = (struct node*)malloc(sizeof(struct node));
    if(newNode==NULL)
    {
        printf("Overflow. \n");
        return;
    }
    printf("Enter the value: \n");
    int data;
    scanf("%d", &data);
    newNode->data = data;
    newNode->next = temp->next;
    newNode->prev = temp;
    if(temp->next!=NULL)
    {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
    printf("Node inserted. \n");

}


void deleteBeginning()
{
    struct node *temp;
    if(head==NULL)
    {
        printf("List is empty. \n");
        return;
    }
    temp = head;
    head = head->next;
    if(head!=NULL)
    {
        head->prev = NULL;
    }
    free(temp);
    printf("Node deleted from beginning. \n");
}


void deleteEnd()
{
    struct node *temp;
    if(head==NULL)
    {
        printf("Overflow. \n");
        return;
    }
    temp = head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    if(temp->prev!=NULL)
    {
        temp->prev->next=NULL;
    }
    else
    {
        head=NULL;
    }
    free(temp);
    printf("Node deleted frome end. \n");
}


void deleteMiddle()
{
    struct node *temp;
    if(head==NULL)
    {
        printf("Overflow. \n");
        return;
    }
    temp = head;
    int loc;
    printf("Enter the location which you want to delete: \n");
    scanf("%d", &loc);
    for(int i=0; i<loc; i++)
    {
        temp=temp->next;
        if(temp==NULL)
        {
            printf("Position out of bounds. \n");
            return;
        }
    }
    if(temp->next!=NULL)
    {
        temp->next->prev = temp->prev;
    }
    if(temp->prev!=NULL)
    {
        temp->prev->next = temp->next;
    }
    if(temp==head)
    {
        head = temp->next;
    }
    free(temp);
}