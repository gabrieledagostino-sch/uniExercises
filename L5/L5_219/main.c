/****************************************************************************************************
 * 
 *      Scrivere un programma che acquisisca da tastiera due numeri N e M (con
 *      N < M) e una successione di numeri interi positivi e li inserisca all’interno
 *      di una lista. La lista non pu`o contenere duplicati. L’acquisizione da tastiera
 *      termina quando si incontra il primo valore negativo (che non va inserito in
 *      lista).
 *      Dopo aver memorizzato la sequenza in una lista ordinata, utilizzare una
 *      funzione per calcolare il prodotto degli elementi della lista compresi tra N
 *      e M. In particolare, si scriva una funzione che riceve come parametro la
 *      testa della lista e i due interi N e M e che restituisce il prodotto dei soli
 *      valori della lista compresi tra N e M. Se la lista `e vuota, la funzione deve
 *      restituire il valore –1. Ad esempio passando come parametro la testa della
 *      lista 1 → 2 → 3 → 4 → 5 → 7 → 8 → 9 → NULL e i valori N = 3, M = 7,
 *      la funzione deve restituire 20, dato che 4*5=20.
 * 
****************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>


typedef struct Element{
    struct Element* next;
    unsigned int     val;
} Node;

typedef Node* List;


int push_front (List *l, int val);
int multiplyNM (const List l, int n, int m);
int contaNElement (const List l, int n, int m);


int main(int argc, char ** argv)
{
    List l = NULL;
    int n,m;
    int N,M;

    m = -1;

    scanf("%d", &N);
    scanf("%d", &M);

    while(1)
    {
        scanf("%d", &n);
        if(n < 0) break;

        if(n != m)  push_front(&l, n);
    }

    int p = -1;
    if(l != NULL) p = multiplyNM(l, N, M);
    printf("%d\n", p);
    return 0;
}


int push_front (List *l, int val)
{
    List newEl = malloc(sizeof(Node));
    newEl -> next = (*l);
    (*l) = newEl;
    newEl->val = val;
    return 0;
}
int contaNElement (const List l, int n, int m)
{
    if(l == NULL) return 0;
    unsigned short int c = l->val > n && l->val < m;
    return c + contaNElement(l->next, n, m);
}
int multiplyNM (const List l, int n, int m)
{
    if(l == NULL) return 1;
    int v = l->val > n && l->val < m? l->val : 1;
    return v*multiplyNM(l->next, n, m);
}