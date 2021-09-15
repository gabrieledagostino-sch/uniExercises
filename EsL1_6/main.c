#include <stdio.h>
#include <stdlib.h>


#define N 4
#define M 3


int main()
{
    int A[N][M], B[N][M];

    //input
    //A
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j<M; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }

    //B
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j<M; j++)
        {
            scanf("%d", &B[i][j]);
        }
    }
    
    //output
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j<M; j++)
        {
            printf("%d ", A[i][j] + B[i][j]);
        }
        printf("\n");
    }


    return 0;
}