// #include <stdio.h>
// #include <string.h>
// #define MAX 100

// struct employee
// {
//     int employeeId;
//     char name[MAX];
//     char email[MAX];
//     float salary;
//     char dob[MAX];
// };

// void countGmail(struct employee *ptr, int n)
// {
//     for(int i=0; i<n; i++)
//     {
//         char* currentEmail = (ptr+i)->email;
//         char ss[11];
//         char *X = "@gmail.com";
//         int len = strlen(currentEmail);
//         int j=0;
//         for(int k=len-10; k<len; k++)
//         {
//             ss[j++] = currentEmail[k];
//         }
//         ss[j] = '\0';
//         if(strcmp(ss, X)==0)
//             printf("%s", (ptr+i)->name);
//         printf("\n");
//     }
// }

// void highestSalary(struct employee *ptr, int n)
// {
//     struct employee *highestPointer=ptr;
//     for(int i=1; i<n; i++)
//     {
//         if((ptr+i)->salary>highestPointer->salary)
//             highestPointer = (ptr+i);
//     }

//     printf("%s", highestPointer->name);
// }

// void retirementList(struct employee *ptr, int n)
// {

// }

// int main()
// {
//     printf("Enter the number of employees: \n");
//     int n;
//     scanf("%d", &n);
//     struct employee employees[n];
//     for(int i=0; i<n; i++)
//     {
//         printf("Enter the employee id, name, email, salary, dob");
//         scanf("%d", &employees[i].employeeId);
//         scanf("%s", employees[i].name);
//         scanf("%s", employees[i].email);
//         scanf("%d", &employees[i].salary);
//         scanf("%s", employees[i].email);
//     }

//     struct employee* ptr = employees;
//     countGmail(ptr, n);
//     highestSalary(ptr, n);
//     retirementList(ptr, n);
    
// }


// #include <stdio.h>
// #include <stdlib.h>
// #define MAX 100

// struct student
// {
//     int regNo;
//     char name[MAX];
//     int marks;
// };

// // struct student stack[MAX];
// int top=-1;

// void push(struct student item, struct student stack[])
// {
//     if(top==MAX-1)
//     {
//         printf("Stack is full. \n");
//         return;
//     }
//     stack[++top]=item;
// }

// void pop(struct student stack[])
// {
//     if(top==-1)
//     {
//         printf("Stack is empty. \n");
//         return;
//     }
//     printf("%s", stack[top].name);
//     top--;
// }

// void display(struct student stack[])
// {
//     if(top==-1)
//     {
//         printf("Stack is empty. \n");
//         return;
//     }
//     for(int i=top; i>=0; i--)
//     {
//         printf("%s", stack[i].name);
//     }
// }

// void countaboveBench(int bench, struct student stack[], int xtop)
// {
//     if(xtop==-1)
//         return;
//     else
//     {
//         if(stack[xtop].marks>bench)
//         {
//             printf("%s", stack[xtop].name);
//             countaboveBench(bench, stack, xtop-1);
//         }
//     }
//     countaboveBench(bench, stack, xtop-1);
// }

// int main()
// {
//     printf("Enter the number of students: \n");
//     int n;
//     scanf("%d", &n);
//     struct student *stack = (struct student*)calloc(n, sizeof(struct student));
//     for(int i=0; i<n; i++)
//     {
//         printf(" Enter the regno, name and marks of the student: \n");
//         struct student temp;
//         scanf("%d %s %d", &temp.regNo, temp.name, &temp.marks);
//         push(temp, stack);
//     }
//     printf("Enter the benchmarks score: \n");
//     int bench;
//     scanf("%d", &bench);
// }



// #include <stdio.h>
// #define MAX 100
// #include <string.h>

// struct college
// {
//     int code, ranking[5];
//     char name[MAX], city[MAX];
// };
// struct college colleges[5];

// struct college stack[MAX];
// int top = -1;

