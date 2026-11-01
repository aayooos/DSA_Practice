#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}*nodeptr;

nodeptr iful(nodeptr last)
{
    nodeptr temp = (nodeptr)malloc(sizeof(struct node));
    printf("Enter the data: \n");
    int data;
    scanf("%d", &data);
    temp->data = data;
    if(last==NULL)
    {
        last = temp;
        last->next = last;
    }
    else
    {
        temp->next = last->next;
        last->next = temp;
    }
    return last;
}


nodeptr ifuh(nodeptr head)
{
    nodeptr temp = (nodeptr)malloc(sizeof(struct node));
    printf("Enter the data: \n");
    int data;
    scanf("%d", &data);
    temp->data = data;
    if(head==NULL)
    {
        head = temp;
        temp->next = head;
    }
    else
    {
        temp->next = head;
        nodeptr current = head;
        while(current->next!=head)
            current = current->next;
        current->next = temp;
        head = temp;
    }
    return head;
}


nodeptr ieul(nodeptr last)
{
    nodeptr temp = (nodeptr)malloc(sizeof(struct node));
    printf("Enter the data: \n");
    int data;
    scanf("%d", &data);
    temp->data = data;
    if(last==NULL)
    {
        last = temp;
        last->next = last;
    }
    else
    {
        temp->next = last->next;
        last->next = temp;
        last = temp;
    }
    return last;
}


nodeptr ieuh(nodeptr head)
{
    nodeptr temp = (nodeptr)malloc(sizeof(struct node));
    printf("Enter the data: \n");
    int data;
    scanf("%d", &data);
    temp->data = data;
    if(head==NULL)
    {
        head = temp;
        temp->next = temp;
    }
    else
    {
        nodeptr current = head;
        while(current->next!=head)
        {
            current = current->next;
        }
        temp->next = current->next;
        current->next = temp;
    }
    return head;
}


nodeptr dful(nodeptr last)
{
    if(last==NULL)
    {
        printf("Nothing to delete. \n");
        return NULL;
    }
    if(last->next == last)
    {
        free(last);
        printf("Deleted only node. \n");
        return NULL;
    }
    nodeptr temp = last->next;
    last->next = temp->next;
    free(temp);
    printf("Deleted first node. \n");
    return last;
}


nodeptr dfuh(nodeptr head)
{
    if(head==NULL)
    {
        printf("Nothing to delete. \n");
        return NULL;
    }
    if(head->next == head)
    {
        free(head);
        printf("Deleted only node. \n");
        return NULL;
    }
    nodeptr temp = head->next;
    nodeptr current = head;
    while(current->next!=head)
        current = current->next;
    current->next = temp;
    free(head);
    head = temp;
    return head;
}


nodeptr dluh(nodeptr head)
{
    if(head==NULL)
    {
        printf("Nothing to delete. \n");
        return NULL;
    }
    if(head==head->next)
    {
        free(head);
        printf("Deleted only node. \n");
        return NULL;
    }
    nodeptr current = head;
    while(current->next->next!=head)
        current = current->next;
    free(current->next);
    current->next = head;
    return head;
}


nodeptr dlul(nodeptr last)
{
    if(last==NULL)
    {
        printf("Nothing to delete. \n");
        return NULL;
    }
    if(last->next==last)
    {
        free(last);
        printf("Deleted only node. \n");
        return NULL;
    }

    nodeptr current = last->next;
    while(current->next != last)
        current = current->next;
    current->next = last->next;
    free(last);
    last = current;
    return last;
}