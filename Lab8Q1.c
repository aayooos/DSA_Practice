#include <stdio.h>
#define MAX 100
int front = -1;
int rear = -1;
struct task
{
    char docname[MAX];
    int id;
};

struct task queue[MAX];

void enqueue(struct task t)
{
    if(rear == MAX-1)
    {
        printf("Queue is full. \n");
        return;
    }

    else if(front==-1)
    {
        front=0;
    }
    queue[++rear] = t;
}

void dequeue()
{
    if(front==-1)
    {
        printf("Queue is empty. \n");
        return;
    }
    else if(front==rear)
    {
        struct task temp = queue[front];
        front=rear=-1;
        printf("Task id: %d \nTask name: %s", temp.id, temp.docname);
    }
    else
    {
        struct task temp = queue[front];
        printf("Task id: %d \nTask name: %s", temp.id, temp.docname);
        front++;
    }

}

int main()
{
    int n;
    printf("Enter the number of jobs: \n");
    scanf("%d", &n);

    for(int i=0; i<n; i++)
    {
        struct task t;
        printf("Enter the document name and id: \n");
        scanf("%s", t.docname);
        scanf("%d", &t.id);
        enqueue(t);
    }

    for(int i=0; i<n; i++)
    {
        dequeue();
        printf("\n");
    }
}