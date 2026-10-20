#include <stdio.h>
#include <string.h>

#define MAX 100
char stack[MAX];
int top = -1;

char pop();
void push(char ch);
int precedence(char ch);
int isOperand(char ch);
int isOperator(char ch);
void convert(char expr[]);

int main()
{

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

void push(char ch)
{
    if(top==MAX-1)
    {
        printf("Stack is full. \n");
        return;
    }
    stack[++top]=ch;
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

int isOperand(char ch)
{
    return((ch>='a'&& ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' && ch<='9'));
}

int isOperator(char ch)
{
    return (ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^');
}

void convert(char expr[])
{
    int len = strlen(expr);
    for(int i=0; i<len; i++)
    {
        char temp = expr[i];
        expr[i] = expr[len-i-1];
        expr[len-i-1] = temp;
    }

    for(int i=0; i<len; i++)
    {
        if(expr[i]=='(')
            expr[i]=')';
        else if(expr[i]==')')
            expr[i]='(';
        else
            continue;
    }

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
            {
                result[j++] = pop();
            }
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
                    result[j++]=pop();
                    push(expr[i]);
                }
                else
                {
                    push(expr[i]);
                }
            }
        }
    }

    while(top!=-1)
    {
        result[j++] = pop();
    }

    for(int i=0; i<j/2; i++)
    {
        char temp = result[i];
        result[i] = result[j-i-1];
        result[j-i-1] = temp;
    }

    result[j] = '\0';
    printf("%s \n", result);
}