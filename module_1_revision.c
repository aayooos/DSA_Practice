#include <stdio.h>

void selectionSort(int arr[], int n)
{
    for(int i=0; i<n; i++)
    {
        int minIndex = i;
        for(int j=i+1; j<n; j++)
        {
            if(arr[j]<arr[minIndex])
                minIndex = j;
        }

        if(minIndex!=i)
        {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

void bubbleSort(int arr[], int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n-i-1; j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void insertionSort(int arr[], int n)
{
    for(int i=1; i<n; i++)
    {
        int key = arr[i];
        int j = i-1;

        while(j>=0 && arr[j]>key)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int main()
{
    // int arr[] = {4, 1, 2, 3, 5};
    // insertionSort(arr, 5);
    // for(int i=0; i<5; i++)
    // {
    //     printf("%d", arr[i]);
    // }
    // int arr[][2] = {{1, 2}, {3, 4}};
    // int i, j;
    // int (*p)[2];
    // p = arr;
    // for(int i=0; i<2; i++)
    // {
    //     for(int j=0; j<2; j++)
    //     {
    //         printf("%d", *(*(p+i)+j))
    //     }
    // }

}

int** createMatrix(int rows, int cols)
{
    int **table;
    table = (int**)calloc(rows, sizeof(int*));
    if(table==NULL)
    {
        printf("Memory allocation failed, exiting. \n");
        exit(1);
    }
    for(int i=0; i<rows; i++)
    {
        table[i] = (int*)calloc(rows, sizeof(int));
        if(table[i]==NULL)
        {
            printf("Memory allocation failed, exiting. \n");
            exit(1);
        }
    }

    return table;
}

int lenString(char str[])
{
    char *ptr = str;
    while(*ptr!='\0')
    {
        ptr++;
    }

    return ptr-str;
}

char* strConcat(char str1[], char str2[])
{
    int len3 = lenString(str1)+lenString(str2)+1;
    char *str3 = (char*)calloc(lenString(str1)+lenString(str2)+1, sizeof(char));
    for(int i=0; i<lenString(str1); i++)
    {
        str3[i] = str1[i];
    }
    for(int j=0; j<lenString(str2); j++)
    {
        str3[lenString(str1)+j] = str2[j];
    }
    str3[lenString(str1)+lenString(str2)] = '\0';

    return str3;
}

int strComp(char str1[], char str2[])
{
    int len1 = lenString(str1);
    int len2 = lenString(str2);
    if(len1!=len2)
        return 0;
    else
    {
        for(int i=0; i<len1; i++)
        {
            if(str1[i]!=str2[i])
                return 0;
        }
    }

    return 1;
}

void insertSub(char mainString[], char subString[], int insertIndex)
{
    int mainLen = lenString(mainString);
    int subLen = lenString(subString);
    char *newString = (char*)calloc(mainLen+subLen+1, sizeof(char));
    for(int i=0; i<insertIndex; i++)
    {
        newString[i] = mainString[i];
    }

    int j=0;
    for(int i=insertIndex; i<insertIndex+subLen; i++)
    {
        newString[i] = subString[j++];
    }

    for(int i=insertIndex+subLen; i<mainLen+subLen; i++)
    {
        newString[i] = mainString[i-subLen];
    }
    newString[mainLen+subLen] = '\0';
    

}

void delSubstring()
{
    
}