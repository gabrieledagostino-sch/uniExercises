#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10000

/*****************************************************************************************************************
 * 
 * Scrivere un programma che legge da standard input un numero intero n, e poi una sequenza di n interi. 
 * Il programma deve stampare solo i numeri positivi in ordine inverso rispetto a quello di lettura. 
 * I numeri vanno stampati separati da uno spazio, e seguiti da un '\n'.
 * 
*********************************************************************************************************************/

int main(int argc, char** argv)
{
    int arr[N];
    int n;

    scanf("%d", &n);
    for (size_t i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }
    
    for (int i = n-1; i >= 0; i--)
    {
        if(arr[i]>0) printf("%d ", arr[i]);
    }
    printf("\n");
    

    return 0;
}
