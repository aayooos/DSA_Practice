#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define max 100

typedef struct polynode
{
    int coeff;
    int expo;
    struct polynode *next;
}*polynode;

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

int compare(int a, int b)
{
    if(a>b)
        return -1;
    else if(a<b)
        return 1;
    else return 0;
}

void attach(int coeff, int expo, polynode *rear)
{
    polynode temp = getNode();
    temp->coeff = coeff;
    temp->expo = expo;
    (*rear)->next = temp;
    *rear = temp;
}

polynode readPolynomial()
{
    int n;
    polynode head, rear;
    printf("Enter the number of terms: \n");
    scanf("%d", &n);
    head = getNode();
    rear = head;
    for(int i=0; i<n; i++)
    {
        printf("Enter the coeff and expo of the node: \n");
        int coeff, expo;
        scanf("%d", &coeff);
        scanf("%d", &expo);
        if(coeff!=0)
            attach(coeff, expo, &rear);
    }
    polynode temp = head;
    head = head->next;
    free(temp);
    return head;
}

polynode add(polynode a, polynode b)
{
    polynode head, rear;
    head = getNode();
    rear = head;
    while(a&&b)
    {
        switch(compare(a->expo, b->expo))
        {
            case -1:
                attach(a->coeff, a->expo, &rear);
                break;
            case 1:
                attach(b->coeff, b->expo, &rear);
                break;
            case 0:
                int sum = a->coeff + b->coeff;
                attach(sum, a->expo, &rear);
                break;
        }
    }
    for(; a; a=a->next)
        attach(a->coeff, a->expo, &rear);
    for(; b; b=b->next)
        attach(b->coeff, b->expo, &rear);
    polynode temp = head;
    head = head->next;
    free(temp);
    return head;
}