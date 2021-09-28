#include <stdio.h>
#define bool unsigned short
#define true 1
#define false 0
#define N 3

bool exLessThanAll(int *, int *, int);

void inputVec(int *, int);
void outputVec(int *, int);

int main()
{

    int A[N], B[N];

    inputVec(A, N);
    inputVec(B, N);
    
    printf("%s\n", exLessThanAll(A, B, N)?"True":"False");

    return 0;
}

bool exLessThanAll(int *A, int *B, int len)
{

    for (int i = 0; i < len; i++){
        int j;
        for(j = 0; j < len && A[i] < B[j]; j++);
        if(j == len) return true;
    }

    return false;
}

void inputVec(int * A, int len)
{
    for (int i = 0; i < len; i++)   scanf("%d", A+i);
    
}
void outputVec(int * A, int len)
{
    for (int i = 0; i < len; i++)   printf("%d ", A[i]);
    
}
