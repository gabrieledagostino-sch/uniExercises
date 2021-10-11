/********************************************************************************
 * 
 * Scrivere un programma che acquisisca da tastiera una successione di numeri
 * interi positivi e li inserica in maniera ordinata in ordine non crescente
 * all’interno di una lista. La lista pu`o contenere duplicati. L’acquisizione da
 * 
 * tastiera termina quando si incontra il primo valore negativo (che non va in-
 * serito in lista).
 * 
 * Dopo aver memorizzato la sequenza in una lista, utilizzare una funzione per
 * 
 * inserire nella posizione corretta all’interno della lista, tutti i numeri man-
 * canti.
 * 
 * Stampare in output la lista ottenuta.
 * Non devono essere usate altre liste o array di appoggio.
 * Esempio: supponiamo che sia fornita in input la sequenza 7, 3, 6, 7, 10.
 * Dopo aver memorizzato gli elementi nella lista 10 → 7 → 7 → 6 → 3 →
 * NULL, vengono inseriti i numeri mancanti, ottenendo la lista composta dagli
 * elementi
 * 
 * 10 → 9 → 8 → 7 → 7 → 6 → 5 → 4 → 3 → NULL.
 * 
********************************************************************************/
#include <stdio.h>
#include <stdlib.h>


typedef struct Element{

    struct Element* next;
    unsigned int     val;

}   Node;

typedef Node* List;


void ordInsert(List *l, unsigned int val);
void printList(const List l);
void fillList(List *l, unsigned int prec);


int main()
{
    List l = NULL;
    int n;
    while(1)
    {
        scanf("%d", &n);
        
        if(n<0) break;

        ordInsert(&l, n);
    }

    if(l == NULL){
        printf("NULL\n");
        return 0;
    }
    
    fillList(&l, l->val);
    printList(l);

    return 0;
}

void ordInsert(List *l, unsigned int val)
{
    if((*l) == NULL || (*l)->val < val)
    {
        List newEl = malloc(sizeof(Node));
        newEl->next = *l;
        *l = newEl;
        (*l)->val= val;
        return;
    }
    ordInsert(&(*l)->next, val);
}

void printList(const List l)
{
    if(l != NULL) 
    {
        printf("%d --> ", l->val);
        printList(l->next);
    }else{
        printf("NULL\n");
    }
}

void fillList(List *l,  unsigned int prec)
{
    if(prec == 0 || (*l) == NULL) return;
    if((*l)->val < prec-1)
    {
        List newEl = malloc(sizeof(Node));
        newEl->val = prec-1;
        newEl->next = *l;
        *l = newEl;
    }
    fillList(&(*l)->next, (*l)->val);
}



