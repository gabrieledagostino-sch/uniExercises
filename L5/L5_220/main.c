/***********************************************************************************************
 * 
 * Scrivere una funzione InserOrd che presa una lista ordinata in maniera non
 * decrescente inserisca un elemento nella giusta posizione rispetto all’ordinamento.
 * 
 * Si scriva poi un programma che acquisisca da tastiera una sequenza di nu-
 * meri postivi che possono contenere duplicati e li inserisca, usando InserOrd,
 * 
 * in una lista (ordinata in maniera non decrescente).
 * Nel main si stampi la lista ottenuta.
 * N.B. Non devono essere usate altre liste o array di appoggio.
 * 
***********************************************************************************************/
#include <stdio.h>
#include <stdlib.h>

typedef struct Element{
    struct Element* next;
    unsigned     int val;
} Node;

typedef Node* List;

void printList (const List  l                  );
void insertOrd (      List *l, unsigned int val);

int main()
{
    int n = 0;
    List l = NULL;
    
    while(1){
        scanf("%d", &n);

        if (n < 0) break;

        insertOrd(&l, n);
    }

    printList(l);

    return 0;
}

void printList (const List  l                  )
{
    if(l == NULL)
    {
        printf("NULL \n");
        return;
    }
    printf("%d -> ", l->val);
    printList(l->next);

}

void insertOrd (      List *l, unsigned int val)
{
    
    if((*l) == NULL || (*l)->val > val)
    {
        Node* newEl = malloc(sizeof(Node));
        newEl->next = *l;
        *l = newEl;
        (*l)->val = val;
        return;
    }
    insertOrd(&(*l)->next, val);

}
