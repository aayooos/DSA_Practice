#include <stdio.h>
#include <stdlib.h>

typedef struct polynode
{
    int expo;
    int coeff;
    struct polynode *next;
}*polynode;

#define COMPARE(x, y) (((x) < (y)) ? -1 : ((x) == (y)) ? 0 : 1)

polynode getNode()
{
    polynode temp = (polynode)malloc(sizeof(struct polynode));
    if(temp==NULL)
    {
        printf("Allocation failed. \n");
        return NULL;
    }
    temp->next = NULL;
    return temp;
}

void attach(int expo, int coeff, polynode *ptr)
{
    polynode temp = getNode();
    temp->coeff = coeff;
    temp->expo = expo;
    (*ptr)->next = temp;
    *ptr = temp;
}

polynode createPoly()
{
    int n;
    polynode head=NULL, rear=NULL;
    int coeff, expo;
    printf("Enter the number of terms: \n");
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        printf("Enter the coefficient and exponent : \n");
        scanf("%d %d \n", &coeff, &expo);
        polynode temp = getNode();
        temp->coeff = coeff;
        temp->expo = expo;
        if(head==NULL)
        {
            head = temp;
            rear = temp;
        }
        else
        {
            rear->next = temp;
            temp = rear;
        }
    }
    return head;
}

void printpoly(polynode head)
{
    if(head==NULL)
    {
        printf("Empty polynomial. \n");
        return;
    }
    while(head!=NULL)
    {
        printf("%dx^%d", head->coeff, head->expo);
        if(head->next!=NULL)
            printf(" + ");
        head = head->next;
    }
}

polynode padd(polynode a, polynode b)
{
    polynode head, rear, temp;
    rear = getNode();
    head = rear;
    while(a&&b)
    {
        switch(COMPARE(a, b))
        {
            case -1:
                attach(b->expo, b->coeff, &rear);
                b=b->next;
                break;
            case 0:
                int sum = a->coeff + b->coeff;
                attach(a->expo, sum, &rear);
                a=a->next;
                b=b->next;
                break;
            case 1:
                attach(a->expo, a->coeff, &rear);
                a=a->next;
                break;
        }
    }
    while(a!=NULL)
    {
        attach(a->expo, a->coeff, &rear);
        a=a->next;
    }
    while(b!=NULL)
    {
        attach(b->expo, b->coeff, &rear);
        b=b->next;
    }
    rear->next = NULL;
    temp = head;
    head = head->next;
    free(temp);
    return head;
}

void erase(polynode *ptr)
{
    polynode temp;
    while(*ptr)
    {
        temp = *ptr;
        *ptr = (*ptr)->next;
        free(temp);
    }
}