// void push(struct college item)
// {
//     if(top==MAX-1)
//     {
//         printf("Stack is full. \n");
//         return;
//     }
//     stack[++top] = item;
// }

// void pop()
// {
//     if(top==-1)
//     {
//         printf("Stack is empty. \n");
//         return;
//     }
//     printf("%s", stack[top].name);
//     top--;
// }

// void highestLowestPushthenPop(struct college colleges[])
// {
//     int maxSum=0;
//     int maxIndex = 0;
//     for(int i=0; i<5; i++)
//     {
//         int sum=0;
//         for(int j=0; j<5; j++)
//         {
//             sum = sum + colleges[i].ranking[j];
//         }
//         if(sum>maxSum)
//         {
//             maxSum = sum;
//             maxIndex = i;
//         }
//     }
//     push(colleges[maxIndex]);

//     int minSum=1000;
//     int minIndex=0;
//     for(int i=0; i<5; i++)
//     {
//         int sum=0;
//         for(int j=0; j<5; j++)
//         {
//             sum = sum + colleges[i].ranking[j];
//         }
//         if(sum<minSum)
//         {
//             minSum = sum;
//             minIndex = i;
//         }
//     }
//     push(colleges[minIndex]);
//     pop();
// }

// int main()
// {
//     for(int i=0; i<5; i++)
//     {
//         printf("Enter the code, name, city and 5 rakings of the college: ");
//         scanf("%d", &colleges[i].code);
//         scanf("%s", colleges[i].name);
//         scanf("%s", colleges[i].city);
//         for(int j=0; j<5; j++)
//         {
//             scanf("%d", &colleges[i].ranking[j]);
//         }
//     }

// }

// #include <stdio.h>
// #include <string.h>
// #define MAX 100
// int top = -1;
// char stack[MAX];

// char pop()
// {
//     if(top==-1)
//     {
//         printf("Stack is empty. \n");
//         return;
//     }
//     return stack[top--];
// }

// void push(char ch)
// {
//     if(top==MAX-1)
//     {
//         printf("Stack is full. \n");
//         return;
//     }
//     stack[++top]=ch;
// }

// int checkPair(char ch1, char ch2)
// {
//     return ((ch1=='(' && ch2==')') || (ch1=='[' && ch2==']') || (ch1=='{' && ch2=='}'));
// }

// int checkBalanced(char expr[])
// {
//     int len = strlen(expr);
//     for(int i=0; i<len; i++)
//     {
//         if(expr[i]=='(' || expr[i]=='[' || expr[i]=='{')
//         {
//             push(expr[i]);
//         }
//         else if(expr[i]==')' || expr[i]==']' || expr[i]=='}')
//         {
//             if(top==-1)
//                 return 0;
//             else if(checkPair(expr[i], stack[top]))
//             {
//                 pop();
//             }
//             else
//                 return 0;
//         }
//     }
//     return top==-1;
// }

// int checkDuplicate(char expr[])
// {
//     int len = strlen(expr);
//     for(int i=0; i<len; i++)
//     {
//         if(expr[i]==')')
//         {
//             if(stack[top]=='(')
//                 return 1;
//             while(top!=-1 && stack[top]=='(')
//             {
//                 pop();
//             }
//             if(top!=-1)
//                 pop();
//         }
//         else
//             push(expr[i]);

//     }

//     while(top!=-1)
//     {
//         if(stack[top]=='(')
//         {
//             return 1;
//         }
//         pop();
//     }
//     return 0;
// }


// #include <stdio.h>
// #define MAX 100
// #include <string.h>
// int top=-1;
// char stack[MAX];

// char pop()
// {
//     if(top==-1)
//     {
//         printf("Stack is empty. \n");
//         return -1;
//     }
//     return stack[top--];
// }

// void push(char ch)
// {
//     if(top==MAX-1)
//     {
//         printf("Stack is full. \n");
//         return;
//     }
//     stack[++top]=ch;
// }

