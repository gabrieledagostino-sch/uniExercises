//Scrivere un programma che legge dalla linea di comando una serie di punti nello spazio  cartesiano in due dimensioni, 
//rappresentati da due coordinate, x e y, e seleziona i punti che sono a distanza Euclidea di al massimo 100 dal ultimo punto letto. 
//Il programma deve stampare il centroide dei punti selezionati (la media delle coordinate x e y). 
//I punti sono inseriti 1 per riga, con le coordinate separate da ','. La prima riga dell'input contiene il numero di punti da leggere.
#include <stdio.h>
#include <math.h>
#define N 500

typedef struct
{
    float x;
    float y;
} Point;

int main()
{
    int size;
    Point A[N];
    Point compare;

    scanf("%d", &size);
    --size;

    for(int i = 0; i < size; i++)
    {
        scanf("%f,%f", &(A[i].x), &(A[i].y));
    }
    if(size == 0)
    {
        printf("output: %f,%f", 0.0,0.0);
    }  
    scanf("%f,%f", &compare.x, &compare.y);
        
    int delta = 1;
    Point center = {compare.x, compare.y};

    for(int i = 0; i < size; i++)
    {
        float squareDist = pow(compare.x - A[i].x, 2) + pow(compare.y - A[i].y, 2);
        if(squareDist <= 10000)
        {
            center.x += A[i].x;
            center.y += A[i].y;
            delta++;
        }
    }

    if(delta != 0){
        center.x /= delta;
        center.y /= delta;
    }

    printf("output : %f,%f\n", center.x, center.y);

    return 0;
}