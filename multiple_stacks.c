#include <stdio.h>
#define MAX 100

int storage[MAX];
int top[MAX];
int boundary[MAX];
int n;

void initialize(int n)
{
    for(int i=0; i<n; i++)
    {
        top[i] = boundary[i] = ((MAX/n)*i)-1;
    }
    boundary[n] = MAX-1;
}

void push(int i, int item)
{
    if(top[i]==boundary[i+1])
    {
        printf("Stack is full. \n");
        return;
    }
    storage[++top[i]] = item;
}

int pop(int i)
{
    if(top[i]==boundary[i])
    {
        printf("Stack is empty. \n");
        return -1;
    }
    return storage[top[i]--];
}

//------------------------------------------------------//

// #include <stdio.h>
// #define MAX 100
// int top[MAX];
// int boundary[MAX];
// storage[MAX][MAX];

// void initialize(int n)
// {
//     for(int i=0; i<n; i++)
//     {
//         top[i] = boundary[i] = ((MAX/n)*i)-1;
//     }
//     boundary[n] = MAX-1;
// }

// void push(int i, char item[])
// {
//     if(top[i]==boundary[i+1])
//     {
//         printf("Stack is full. \n");
//         return;
//     }
//     strcpy(storage[++top[i]], item);
// }

// char* pop(int i)
// {
//     if(top[i]==boundary[i])
//     {
//         printf("Stack is empty. \n");
//         return -1;
//     }
//     return storage[top[i]--];
// }

// void display(int i)
// {
//     if(top[i]==boundary[i])
//     {
//         printf("Stack is empty. \n");
//         return;
//     }
//     for(int j=top[i]; j>boundary[i]; j--)
//     {
//         printf("%s", storage[j]);
//     }
// }

// #include <stdio.h>
// #include <string.h>
// #define MAX 100
// int top[MAX];
// int stack[MAX];
// int boundary[MAX];

// void initialize(int n)
// {
//     for(int i=0; i<n; i++)
//     {
//         top[i] = boundary[i] = ((MAX/n)*i)-1;
//     }

//     boundary[n] = MAX-1;
// }

// void push(int i, int item)
// {
//     if(top[i]==boundary[i+1])
//     {
//         printf("Stack is full. \n");
//         return;
//     }
//     stack[++top[i]] = item;
// }

// int pop(int i)
// {
//     if(top[i]==boundary[i])
//     {
//         printf("Stack is empty. \n");
//         return -1;
//     }
//     return stack[top[i]--];
// }

// void display(int i)
// {
//     for(int j=top[i]; j>boundary[i]; j--)
//     {
//         printf("%d", stack[j]);
//     }
// }