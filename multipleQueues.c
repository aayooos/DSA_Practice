// #include <stdio.h>
// #include <stdlib.h>
// #define MAX 5

// struct node
// {
//     int data;
//     struct node *next;
// };

// struct node *front[MAX];
// struct node *rear[MAX];

// void initQueues()
// {
//     for(int i=0; i<MAX; i++)
//     {
//         front[i] = rear[i] = NULL;
//     }
// }

// int isEmpty(struct node *f)
// {
//     return (f==NULL);
// }

// void enqueue(int q, int item)
// {
//     struct node *newNode = (struct node*)malloc(sizeof(struct node));
//     if(newNode==NULL)
//     {
//         printf("Overflow. \n");
//         return;
//     }
//     newNode->data = item;
//     newNode->next = NULL;
//     if(rear[q]!=NULL)
//     {
//         rear[q]->next = newNode;
//         rear[q] = newNode;
//     }
//     else
//     {
//         front[q]=rear[q]=newNode;
//     }
// }

// int dequeue(int q)
// {
//     if(front[q]==NULL)
//     {
//         printf("List empty. \n");
//         return;
//     }
//     struct node *temp = front[q];
//     int val = temp->data;
//     front[q]=front[q]->next;
//     if(front[q]==NULL)
//         rear[q]=NULL;
//     free(temp);
//     return val;
// }


// void initQueue()
// {
//     for(int i=0; i<MAX; i++)
//     {
//         front[i]=rear[i]=NULL;
//     }
// }


#include <stdio.h>
#include <stdlib.h>
#define MAX 100

struct node
{
    int data;
    struct node *next;
};

struct node *front[MAX];
struct node *rear[MAX];


void initQueue()
{
    for(int i=0; i<MAX; i++)
    {
        front[i]=rear[i]=NULL;
    }
}

void enqueue(int q, int item)
{
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    if(newNode==NULL)
    {
        printf("Overflow. \n");
        return;
    }
    newNode->data = item;
    newNode->next = NULL;
    if(rear[q]==NULL)
    {
        front[q]=rear[q]=newNode;
    }
    else
    {
        rear[q]->next = newNode;
        rear[q] = newNode;
    }

}

int dequeue(int q)
{
    struct node *temp = front[q];
    if(front[q]==NULL)
    {
        printf("List is empty. \n");
        return;
    }
    int val = temp->data;
    front[q]=front[q]->next;
    if(front[q]==NULL)
        rear[q]=NULL;
    free(temp);
    return val;
}

