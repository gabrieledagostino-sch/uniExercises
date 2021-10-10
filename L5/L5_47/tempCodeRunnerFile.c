/***********************************************************************************************
 * 
 *      Scrivere un programma che acquisisca da tastiera una successione di numeri
 *      interi positivi e li inserisca in ordine di arrivo ad una lista.
 *      La lista puo’ contenere duplicati, e l’acquisizione da tastiera termina quando
 *      si incontra il primo valore negativo (che non va inserito in lista).
 *      Si stampi: usando la funzione CalcoloSomma la somma dei valori contenuti
 *      negli elementi della lista e usando la funzione CalcoloNElementi il numero
 *      degli elementi nella lista che contengono un valore strettamente maggiore di
 *      un quarto della somma ottenuta dalla funzione CalcoloSomma.
 * 
 * ********************************************************************************************/
#include <stdio.h>
#include <stdlib.h>

typedef struct Element{
    struct Element* next;
    unsigned int val;
}Node;

typedef Node* List;


int ls_pushHead     (List       * l, int val);
int CalcoloSomma    (const List   l, int min);
int CalcoloNElemnti (const List   l, int min);

int main()
{
    List l = NULL;
    int n = -1;

    while(1)
    {
        scanf("%d", &n);
        if(n<0) break;

        ls_pushHead(&l, n);
    }
    int s = CalcoloSomma(l, 0);
    int m = CalcoloNElemnti(l, s/4);
    
    printf("%d\n", s);
    printf("%d\n", m);

    return 0;
}

int ls_pushHead     (List       * l, int val)
{
    List newEl = malloc(sizeof(Node));
    newEl -> next = (*l);
    newEl -> val  = val ;
    (*l)  = newEl;
    return 0;
}

int CalcoloSomma    (const List   l, int min)
{   
    if(l == NULL) return 0;
    int v = l->val > min? l->val : 0;
    return v+CalcoloSomma(l->next, min);
}
int CalcoloNElemnti (const List   l, int min)
{   
    if(l == NULL) return 0;
    return (l->val > min) + CalcoloNElemnti(l->next, min);
}