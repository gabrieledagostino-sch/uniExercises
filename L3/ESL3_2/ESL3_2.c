#include <stdio.h>
#define N 4
#define M 3

void inpMatrix(int *, int, int);
int mul3Col(int *, int);

int main()
{

    int A[N][M];
    inpMatrix((int *)A,N,M);

    printf("%d", mul3Col((int *)A, N));

    return 0;
}



int mul3Col(int *A, int n)
{
    for(int j = 0; j < M; j++)
    {
        int i;
        for (i = 0; i < n && A[i*M + j]%3==0; i++);
        if(i == n) return j;
    }

    return -1;
}

void inpMatrix(int *A, int n, int m)
{
    for (int i = 0; i < n * m; i++)
        scanf("%d", A+i);
}