/*********************************************************************************************************************** *
 * 
 *      Scrivere un programma che legge da standard input un numero di righe r e un numero di colonne c, 
 *      e poi gli elementi di una matrice rXc. 
 *      Il programma deve ordinare le righe de la matrice in ordine crescente in base agli elementi sulla prima colonna. 
 *      Se gli elementi sono uguali, si ordina in base alla seconda colonna, poi terza colonna, etc.
 *      Il programma stampa la matrice con le righe ordinate (vedi test case per esempi).
 * 
 * **********************************************************************************************************************/
#include <stdlib.h>
#include <stdio.h>


size_t n,m;
void inpMatrix(int **mat, size_t n, size_t m);
void outMatrix(int **mat, size_t n, size_t m);
int compare(const void *a, const void *b);


int main()
{
    int** matrix;


    scanf("%lu", &n);
    scanf("%lu", &m);

    matrix = (int**) malloc(n * sizeof(int*));
    for (size_t i = 0; i < n; i++)
        matrix[i] = (int *)malloc(m* sizeof(int));

    inpMatrix(matrix, n, m);

    qsort(matrix, n, sizeof(int*), &compare);

    outMatrix(matrix, n, m);

    return 0;
}


void inpMatrix(int **mat, size_t n, size_t m)
{

    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < m; j++)
            scanf("%d", mat[i] + j);
    

}
void outMatrix(int **mat, size_t n, size_t m)
{

    for (size_t i = 0; i < n; i++){
        for (size_t j = 0; j < m; j++)
            printf("%d ", mat[i][j]);
        printf("\n");
    }
    printf("\n");
}

int compare(const void *a, const void *b)
{
    int* arrA = *(int**)a;
    int* arrB = *(int**)b;
    

    size_t i;
    for (i = 0; i < m-1 && arrA[i] == arrB[i]; i++);

    return arrA[i] - arrB[i];
}