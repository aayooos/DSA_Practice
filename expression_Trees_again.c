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

nodeptr buildExpressionTree(char postfix[])
{
    int i=0;
    int top=-1;
    nodeptr stack[max];
    nodeptr temp = (nodeptr)malloc(sizeof(struct node));
    if(temp==NULL)
    {
        printf("Allocation failed. \n");
        return NULL;
    }
    temp->data = postfix[i];
    while(postfix[i]!='\0')
    {
        if(postfix[i]==' ')
        {
            i++;
            continue;
        }
        if(postfix=='+' || postfix=='-' || postfix=='*' || postfix=='/')
        {
            temp->rchild = stack[top--];
            temp->lchild = stack[top--];
        }
        stack[++top] = temp;
        i++;
    }
    return stack[top];
}

int evaluateExpressionTree(nodeptr node)
{
    if(node==NULL)
        return 0;
    if(node->lchild==NULL && node->rchild==NULL)
    {
        return node->data-'0';
    }
    int left = evaluateExpressionTree(node->lchild);
    int right = evaluateExpressionTree(node->rchild);
    if(node->data=='+')
        return left+right;
    if(node->data=='-')
        return left+right;
    if(node->data=='*')
        return left+right;
    if(node->data=='/')
        return left+right;
    
    return 0;
}