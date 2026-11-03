#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

void attach(int coefficient, int exponent, polynode *ptr)
{
    polynode temp = getNode();
    temp->coeff = coefficient;
    temp->expo = exponent;
    (*ptr)->next = temp;
    *ptr = temp;
}

polynode readPoly()
{
    polynode head, rear;
    int n, coeff, expo;
    head = getNode();
    rear = head;
    printf("Enter number of terms: \n");
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        printf("Enter the coefficient and exponenet: \n");
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

int compare(int a, int b)
{
    if(a>b)
        return -1;
    else if(a<b)
        return -1;
    else return 0;
}

polynode add(polynode a, polynode b)
{
    polynode rear, temp, c;
    int sum;
    rear = getNode();
    c = rear;
    while(a&&b)
    {
        switch(compare(a->coeff, b->coeff))
        {
            case -1:
                attach(a->coeff, a->expo, &rear);
                a = a->next;
                break;
            case 0:
                sum = a->expo + b->expo;
                attach(sum, a->expo, &rear);
                break;
            case 1:
                attach(b->coeff, b->expo, &rear);
                b = b->next;
                break;
        }
    }
    for(; a; a = a->next)
        attach(a->coeff, a->expo, &rear);


    // Attach remaining terms from b

    for(; b; b = b->next)
        attach(b->coeff, b->expo, &rear);

    temp = c;
    c = c->next;
    free(temp);
}