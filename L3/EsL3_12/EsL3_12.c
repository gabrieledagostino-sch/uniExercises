/*******************************************************************************************
 * 
 * 
 *       Si realizzi un programma che legga 3 interi da standard input ed applichi          
 *       la funzione a 3 argomenti ordered swap(·,·,·) alle 3 variabili in cui sono         
 *       stati memorizzati i 3 valori. I valori letti devono essere passati alla funzione   
 *       nell’ordine in cui vengono acquisiti da tastiera.                                  
 *       Si implementi la funzione ordered swap, che scambia il contenuto delle 3           
 *       variabili di input in modo che la variabile corrispondente al primo argomento      
 *       contenga l’intero minore, la seconda variabile contenga l’intero mediano e la      
 *       terza contenga l’intero di valore maggiore.                                        
 *       Si stampi a video il contenuto delle 3 variabili all’uscita dall’esecuzione        
 *       della funzione.                                                                    
 * 
 * 
 *******************************************************************************************/
#include <stdio.h>

int ordered_swap(int *a, int *b, int *c);
int swap(int *a, int *b);

int main()
{
    int a,b,c;
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);

    ordered_swap(&a, &b, &c);

    printf("%d\n", a);
    printf("%d\n", b);
    printf("%d\n", c);
    
    return 0;
}

int ordered_swap(int *a, int *b, int *c)
{
    if(*b < *a) swap(a,b);
    if(*c < *a) swap(a,c);
    if(*c < *b) swap(b,c);

    return 0;
}

int swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
    return 0;
}