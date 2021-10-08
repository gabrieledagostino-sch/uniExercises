/*****************************************************************************************
 * 
 * 
 *      TicTacToe `e un gioco dove 2 giocatori devono completare a turni una griglia
 *      di 3 × 3 con x e o. Uno dei due giocatori ( x o o) vince se riesce a mettere 3
 *      segni in linea (verticale, orizzontale o diagonale). Se nessuno vince, il gioco
 *      `e finito in pareggio. Scrivere un programma che legge da standard input una
 *      matrice 3 × 3 contenente ’x’, ’o’ e ’-’ (se non c’`e nessun segno) e stampa il
 *      vincitore tra x e o, o ’pareggio’ se nessuno ha vinto.
 *      Usare aritmetica dei puntatori per gestire la matrice.
 * 
 * 
*****************************************************************************************/
#include <stdlib.h>
#include <stdio.h>
#define N 3
#define M N
//#define DEBUG

void inpMat(char *mat, int n, int m);
void outputMat(char *mat, int n, int m);
int vincitore(char *mat);
unsigned short equals(char a, char b, char c);


int main(int argc, char *argv[])
{
    char Mat[N][M];
    inpMat((char *)Mat, N, M);
    
    #ifdef DEBUG
        outputMat((char *)Mat, N, M);
    #endif
    int winner = vincitore((char*)Mat);
    printf("%s\n", winner==1?"Vince o":winner==2?"Pareggio":"Vince x");

    return 0;
}

void inpMat(char *mat, int n, int m)
{
    for (int i = 0; i < n*m; i++)
        while (scanf("%[xo-]", mat+i)!=1)
            scanf("%*[^xo-]");
        
}

void outputMat(char *mat, int n, int m){
    for (int i = 0; i < n*m; i++)
    {
        printf("%c", mat[i]);
    }
}

int vincitore(char *mat)
{
    //righe
    for (int i = 0; i < 9; i+=3) if(equals(mat[i],mat[i+1],mat[i+2])) return mat[i] == 'o';
    //colonne
    for (int i = 0; i < 3; i++) if(equals(mat[i],mat[i+3],mat[i+6])) return mat[i] == 'o';
    //diagonali
    if(equals(mat[0],mat[4],mat[8])) return mat[4] == 'o';
    if(equals(mat[2],mat[4],mat[6])) return mat[4] == 'o';
    
    return 2;
}

unsigned short equals(char a, char b, char c)
{
    return a==b && b == c;
}