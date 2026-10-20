#include <stdio.h>
#include <string.h>
#define MAX 100
int stack[MAX];
int top = -1;

int pop();
void push(int ch);
int evaluate(char expr[]);
int isOperand(char ch);
int isOperator(char ch);

int main()
{

}

void push(int ch)
{
    if(top==MAX-1)
    {
        printf("Stack is full. \n");
        return;
    }
    stack[++top] = ch;
}

int pop()
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
    return((ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' && ch<='9'));
}

int isOperator(char ch)
{
    return(ch=='+' || ch=='*' || ch=='-' || ch=='^' || ch=='/');
}

int evaluate(char expr[])
{
    int len = strlen(expr);
    for(int i=0; i<len; i++)
    {
        if(isOperand(expr[i]))
        {
            push(expr[i]-'0');
        }

        else
        {
            int op1 = pop();
            int op2 = pop();
            if(expr[i]=='+')
                push(op2+op1);

            else if(expr[i]=='-')
                push(op2-op1);

            else if(expr[i]=='*')
                push(op2*op1);

            else if(expr[i]=='/')
                push(op2/op1);

            else if(expr[i]=='^')
            {
                int result=1;
                for(int j=0; j<op1; j++)
                {
                    result = result*op2;
                }
                push(result);
            }
        }
    }
    return pop();
}