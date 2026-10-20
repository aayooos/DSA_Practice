#include <stdio.h>
#include <stdlib.h>

void productFunction(int** matrix1, int** matrix2, int rows1, int cols1, int rows2, int cols2);


int main()
{
    int rows1, cols1;
    printf("Enter the number of rows andn cols: ");
    scanf("%d", &rows1);
    scanf("%d", &cols1);

    int** matrix1 = (int**)calloc(rows1, sizeof(int*));
    if(matrix1==NULL)
        exit(0);
    for(int i=0; i<rows1; i++)
    {
        matrix1[i] = (int*)calloc(cols1, sizeof(int));
        if(matrix1[i]==NULL)
            exit(0);
    }

    printf("Enter the elements into the matrix: ");
    for(int i=0; i<rows1; i++)
    {
        for(int j=0; j<cols1; j++)
        {
            scanf("%d", (*(matrix1+i)+j));
        }
    }

    int rows2, cols2;
    printf("Enter the number of rows andn cols: ");
    scanf("%d", &rows2);
    scanf("%d", &cols2);

    int** matrix2 = (int**)calloc(rows2, sizeof(int*));
    if(matrix2==NULL)
        exit(0);
    for(int i=0; i<rows2; i++)
    {
        matrix2[i] = (int*)calloc(cols2, sizeof(int));
        if(matrix2[i]==NULL)
            exit(0);
    }

    printf("Enter the elements into the matrix: ");
    for(int i=0; i<rows2; i++)
    {
        for(int j=0; j<cols2; j++)
        {
            scanf("%d", (*(matrix2+i)+j));
        }
    }

    productFunction(matrix1, matrix2, rows1, cols1, rows2, cols2);

}

void productFunction(int** matrix1, int** matrix2, int rows1, int cols1, int rows2, int cols2)
{
    if(cols1!=rows2)
    {
        printf("Invalid matrix entries.");
        return;
    }
    int** product = (int**)calloc(rows1, sizeof(int*));
    if(product==NULL)
        exit(0);
    for(int i=0; i<rows1; i++)
    {
        product[i] = (int*)calloc(cols2, sizeof(int));
        if(product[i]==NULL)
            exit(0);
    }

    for(int i=0; i<rows1; i++)
    {
        for(int j=0; j<cols2; j++)
        {
            for(int k=0; k<cols1; k++)
            {
                *(*(product+i)+j) += *(*(matrix1+i)+k) * *(*(matrix2+k)+j);
            }
        }
    }

    for(int i=0; i<rows1; i++)
    {
        for(int j=0; j<cols2; j++)
        {
            printf("%d ", *(*(product+i)+j));
        }
        printf("\n");
    }

    for(int i=0; i<rows1; i++)
        free(matrix1[i]);
    free(matrix1);

    for(int i=0; i<rows2; i++)
        free(matrix2[i]);
    free(matrix2);

    for(int i=0; i<rows1; i++)
        free(product[i]);
    free(product);

}