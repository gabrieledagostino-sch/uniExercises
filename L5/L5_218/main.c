/*****************************************************************************************************************
 * 
 * Scrivere un programma che acquisisca da tastiera una successione di numeri
 * interi positivi e li inserisca in ordine di arrivo in una lista.
 * Il programma legge anche dall’input un valore intero n.
 * Si scriva una procedura/funzione che preso una lista e un intero n inserisca
 * l’intero dopo il quarto elemento della lista.
 * Se gli elementi della lista sono meno di 4 si inserisca l’elemento in coda. Nel
 * main poi si stampi la lista cosi’ ottenuta.
 * 
*****************************************************************************************************************/
#include <stdlib.h>
#include <stdio.h>

#define I 4

typedef struct Element{
    struct Element* next;
    unsigned int     val;
} Node;

typedef Node* List;


int push_back   (      List *l, int val);
int insert      (      List *l, int val, int idx);
void printList  (const List  l         );


int main(int argc, char** argv)
{
    List l = NULL;
    int n = 0;

    while(1)
    {
        scanf("%d", &n);

        if (n < 0) break;
        push_back(&l, n);
    }
    scanf("%d", &n);
    insert(&l, n, I);
    printList(l);
}

int push_back   (      List *l, int val)
{
    if((*l) == NULL)
    {
        List newEl = malloc(sizeof(Node));
        newEl->next = NULL;
        (*l) = newEl;
        newEl->val = val;
        return 0;
    }
    return push_back(&((*l)->next), val);
}
int insert      (      List *l, int val, int idx)
{
    if((*l) == NULL || idx == 0)
    {
        List newEl = malloc(sizeof(Node));
        newEl -> next = (*l) == NULL? NULL : (*l);
        (*l) = newEl;
        newEl ->val = val;
        return 0;
    }
    return insert(&(*l)->next, val, idx-1);
}
void printList  (const List  l         )
{
    if(l == NULL) 
    {
        printf("NULL\n");
        return ;
    }
    printf("%u -> ",l->val);
    printList(l->next);
}
