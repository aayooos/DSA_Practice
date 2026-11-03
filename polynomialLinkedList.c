#include <stdio.h>
#include <stdlib.h>

typedef struct polynode
{
    int coeff;
    int expo;
    struct polynode *next;
}*polynode;

#define COMPARE(x, y) (((x) < (y)) ? -1 : ((x) == (y)) ? 0 : 1)

polynode getNode()
{
    polynode temp = (polynode)malloc(sizeof(struct polynode));
    if(temp == NULL)
    {
        printf("Allocation failed.\n");
        exit(1);
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

polynode createPoly()
{
    polynode head = NULL, rear = NULL;
    int coef, expo, n;
    printf("Enter number of terms:\n");
    scanf("%d", &n);
    printf("Enter terms in descending order of exponent (coef expo):\n");
    for(int i = 0; i < n; i++)
    {
        scanf("%d %d", &coef, &expo);
        polynode temp = getNode();
        temp->coeff = coef;
        temp->expo = expo;
        if(head == NULL)
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

void print_poly(polynode p)
{
    if(p == NULL)
    {
        printf("Empty polynomial\n");
        return;
    }
    while(p != NULL)
    {
        printf("%dx^%d", p->coeff, p->expo);
        if(p->next != NULL)
            printf(" + ");
        p = p->next;
    }
    printf("\n");
}

polynode padd(polynode a, polynode b)
{
    polynode head, rear, temp;
    int sum;

    rear = getNode();
    head = rear;

    while(a && b)
    {
        switch(COMPARE(a->expo, b->expo))
        {
            case -1:
                attach(b->coeff, b->expo, &rear);
                b = b->next;
                break;

            case 0:
                sum = a->coeff + b->coeff;
                if(sum != 0)
                    attach(sum, a->expo, &rear);
                a = a->next;
                b = b->next;
                break;

            case 1:
                attach(a->coeff, a->expo, &rear);
                a = a->next;
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

int main()
{
    polynode a, b, c;
    printf("Enter polynomial A:\n");
    a = createPoly();
    printf("Enter polynomial B:\n");
    b = createPoly();
    printf("\nA = ");
    print_poly(a);
    printf("B = ");
    print_poly(b);
    c = padd(a, b);
    printf("A + B = ");
    print_poly(c);
    erase(&a);
    erase(&b);
    erase(&c);
    return 0;
}