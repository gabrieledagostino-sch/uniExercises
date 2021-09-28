/**************************************************************************************
 * 
 *  Si realizzi un programma che legga un array di 10 interi da standard input ed
 *  applichi una funzione min azzera che calcoli il minimo di tutti gli elementi
 *  e azzeri tutti gli elementi in posizione dispari. Fare attenzione all’ordine in
 *  cui eseguire le operazioni, cercando di scorrere l’array una sola volta.
 *  Si stampi a video il contenuto dell’array e il minimo trovato.
 * 
**************************************************************************************/
#include <stdio.h>
#include <limits.h>
#define N 10

int min_azzera(int *A, int l);

int main()
{
    int A[N];

    for (int i = 0; i < N; i++) scanf("%d",A+i);
    
    int m = min_azzera(A, N);

    for (int i = 0; i < N; i++) printf("%d\n",A[i]);    
    printf("%d\n", m);

    return 0;
}

int min_azzera(int *A, int l)
{   
    int min = INT_MAX;

    for (int i = 0; i < l; i++)
    {
        min = min>A[i]?A[i]:min;
        A[i] = i%2==0?A[i]:0;
    }
    
    return min;
}