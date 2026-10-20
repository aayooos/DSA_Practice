// #include <stdio.h>
// #include <string.h>
// #define MAX 100
// int top=-1;
// char stack[MAX][MAX];


// void push(char ch)
// {
//     if(top==MAX-1)
//     {
//         printf("Stack is full. \n");
//         return;
//     }
//     stack[0][++top] = ch;
// }

// char pop()
// {
//     if(top==-1)
//     {
//         printf("Stack is empty. \n");
//         return -1;
//     }
//     return stack[0][top--];
// }

// int isOperand(char ch)
// {
//     return ((ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' && ch<='9'));
// }

// int isOperator(char ch)
// {
//     return (ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^');
// }

// void convert(char expr[])
// {
//     int len = strlen(expr);
//     for(int i=0; i<len; i++)
//     {
//         if(isOperand(expr[i]))
//         {
//             push(expr[i]);
//         }
//         else if(isOperator)
//         {
//             char result[];
//             int op1 = pop();
//             int op2 = pop();
//             if(expr[i]=='*')
//                 result = op1*op2;
//             if(expr[i]=='+')
//                 result = op1+op2;
//             if(expr[i]=='-')
//                 result = op1-op2;
//             if(expr[i]=='/')
//                 result = op1/op2;
            
            
//         }
//     }
// }