#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *lchild, *rchild;
};
struct node *getnode(){
    struct node *p = (struct node *)malloc(sizeof(struct node));
    if(p==NULL){
        printf("Memory allocation failed");
        exit(1);
    }
    return p;
}
struct node *createbst(struct node *root, int x){
     if(root == NULL){
        root = getnode();
        root->data = x;
        root->lchild = root->rchild = NULL;
        return root;
     }
     else if(x<root->data)
     root->lchild = createbst(root->lchild, x);
     else if(x>root->data)
     root->rchild = createbst(root->rchild, x);
    return root;
}