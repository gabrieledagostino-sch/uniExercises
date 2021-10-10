/****************************************************************************************************
 * 
 *      Scrivere un programma che acquisisca da tastiera due successioni di interi
 *      positivi, entrambe terminate da un numero negativo, e le inserisca in due
 *      Nodee distinte. Scegliere se realizzare una procedura o una funzione che, prese
 *      in input le due Nodee, crei una terza Nodea contenente l’intersezione ordinata
 *      tra le due precedenti: non vi devono quindi essere elementi ripetuti e i valori
 *      devono essere memorizzati in ordine crescente. Si stampi il contenuto della
 *      Nodea intersezione.
 *      Nota: potete organizzare le due Nodee in input come meglio ritenete necessario.
 * 
****************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>

typedef struct Element
{

    struct Element *next;              //pointer to next
    int              val;              //element itself

} Node;

typedef Node* List;

int    ordInsert (      List *l,       int val);
List*  ordInters (const List l1, const List l2);
void   printList (const List  l               );

int main(int argc, char* argv[])
{   
    int n;
    List l1, l2;
    l1 = l2 = NULL;

    while (1)
    {
        scanf("%d", &n);
        
        if(n<0)             break;

        ordInsert(&l1, n);
    }
    while (1)
    {
        scanf("%d", &n);
        
        if(n<0)             break;

        ordInsert(&l2, n);
    }

    List* li = ordInters(l1, l2);
    printList(*li);
    if(*li == NULL) printf("\n");

    return 0;
}


int    ordInsert (      List *l,       int val)
{
    
    if(*l == NULL || (*l)->val > val)                     //lista vuota
    {
        List newEl = malloc(sizeof(Node));
        newEl->val = val;
        newEl->next = *l;
        *l = newEl;
        return 0;
    }

    //in generale se N < v allora controllo se N->next < v
    //se N->next > v allora lo inserisco fra N e N->next
    //altrimenti N = N->next
    List N = *l;
    while(N->next != NULL && N->next->val < val)
    {
        N=N->next;
    }

    List newEl = malloc(sizeof(Node));
    newEl -> val = val;
    newEl -> next = N->next;
    N->next = newEl;
    return 0;
}


void   printList (const List  l               )
{
    List list = (List) l;
    while (list != NULL)   
    {
        printf("%d\n", list->val);
        list = list->next;
    }
}

List*  ordInters (const List l1, const List l2)
{
    List *instersection = malloc(sizeof(List));
    (*instersection) = NULL;
    List a = l1, b = l2;

    int prev = -1;

    while(a != NULL && b != NULL)
    {
        int av = a->val;
        int bv = b->val;
        
        int nv = prev;
        
        if(av < bv)
        {
            a = a->next;
        }
        else if(av > bv)
        {
            b = b->next;
        }else{
            nv = av;
            a = a->next;
            b = b->next;
        }

        if(nv!=prev)
        {
            ordInsert(instersection, nv);
            prev = nv;
        }
    }

    return instersection;
}