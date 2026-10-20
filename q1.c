#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Enter the size of the matrix: \n");
    scanf("%d", &n);

    int *matrix = (int*)calloc(n, sizeof(int));
    for(int i=0; i<n; i++)
    {
        scanf("%d", &matrix[i]);
    }

    printf("Minimum element is: %d \n", min(matrix, n));

}

int min(int matrix[], int n)
{
    int* ptr;
    ptr = &matrix[0];
    for(int i=0; i<n; i++)
    {
        if(matrix[i]<*ptr)
            ptr=&matrix[i];
    }

    return *ptr;
}