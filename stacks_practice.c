#include <stdio.h>
#define MAX 100

// int stack[MAX], top = -1;

// void push(int item)
// {
//     if(top==-1)
//     {
//         printf("Stack overflow error. Empty stack.");
//     }
//     else
//     {
//         stack[++top] = item;
//         printf("Pushed %d to the top.", item);
//     }
// }

// void pop()
// {
//     if(top==-1)
//         printf("Stack overflow error. Empty stack.");
//     else
//     {
//         printf("Popped %d", stack[top--]);
//     }
// }

// void peek()
// {
//     if(top==-1)
//         printf("Stack overflow error. Empty stack.");
//     else
//     {
//         printf("Top element: %d", stack[top]);
//     }
// }

// void isEmpty()
// {
//     if(top==-1)
//     {
//         printf("Stack overflow error. Empty Stack.");
//     }
//     else
//         printf("Stack is not empty.");
// }

// void display()
// {
//     if(top==-1)
//     {
//         printf("Stack overflow error. Empty Stack.");
//     }
//     else
//     {
//         printf("Stack.");
//         for(int i=top; i>=0; i--)
//         {
//             printf("%d", stack[i]);
//         }
//         printf("\n");
//     }
// }

// struct stack 
// {
//     char stck[MAX];
//     int top;
// }s;

// int checkBalanced(char expr[], int len)
// {
//     for(int i=0; i<len; i++)
//     {
//         if(expr[i]=='(' || expr[i]=='[' || expr[i]=='{')
//         {
//             push(expr[i]);
//         }

//         else if(expr[i]==')' || expr[i]==']' || expr[i]=='}')
//         {
//             if(s.top==-1)
//                 return 0;
//             else if(checkPair(s.stck[s.top], expr[i]))
//                 pop();
//             else
//                 return 0;
//         }
//     }
//     return (s.top==-1);
// }

// int checkPair(char val1, char val2)
// {
//     return ((val1=='(' && val2==')') ||
//             (val1=='[' && val2==']') ||
//             (val1=='{' && val2=='}'));
// }

// int main()
// {
//     char expr[MAX];
//     printf("Enter an expression: ");
//     fgets(expr, MAX, stdin);
//     expr[strcspn(expr, "\n")] = "\0";
//     int len = strlen(expr);
//     s.top=-1;
//     if(checkBalanced(expr, len))
//         printf("Balanced.");
//     else
//         printf("Unbalanced.");
        
//     return 0;

// }


#include <stdio.h>
#include <string.h>

#define MAX 100
int top=-1;

char stack[MAX];

void push(char item)
{
    if(top==MAX-1)
        printf("Stack is full. \n");
    else
    {
        stack[++top] = item;
    }
}

// void pop()
// {
//     if(top==-1)
//         printf("Stack is empty. \n");
//     else
//     {
//         top--;
//     }
// }

int pop()
{
    if(top==-1)
        printf("Stack is empty. \n");
    else
    {
        return stack[top--];
    }
}

int checkPair(char c1, char c2)
{
    if((c1=='(' && c2==')') ||
    (c1=='{' && c2=='}') ||
    (c1=='[' && c2==']'))
    {
        return 1;
    }
    else
        return 0;
}

int checkBalanced(int len, char exp[])
{
    for(int i=0; i<len; i++)
    {
        if(exp[i]=='(' || exp[i]=='[' || exp[i]=='{')
        {
            push(exp[i]);
        }
        else if(exp[i]==')' || exp[i]==']' || exp[i]=='}')
        {
            if(top==-1)
            {
                return 0;
            }
            
            else if(checkPair(stack[top], exp[i]))
            {
                pop();
            }
            else
                return 0;
        }

    }

    return top==-1;
}

int checkDuplicate(int len, char exp[])
{

    for(int i=0; i<len; i++)
    {
        if(exp[i]==')')
        {
            int count=0;
            while(top!=-1 && stack[top]!='(')
            {
                pop();
                count++;
            }
            pop();
            if(count==0)
                return 1;
        }
        else
            push(exp[i]);
    }
    return 0;
}

int isOperator(char c)
{
    return (c=='+' || c=='-' || c=='*' || c=='/' || c=='^');
}

int isOperand(char c)
{
    return ((c>='A' && c<='Z') || (c>='a' && c<='z') || (c>='0' && c<='9'));
}

int precedence(char op)
{
    if(op=='^')
        return 3;
    else if(op=='+'||op=='-')
        return 1;
    else if(op=='*'||op=='/')
        return 2;
    return 0;
}

int comparePrecedence(char stackTop, char incoming)
{
    int p1 = precedence(stackTop);
    int p2 = precedence(incoming);

    if(p1==p2)
    {
        if(stackTop=='^')
        {
            return 0;
        }
        return 1;
    }
    
    else if(p2>p1)
        return 0;

    else if(p1>p2)
        return 1;
}

void convert(char infix[], char postfix[])
{
    char stack[MAX];
    int top = -1;
    int i=0; int j=0;

    top=top+1;
    stack[top]='(';
    strcat(infix, ")");
    int len = strlen(infix);
    
    for(int i=0; i<len; i++)
    {
        char ch = infix[i];
        if(ch==' ')
            continue;
        else if(ch=='(')
        {
            top = top+1;
            stack[top]==ch;
        }
        else if(isOperand(ch))
        {
            postfix[j] = ch;
            j++;
        }
        else if(isOperator)
        {
            while(top!=-1 && comparePrecedence(stack[top], ch))
            {
                postfix[j] = stack[top];
                j++;
                top--;
            }
            top++;
            stack[top] = ch;
        }

        else if(ch==')')
        {
            while(top!=-1 && stack[top]!='(')
            {
                postfix[j] = stack[top];
                j++;
                top--;
            }
            top++;
        }
    }
    postfix[j] = '\0';

}

int evaluate(char postfix[], int len)
{
    for(int i=0; i<len; i++)
    {
        char ch = postfix[i];
        if(ch>='0' && ch<='9')
            push(ch-'0');
        
        else
        {
            int firstPop = pop();
            int secondPop = pop();
            if(ch=='+')
                push(firstPop + secondPop);
            else if(ch=='-')
                push(secondPop-firstPop);
            else if(ch=='*')
                push(firstPop*secondPop);
            else if(ch=='/')
                push(secondPop/firstPop);
        }
    }

    return pop();
}


int main()
{
    char exp[] = "fuck you";
    int len = strlen(exp);
    if(checkBalanced(len, exp))
        printf("Balanced expression it is. \n");
    else
        printf("Expression is not balanced. \n");
}

//---------------------------------------------------------------------------------------//

