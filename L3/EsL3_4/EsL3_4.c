#include <stdio.h>
#include <stdlib.h>

int prodMatTrans(int r, int c, int* M, int* R);
void inpMatrix(int n, int m, int *A);
void outMatrix(int n, int m, int *A);

int main()
{

    int r,c;
    scanf("%d %d", &r, &c);

    int* M,* R;
    M = (int*)calloc(r*c, sizeof(int));
    R = (int*)calloc(r*r, sizeof(int));

    inpMatrix(r, c, M);

    prodMatTrans(r, c, M, R);

    outMatrix(r, r, R);

    return 0;
}

int prodMatTrans(int r, int c, int* M, int* R)
{

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < r; j++)
        {
            int sum=0;
            for (int z = 0; z < c; z++)
            {
                sum += M[i* c + z]*M[j*c + z];
            }
            R[i*r + j] = sum;
        }
        
    }
    
    return 0;
}

void inpMatrix(int n, int m, int *A)
{
    for (int i = 0; i < n * m; i++)
        scanf("%d", A+i);
}
void outMatrix(int n, int m, int *A)
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++) printf("%d ", A[i*m + j]);
        printf("\n");
    }
}