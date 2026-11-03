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

#include <stdio.h>
#include <stdlib.h>
#define max 100
int queue[max];
int front = -1;
int rear =-1;

void enqueue(int item)
{
    if(front==-1 && rear==-1)
    {
        front = rear = 0;
        queue[rear] = item;
    }
    else if((rear+1)%max==front)
    {
        printf("Full. \n");
        return;
    }
    else
    {
        rear = (rear+1)%max;
        queue[rear] = item;
    }
}

int dequeue()
{
    if(front==-1 && rear==-1)
    {
        printf("Empty. \n");
        return;
    }
    if(front==rear)
    {
        int element = queue[front];
        front = rear = -1;
        return element;
    }
    else
    {
        int element = queue[front];
        front = (front+1)%max;
        return element;
    }
}