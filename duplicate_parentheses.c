#include <stdio.h>
#include <string.h>
#define MAX 100

int top = -1;
char stack[MAX];

void push(char item)
{
    if(top==MAX-1)
    {
        printf("Stack is full. \n");
        return;
    }
    else
    {
        stack[++top] = item;
    }
}

void pop()
{
    if(top==-1)
    {
        printf("Stack is empty. \n");
        return;
    }
    top--;
}

int checkDuplicate(char expr[])
{
    int len = strlen(expr);
    for(int i=0; i<len; i++)
    {
        if(expr[i]==')')
        {
            if(stack[top]=='(')
                return 1;
            while(stack[top]=='(')
                pop();
            pop();
        }

        else
            push(expr[i]);
    }

    return 0;
}

int main()
{
    char expr[] = "(a+b+())";
    if(checkDuplicate(expr))
    {
        printf("Duplicate expression found. \n");
    }
    else
        printf("It's not duplicate. \n");
}