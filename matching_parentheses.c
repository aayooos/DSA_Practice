#include <stdio.h>
#include <string.h>
#define MAX 100
int top=-1;
char stack[MAX];

void pop()
{
    if(top==-1)
    {
        printf("Stack is empty. \n");
        return;
    }
    top--;
}

void push(char ch)
{
    if(top==MAX-1)
    {
        printf("Stack is full. \n");
        return;
    }
    stack[++top]=ch;
}

int matching(char incoming, char stacktop)
{
    return (incoming==')' && stacktop=='(' || incoming==']' && stacktop=='[' || incoming=='}' && stacktop=='{');
}

int isBalanced(char expr[])
{
    int len = strlen(expr);
    for(int i=0; i<len; i++)
    {
        if(expr[i]=='(' || expr[i]=='[' || expr[i]=='{')
            push(expr[i]);
        else if(expr[i]==')' || expr[i]==']' || expr[i]=='}')
        {
            if(top==-1)
            {
                return 0;
            }

            else if(matching(expr[i], stack[top]))
            {
                pop();
            }

            else
            {
                return 0;
            }
        }
    }
    return top==-1;
}