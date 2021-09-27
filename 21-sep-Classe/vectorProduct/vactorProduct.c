#include <stdio.h>

int dotProduct(int *, int * , int);
void vecProduct(int *, int * , int* , int);

void inputVec(int *, int);
void outputVec(int *, int);

int main(){

    int n;
    scanf("%d", &n);

    int A[n], B[n], C[n];
    inputVec(A,n);
    inputVec(B,n);
    
    int res = dotProduct(A, B, n);
    vecProduct(A, B, C, n);

    outputVec(A,n);
    printf("\n");
    outputVec(B,n);
    printf("\n");
    outputVec(C,n);
    printf("\n");
    printf("%d\n", res);

    return 0;

}

void inputVec(int * A, int len)
{
    for (int i = 0; i < len; i++)   scanf("%d", A+i);
    
}
void outputVec(int * A, int len)
{
    for (int i = 0; i < len; i++)   printf("%d ", A[i]);
    
}

int dotProduct(int * A, int * B, int len)
{
    int sum = 0;
    for (int i = 0; i < len; i++)   sum += A[i] * B[i];

    return sum;

}
void vecProduct(int * A, int * B, int * C, int len)
{
    for (int i = 0; i < len; i++)   C[i] = A[i] * B[i];
}
