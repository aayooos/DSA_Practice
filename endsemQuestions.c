// #include <stdio.h>
// #include <stdlib.h>
// #define max 100
// #include <string.h>

// typedef struct centreNode
// {
//     int cid;
//     char cname[max];
//     char location[max];
//     struct node  *lchild;
//     struct node *rchild;
// }*centreNode;

// typedef struct request
// {
//     int rid;
//     int cid;
//     char item[max];
//     int quantity;
//     int priority;
//     struct request *next;
// }*request;


// centreNode getcNode()
// {
//     centreNode temp = (centreNode)malloc(sizeof(struct centreNode));
//     if(temp==NULL)
//     {
//         printf("Allocation failed. \n");
//         return;
//     }
//     temp->lchild = temp->rchild = NULL;
//     return temp;
// }

// centreNode search(centreNode root, int cid)
// {
//     if(root==NULL)
//         return NULL;
//     if(root->cid==cid)
//         return root;
//     else if(root->cid>cid)
//         return search(root->lchild, cid);
//     else
//         return search(root->rchild, cid);
// }

// centreNode addReliefCenter(centreNode root, int cid, char cname[], char location[])
// {
//     centreNode temp = getcNode();
//     if(temp==NULL)
//         return root;
//     temp->cid = cid;
//     strcpy(temp->cname, cname);
//     strcpy(temp->location, location);
//     centreNode current = root;
//     centreNode parent = NULL;

//     while(current)
//     {
//         parent = current;
//         if(strcmp(current->cname, cname)>0)
//         {
//             current = current->lchild;
//         }
//         else if(strcmp(current->cname, cname)<0)
//         {
//             current = current->rchild;
//         }
//         else
//         {
//             printf("Can't have duplicate names. \n");
//             return NULL;
//         }
//     }
//     if(strcmp(cname, parent->cname)>0)
//         parent->rchild = temp;
//     else
//         parent->lchild = temp;
//     printf("Relief center added. \n");
//     return root;
// }


// request getrNode()
// {
//     request temp = (request)malloc(sizeof(struct request));
//     if(temp==NULL)
//     {
//         printf("Allocation failed. \n");
//         return NULL;
//     }
//     temp->next = NULL;
//     return temp;
// }

// request submitRequest(int rid, int cid, char item[], int quantity, int priority, request front, centreNode root)
// {
//     if(search(root, cid)==NULL)
//     {
//         printf("Invalid. \n");
//         return;
//     }
//     request temp = getrNode();
//     temp->rid = rid;
//     temp->cid = cid;
//     temp->quantity = quantity;
//     temp->priority = priority;
//     strcpy(temp->item, item);

//     if(front==NULL || temp->priority>front->priority)
//     {
//         temp->next = front;
//         front = temp;
//     }
//     else
//     {
//         request current = root;
//         while(current->next!=NULL && current->next->priority>=temp->priority)
//         {
//             current = current->next;
//         }
//         temp->next = current->next;
//         current->next = temp;
//     }
//     printf("Request submitted. \n");
//     return front;
// }

// request processRequest(request front)
// {
//     if(front==NULL)
//     {
//         printf("Underflow. \n");
//         return;
//     }
//     request temp = front;
//     front = front->next;
//     free(temp);
//     printf("Processed. \n");
// }


#include <stdio.h>
#include <stdlib.h>
#define max 100
#include <string.h>

typedef struct patient
{
    int id;
    char name[max];
    int priority;
    int cost;
    struct patient *next;
}*patient;

typedef struct node
{
    char data;
    struct node *lchild;
    struct node *rchild;
}*nodeptr;

patient top=NULL;
patient head = NULL;
patient getNode()
{
    patient temp = (patient)malloc(sizeof(struct patient));
    if(temp==NULL)
    {
        printf("Allocation failed. \n");
        return NULL;
    }
    temp->next = NULL;
    return temp;
}

void registerPatient(int id, char name[], int priority, int cost)
{
    patient temp = getNode();
    temp->id = id;
    temp->priority = priority;
    temp->cost = cost;
    strcpy(temp->name, name);
    patient temp2 = head;
    while(temp2)
    {
        if(temp2->id==id)
        {
            printf("Duplicates not allowed. \n");
            return;
        }
        temp2 = temp2->next;
    }
    if(head==NULL)
    {
        head = temp;
        return;
    }
    patient current = head;
    while(current->next!=NULL)
    {
        current = current->next;
    }
    current->next = temp;
    temp->next = NULL;
    if(top==NULL)
    {
        top = temp;
    }
    temp->next = top;
    top = temp;
    printf("Succesfully registered. \n");
}

void listPatients()
{
    if(top==NULL)
    {
        printf("Empty list. \n");
        return;
    }
    patient current = top;
    while(current!=NULL)
    {
        printf("%d \n", current->id);
        printf("%s \n", current->name);
        printf("%d \n", current->priority);
        printf("%d \n", current->cost);
        printf("\n");
        current = current->next;
    }

}

void undoRegistration()
{
    if(top==NULL)
    {
        printf("Empty. \n");
        return;
    }
    patient current = head;
    while(current->next->next!=NULL)
    {
        current = current->next;
    }
    patient temp = current->next;
    current->next = NULL;
    printf("Freed %s \n", temp->name);
    free(temp);

    patient x = top;
    top = top->next;
    free(top);
}

void expressionTree(int id)
{
    patient current = top;
    int found=0;
    while(current)
    {
        if(current->id==id)
        {
            found=1;
            break;
        }
        current = current->next;
    }
    if(found==0)
    {
        printf("Invalid id. \n");
        return;
    }
    char postfix[max];
    printf("Enter a postfix expression: \n");
    scanf("%s", postfix);
    int top1=-1;
    int i=0;
    char stack[max];
    while(postfix[i]!='\0')
    {
        if(postfix[i]==' ')
        {
            i++;
            continue;
        }
        nodeptr temp = getNode();
        temp->data = postfix[i];
        if(postfix[i]=='+' || postfix[i]=='-' || postfix[i]=='*' || postfix[i]=='/')
        {
            temp->lchild = stack[top1--];
            temp->rchild = stack[top1--];
        }
        stack[++top1] = temp;
        i++;
    }

}
