#include <stdio.h>

void selectionSort(int arr[], int n)
{
    for(int i=0; i<n-1; i++)
    {
        int minIndex=i;
        for(int j=i+1; j<n; j++)
        {
            if(arr[j]<arr[minIndex])
                minIndex=j;
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
        for(int j=i; j<n-i-1; j++)
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
        int j=i-1;
        while(j>=0 && arr[j]>key)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int binarySearch(int arr[], int start, int end, int target)
{
    if(end>=start)
    {
        int mid = start + (end-start)/2;
        if(arr[mid]==target)
            return mid;
        else if(arr[mid]>target)
            return binarySearch(arr, start, mid-1, target);
        else
            return binarySearch(arr, mid+1, end, target);
    }
    return -1;
}

