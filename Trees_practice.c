#include <stdio.h>
#include <stdlib.h>
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
        return NULL;
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


void preOrderTraversalRec(nodeptr node)
{
    if(node==NULL)
        return;
    printf("%c ", node->data);
    preOrderTraversalRec(node->lchild);
    preOrderTraversalRec(node->rchild);
}


void inOrderTraversalRec(nodeptr node)
{
    if(node==NULL)
        return;
    inOrderTraversalRec(node->lchild);
    printf("%c ", node->data);
    inOrderTraversalRec(node->rchild);
}


void postOrderTraversalRec(nodeptr node)
{
    if(node==NULL)
        return;
    postOrderTraversalRec(node->lchild);
    postOrderTraversalRec(node->rchild);
    printf("%c ", node->data);
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
        printf("%c ", current->data);
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
        printf("%c ", current->data);
        current = current->rchild;
    }
}


void postOrderTraversalIter(nodeptr node)
{
    nodeptr stack[100];
    int top = -1;
    nodeptr temp;
    nodeptr current = node;

    while(top!=-1 || current!=NULL)
    {
        if(current!=NULL)
        {
            stack[++top] = current;
            current = current->lchild;
        }
        else
        {
            temp = stack[top]->rchild;
            if(temp == NULL)
            {
                temp = stack[top--];
                printf("%c ", temp->data);
                while(top != -1 && stack[top]->rchild == temp)
                {
                    temp = stack[top--];
                    printf("%c ", temp->data);
                }
            }
            else
                current = temp;
        }
    }
}


void levelOrderTraversal(nodeptr node)
{
    if(node==NULL)
        return;
    nodeptr queue[100];
    int front=0, rear=-1;
    queue[++rear]=node;
    while(front<=rear)
    {
        nodeptr current = queue[front++];
        printf("%c ", current->data);
        if(current->lchild!=NULL)
            queue[++rear] = current->lchild;
        if(current->rchild!=NULL)
            queue[++rear] = current->rchild;
    }
}


int Search(nodeptr node, int element)
{
    if(node==NULL)
        return 0;
    if(node->data==element)
        return 1;
    if(Search(node->lchild, element)) return 1;
    return Search(node->rchild, element);
}


nodeptr copy(nodeptr node)
{
    if(node==NULL)
        return NULL;
    nodeptr temp = getNode();
    temp->data = node->data;
    temp->lchild = copy(node->lchild);
    temp->rchild = copy(node->rchild);
    return temp;
}


int countNodes(nodeptr node)
{
    if(node==NULL)
        return 0;
    return 1 + countNodes(node->lchild) + countNodes(node->rchild);
}


int countLeafNodes(nodeptr node)
{
    if(node==NULL)
        return 0;
    if(node->lchild==NULL && node->rchild==NULL)
        return 1;
    return countLeafNodes(node->lchild) + countLeafNodes(node->rchild);
}


int EqualTrees(nodeptr node1, nodeptr node2)
{
    if(node1==NULL && node2==NULL)
        return 1;
    if(node1==NULL || node2==NULL)
        return 0;
    return ((node1->data==node2->data) &&
            EqualTrees(node1->lchild, node2->lchild) &&
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
            temp = temp->lchild;
        temp->lchild = r;
    }
}


nodeptr createBST(nodeptr root, int item)
{
    if(root==NULL)
    {
        root = getNode();
        root->data = item;
        root->lchild = root->rchild = NULL;
        return root;
    }
    if(item<root->data)
        root->lchild = createBST(root->lchild, item);
    else if(item>root->data)
        root->rchild = createBST(root->rchild, item);
    else
        printf("Duplicates are not allowed. \n");
    return root;
}


nodeptr BSTsearch(nodeptr root, int item)
{
    if(root==NULL)
        return NULL;
    if(item==root->data)
        return root;
    else if(item>root->data)
        return BSTsearch(root->rchild, item);
    else
        return BSTsearch(root->lchild, item);
}


nodeptr BSTsearchIter(nodeptr root, int item)
{
    while(root)
    {
        if(item==root->data)
            return root;
        else if(item<root->data)
            root = root->lchild;
        else
            root = root->rchild;
    }
    return NULL;
}


nodeptr insertBST(nodeptr node, int item)
{
    nodeptr temp = getNode();
    temp->data = item;
    temp->lchild = temp->rchild = NULL;
    if(node==NULL)
        return temp;
    nodeptr parent = NULL;
    nodeptr current = node;
    while(current)
    {
        parent = current;
        if(current->data == item)
        {
            printf("Duplicates are not allowed. \n");
            return node;
        }
        else if(current->data < item)
            current = current->rchild;
        else
            current = current->lchild;
    }
    if(parent->data < item)
        parent->rchild = temp;
    else
        parent->lchild = temp;
    return node;
}


nodeptr deleteBST(nodeptr node, int item)
{
    nodeptr parent, current;
    nodeptr succ, q;

    if(node==NULL)
    {
        printf("Empty tree. \n");
        return node;
    }
    parent = NULL;
    current = node;
    while(current && (current->data!=item))
    {
        parent = current;
        if(current->data > item)
            current = current->lchild;
        else
            current = current->rchild;
    }
    if(current==NULL)
    {
        printf("Item not found. \n");
        return node;
    }

    if(current->lchild==NULL)
        q = current->rchild;
    else if(current->rchild==NULL)
        q = current->lchild;
    else
    {
        parent = current;
        succ = parent->rchild;
        while(succ->lchild)
        {
            parent = succ;
            succ = succ->lchild;
        }
        current->data = succ->data;
        current = succ;
        q = current->rchild;
    }

    if(parent==NULL)
    {
        free(current);
        node = q;
        return node;
    }
    if(current==parent->lchild)
        parent->lchild = q;
    else
        parent->rchild = q;
    free(current);
    return node;
}

nodeptr findMin(nodeptr node)
{
    while(node->lchild!=NULL)
        node = node->lchild;
    return node;
}

nodeptr deleteBST2(nodeptr node, int item)
{
    if(node==NULL)
    {
        printf("Item not found. \n");
        return NULL;
    }
    if(item<node->data)
        node->lchild = deleteBST(node->lchild, item);
    if(item>node->data)
        node->rchild = deleteBST(node->rchild, item);
    else
    {
        if(node->lchild==NULL && node->rchild==NULL)
        {
            free(node);
            return NULL;
        }
        else if(node->lchild==NULL)
        {
            nodeptr temp = node->rchild;
            free(node);
            return temp;
        }
        else if(node->rchild==NULL)
        {
            nodeptr temp = node->lchild;
            free(node);
            return temp;
        }
        else
        {
            nodeptr temp = findMin(node->rchild);
            node->data = temp->data;
            node->rchild = deleteBST(node->rchild, temp->data);
        }

    }
    return node;
}