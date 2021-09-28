/******************************************************************************************
 * 
 *      Dobbiamo piastrellare una sentiero largo 1m con delle piastrelle che esistono
 *      in 2 dimensioni: 1 × 1 m o 1 × 2 m. Quelle da 1 × 1 possono essere bianche
 *      o blu, quelle da 1 × 2 possono essere gialle, verdi o nere. Se il sentiero
 *      lungo n metri, in quanti modi diversi puo essere piastrellato? Scrivere una
 *      funzione conta possibilita(n)che calcoli il numero di possibilita’, data la
 *      lunghezza n. Scrivere un programma che legga da tastiera n, e stampi il
 *      numero di possibilita’.
 *      Suggerimento: trovare una relazione ricorsiva per calcolare il numero di
 *      possibilita’, poi implementare la funzione in modo ricorsivo (preferibilmente
 *      in coda).
 * 
******************************************************************************************/
#include <stdio.h>

long int conta_possibilita (long int len);

int main()
{
    long int n;
    printf("%lu", sizeof(long));
    while (scanf("%ld", &n) != 1 || n < 0)
    {
        printf("Errore. Inserisci un intero positivo.\n");
        scanf("%*[^\n]\n");
    }

    printf("%ld\n", conta_possibilita(n));
    return 0;
}

long int conta_possibilita (long int len)
{
    if(len == 0) return 0;
    if(len == 1) return 2;
    if(len == 2) return 7;

    return 2*conta_possibilita(len-1) + 3*conta_possibilita(len-2);
}
