/**************************************************************************************
 *  Si implementi una lista concatenata che contenga, come dati, interi positivi.
 *  Si scelga se implementare procedure o funzioni che realizzino i seguenti punti:
 *  • Aggiungere un elemento in fondo alla lista;
 *  • Aggiungere un elemento in cima alla lista;
 *  • Dato un valore positivo v, eliminare la prima occorrenza di v nella lista
 *  (non modificare la lista nel caso che non contenga v);
 *  Quindi, scrivere un programma che legga degli interi. Per ogni intero letto
 *  (e nello stesso ordine dell’input), si applichi una delle seguenti modifiche:
 *  • Se il valore letto v `e strettamente negativo, rimuovere il primo elemento
 *  uguale a |v| dalla lista (non modificare la lista nel caso che questa non
 *  contenga |v|);
 *  • Se il valore letto v `e positivo e pari, aggiungerlo in cima alla lista;
 *  • Se il valore letto v `e positivo e dispari, aggiungerlo in fondo alla lista;
 *  • Se il valore letto `e 0, terminare l’esecuzione del programma stampando,
 *  in ordine, gli elementi della lista.
**************************************************************************************/

#include "list.h"
#include <stdio.h>

int main()
{
    List l = newList();
    int n;

    while(1)
    {
        scanf("%d", &n);
        if(n == 0) break;
        if(n < 0)
        {
            removeOccorrence(&l, -n);
        }
        else if(n%2)
        {
            push_back(&l, n);
        }else{
            push_top(&l, n);
        }
    }
    printNodes(l);

    return 0;
}