// // #include <stdio.h>

// // void insertionSort(int arr[], int n)
// // {
// //     for(int i=1; i<n; i++)
// //     {
// //         int j=i-1;
// //         int key=arr[i];
// //         while(j>=0 && arr[j]>key)
// //         {
// //             arr[j+1]=arr[j];
// //             j--;
// //         }
// //         arr[j+1]=key;
// //     }
// // }

// // int fact(int n)
// // {
// //     int factorial=1;
// //     if(n==1)
// //         return 1;
// //     else if(n==0)
// //         return 1;
// //     else
// //     {
// //         factorial = n*fact(n-1);
// //     }
// // }

// // int binarySearchRecursion(int arr[], int start, int end, int target)
// // {
// //     if(end>=start)
// //     {
// //         int mid = (start+end)/2;
// //         if(target>arr[mid])
// //             return binarySearchRecursion(arr, mid+1, end, target);
// //         else if(target<arr[mid])
// //             return binarySearchRecursion(arr, start, mid-1, target);
// //         else
// //             return mid;
// //     }
// //     return -1;
// // }

// // int **createMatrix(int rows, int cols)
// // {
// //     int **table = (int**)calloc(rows, sizeof(int*));
// //     if(table==NULL)
// //     {
// //         printf("Overflow. \n");
// //         return;
// //     }
// //     for(int i=0; i<rows; i++)
// //     {
// //         table[i] = (int*)calloc(cols, sizeof(int));
// //         if(table[i]==NULL)
// //         {
// //             printf("Overflow. \n");
// //             return;
// //         }
// //     }
// //     return table;
// // }


// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>
// #define MAX 100

// char stack[MAX];
// int top=-1;

// void push(char item)
// {
//     if(top==MAX-1)
//     {
//         printf("Full. \n");
//         return;
//     }
//     else
//     {
//         stack[++top]=item;
//     }
// }

// char pop()
// {
//     if(top==-1)
//     {
//         printf("Empty. \n");
//         return;
//     }
//     else
//     {
//         return top--;
//     }
// }

// int checkPair(char c1, char c2)
// {
//     return ((c1=='(' && c2==')') || (c1=='[' && c2==']') || (c1=='{' && c2=='}'));
// }

// int checkBalanced(char expr[])
// {
//     int len = strlen(expr);
//     for(int i=0; i<len; i++)
//     {
//         if(expr[i]=='(' || expr[i]=='{' || expr[i]=='[')
//             push(expr[i]);
//         else if(expr[i]==')' || expr[i]=='}' || expr[i]==']')
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


// int checkDuplicate(char expr[])
// {
//     int len = strlen(expr);
//     for(int i=0; i<len; i++)
//     {
//         if(expr[i]==')')
//         {
//             if(stack[top]=='(')
//                 return 1;
//             while(stack[top]!='(')
//             {
//                 pop();
//             }
//             pop();
//         }
//         else
//             push(expr[i]);
//     }
//     return 0;
// }


// int isOperand(char ch)
// {
//     return ((ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>=0 && ch<=9));
// }

// int precedence(char ch)
// {
//     if(ch=='*' || ch=='/')
//         return 2;
//     else if(ch=='^')
//         return 3;
//     else if(ch=='+'||ch=='-')
//         return 1;
//     return 0;
// }

// void convert(char expr[])
// {
//     int len = strlen(expr);
//     int j=0;
//     char result[len];
//     for(int i=0; i<len; i++)
//     {
//         if(expr[i]=='(')
//         {
//             push(expr[i]);
//         }
//         else if(expr[i]==')')
//         {
//             while(top!=-1 && stack[top]!='(')
//             {
//                 result[j++]=pop();
//             }
//             pop();
//         }
//         else if(isOperand(expr[i]))
//         {
//             result[j++]=expr[i];
//         }
//         else
//         {
//             if(top==-1 || precedence(expr[i])>precedence(stack[top]))
//             {
//                 push(expr[i]);
//             }
//             else if(precedence(expr[i])<precedence(stack[top]))
//             {
//                 while(top!=-1 && precedence(expr[i])<precedence(stack[top]))
//                 {
//                     result[j++]=pop();
//                 }
//                 push(expr[i]);
//             }
//             else
//             {
//                 if(expr[i]=='^')
//                 {
//                     push(expr[i]);
//                 }
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
//         result[j++]=pop();
//     }
//     result[j]='\0';
// }



// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #define max 100

// int stack[max];
// int top[max];
// int boundary[max];

// void initialize(int n)
// {
//     for(int i=0; i<n; i++)
//     {
//         top[i]=boundary[i]=((max/n)*i)-1;
//     }
//     boundary[n]=max-1;
// }

// void push(int i, int item)
// {
//     if(top[i]==boundary[i+1])
//     {
//         printf("Stack is full. \n");
//         return;
//     }
//     stack[++top[i]]=item;
// }

// int pop(int i)
// {
//     if(boundary[i]==top[i])
//     {
//         printf("Stack is empty. \n");
//         return;
//     }
//     return stack[top[i]--];
// }

// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>
// #define max 100

// struct node
// {
//     int data;
//     struct node *next;
// };

// struct node *front[max];
// struct node *rear[max];

// void init()
// {
//     for(int i=0; i<max; i++)
//     {
//         front[i]=rear[i]=NULL;
//     }
// }

