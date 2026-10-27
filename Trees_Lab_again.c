#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *lchild;
    struct node *rchild;
} *nodeptr;


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
    printf("Enter the data for left child of %d, -1 for null: \n", item);
    int left, right;
    scanf("%d", &left);
    temp->lchild = createTreeRec(left);
    printf("Enter the data for right child of %d, -1 for null: \n", item);
    scanf("%d", &right);
    temp->rchild = createTreeRec(right);

    return temp;
}


void inOrderTraversalIter(nodeptr node)
{
    if(node==NULL)
        return;
    int top=-1;
    nodeptr stack[100];
    nodeptr current = node;
    while(top!=-1 || current!=NULL)
    {
        while(current!=NULL)
        {
            stack[++top] = current;
            current = current->lchild;
        }
        current = stack[top--];
        printf("%d ", current->data);
        current = current->rchild;
    }
}

void preOrderTraversalIter(nodeptr node)
{
    if(node==NULL)
        return;
    int top=-1;
    nodeptr stack[100];
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


void postOrderTraversalIter(nodeptr node)
{
    if(node==NULL)
        return;
    int top1=-1; int top2=-1;
    nodeptr stack1[100], stack2[100];
    stack1[++top1] = node;
    while(top1!=-1)
    {
        nodeptr current = stack1[top1--];
        stack2[++top2] = current;
        if(current->lchild!=NULL)
            stack1[++top1] = current->lchild;
        if(current->rchild!=NULL)
            stack1[++top1] = current->rchild;
    }
    while(top2!=-1)
    {
        printf("%d ", stack2[top2--]->data);
    }
}


void levelOrderTraversal(nodeptr node)
{
    nodeptr queue[100];
    int front=0;
    int rear=-1;
    queue[++rear] = node;
    while(front<=rear)
    {
        nodeptr current = queue[front++];
        printf("%d", current->data);
        if(current->lchild!=NULL)
            queue[++rear] = current->lchild;
        if(current->rchild!=NULL)
            queue[++rear] = current->rchild;
    }
}


void printParent(nodeptr node, nodeptr key)
{
    if(node==NULL || key==NULL)
        return NULL;
    if(node->lchild==key || node->rchild==key)
    {
        printf("Parent is %d \n", node->data);
    }
    else
    {
        printParent(node->lchild, key);
        printParent(node->rchild, key);
    }
}


int countLeafNodes(nodeptr node)
{
    if(node==NULL)
        return 0;
    static int count=0;
    if(node->lchild==NULL && node->rchild==NULL)
        count++;
    countLeafNodes(node->lchild);
    countLeafNodes(node->rchild);
    return count;
}


int printDepth(nodeptr node)
{
    if(node==NULL) 
        return 0;
    int leftDepth = printDepth(node->lchild);
    int rightDepth = printDepth(node->rchild);
    return 1 + (leftDepth>rightDepth? leftDepth : rightDepth);
}


nodeptr returnParent(nodeptr node, nodeptr key)
{
    if(node==NULL || key==NULL)
        return NULL;
    if(node->lchild==key || node->rchild==key)
        return node;
    nodeptr result = returnParent(node->lchild, key);
    if(result!=NULL)
        return result;
    return returnParent(node->rchild, key);
}


void printAncestors(nodeptr node, nodeptr key)
{
    if(node==NULL)
        return;
    nodeptr parent = returnParent(node, key);
    printf("%d ", parent->data);
    printAncestors(node, parent);
}


int search(nodeptr node, int key)
{
    if(node==NULL)
        return 0;
    if(node->data==key)
        return 1;
    return search(node->lchild, key) || search(node->rchild, key);
}


nodeptr createCopy(nodeptr node)
{
    if(node==NULL)
        return NULL;
    nodeptr temp = (nodeptr)malloc(sizeof(struct node));
    temp->data = node->data;
    temp->lchild = createCopy(node->lchild);
    temp->rchild = createCopy(node->rchild);
    return temp;
}


int main()
{
    printf("Enter the tree root: \n");
    int rootval;
    scanf("%d", &rootval);
    nodeptr root = createTreeRec(rootval);
    inOrderTraversalIter(root);
}