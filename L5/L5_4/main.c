/*****************************************************************************************
 * 
 * Scrivere un programma che acquisisca da tastiera una successione di numeri
 * interi positivi e li inserisca in maniera ordinata (crescente) all’interno di una
 * lista. La lista puo’ contenere duplicati. L’acquisizione da tastiera termina
 * quando si incontra il primo valore negativo (che non va inserito in lista) e
 * viene stampato il contenuto corrente della lista.
 * 
*****************************************************************************************/
#include <stdio.h>
#include "list.h"

int main()
{
    int n;
    List l = newList();

    while (1)
    {
        scanf("%d", &n);
        if(n < 0) break;
        orderedInsert(&l, n);
    }

    printList(l);

    return 0;
}
