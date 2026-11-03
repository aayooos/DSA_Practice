// #include <stdio.h>
// #include <stdlib.h>
// #define MAX 100

// int top=-1;
// int stack[MAX];

// void push(int item)
// {
//     if(top==MAX-1)
//     {
//         printf("Overflow. \n");
//         return;
//     }
//     stack[++top] = item;
//     printf("%d pushed to stack. \n", item);
// }

// int pop()
// {
//     if(top==-1)
//     {
//         printf("Empty. \n");
//         return;
//     }
//     int temp = stack[top--];
//     printf("Popped: %d", temp);
// }

// void peek()
// {
//     if(top==-1)
//     {
//         prinf("Empty. \n");
//         return;
//     }
//     printf("%d", stack[top]);
// }

// void isEmpty()
// {
//     if(top==-1)
//     {
//         printf("Stack is empty. \n");
//     }
//     else
//     {
//         printf("Stack is not empty. \n");
//     }
// }

// void display()
// {
//     if(top==-1)
//     {
//         printf("Stack is empty. \n");
//         return;
//     }
//     for(int i=top; i>=0; i--)
//     {
//         printf("%d ", stack[i]);
//     }
// }

// #include <stdio.h>
// #include <stdlib.h>


// typedef struct node
// {
//     int data;
//     struct node* next;
// } *nodeptr;

// nodeptr top=NULL;

// void push(int item)
// {
//     nodeptr temp = (nodeptr)malloc(sizeof(struct node));
//     if(temp==NULL)
//     {
//         printf("Allocation failed. \n");
//         return;
//     }
//     temp->data = item;
//     temp->next = top;
//     top = temp;
//     printf("Pushed %d to stack. \n", item);
// }

// void pop()
// {
//     if(top==NULL)
//     {
//         printf("Empty list. \n");
//         return;
//     }
//     nodeptr temp = top;
//     top = top->next;
//     printf("Popped %d. \n", temp->data);
//     free(temp);
// }

// void peek()
// {
//     if(top==NULL)
//     {
//         printf("Empty list. \n");
//         return;
//     }
//     printf("%d \n", top->data);
// }

// int isEmpty()
// {
//     return top==NULL;
// }

// void display()
// {
//     nodeptr temp = top;
//     if(temp==NULL)
//     {
//         printf("Empty list. \n");
//         return;
//     }
//     while(temp!=NULL)
//     {
//         printf("%d ", temp->data);
//         temp = temp->next;
//     }

// }

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #define MAX 100
// int top=-1;
// char stack[MAX];

// void push(char item)
// {
//     if(top==MAX-1)
//     {
//         printf("Overflow. \n");
//         return;
//     }
//     stack[++top] = item;
// }

// void pop()
// {
//     if(top==-1)
//     {
//         printf("Stack empty. \n");
//         return;
//     }
//     top--;
// }

// int checkPair(char stacktop, char incoming)
// {
//     return ((stacktop == '(' && incoming == ')') ||
//             (stacktop == '[' && incoming == ']') ||
//             (stacktop == '{' && incoming == '}'));
// }


// int checkBalanced(char expr[])
// {
//     top=-1;
//     int len = strlen(expr);
//     for(int i=0; i<len; i++)
//     {
//         if(expr[i]=="(" || expr[i]=="{" || expr[i]=="[")
//             push(expr[i]);
//         else if(expr[i]==")" || expr[i]=="}" || expr[i]=="]")
//         {
//             if(top==-1)
//                 return 0;
//             else if(checkPair(stack[top], expr[i]))
//                 pop();
//             else
//                 return 0;
//         }
//     }
//     return top==-1;
// }

// void checkDuplicate(char expr[])
// {
//     int len = strlen(expr);
//     for(int i=0; i<len; i++)
//     {
//         if(expr[i]==')')
//         {
//             if(expr[i]=='(')
//                 return 1;
//             while(stack[top]=='(')
//                 pop();
//             pop();
//         }
//         else
//             push(expr[i]);
//     }
// }

// void push(char ch)
// {
//     if(top==MAX-1)
//     {
//         printf("Stack is full. \n");
//         return;
//     }
//     stack[++top] = ch;
// }

// char pop()
// {
//     if(top==-1)
//     {
//         printf("Stack is empty. \n");
//         return -1;
//     }
//     return stack[top--];
// }

// int isOperand(char ch)
// {
//     return ((ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' &&ch<='9'));
// }

// int isOperator(char ch)
// {
//     return (ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^');
// }

