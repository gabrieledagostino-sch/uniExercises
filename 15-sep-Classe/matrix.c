//moltiplicazione di matrici: leggere n,  due matrici nxn, e stampare il loro prodotto
#include <stdio.h>
#define N 500

int rowColMul(int A[][N], int B[][N], int row, int col, int n)
{
    int partSum = 0;
    for(int i = 0; i < n; i++){
        partSum += A[row][i] * B[i][col];
    }
    return partSum;
}

int main()
{
    int n;
    int A[N][N], B[N][N];

    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &A[i][j]);
        }
        
    }
    for(int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &B[i][j]);
        }
        
    }

    for(int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", rowColMul(A, B, i, j, n));
        }
        printf("\n");
        
    }
    for(int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
    for(int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", B[i][j]);
        }
        printf("\n");
    }

}