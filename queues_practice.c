#include <stdio.h>
#include <string.h>
#define MAX 100
typedef int element;
element queue[MAX];
int front = -1;
int rear = -1;

int isEmpty()
{
    if(front==-1)
    {
        return 1;
    }
    return 0;
}

int isFull()
{
    if(rear == MAX-1)
    {
        return 1;
    }
    return 0;
}

void enqueue(element item)
{
    if(isFull())
    {
        printf("Queue is full. \n");
        return;
    }
    else if(isEmpty())
        front=0;
    queue[++rear] = item;
}

element dequeue()
{
    if(isEmpty())
    {
        printf("Stack is empty. \n");
        return -1;
    }

    int item = queue[front];

    if(front==rear)
    {
        front=rear=-1;
    }

    else
        front++;

    return item;
}

element peek()
{
    if(isEmpty())
    {
        printf("Stack is empty. \n");
        return -1;
    }
    return queue[front];
}

int main()
{

}