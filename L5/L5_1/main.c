/**********************************************************************************************
 *      Si realizzi un programma che legga un array di 7 interi da standard input ed
 *      applichi una funzione con prototipo
 *      void primoultimopari(int arr[], int dim, int* primaocc,int* ultimaocc);
 *      
 *      che ricevuto un array di interi, restituisca la posizione della prima e dell’ ul-
 *      tima occorrenza di un elemento pari nell’array, se esiste almeno un’occorrenza
 *      
 *      di un numero pari, altrimenti -1. Si utilizzi l’aritmetica dei puntatori e si
 *      scorra l’array una sola volta.
 *      Si stampi a video la prima e l’ultima posizione dell’elemento pari trovata.
**********************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#define N 7
#define bool unsigned short int

void primoultimopari(int arr[], int dim, int* primaocc,int* ultimaocc);
void inputArray(int arr[], int dim);

int main(int argc, char *argv[])
{    
    int Arr[N], primaooc, ultimaocc;

    inputArray(Arr, N);

    primoultimopari(Arr, N, &primaooc, &ultimaocc);

    printf("%d %d\n", primaooc, ultimaocc);

    return 0;
}

void inputArray(int arr[], int dim)
{   
    for (int i = 0; i < dim; i++)   scanf("%d", arr+i);
}

bool isEven(int n)  {return !(n%2);}

void primoultimopari(int arr[], int dim, int* primaocc,int* ultimaocc)
{
    int i;
    *(ultimaocc) = *(primaocc) = -1;

    for (i = 0; i < dim && !isEven(arr[i]); ++i);
    if(i == dim) return;

    *(ultimaocc) = *(primaocc) = i;

    for (; i < dim; ++i)
        if(isEven(arr[i]))
            *(ultimaocc) = i;

}
