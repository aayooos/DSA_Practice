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
    while(postfix[i]!='\0')
    {
        if(postfix[i]==' ')
        {
            i++;
            continue;
        }
        nodeptr temp = (nodeptr)malloc(sizeof(struct node));
        temp->data = postfix[i];
        temp->lchild = temp->rchild = NULL;
        if(postfix[i]=='+' || postfix[i]=='-' || postfix[i]=='*' || postfix[i]=='/')
        {
            temp->rchild = stack[top--];
            temp->lchild = stack[top--];
        }
        stack[++top] = temp->data;
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
    else if(node->data=='-')
        return left-right;
    else if(node->data=='*')
        return left*right;
    else if(node->data=='/')
        return left/right;
    
    return 0;
    
}