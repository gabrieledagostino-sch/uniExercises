#include <stdio.h>

void inpMatrix(int *, int, int);
void outMatrix(int *, int, int);
int rowColProd(int *, int *, int *, int, int, int);

int main()
{

    int n;
    scanf("%d",&n);

    
    int A[n][n], B[n][n], C[n][n];
    inpMatrix((int *)A, n, n);
    inpMatrix((int *)B, n, n);
    printf("\n");

    outMatrix((int *)A, n, n);
    printf("\n");
    outMatrix((int *)B, n, n);
    printf("\n");

    rowColProd((int *)A, (int *)B, (int *)C, n, n, n);
    printf("\n");

    outMatrix((int *)C, n, n);
    printf("\n");

    return 0;
}

void inpMatrix(int *A, int n, int m)
{
    for (int i = 0; i < n * m; i++)
        scanf("%d", A+i);
}
void outMatrix(int *A, int n, int m)
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++) printf("(%d) ", A[i*m + j]);
        printf("\n");
    }
}
int rowColProd(int *A, int *B, int *C, int n, int m, int d)
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < d; j++)
        {   
            int sum = 0;
            for (int z = 0; z < m; z++)
            {
                sum += A[i*m + z] * B[z*d + j];
            }
            C[i*d + j] = sum;
        }
        
    }
    return 0;
}