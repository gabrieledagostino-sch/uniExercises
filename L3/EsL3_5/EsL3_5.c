/****************************************************************************************
 *      Scrivere un programma che legga da tastiera 10 interi, li scriva in un array
 *      A, e lo passi ad una funzione verifica condizione. La funzione restituisce
 *      l’indice i del primo elemento che verifica la seguente condizione:
 *      
 *      A[i] = A[i + 1] − A[i − 1]
 *      
 *      oppure -1 nel caso in cui nessun elemento verifichi la suddetta condizione. Il
 *      risultato della funzione viene stampato nella main.
****************************************************************************************/
#include <stdio.h>
#define N 10

int verifica_condizione(int *A, int l);

int main()
{
    int A[N];

    for (int i = 0; i < N; i++)    scanf("%d", A+i);

    int res = verifica_condizione(A, N);
    printf("%d\n", res);
    
    return 0;
}

int verifica_condizione(int *A, int l)
{   
    for (int i = 1; i < l-1; i++)
        if(A[i] == (A[i+1] - A[i-1]))
            return i;
    return -1;
}
