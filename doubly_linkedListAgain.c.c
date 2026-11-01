#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
}*nodeptr;


nodeptr head=NULL;

void insertBegin()
{
    nodeptr newNode = (nodeptr)malloc(sizeof(struct node));
    if(newNode==NULL)
    {
        printf("Allocation failed. \n");
        return;
    }
    printf("Enter value: \n");
    int data;
    scanf("%d", &data);
    newNode->data = data;
    newNode->next = head;
    newNode->prev = NULL;
    if(head!=NULL)
        head->prev = newNode;
    head = newNode;
    printf("Node inserted in the beginning. \n");
}


void insertEnd()
{
    nodeptr newNode = (nodeptr)malloc(sizeof(struct node));
    if(newNode==NULL)
    {
        printf("Allocation failed. \n");
        return;
    }
    printf("Enter the data: \n");
    int data;
    scanf("%d", &data);
    newNode->next = NULL;
    if(head==NULL)
    {
        newNode->prev = NULL;
        head = newNode;
        return;
    }
    nodeptr temp = head;
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;

}


void insertMiddle()
{
    nodeptr newNode = (nodeptr)malloc(sizeof(struct node));
    if(newNode==NULL)
    {
        printf("Allocation failed. \n");
        return;
    }
    if(head==NULL)
    {
        printf("Empty list. \n");
        return;
    }
    printf("Enter the data and location after which you want to insert: ");
    int data, loc;
    scanf("%d", &data);
    scanf("%d", &loc);
    newNode->data = data;
    nodeptr temp = head;
    for(int i=0; i<loc; i++)
    {
        temp = temp->next;
        if(temp==NULL)
        {
            printf("Location out of bounds. \n");
            return;
        }
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    if(temp->next!=NULL)
        temp->next->prev = newNode;
    temp->next = newNode;
    printf("Node inserted in between. \n");
}


void deleteFront()
{
    if(head==NULL)
    {
        printf("Empty list. \n");
        return;
    }
    nodeptr temp = head;
    head = head->next;
    if(head!=NULL)
        head->prev = NULL;
    free(temp);
}


void deleteEnd()
{
    if(head==NULL)
    {
        printf("Empty list. \n");
        return;
    }
    nodeptr temp = head;
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    if(temp->prev!=NULL)
        temp->prev->next = NULL;
    free(temp);
}


void deleteMiddle()
{
    if(head==NULL)
    {
        printf("Empty list. \n");
        return;
    }
    printf("Enter the location which you want to delete: \n");
    int loc;
    scanf("%d", &loc);
    nodeptr temp = head;
    for(int i=0; i<loc; i++)
    {
        temp = temp->next;
        if(temp==NULL)
        {
            printf("Location out of bounds. \n");
            return;
        }
    }
    if(temp->next!=NULL)
        temp->next->prev = temp->prev;
    if(temp->prev!=NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;
    free(temp);
}


