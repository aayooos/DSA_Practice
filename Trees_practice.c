#include <stdio.h>
#include <string.h>

typedef struct node
{
    char data;
    struct node *lchild;
    struct node *rchild;
} *nodeptr;

nodeptr getNode()
{
    nodeptr temp = (nodeptr)malloc(sizeof(struct node));
    if(temp==NULL)
    {
        printf("Allocation failed. \n");
        return;
    }
    temp->lchild = NULL;
    temp->rchild = NULL;
    return temp;
}

nodeptr createTreeRec(int item)
{
    if(item!=-1)
    {
        nodeptr temp = getNode();
        temp->data = item;
        printf("Enter left child, -1 for null: \n");
        int left, right;
        scanf("%d", &left);
        temp->lchild = createTreeRec(left);
        printf("Enter the right child, -1 for null: \n");
        scanf("%d", &right);
        temp->rchild = createTreeRec(right);
        return temp;
    }
    return NULL;
}

void preOrderTravesalRec(nodeptr node)
{
    if(node==NULL)
        return;
    printf("%d", node->data);
    preOrderTravesalRec(node->lchild);
    preOrderTravesalRec(node->rchild);
}

void inOrderTraversalRec(nodeptr node)
{
    if(node==NULL)
        return;
    inOrderTraversalRec(node->lchild);
    printf("%d", node->data);
    inOrderTraversalRec(node->rchild);
}

void postOrderTraversalRec(nodeptr node)
{
    if(node==NULL)
        return;
    postOrderTraversalRec(node->lchild);
    postOrderTraversalRec(node->rchild);
    printf("%d", node->data);
}


void preOrderTraversalIter(nodeptr node)
{
    if(node==NULL)
        return;
    nodeptr stack[100];
    int top=-1;
    stack[++top]=node;
    while(top!=-1)
    {
        nodeptr current = stack[top--];
        printf("%d", &current->data);
        if(current->rchild!=NULL)
            stack[++top]=current->rchild;
        if(current->lchild!=NULL)
            stack[++top]=current->lchild;
    }
}


void inOrderTraversalIter(nodeptr node)
{
    if(node==NULL)
        return;
    nodeptr current = node;
    int top=-1;
    nodeptr stack[100];
    while(top>-1 || current!=NULL)
    {
        while(current!=NULL)
        {
            stack[++top]=current;
            current=current->lchild;
        }
        current = stack[top--];
        printf("%d", current->data);
        current = current->rchild;
    }
}


void postOrderTraversalIter(nodeptr node)
{
    nodeptr stack[100];
    int top=-1;
    nodeptr temp;
    nodeptr current = node;
    stack[++top]=current;
    while(top!=-1 || current!=NULL)
    {
        if(current!=NULL)
        {
            stack[++top] = current;
            current = current->lchild;
        }
        else
        {
            temp = current->rchild;
            if(temp==NULL)
            {
                temp = stack[top--];
                printf("%d", temp->data);
                while(top!=-1 && stack[top]->rchild==temp)
                {
                    temp = stack[top--];
                    printf("%d", temp->data);
                }
            }
            else
            {
                current = temp;
            }
        }
    }
}


void levelOrderTraversal(nodeptr node)
{
    if(node==NULL)
        return;
    nodeptr queue[100];
    int front=0;
    int rear=-1;
    queue[++rear]=node;
    while(front<=rear)
    {
        nodeptr current = queue[front++];
        printf("%d", current->data);

        if(current->lchild!=NULL)
        {
            queue[++rear] = current->lchild;
        }
        if(current->rchild!=NULL)
        {
            queue[++rear] = current->rchild;
        }
    }
}


int Search(nodeptr node, int element)
{
    int found=0;
    if(node)
    {
        if(node->data==element)
        {
            found=1;
            return found;
        }
        if(found==0)
            Search(node->lchild, element);
        if(found==0)
            Search(node->rchild, element);
    }
}


nodeptr copy(nodeptr node)
{
    if(node==NULL)
        return;
    nodeptr temp = getNode();
    temp->data = node->data;
    temp->lchild = node->lchild;
    temp->rchild = node->rchild;
    return temp;
}


int countNodes(nodeptr node)
{
    if(node==NULL)
        return 0;
    static int count=0;
    count++;
    countNodes(node->lchild);
    countNodes(node->rchild);
    return count;
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


int EqualTrees(nodeptr node1, nodeptr node2)
{
    if(node1==NULL && node2==NULL)
        return 0;
    if(node1==NULL || node2==NULL)
        return 1;
    return ((node1->data==node2->data) ||
            EqualTrees(node1->lchild, node2->lchild) ||
            EqualTrees(node1->rchild, node2->rchild));
}


nodeptr buildExpressionTree(char* postfix)
{
    nodeptr stack[100];
    int top=-1;
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
        if(postfix[i]=='+' || postfix[i]=='*' || postfix[i]=='-' || postfix[i]=='/')
        {
            temp->rchild = stack[top--];
            temp->lchild = stack[top--];
        }
        stack[++top] = temp;
        i++;
    }
    return stack[top];
}


typedef struct threadedTree
{
    char data;
    short int leftThread;
    short int rightThread;
    struct threadedTree *lchild;
    struct threadedTree *rchild;
} *threadPointer;


threadPointer inOrderSuccessor(threadPointer node)
{
    threadPointer temp = node->rchild;
    if(node->rightThread==0)
    {
        while(temp->leftThread==0)
            temp = temp->lchild;
    }
    return temp;
}


void inOrderTraversal(threadPointer treehead)
{
    threadPointer temp = treehead;
    while(1)
    {
        temp = inOrderSuccessor(temp);
        if(temp==treehead)
            break;
        printf("%c ", temp->data);
    }
}


void insertRightThreaded(threadPointer s, threadPointer r)
{
    r->lchild = s;
    r->leftThread = 1;

    if(s->rightThread==0)
    {
        r->rchild = s->rchild;
        r->rightThread=1;
        
        s->rchild = r;
        s->rightThread=0;
    }

    else
    {
        r->rchild = s->rchild;
        r->rightThread = 0;

        s->rchild = r;
        s->rightThread = 1;
        
        threadPointer temp = r->rchild;
        while(temp->leftThread==0)
        {
            temp = temp->lchild;
        }
        temp->lchild = r;
    }
}