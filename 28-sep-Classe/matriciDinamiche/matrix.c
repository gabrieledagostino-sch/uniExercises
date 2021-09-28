#include <stdio.h>
#include <stdlib.h>

int ** leggiMatrice(int *n, int *m);

int main(){

    int n1,m1, n2, m2;
    int **m1 = leggiMatrice(&n1,&m1);
    int **m2 = leggiMatrice(&n2,&m2);



    return 0;
}

int ** leggiMatrice(int *n, int *m){

    scanf("%d %d", n, m);

    int ** mat;

    mat = (int**)calloc(*n, sizeof(int*));
    if (mat == NULL) exit(1);
    for (int i = 0; i < *n; i++)
    {
        mat[i] = (int *)calloc(*m, sizeof(int));
        if (mat[i] == NULL) exit(1);
        for (int j = 0; j < *m; j++)
        {
            scanf("%d", mat[i] + j);
        }
    }

    return mat;
}