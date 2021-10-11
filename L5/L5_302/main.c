/**************************************************************************************************
 *      Si vuole gestire un elenco anonimo degli studenti che si immatricolano al
 *      corso di laurea in informatica. Per ogni studenti, in questo elenco per motivi
 *      di privacy, si vuole mantenere solo il numero di matricola che sar`a un numero
 *      intero maggiore di 0.
 *      
 *      Realizzare un programma che tramite una funzione add end legga degli in-
 *      teri da tastiera. Ogni intero letto (se positivo) deve essere memorizzato nella
 *      
 *      struttura dati (chiamata ANONIMI) creata per mantenere l’elenco anonimo.
 *      La funzione termina la sua esecuzione quando l’utente inserisce il valore 0
 *      (va inserito nell’elenco?). Sono ammessi duplicati.
 *      Il main dovr`a chiamare la funzione ricorsiva RecLength al fine di calcolare
 *      il numero di matricole nell’elenco e ne visualizzi il risultato.
 *      Quindi, il main deve chiamare la funzione ricorsiva RecStampaInversa
 *      che stampi gli elementi dell’elenco partendo dall’ultimo.
 *      
 *      Il main adesso deve prendere da tastiera un intero n e chiami una fun-
 *      zione che cancella tutti gli elementi dall’elenco il cui numero di matricola `e
 *      
 *      multiplo di n.
 *      Il main dovr`a quindi chiamare una funzione ricorsiva RecStampa che
 *      stampi gli elementi dell’elenco nel formato mostrato nell’esempio.
 *      
 *      Infine, il main usando una o pi`u funzioni deve individuare la prima ma-
 *      tricola dispari (se esiste altrimenti -1) e la prima matricola pari (se esiste
 *      
 *      altrimenti -1) degli elementi dell’elenco.
 *      
 *      Le funzioni non devono necessariamente scorrere tutto l’elenco ma si de-
 *      vono fermare appena possibile. Le funzioni non devono stampare nulla ma
 *      
 *      passare al main i valori trovati. Nel main poi si stampino i valori ottenuti,
 *      prima il dispari e poi il pari separati da un’interlinea. E possibile scrivere `
 *      una funzione che trovi entrambi i valori?
**************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>

#define SN 101

typedef struct Anonimi
{
    unsigned int val;
} Anonimi;

typedef struct Node
{
    struct Anonimi Element;
    struct Node*      next;
} Node;

typedef struct Node* List;

size_t recLength      (const List l);
void recStampaInversa (const List l);
void recStampa        (const List l);
void pariDispari      (const List l, int *pari, int *dispari);
void deleteMul        (List *l, unsigned int n);
void add_end (List* l, unsigned int val);
void getLine(char *s, size_t l);


int main()
{
    List l = NULL;
    int n;
    char s[SN] = "";

    while(1)
    {
        getLine(s, SN-1);
        n = atoi(s);
        if(s[0] == '0') break;

        if(n>0) add_end(&l, n);
        else printf("Inserisci intero positivo o 0 per uscire\n");
    }

    printf("Stampa l'elenco in ordine inverso di immissione (NULL se vuota):\n");
    recStampaInversa(l);
    
    
    printf("Inserisci il numero richiesto:\n");
    scanf("%d", &n);
    deleteMul(&l, n);
    
    printf("Stampa l'elenco in ordine di immissione (NULL se vuota):\n");
    recStampa(l);
    
    
    int pari = -1;
    int dispari = -1;
    pariDispari(l, &pari, &dispari);

    printf("Dispari:%d\nPari:%d\n", dispari==-1?-1:dispari+1, pari==-1?-1:pari+1);

    return 0;
}

size_t recLength      (const List l)
{
    if(l == NULL) return 0;

    return 1 + recLength(l->next);
}
void stampInvers(const List l)
{
    if(l!=NULL)
    {
        stampInvers(l->next);
        printf("%d->", l->Element.val);
    }

}
void recStampaInversa (const List l)
{
    stampInvers(l);
    printf("NULL \n");
}

void recStampa        (const List l)
{
    if(l!=NULL)
    {
        printf("%d->", l->Element.val);
        recStampa(l->next);
    }else{
        printf("NULL \n");
    }
}
void pariDispari      (const List l, int *pari, int *dispari)
{
    if(l == NULL)   return;

    if(l->Element.val % 2){ if(*dispari == -1) *dispari = l->Element.val; }
    else {if(*pari == -1) *pari = l->Element.val; }

   pariDispari(l->next, pari, dispari);

}



void add_end (List* l, unsigned int val)
{
    if(*l == NULL)
    {
        List newEl = malloc(sizeof(Node));
        newEl->next = NULL;
        newEl->Element.val = val;
        *l = newEl;
        return;
    }
    add_end(&(*l)->next , val);
}

void deleteMul(List *l , unsigned int n)
{
    if(*l == NULL)   return;
    
    if((*l)->Element.val % n == 0)
    {
        (*l) = (*l)->next;
        deleteMul(l, n);
        return;
    }
    deleteMul(&(*l)->next, n);
}

void getLine(char *s, size_t l)
{
    char x;
    size_t i;
    for(i = 0; i<l && (x = getchar())!='\n'; i++)
        s[i] = x;
    s[i] = '\0';
}