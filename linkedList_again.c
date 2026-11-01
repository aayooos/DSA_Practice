#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}*nodeptr;

nodeptr head=NULL;


void beginInsert()
{
    nodeptr newNode = (nodeptr)malloc(sizeof(struct node));
    int data;
    if(newNode==NULL)
    {
        printf("Allocation failed. \n");
        return;
    }
    else
    {
        printf("Enter the data of the new node: \n");
        scanf("%d", &data);
        newNode->data=data;
        newNode->next = head;
        head = newNode;
        printf("New node inserted. \n");
    }
}

void lastInsert()
{
    nodeptr newNode = (nodeptr)malloc(sizeof(struct node));
    int data;
    if(newNode==NULL)
    {
        printf("Allocation failed. \n");
        return;
    }
    else
    {
        printf("Enter the data for the new node: \n");
        scanf("%d", &data);
        newNode->data = data;
        if(head==NULL)
        {
            head = newNode;
            return;
        }
        nodeptr temp = head;
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next = newNode;
        newNode->next = NULL;
    }
}


void insertMiddle()
{
    nodeptr newNode = (nodeptr)malloc(sizeof(struct node));
    if(newNode==NULL)
    {
        printf("Allocation failed. \n");
        return;
    }
    else
    {
        int data, n;
        printf("Enter the data of the new node and the location after which you want to insert it: \n");
        scanf("%d", &data);
        scanf("%d", &n);
        if(head==NULL)
        {
            printf("Empty list. \n");
            return;
        }
        nodeptr temp = head;
        for(int i=0; i<n; i++)
        {
            temp = temp->next;
            if(temp==NULL)
            {
                printf("Location out of bounds. \n");
                free(newNode);
                return;
            }
        }
        newNode->next = temp->next;
        temp->next = newNode;
        newNode->data = data;
        printf("Node inserted. \n");
    }

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
    free(temp);
    printf("Node deleted. \n");
}


void deleteLast()
{
    if(head==NULL)
    {
        printf("Empty list. \n");
        return;
    }
    if(head->next==NULL)
    {
        free(head);
        head=NULL;
        return;
    }
    nodeptr temp, temp1;
    temp=head;
    while(temp->next!=NULL)
    {
        temp1 = temp;
        temp = temp->next;
    }
    free(temp);
    temp1->next = NULL;
}


void deleteMiddle()
{
    nodeptr temp, temp1;
    if(head==NULL)
    {
        printf("Empty list. \n");
        return;
    }
    if(head->next==NULL)
    {
        free(head);
        head=NULL;
        return;
    }
    printf("Enter the location after which you want to delete. \n");
    int loc;
    scanf("%d", &loc);
    for(int i=0; i<loc; i++)
    {
        temp1 = temp;
        temp = temp->next;
        if(temp==NULL)
        {
            printf("Location out of bounds. \n");
            return;
        }
    }
    temp1->next = temp->next;
    free(temp);
    printf("Node deleted. \n");
}


