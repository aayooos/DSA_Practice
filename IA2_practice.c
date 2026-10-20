// #include <stdio.h>
// #include <string.h>
// #define MAX 100

// typedef int element;
// element queue[MAX];
// int front=-1;
// int rear=-1;

// int isFull()
// {
//     return (rear==MAX-1);
// }

// int isEmpty()
// {
//     return (front==-1);
// }

// element Peek()
// {
//     if(isEmpty())
//     {
//         printf("Queue is empty. \n");
//         exit(1);
//     }
//     return queue[front];
// }

// void enqueue(element item)
// {
//     if(isFull())
//     {
//         printf("Queue is full. \n");
//         return;
//     }
//     else if(isEmpty())
//     {
//         front=0;
//     }
//     queue[++rear]=item;
// }

// element dequeue()
// {
//     if(isEmpty())
//     {
//         printf("Queue is empty. \n");
//         exit(1);
//     }

//     element temp = queue[front];
//     if(front==rear)
//     {
//         front = rear = -1; 
//     }
//     else
//     {
//         front++;
//     }
//     return temp;
// }

// #include <stdio.h>
// #define MAX 100

// int front=-1;
// int rear=-1;
// typedef int element;
// element queue[MAX];

// void enqueue(element item)
// {
//     if(front==-1 && rear==-1)
//     {
//         front=rear=0;
//         queue[rear] = item;
//     }
//     else if((rear+1)%MAX==front)
//     {
//         printf("Queue is full. \n");
//     }
//     else
//     {
//         rear = (rear+1)%MAX;
//         queue[rear]=item;
//     }
// }

// element dequeue()
// {
//     if(front==-1 && rear==-1)
//     {
//         printf("Queue is empty. \n");
//         exit(1);
//     }
//     else if(front==rear)
//     {
//         element temp = queue[front];
//         front = rear = -1;
//         return temp;
//     }
//     else
//     {
//         element temp = queue[front];
//         front = (front+1)%MAX;
//         return temp;
//     }
// }

// #include <stdio.h>
// #define MAX 100
// int size=0;

// typedef int element;
// element queue[MAX];

// void insertElement(element item)
// {
//     if(size==MAX-1)
//     {
//         printf("Queue is full. \n");
//         return;
//     }
//     queue[size++] = item;
// }

// void deleteElement()
// {
//     int maxIndex=0;
//     for(int i=1; i<size; i++)
//     {
//         if(queue[i]>queue[maxIndex])
//             maxIndex = i;
//     }
//     int maxElement = queue[maxIndex];
//     for(int i=maxElement; i<size-1; i++)
//     {
//         queue[i] = queue[i+1];
//     }
//     size--;
//     return maxElement;
// }

