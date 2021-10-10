/********************************************************************************************* * 
 * 
 *       Scrivere un programma che utilizzi la funzione qsort per ordinare un array
 *      di stringhe. Le stringhe devono essere ordinate per lunghezza crescente. A
 *      parit`a di lunghezza, si utilizzi l’ordinamento lessicografico. Utilizzare una
 *      struct che memorizzi una stringa e la sua lunghezza per evitare di calcolare
 *      quest’ultima ad ogni confronto.
 *      
 *      La prima riga dell’input contiene la dimensione N dell’array. Le righe suc-
 *      cessive contengono gli elementi dell’array, una stringa per riga. Ogni stringa
 *      
 *      ha lunghezza massima di 100 caratteri.
 *      L’output contiene gli elementi dell’array ordinato come richiesto, una stringa
 *      per riga.
 * 
 * *********************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define N 10000
#define SN 101


struct strLen{
    char*         s;
    size_t      len;
};


int compare(const void* a, const void* b);
void getLine(char *s, size_t l);


int main(int argc, char** argv)
{
    struct strLen Arr[N];
    size_t     n;

    scanf("%lu\n", &n);

    for (size_t i = 0; i < n; i++)
    {
        Arr[i].s = malloc(SN);
        getLine(Arr[i].s, SN);
        Arr[i].len = strlen(Arr[i].s);
    }
    
    qsort(Arr, n, sizeof(struct strLen), &compare);
    
    for (size_t i = 0; i < n; i++)
    {
        printf("%s\n",Arr[i].s);
    }

    return 0;
}

int compare(const void *a, const void *b)
{
    struct strLen *sA = (struct strLen*) a;
    struct strLen *sB = (struct strLen*) b;

    if(sA->len == sB->len)
        return strcmp(sA->s, sB->s);
    
    return sA->len - sB->len;

}

void getLine(char *s, size_t l)
{
    char    x;
    size_t  i;
    for (i = 0; i < l && (x = getchar()) != '\n'; i++)
    {
        s[i] = x;
    }
    
    s[i] = '\0';
}

