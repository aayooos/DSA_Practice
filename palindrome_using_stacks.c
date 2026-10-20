#include <stdio.h>
#include <string.h>
#define MAX 100
char stack[MAX];
int top = -1;

int isPalindrome(char expr[])
{
    int len = strlen(expr);
    for(int i=0; i<len; i++)
    {
        stack[++top] = expr[i];
    }
    int palindrome=1;
    for(int i=0; i<len; i++)
    {
        if(top!=-1 && stack[top]==expr[i])
            top--;
        else
        {
            palindrome=0;
            break;
        }
    }
    return palindrome;
}


int main()
{
    char expr[MAX];
    printf("Enter the string. \n");
    scanf("%s", expr);
    if(isPalindrome(expr))
        printf("Yes it's palindrome. \n");
    else
        printf("It's not a palindrome. \n");

}

