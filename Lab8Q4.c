#include <stdio.h>
int front = -1;
int rear = -1;
#define MAX 100
struct patient
{
    char name[MAX];
    int age;
    int priority;
};