// int precedence(char ch)
// {
//     if(ch=='+' || ch=='-')
//         return 1;
//     else if(ch=='*' || ch=='/')
//         return 2;
//     else if(ch=='^')   
//         return 3;
//     return 0;
// }

// int isOperator(char ch)
// {
//     return(ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^');
// }

// int isOperand(char ch)
// {
//     return((ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' && ch<='9'));
// }

// void convert(char expr[])
// {
//     int len = strlen(expr);
//     char output[MAX];
//     int j=0;
//     for(int i=0; i<len; i++)
//     {
//         if(expr[i]=='(')
//             push(expr[i]);

//         else if(expr[i]==')')
//         {
//             while(top!=-1 && stack[top]!='(')
//             {
//                 output[j++] = pop();
//             }
//             pop();
//         }

//         else if(isOperand(expr[i]))
//         {
//             output[j++] = expr[i];
//         }

//         else if(isOperator(expr[i]))
//         {
//             if(top==-1 || precedence(expr[i])>precedence(stack[top]))
//             {
//                 push(expr[i]);
//             }

//             else if(precedence(expr[i])<precedence(stack[top]))
//             {
//                 while(top!=-1 && precedence(expr[i])<precedence(stack[top]))
//                 {
//                     output[j++] = pop();
//                 }
//                 push(expr[i]);
//             }

//             else if(precedence(expr[i])==precedence(stack[top]))
//             {
//                 if(expr[i]=='^')
//                 {
//                     push(expr[i]);
//                 }
//                 else
//                 {
//                     output[j++] = pop();
//                     push(expr[i]);
//                 }
//             }

//         }

//     }

//     while(top!=-1)
//     {
//         output[j++] = pop();
//     }
//     output[j] = '\0';
//     printf("%s\n", output);
// }

// int main()
// {
//     char* expr = "a+((b*c)/d)";
//     convert(expr);
// }

// #include <stdio.h>
// #include <string.h>
// #define MAX 100
// int top=-1;
// char stack[MAX];

// char pop()
// {
//     if(top==-1)
//     {
//         printf("Stack is empty. \n");
//         return -1;
//     }
//     return stack[top--];
// }

// void push(char ch)
// {
//     if(top==MAX-1)
//     {
//         printf("Stack is full. \n");
//         return;
//     }
//     stack[++top]=ch;
// }

// int precedence(char ch)
// {
//     if(ch=='+' || ch=='-')
//         return 1;
//     else if(ch=='*' || ch=='/')
//         return 2;
//     else if(ch=='^')   
//         return 3;
//     return 0;
// }

// int isOperator(char ch)
// {
//     return(ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^');
// }

// int isOperand(char ch)
// {
//     return((ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' && ch<='9'));
// }

// void convert(char expr[])
// {
//     int len = strlen(expr);
//     char reversedExp[len+1];
//     for(int i=0; i<len; i++)
//     {
//         reversedExp[len-i-1] = expr[i];
//     }
//     reversedExp[len] = '\0';
//     for(int i=0; i<len; i++)
//     {
//         if(reversedExp[i]=='(')
//             reversedExp[i]=')';
//         else if(reversedExp[i]==')')
//             reversedExp[i]='(';
//     }
//     expr = reversedExp;
//     char output[len+1];
//     int j=0;
//     for(int i=0; i<len; i++)
//     {
//         if(expr[i]=='(')
//             push(expr[i]);
        
//         else if(expr[i]==')')
//         {
//             while(top!=-1 && stack[top]!='(')
//             {
//                 output[j++] = pop();
//             }
//             pop();
//         }

//         else if(isOperand(expr[i]))
//         {
//             output[j++] = expr[i];
//         }

//         else if(isOperator(expr[i]))
//         {
//             if(precedence(expr[i])>precedence(stack[top]))
//             {
//                 push(expr[i]);
//             }
//             else if(top==-1 || precedence(expr[i])<precedence(stack[top]))
//             {
//                 while(top!=-1 && precedence(expr[i])<precedence(stack[top]))
//                 {
//                     output[j++] = pop();
//                 }
//                 push(expr[i]);
//             }

