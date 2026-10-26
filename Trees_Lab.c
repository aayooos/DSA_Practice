#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    char data;
    struct node *lchild;
    struct node *rchild;
}*nodeptr;

nodeptr createTreeRec(int item)
{
    if(item==-1)
        return NULL;
    
    nodeptr temp = (nodeptr)malloc(sizeof(struct node));
    if(temp==NULL)
    {
        printf("Allocation failed. \n");
        exit(1);
    }
    temp->data = item;
    printf("Enter the left child data, -1 for null: \n");
    int left, right;
    scanf("%d", &left);
    temp->lchild = createTreeRec(left);
    printf("Enter the right child data, -1 for null: \n");
    scanf("%d", &right);
    temp->rchild = createTreeRec(right);
    return temp;
}


void preOrderTraversal(nodeptr node)
{
    if(node==NULL)
        return;
    nodeptr stack[100];
    int top=-1;
    stack[++top] = node;
    while(top!=-1)
    {
        nodeptr current = stack[top--];
        printf("%d", current->data);
        if(current->rchild!=NULL)
            stack[++top] = current->rchild;
        if(current->lchild!=NULL)
            stack[++top] = current->lchild;
    }
}


void inOrderTraversal(nodeptr node)
{
    if(node==NULL)
        return;
    int top=-1;
    nodeptr stack[100];
    nodeptr current = node;
    while(current!=NULL || top>-1)
    {
        while(current!=NULL)
        {
            stack[++top] = current;
            current = current->lchild;
        }
        current = stack[top--];
        printf("%d", current->data);
        current = current->rchild;
    }

}


// void postOrderTraversal(nodeptr node)
// {
//     if(node==NULL)
//         return;
//     int top=-1;
//     nodeptr stack[100];
//     nodeptr current = node;
//     while(top!=-1 || current!=NULL)
//     {
//         if(current!=NULL)
//         {
//             stack[++top] = current;
//             current = current->lchild;
//         }
//         else
//         {
//             nodeptr temp = stack[top]->rchild;
//             if(temp==NULL)
//             {
//                 temp = stack[top--];
//                 while(top!=-1 && stack[top]->rchild==temp)
//                 {
//                     printf("%d", )
//                 }
//             }
//         }
//     }
// }


// void printParent(nodeptr node, int key)
// {
//     if(node==NULL)
//         return;

//     if(node->lchild!=NULL && node->lchild->data==key || node->rchild!=NULL && node->rchild->data==key)
//     {
//         printf("Parent is: %d", node->data);
//         return;
//     }
//     printParent(node->lchild, key);
//     printParent(node->rchild, key);
// }


void printParent(nodeptr key, nodeptr node)
{
    if(node==NULL || node==key)
        return;
    
    if(node->lchild==key || node->rchild==key)
    {
        printf("Parent is: %d", node->data);
        return;
    }
    printParent(key, node->lchild);
    printParent(key, node->rchild);
}


int countLeafNodes(nodeptr node)
{
    if(node==NULL)
        return 0;
    static int count=0;
    if(node->lchild==NULL && node->rchild==NULL)
    {
        count++;
    }
    countLeafNodes(node->lchild);
    countLeafNodes(node->rchild);
    
    return count;
}


nodeptr printParent2(nodeptr key, nodeptr node)
{
    if(node == NULL || node == key)
        return NULL;

    if(node->lchild == key || node->rchild == key)
        return node;

    nodeptr result = printParent2(key, node->lchild);
    if(result != NULL)
        return result;

    return printParent2(key, node->rchild);
}


void printAncestors(nodeptr node, nodeptr current)
{
    if(node==NULL)
        return;
    
    nodeptr parent = printParent2(current, node);
    if(parent==NULL)
        return;
    printf("%d", parent->data);
    printAncestors(node, parent);
}