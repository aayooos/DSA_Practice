#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};
struct node* head = NULL;

void beginInsert()
{
    struct node *newNode;
    newNode = (struct node*)malloc(sizeof(struct node));
    int data;
    if(newNode==NULL)
    {
        printf("Overflow\n");
        return;
    }
    else
    {
        printf("Enter the data: \n");
        scanf("%d", &data);
        newNode->data = data;
        newNode->next = head;
        head = newNode;
        printf("Node inserted at the beginning. \n");
    }
    
}

void lastInsert()
{
    struct node* newNode;
    newNode = (struct node*)malloc(sizeof(struct node));
    int data;
    if(newNode==NULL)
    {
        printf("Overflow. \n");
        return;
    }
    else
    {
        printf("Enter the data: \n");
        scanf("%d", &data);
        newNode->data = data;
        newNode->next = NULL;
        if(head==NULL)
        {
            head=newNode;
            printf("Node inserted at the last. \n");
            return;
        }
        else
        {
            struct node *temp;
            temp = head;
            while(temp->next!=NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            printf("Node inserted at the last. \n");
        }
    }
    
}


void insertBetween()
{
    struct node* newNode;
    newNode = (struct node*)malloc(sizeof(struct node));
    if(newNode==NULL)
    {
        printf("Overflow. \n");
        return;
    }
    else
    {
        int data;
        printf("Enter the data: \n");
        scanf("%d", &data);
        printf("Enter the location after which you want to insert the node: \n");
        int n;
        scanf("%d", &n);
        newNode->data = data;
        struct node* temp = head;
        for(int i=0; i<n; i++)
        {
            temp = temp->next;
            if(temp==NULL)
            {
                printf("Location is out of capacity. \n");
                return;
            }
        }
        newNode->next = temp->next;
        temp->next = newNode;
        printf("Node inserted. \n");
    }
}


void deleteFront()
{
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));
    if(temp==NULL)
    {
        printf("Overflow. \n");
        return;
    }
    else
    {
        temp = head;
        head = temp->next;
        free(temp);
        printf("Deleted node at the beginning. \n");
    }
}


void deleteLast()
{
    struct node *temp, *temp1;
    
    if(head==NULL)
    {
        printf("Overflow. \n");
        return;
    }
    else if(head->next==NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
        printf("Deleted the only node. \n");
    }
    else
    {
        temp = head;
        while(temp->next!=NULL)
        {
            temp1 = temp;
            temp = temp->next;
        }
        temp1->next = NULL;
        free(temp);
    }
}


void deleteMiddle()
{
    struct node *temp, *temp1;
    int loc;
    if(head==NULL)
    {
        printf("Overflow. \n");
        return;
    }
    temp = head;
    printf("Enter the location: \n");
    scanf("%d", &loc);
    if(loc==1)
    {
        head=head->next;
        free(temp);
        return;
    }
    for(int i=0; i<loc; i++)
    {
        temp1 = temp;
        temp = temp->next;
        if(temp==NULL)
        {
            printf("Location out of capacity. \n");
            return;
        }
    }
    temp1->next = temp->next;
    free(temp);
}


void search()
{
    struct node *temp;
    temp = head;
    if(head==NULL)
    {
        printf("List is empty. \n");
        return;
    }

    int n;
    int found=0;
    printf("Enter the element to be searched: \n");
    scanf("%d", &n);
    while(temp!=NULL)
    {
        if(temp->data==n)
        {
            found=1;
            break;
        }
        temp = temp->next;
    }

    if(found==0)
    {
        printf("Found. \n");
    }
    else
        printf("Not found. \n");
}


void reverseLL()
{
    struct node *next=NULL, *current=head, *prev=NULL;
    if(head==NULL)
    {
        printf("List is empty. \n");
        return;
    }

    while(current!=NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    printf("List is reversed. \n");
}


void displayLL()
{
    struct node *temp = head;
    if(head==NULL)
    {
        printf("List is empty. \n");
        return;
    }
    while(temp!=NULL)
    {
        printf("%d \n", temp->data);
        temp = temp->next;
    }
}


struct node* head1;
struct node* head2;
void concatLL()
{
    struct node *temp=head1;
    if(head1==NULL)
    {
        head1=head2;
        return;
    }
    if(head2==NULL)
    {
        return;
    }

    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    temp->next = head2;
}


/* linked list implementation of stacks */

struct node *top=NULL;

void push(int item)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if(newNode==NULL)
    {
        printf("Overflow. \n");
        return;
    }
    newNode->data = item;
    newNode->next = top;
    top=newNode;
}

int pop()
{
    if(top==NULL)
    {
        printf("Nothing to pop. \n");
        return;
    }

    struct node* temp = top;
    top=top->next;
    int val = temp->data;
    free(temp);
    return val;

}


void peek()
{
    if(top==NULL)
    {
        printf("List is empty. \n");
        return;
    }
    printf("%d", top->data);
}


/*queue implementation using singly linked list*/

struct node* front=NULL;
struct node* rear=NULL;

void enqueueQ(int item)
{
    struct node *newNode;
    newNode->data = item;
    if(rear==NULL)
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
}

int dequeueQ()
{
    struct node *temp=front;
    int val = front->data;
    front = front->next;
    if(front==NULL)
        rear=NULL;
    free(temp);
    return val;
}

/*multiple queues using linked list */

