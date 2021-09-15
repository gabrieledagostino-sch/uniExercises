//bubble sort: scrivere un programma che legge da tastiera dei numeri reali, 
//fino a quando legge il numero 0. 
//Il programma deve stampare i numeri letti (incluso il 0) in ordine decrescente.
#include <stdio.h>
#define N 500

void swapFloats(float* a, float* b){
    int temp = *a;
    *a = *b;
    *b = temp;
    
    return;
}

void bubbleSort(float *A, int size){
    for(int i = size; i > 0; i--){
        for(int j = 0; j < i-1; j++){
            if(A[j] < A[j+1]) swapFloats(A+j, A+j+1);
        }
    }
}

int main()
{
    float A[N];    

    int n,size = 0;
    do
    {
        scanf("%f", A+size);
    }while(A[size++] != 0);

    bubbleSort(A, size-1);

    for(int i = 0; i < size; i++){
        printf("%.2f\n", A[i]);
    }

}