//             else if(precedence(expr[i])==precedence(stack[top]))
//             {
//                 if(expr[i]=='^')
//                 {
//                     output[j++] = pop();
//                     push(expr[i]);
//                 }
//                 else
//                 {
//                     push(expr[i]);
//                 }
//             }
//         }
//     }

//     while(top!=-1)
//         output[j++] = pop();
//     output[j] = '\0';


//     char final[len+1];
//     int k=0;
//     for(int i=j-1; i>=0; i--)
//     {
//         final[k++] = output[i];
//     }
//     final[k] = '\0';
//     printf("%s\n", final);
// }

// int main()
// {
//     char expr[] = "(a+b+c*d*(x/y))";
//     convert(expr);
// }

// #include <stdio.h>
// #include <string.h>
// #define MAX 100

// int isOperator(char ch)
// {
//     return(ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^');
// }

// int isOperand(char ch)
// {
//     return((ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' && ch<='9'));
// }

// struct Stack
// {
//     int arr[MAX];
//     int top;
// };

// struct Stack stack;

// void push(int x)
// {
//     if(stack.top==MAX-1)
//     {
//         printf("Stack is full. \n");
//         return;
//     }
//     stack.arr[++stack.top] = x;
    
// }

// int pop()
// {
//     if(stack.top==-1)
//     {
//         printf("Stack is empty. \n");
//         return -1;
//     }
//     return stack.arr[stack.top--];
// }

// void evaluate(char expr[])
// {
    
//     int len = strlen(expr);
//     for(int i=len-1; i>=0; i--)
//     {
//         if(isOperand(expr[i]))
//             push(expr[i]-'0');
        
//         if(isOperator(expr[i]))
//         {
//             int op1 = pop();
//             int op2 = pop();
//             if(expr[i]=='+') push(op1+op2);
//             else if(expr[i]=='-') push(op1-op2);
//             else if(expr[i]=='*') push(op1*op2);
//             else if(expr[i]=='/') push(op1/op2);
//             else if(expr[i]=='^')
//             {
//                 int result=1;
//                 int j=1;
//                 while(j<=op2)
//                 {
//                     result=result*op1;
//                     j++;
//                 }
//                 push(result);
//             }
//         }
//     }
//     printf("%d", stack.arr[stack.top]);
// }

// int main()
// {
//     stack.top=-1;
//     char *expr = "+2*34";
//     evaluate(expr);
// }



// #include <stdio.h>
// #include <string.h>
// #define MAX 100
// #include <stdlib.h>
// int qSize;
// struct order 
// {
//     int orderNo;
//     char studentName[MAX];
//     int noItems;   
// };

// struct order* queue;
// int front=-1;
// int rear=-1;

// void addOrder(struct order incoming)
// {
//     if(rear==qSize-1)
//     {
//         printf("Queue is full. \n");
//         return;
//     }
//     if(front==-1)
//         front=0;
//     rear++;
//     (queue+ (rear))->orderNo = incoming.orderNo;
//     strcpy((queue+(rear))->studentName, incoming.studentName);
//     (queue+ (rear))->noItems = incoming.noItems;
// }

// void serveOrder()
// {
//     if(front==-1)
//     {
//         printf("Queue is empty. \n");
//         return;
//     }
//     printf("%d", (queue+front)->orderNo);
//     if(front==rear)
//     {
//         front=rear=-1;
//     }
//     else   
//         front++;
// }

// void displayOrder()
// {
//     if(front==-1)
//     {
//         printf("Stack is empty. \n");
//         return;
//     }
//     for(int i=front; i<=rear; i++)
//     {
//         printf("%d", (queue+i)->orderNo);
//     }
// }


