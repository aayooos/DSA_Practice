#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Enter number of elements: ");
    int n;
    scanf("%d", &n);
    int arr[n];

    printf("Enter the elements: ");
    for(int i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }

    selectionSort(arr, n, 0);

    for(int i=0; i<n; i++)
    {
        printf("%d ", arr[i]);
    }

}

void swap(int i, int minI, int arr[])
{
        int temp = arr[i];
        arr[i] = arr[minI];
        arr[minI] = temp;
}

void selectionSort(int arr[], int n, int i)
{
    if(i==n-1)
        return;
    int minI=i;
    for(int j=i+1; j<n; j++)
    {
        if(arr[j]<arr[minI])
            minI=j;
    }

    swap(i, minI, arr);
    selectionSort(arr, n, i+1);
}