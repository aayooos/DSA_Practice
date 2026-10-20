#include <stdio.h>
#define MAX 100
typedef int element;
element queue[MAX];

int front = -1;
int rear = -1;

void enqueue(element item)
{
    if(front==-1 && rear==-1)
    {
        front=rear=0;
        queue[rear] = item;
    }

    else if((rear+1)%MAX==front)
    {
        printf("Stack is full. \n");
        return;
    }

    else
    {
        rear = (rear+1)%MAX;
        queue[rear] = item;
    }
}

element dequeue()
{
    if(front==-1 && rear==-1)
    {
        printf("Stack is empty. \n");
        return -1;
    }

    else if(front==rear)
    {
        int temp = queue[front];
        front=rear=-1;
        return temp;
    }

    else
    {
        int temp = queue[front];
        front = (front+1)%MAX;
        return temp;
    }
}

element peek()
{
    return queue[front];
}