// int main()
// {
//     printf("Enter the size of the queue: \n");
//     scanf("%d", &qSize);
//     queue = (struct order*)calloc(qSize, sizeof(struct order));
//     printf("Enter the number of people: \n");
//     int nPeople;
//     scanf("%d", &nPeople);
//     struct order temp;
//     for(int i=0; i<nPeople; i++)
//     {
//         printf("Enter the order no. student name and number of orders of this student: \n");
//         scanf("%d", &(temp.orderNo));
//         scanf("%s", temp.studentName);
//         scanf("%d", &(temp.noItems));
//         addOrder(temp);
//     }

// }

// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>
// #define MAX 100

// struct RechargeRequest
// {
//     char custName[MAX];
//     int mobNo;
//     float rechargeAmt;
// };

// int qSize;
// struct RechargeRequest* queue;
// int front=-1;
// int rear=-1;

// void addRequest(struct RechargeRequest incoming)
// {
//     if(rear==qSize-1)
//     {
//         printf("Queue is full. \n");
//         return;
//     }
//     else if(front==-1)
//     {
//         front=0;
//     }
//     rear++;
//     strcpy((queue+rear)->custName, incoming.custName);
//     (queue+rear)->mobNo = incoming.mobNo;
//     (queue+rear)->rechargeAmt = incoming.rechargeAmt;
// }


// void processRequest()
// {
//     if(front==-1)
//     {
//         printf("Queue is empty. \n");
//         return;
//     }
//     else if(front==rear)
//     {
//         printf("Top request is: %s", (queue+front)->custName);
//         front=rear=-1;
//     }
//     else
//     {
//         printf("Top request is: %s", (queue+front)->custName);
//         front++;
//     }
// }

// void displayPending()
// {
//     if(front==-1)
//     {
//         printf("Queue is empty. \n");
//     }
//     else
//     {
//         for(int i=front; i<=rear; i++)
//         {
//             printf("%s \n", (queue+i)->custName);
//         }
//     }
// }

// float findHighest(int f, int r)
// {
//     if(f==r)
//         return (queue+f)->rechargeAmt;
//     float currentAmt = (queue+f)->rechargeAmt;
//     float maxRemaining = findHighest(f+1, r);
//     if(currentAmt>maxRemaining)
//         return currentAmt;
//     else
//         return maxRemaining;
// }

// int main()
// {
//     printf("Enter the size of the queue: \n");
//     scanf("%d", &qSize);
//     queue = (struct RechargeRequest*)calloc(qSize, sizeof(struct RechargeRequest));
//     printf("Enter the number of requests: \n");
//     int numReq;
//     scanf("%d", &numReq);
//     for(int i=0; i<numReq; i++)
//     {
//         struct RechargeRequest temp;
//         printf("Enter the customer name, mobile no. and the recharge amount for this customer: \n");
//         scanf("%s", temp.custName);
//         scanf("%d", &temp.mobNo);
//         scanf("%f", temp.rechargeAmt);
//         addRequest(temp);
//     }
// }


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100

struct page
{
    char date[MAX];
    char url[MAX];
};

int top=-1;
struct page stack[MAX];

void visitPage(struct page x)
{
    if(top==MAX-1)
    {
        printf("Stack is full. \n");
        return;
    }
    stack[++top]=x;
}

void goBack()
{
    if(top==-1)
    {
        printf("Stack is empty. \n");
        return;
    }
    top--;
    printf("%s \n", stack[top].url);

}

void display_history(int t)
{
    if(t==-1)
        return;
    else
    {
        printf("%s \n", stack[t].url);
        display_history(--t);
    }
}

int longestUrl(int t)
{
    if(t==-1)
        return -1;
    
    int currentlen = strlen(stack[t].url);
    int maxRemaining = longestUrl(t-1);

    if(maxRemaining==-1)
        return t;

    if(currentlen>strlen(stack[maxRemaining].url))
        return t;
    else
        return maxRemaining;
}