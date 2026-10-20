#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;

void odd_eve()
{
    if(head==NULL || head->next==NULL)
    {
        printf("Not enough nodes. \n");
        return;
    }
    struct node *odd = head;
    struct node *even = head->next;
    struct node *evenHead = even;

    while(even!=NULL && even->next!=NULL)
    {
        odd->next = odd->next->next;
        even->next = even->next->next;
        odd=odd->next;
        even=even->next;
    }
    odd->next = evenHead;

}