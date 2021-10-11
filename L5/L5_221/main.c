/********************************************************************************************
 * 
 * Scrivere un programma che acquisisca da tastiera due successioni ordinate
 * di interi positivi, entrambe terminate da un numero negativo (che non va
 * 
 * inserito in lista), e le inserisca in due liste distinte. Le liste possono con-
 * tenere duplicati. Scrivere una funzione che, prese in input le due liste, crei
 * 
 * una terza lista di numeri interi ordinata, ottenuta mediante la “fusione” delle
 * prime due. Si stampi il contenuto della lista ottenuta.
 * 
********************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct Element{
    struct Element* next;
    unsigned     int val;
} Node;

typedef Node* List;

void printList (const List  l                  );
void insertOrd (      List *l, unsigned int val);
void fusion    (const List l1, const List l2, List * result);

int main()
{
    int n = 0;
    List l = NULL;
    
    while(1){
        scanf("%d", &n);

        if (n < 0) break;

        insertOrd(&l, n);
    }

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


void fusion    (const List l1, const List l2, List * result)
{
    List a = l1,b = l2;
    while(a != NULL || b != NULL)
    {
        Node* newEl = malloc(sizeof(Node));
        newEl->next = *result;
        *result = newEl;
        int val = 0;
        if(b==NULL || a->val < b->val)
        {
            val = a->val;
            a = a->next;
        }else{
            val = b->val;
            b = b->next;
        }
    }
    ;
}