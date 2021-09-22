/***********************************
*                                  *
*          Es Array Funz           *
*                                  *
************************************/
//
//      Scrivere un programma che legge n e due vettori di dimensione n, 
//      e fa il prodotto scalare tra i due vettori. 
//      Il prodotto va calcolato in una funzione.
//
#include <stdio.h>


float dotProduct(float *, float *, int dim);

int main(){
    int n;
    scanf("%d", &n);

    float A1[n], A2[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%f", A1 + i);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%f", A2 + i);
    }
    
    float s = 0;
    for(int i = 0; i < n; i++){
        s += A1[i] * A2[i];
    }


    printf("%f\n", s);

    return 0;
}