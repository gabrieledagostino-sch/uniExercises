/******************************************************************************************************* *
 * 
 *      Scrivere un programma che utilizzi la funzione qsort e ordini un vettore di
 *      interi (in input), in modo da ottenere il seguente effetto. L’array ordinato
 *      deve contenere prima tutti i numeri pari e, a seguire, i numeri dispari. Si
 *      assuma che il numero 0 sia pari. I numeri pari devono essere ordinati in
 *      modo crescente fra di loro. I numeri dispari devono essere ordinati in modo
 *      decrescente fra di loro.
 *      La prima riga dell’input contiene la dimensione N (non limitata) dell’array.
 *      Le righe successive contengono gli elementi dell’array, uno per riga.
 *      L’output contiene gli elementi dell’array ordinati come richiesto, uno per
 * 
 * ******************************************************************************************************/ 
#include <stdlib.h>
#include <stdio.h>

#define N 10000


int compare(const void*a, const void *b);


int main()
{   
    int arr[N];
    int n;

    scanf("%d", &n);
    for (size_t i = 0; i < n; i++)
    {
        scanf("%d", arr+i);
    }

    qsort(arr, n, sizeof(int), &compare);    

    for (size_t i = 0; i < n; i++)
    {
        printf("%d\n", arr[i]);
    }
    

    return 0;
}


int compare(const void*a, const void *b)
{
    int nA = *(int*)a;
    int nB = *(int*)b;

    int pA, pB;
    pA = nA%2;
    pB = nB%2;

    if(pA && pB)
        return nB-nA;
    else if(pA && !pB)
        return 1;
    else if(!pA && pB)
        return -1;
    else
        return nA-nB;
}
