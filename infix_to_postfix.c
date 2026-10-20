#include <stdio.h>
#define MAX 100
#include <string.h>
char stack[MAX];
int top = -1;

void push(char ch);
char pop();
int isOperator(char ch);
int isOperand(char ch);
int precedence(char ch);
void convert(char expr[]);

int main()
{
    printf("Enter the expression: \n");
    char expr[MAX];
    scanf("%s", expr);
    convert(expr);
}

void push(char ch)
{
    if(top==MAX-1)
    {
        printf("Stack is full. \n");
        return;
    }
    stack[++top] = ch;
}

char pop()
{
    if(top==-1)
    {
        printf("Stack is empty. \n");
        return -1;
    }
    return stack[top--];
}

int isOperand(char ch)
{
    return ((ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' && ch<='9'));
}

int isOperator(char ch)
{
    return (ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^');
}

int precedence(char ch)
{
    if(ch=='^')
        return 3;
    else if(ch=='*' || ch=='/')
        return 2;
    else if(ch=='+' || ch=='-')
        return 1;
    return 0;
}

void convert(char expr[])
{
    int len = strlen(expr);
    char result[MAX];
    int j=0;
    for(int i=0; i<len; i++)
    {
        if(expr[i]=='(')
            push(expr[i]);

        else if(isOperand(expr[i]))
        {
            result[j++] = expr[i];
        }

        else if(expr[i]==')')
        {
            while(top!=-1 && stack[top]!='(')
                result[j++] = pop();
            pop();
        }

        else
        {
            if(top==-1 || precedence(expr[i])>precedence(stack[top]))
            {
                push(expr[i]);
            }

            else if(precedence(expr[i])<precedence(stack[top]))
            {
                while(top!=-1 && precedence(expr[i])<precedence(stack[top]))
                {
                    result[j++] = pop();
                }
                push(expr[i]);
            }

            else if(precedence(expr[i])==precedence(stack[top]))
            {
                if(expr[i]=='^')
                {
                    push(expr[i]);
                }

                else
                {
                    result[j++] = pop();
                    push(expr[i]);
                }
            }
        }

    }
    while(top!=-1)
    {
        result[j++] = pop();
    }
    result[j] = '\0';
    printf("%s \n", result);

}