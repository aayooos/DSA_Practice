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

void attach(int coeff, int expo, polynode *ptr)
{
    polynode temp = getNode();
    temp->coeff = coeff;
    temp->expo = expo;
    (*ptr)->next = temp;
    *ptr = temp;
}

polynode createPoly()
{
    polynode head=NULL, rear=NULL;
    int expo, coeff, n;
    printf("Enter the number of terms: \n");
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        printf("Enter the coefficient and exponent value: \n");
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
            rear = temp;
        }
    }
    return head;
}

void printPoly(polynode p)
{
    if(p==NULL)
    {
        printf("Empty polynomial. \n");
        return;
    }
    while(p!=NULL)
    {
        printf("%dx^%d", p->coeff, p->expo);
        if(p->next!=NULL)
            printf(" + ");
        p=p->next;
    }
    printf("\n");
}

polynode padd(polynode a, polynode b)
{
    polynode head, rear, temp;
    rear = getNode();
    head = rear;
    while(a&&b)
    {
        switch(COMPARE(a->expo, b->expo))
        {
            case -1:
                attach(b->coeff, b->expo, &rear);
                b=b->next;
                break;
            case 0:
                int sum = a->coeff + b->coeff;
                attach(sum, a->expo, &rear);
                a=a->next;
                b=b->next;
                break;
            case 1:
                attach(a->coeff, a->expo, &rear);
                a=a->next;
                break;
        }
    }
    while(a!=NULL)
    {
        attach(a->coeff, a->expo, &rear);
        a=a->next;
    }
    while(b!=NULL)
    {
        attach(b->coeff, b->expo, &rear);
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

