#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define max 100

typedef struct node
{
    char data;
    struct node *lchild;
    struct node *rchild;
}*nodeptr;

typedef struct patient
{
    int id;
    char name[max];
    int priority;
    int cost;
    struct patient *next;
    struct patient *stacknext;
    nodeptr exprRoot;
}*patient;

patient top = NULL;
patient head = NULL;

patient getNode()
{
    patient temp = (patient)malloc(sizeof(struct patient));
    if(temp==NULL)
    {
        printf("Allocation failed. \n");
        return;
    }
    temp->next = NULL;
    temp->stacknext = NULL;
    temp->exprRoot = NULL;
    return temp;
}

nodeptr getExprNode()
{
    nodeptr temp = (nodeptr)malloc(sizeof(struct node));
    if(temp==NULL)
    {
        printf("Allocation failed. \n");
        return NULL;
    }
    temp->lchild = temp->rchild = NULL;
    return temp;
}

void registerPatient(int id, char name[], int priority, int cost)
{
    patient temp2 = head;
    while(temp2)
    {
        if(temp2->id==id)
        {
            printf("Duplicates not allowed. \n");
            return;
        }
        temp2 = temp2->next;
    }
    patient temp = getNode();
    temp->id = id;
    temp->cost = cost;
    temp->priority = priority;
    strcpy(temp->name, name);
    if(head==NULL)
    {
        head = temp;
    }
    else
    {
        patient current = head;
        while(current->next!=NULL)
        {
            current = current->next;
        }
        current->next = temp;
    }

    temp->stacknext = top;
    top = temp;
    printf("Succesfully registered. \n");
}


void listPatients()
{
    if(head==NULL)
    {
        printf("Empty. \n");
        return;
    }
    patient current = head;
    while(current!=NULL)
    {
        printf("%s", current->name);
        current = current->next;
    }
}


void undoRegistration()
{
    if(top==NULL)
    {
        printf("Empty stack. \n");
        return;
    }
    patient x = top;
    if(head==x)
    {
        head = NULL;
    }
    else
    {
        patient current = head;
        while(current->next!=x)
            current = current->next;
        current->next = NULL;
    }
    top = top->stacknext;
    free(x->exprRoot);
    free(x);
}

void preOrderTraversalRec(nodeptr node)
{
    if(node==NULL)
        return;
    printf("%c", node->data);
    preOrderTraversalRec(node->lchild);
    preOrderTraversalRec(node->rchild);
}

void expressionTree(patient current)
{
    char postfix[max];
    printf("Enter the postfix expression: \n");
    scanf("%s", postfix);
    int top=-1;
    nodeptr stack[max];
    int i=0;
    while(postfix[i]!='\0')
    {
        if(postfix[i]==' ')
        {
            i++;
            continue;
        }
        nodeptr temp = getNode();
        temp->data = postfix[i];
        if(postfix[i]=='+' || postfix[i]=='-' || postfix[i]=='*' || postfix[i]=='/')
        {
            temp->rchild = stack[top--];
            temp->lchild = stack[top--];
        }
        stack[++top] = temp;
        i++;
    }
}