#include <stdio.h>
#include <stdlib.h>
#define max 100


int deque[max];
int front=-1;
int rear=-1;

void insertFront(int item)
{
    if((front==0 && rear==max-1) || front==rear+1)
    {
        printf("Deque is full. \n");
        return;
    }

    if(front==-1)
    {
        front=rear=0;
    }
    else if(front==0)
    {
        front = max-1;
    }
    else
    {
        front=front-1;
    }
    deque[front]=item;
    
}

int deleteFront()
{
    if(front==-1)
    {
        printf("Empty. \n");
        return;
    }
    int val = deque[front];
    if(front==rear)
    {
        front=rear=-1;
    }
    else if(front==max-1)
    {
        front=0;
    }
    else
    {
        front = front+1;
    }
    return val;
}

void insertRear(int item)
{
    if((front==0 && rear==max-1) || front==rear+1)
    {
        printf("Full. \n");
        return;
    }
    if(front==-1)
    {
        front=rear=0;
    }
    else if(rear==max-1)
    {
        rear=0;
    }
    else
    {
        rear=rear+1;
    }
    deque[rear]=item;

}

int deleteRear()
{
    if(front==-1)
    {
        printf("Empty. \n");
        return;
    }
    if(front==rear)
    {
        front=rear=-1;
    }
    else if(rear==0)
    {
        rear=max-1;
    }
    else
    {
        rear=rear-1;
    }
}