// int precedence(char ch)
// {
//     if(ch=='^')
//         return 3;
//     else if(ch=='*' || ch=='/')
//         return 2;
//     else if(ch=='+' || ch=='-')
//         return 1;
//     return 0;
// }

// void convert(char expr[])
// {
//     int len = strlen(expr);
//     char result[MAX];
//     int j=0;
//     for(int i=0; i<len; i++)
//     {
//         if(expr[i]=='(')
//             push(expr[i]);
//         else if(expr[i]==')')
//         {
//             while(top!=-1 && expr[i]!='(')
//                 result[j++] = pop();
//             pop();
//         }
//         else if(isOperand(expr[i]))
//             result[j++] = expr[i];
//         else
//         {
//             if(top==-1 || precedence(expr[i])>precedence(stack[top]))
//                 push(expr[i]);
//             else if(precedence(expr[i])<precedence(stack[top]))
//             {
//                 while(top!=-1 && precedence(expr[i])<precedence(stack[top]))
//                 {
//                     result[j++] = pop();
//                 }
//                 push(expr[i]);
//             }
//             else if(precedence(expr[i])==precedence(stack[top]))
//             {
//                 if(expr[i]=='^')
//                     push(expr[i]);
//                 else
//                 {
//                     result[j++]=pop();
//                     push(expr[i]);
//                 }
//             }
//         }
//     }
//     while(top!=-1)
//     {
//         result[j++] = pop();
//     }
//     result[j]='\0';
// }

// #include <stdio.h>
// #include <stdlib.h>
// #define MAX 100

// int storage[MAX];
// int top[MAX];
// int boundary[MAX];
// int n;

// void initialize(int n)
// {
//     for(int i=0; i<n; i++)
//     {
//         top[i] = boundary[i] = ((MAX/n)*i-1);
//     }
//     boundary[n] = MAX-1;
// }

// void push(int item, int i)
// {
//     if(top[i]==boundary[i+1])
//     {
//         printf("Stack is full. \n");
//         return;
//     }
//     storage[++top[i]] = item;
// }

// int pop(int i)
// {
//     if(top[i]==boundary[i])
//     {
//         printf("Stack is empty. \n");
//         return -1;
//     }
//     return storage[top[i]--];
// }

// #include <stdio.h>
// #include <stdlib.h>
// #define max 100

// int queue[max];
// int front=-1;
// int rear=-1;

// void enqueue(int item)
// {
//     if(rear=max-1)
//     {
//         printf("FUll. \n");
//         return;
//     }
//     queue[++rear] = item;
// }

// int dequeue()
// {
//     if(front==-1)
//     {
//         printf("Empty. \n");
//         return;
//     }
//     int element = queue[front];
//     if(front==rear)
//     {
//         front=-1;
//         rear=-1;
//     }
//     else
//         front++;
//     return element;
// }

// #include <stdio.h>
// #include <stdlib.h>
// #define max 100
// int queue[max];
// int front = -1;
// int rear =-1;

// void enqueue(int item)
// {
//     if(front==-1 && rear==-1)
//     {
//         front = rear = 0;
//         queue[rear] = item;
//     }
//     else if((rear+1)%max==front)
//     {
//         printf("Full. \n");
//         return;
//     }
//     else
//     {
//         rear = (rear+1)%max;
//         queue[rear] = item;
//     }
// }

// int dequeue()
// {
//     if(front==-1 && rear==-1)
//     {
//         printf("Empty. \n");
//         return;
//     }
//     if(front==rear)
//     {
//         int element = queue[front];
//         front = rear = -1;
//         return element;
//     }
//     else
//     {
//         int element = queue[front];
//         front = (front+1)%max;
//         return element;
//     }
// }

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *lchild;
    struct node *rchild;
}*nodeptr;

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

nodeptr createTree(int item)
{
    if(item!=-1)
    {
        nodeptr temp = getNode();
        temp->data = item;
        printf("Enter the left child data for %d, -1 for null: ", item);
        int left, right;
        scanf("%d", &left);
        temp->lchild = createTree(left);
        printf("Enter the right child data for %d, -1 for null: ", item);
        scanf("%d", &right);
        temp->rchild = createTree(right);
        return temp;
    }
    return NULL;
}

void preOrderTraversalRec(nodeptr node)
{
    if(node==NULL)
        return;
    printf("%d", node->data);
    preOrderTraversalRec(node->lchild);
    preOrderTraversalRec(node->lchild);
}

void inOrderTraversalRec(nodeptr node)
{
    if(node==NULL)
        return;
    inOrderTraversalRec(node->lchild);
    printf("%d", node->data);
    inOrderTraversalRec(node->rchild);
}

