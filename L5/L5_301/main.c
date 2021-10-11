/**************************************************************************************************************
 * 
 * Data la definizione di tipo
 * typedef enum{false,true} boolean;
 * partendo dalla definizione di lista data a lezione, realizzare una funzione
 * 
 * ricorsiva che controlla che la lista data in input sia ordinata in ordine stret-
 * tamente crescente. Scrivere poi un programma che acquisisca da tastiera
 * 
 * una successione di numeri interi positivi e li inserisca in una lista mante-
 * nendo l’ordine di lettura. La lista pu`o contenere duplicati, e l’acquisizione
 * 
 * da tastiera termina quando si incontra il primo valore negativo (che non va
 * inserito in lista). Si stampi il risultato della funzione descritta sopra.
 * 
**************************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>

typedef enum{false, true} boolean;

typedef struct Element{
    
    struct Element* next;
    unsigned int     val;
    
} Node;

typedef Node* List;


boolean isOrdered (const List  l);
void    push_back (      List *l, unsigned int val);

int main(int argc, char** argv)
{
    List l = NULL;
    int  n;
    
    while (1)
    {
        scanf("%d", &n);

        if(n<0) break;

        push_back(&l, n);
    }

    if(isOrdered(l))
    {
        printf("True\n");
    }else{
        printf("False\n");
    }

    return 0;
}

boolean isOrdered(const List  l)
{
    if(l == NULL) return true;
    if(l->next == NULL) return true;
    
    return (l->val < l->next->val) && isOrdered(l->next);
}

void    push_back (      List *l, unsigned int val)
{
    if((*l) == NULL)
    {
        List newEl = malloc(sizeof(Node));
        newEl->next = NULL;
        newEl->val = val;
        (*l) = newEl;
        return;
    }
    push_back(&(*l)->next, val);
}