// void enqueue(int item, int q)
// {
//     struct node *newNode = (struct node*)malloc(sizeof(struct node));
//     if(newNode==NULL)
//     {
//         printf("Overlfow. \n");
//         return;
//     }
//     newNode->data = item;
//     newNode->next = NULL;
//     if(rear[q]==NULL)
//     {
//         front[q]=rear[q]=newNode;
//     }
//     else
//     {
//         rear[q]->next = newNode;
//         rear[q]=newNode;
//     }
// }

// int dequeue(int q)
// {
//     struct node *temp = front[q];
//     if(temp==NULL)
//     {
//         printf("Empty. \n");
//         return;
//     }
//     else
//     {
//         int val = temp->data;
//         front[q]=front[q]->next;
//         if(front[q]==NULL)
//             rear[q]=NULL;
//         free(temp);
//     }
// }

// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>
// #define max 100

// int front=-1;
// int rear=-1;
// int queue[max];

// void push(int item)
// {
//     if(front==-1)
//     {
//         front=rear=0;
//         queue[rear]=item;
//     }
//     else if((rear+1)%max==front)
//     {
//         printf("Full. \n");
//         return;
//     }
//     else
//     {
//         rear=(rear+1)%max;
//         queue[rear]=item;
//     }
// }

// int pop()
// {
//     if(front==-1)
//     {
//         printf("Empty. \n");
//         return;
//     }
//     else if(front==rear)
//     {
//         int temp = queue[front];
//         front=rear=-1;
//         return temp;
//     }
//     else
//     {
//         front = (front+1)%max;
//     }
// }

// #include <stdio.h>
// #define max 100

// int deque[100];
// int front=-1;
// int rear=-1;

// void insertFront(int item)
// {
//     if((front==0 && rear==max-1) || front==rear+1)
//     {
//         printf("Full. \n");
//         return;
//     }
//     if(front==-1)
//     {
//         front=rear=0;
//     }
//     else if(front==0)
//     {
//         front=max-1;
//     }
//     else
//         front=front-1;

//     deque[front]=item;
// }

// void deleteFront()
// {
//     if(front==-1)
//     {
//         printf("Empty. \n");
//         return;
//     }
//     if(front==0)
//     {
//         front=rear=-1;
//     }
//     else if(front==max-1)
//     {
//         front=0;
//     }
//     else
//     {
//         front=front+1;
//     }
// }


// void insertRear()
// {
//     if(front==0 && rear==max-1 || front==rear+1)
//     {
//         printf("Full. \n");
//         return;
//     }
//     if(front==1)
//     {
//         front=rear=0;
//     }
//     else if(rear==max-1)
//     {
//         rear=0;
//     }
//     else 
//         rear=rear+1;
    
// }

// void deleteRear()
// {
//     if(front==-1)
//     {
//         printf("Empty. \n");
//         return;
//     }
//     if(front==rear)
//     {
//         front=rear=-1;
//     }
//     else if(rear==0)
//         rear=max-1;
//     else
//         rear=rear-1;
// }


// #include <stdio.h>
// #include <stdlib.h>
// #define max 5
// struct node 
// {
//     int data;
//     struct node *next;
// };

// struct node *head=NULL;

// void reverse_List()
// {
//     struct node *prev=NULL, *current=head, *next=NULL;
//     if(head==NULL)
//     {
//         printf("Empty. \n");
//         return;
//     }
//     while(current!=NULL)
//     {
//         next = current->next;
//         current->next=prev;
//         prev=current;
//         current=next;
//     }
//     head=prev;
// }


// void selectionSort(int arr[], int n, int i)
// {
//     if(i==n-1)
//     {
//         return;
//     }

//     int minIndex=i;
//     for(int j=i+1; j<n; j++)
//     {
//         if(arr[j]<arr[minIndex])
//             minIndex=j;
//     }
//     if(minIndex!=i)
//     {
//         int temp=arr[minIndex];
//         arr[minIndex]=arr[i];
//         arr[i]=temp;
//     }
//     selectionSort(arr, n, i+1);     
// }

// #include <stdio.h>
// int **A, **B, **C;
// int main()
// {
//     int rows=2;
//     int cols=2;
//     A = (int**)calloc(rows, sizeof(int*));
//     B = (int**)calloc(rows, sizeof(int*));
//     for(int i=0; i<cols; i++)
//     {
//         *(A+i)=(int*)calloc(cols, sizeof(int*));
//     }
//     for(int i=0; i<cols; i++)
//     {
//         *(B+i)=(int*)calloc(cols, sizeof(int*));
//     }

//     for(int i=0; i<rows; i++)
//     {
//         for(int j=0; j<cols; j++)
//         {
//             scanf("%d", &(*(*(A+i)+j)));
//         }
//     }

//     for(int i=0; i<rows; i++)
//     {
//         for(int j=0; j<cols; j++)
//         {
//             scanf("%d", &(*(*(A+i)+j)));
//         }
//     }

//     C = (int**)calloc(rows, sizeof(int*));
//     for(int i=0; i<rows; i++)
//     {
//         *(C+i)=(int*)calloc(cols, sizeof(int));
//     }

//     for(int i=0; i<rows; i++)
//     {
//         for(int j=0; j<cols; j++)
//         {
//             for(int k=0; k<cols; k++)
//             {
//                 *(*(C+i)+j) += (*(*(A+i)+k)) * (*(*(B+k)+j));
//             }
//         }
//     }
// }