void postOrderTraversalIter(nodeptr node)
{
    if(node==NULL)
        return;
    postOrderTraversalIter(node->lchild);
    postOrderTraversalIter(node->rchild);
    printf("%d", node->data);
}

void preOrderTraversalIter(nodeptr node)
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

void inOrderTraversalIter(nodeptr node)
{
    if(node==NULL)
        return;
    int top=-1;
    nodeptr current = node;
    nodeptr stack[100];
    while(top!=-1 || current!=NULL)
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

void postOrderTraversalIter(nodeptr node)
{
    if(node==NULL)
        return;
    int top1=-1, top2=-1;
    nodeptr stack1[100], stack2[100];
    stack1[++top1] = node;
    while(top1!=-1)
    {
        nodeptr current = stack1[top1--];
        stack2[++top2] = current;
        if(current->lchild!=NULL)
            stack2[++top2] = current->lchild;
        if(current->rchild!=NULL)
            stack2[++top2] = current->rchild;
    }
    while(top2!=-1)
        printf("%d ", stack2[top2--]->data);
}

void levelOrderTraversalIter(nodeptr node)
{
    if(node==NULL)
        return;
    int front=0;
    int rear=-1;
    nodeptr queue[100];
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

int search(int key, nodeptr node)
{
    if(node==NULL)
        return 0;
    if(node->data==key)
        return 1;
    if(search(key, node->lchild))
        return 1;
    return search(key, node->rchild);
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
    else if(node->lchild==NULL && node->rchild==NULL)
        return 1;
    return countLeafNodes(node->lchild) + countLeafNodes(node->rchild);
}

int equalTrees(nodeptr node1, nodeptr node2)
{
    if(node1==NULL && node2==NULL)
        return 1;
    else if(node1==NULL || node2==NULL)
        return 0;
    return ((node1->data==node2->data) && 
            (equalTrees(node1->lchild, node2->lchild)) &&
            (equalTrees(node1->rchild, node2->rchild)));
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
        if(postfix[i]=='+' || postfix[i]=='-' || postfix[i]=='*' || postfix[i]=='/')
        {
            temp->lchild = stack[top--];
            temp->rchild = stack[top--];
        }
        stack[++top] = temp;
        i++;
    }
    return stack[top];
}

int evaluateExpression(nodeptr node)
{
    if(node==NULL)
        return 0;
    if(node->lchild==NULL && node->rchild==NULL)
        return node->data-'0';
    int left = evaluateExpression(node->lchild);
    int right = evaluateExpression(node->rchild);
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

nodeptr createBST(nodeptr root, int item)
{
    if(root==NULL)
    {
        root = getNode();
        root->data = item;
    }
    if(item<root->data)
        root->lchild = createBST(root->lchild, item);
    else if(item>root->data)
        root->rchild = createBST(root->rchild, item);
    else
        printf("Duplicates not allowed. \n");
    return root;
}

nodeptr bstSearch(nodeptr root, int key)
{
    if(root==NULL)
        return NULL;
    if(key==root->data)
        return root;
    else if(key<root->data)
        return bstSearch(root->lchild, key);
    else
        return bstSearch(root->rchild, key);
}

nodeptr bstSearchIter(nodeptr root, int key)
{
    while(root)
    {
        if(key==root->data)
            return root;
        else if(key<root->data)
            return bstSearchIter(root->lchild, key);
        else 
            return bstSearchIter(root->rchild, key);
    }
    return NULL;
}

nodeptr insertBST(nodeptr root, int item)
{
    nodeptr temp = getNode();
    temp->data = item;
    nodeptr current = root;
    nodeptr parent = NULL;
    if(root==NULL)
        return temp;
    while(current)
    {
        parent = current;
        if(item==current->data)
        {
            printf("Duplicates are not allowed. \n");
            return root;
        }
        else if(item<current->data)
        {
            current = current->lchild;
        }
        else
            current = current->rchild;
    }
    if(item<parent->data)
        parent->lchild = temp;
    else
        parent->rchild = temp;
    return root;
}


nodeptr findMin(nodeptr node)
{
    while(node->lchild!=NULL)
        node=node->lchild;
    return node;
}

nodeptr deleteBST(nodeptr node, int item)
{
    if(node==NULL)
    {
        printf("Item not found. \n");
        return NULL;
    }
    if(item<node->data)
        node->lchild = deleteBST(node->lchild, item);
    else if(item>node->data)
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