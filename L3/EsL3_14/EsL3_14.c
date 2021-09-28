 /******************************************************************************************
  * 
 *      Si realizzi un programma C che implementi e usi due funzioni ricorsive per
 *      stampare le cifre di un numero intero positivo (puo’ essere 0) prima in ordine
 *      inverso poi in ordine normale, sempre divise da un’interlinea. Le funzioni
 *      stampa cifre e stampa cifre inverso prendono come parametro il numero
 *      da processare. Il programma deve leggere da tastiera un numero intero (con
 *      controllo dell’input) e passarlo alle due funzioni.
 *
 ******************************************************************************************/
#include <stdio.h>

int printDigits(int n);
int revPrintDigits(int n);

int main()
{
    int n;

    while (scanf("%d", &n) != 1 || n < 0)
    {
        printf("Errore. Inserisci un intero positivo.\n");
        scanf("%*[^\n]\n");
    }

    revPrintDigits(n);
    printDigits(n);

    return 0;
}

int printDigits(int n)
{
    if(n/10 > 0)
        printDigits(n/10);
    printf("%d\n", n%10);

    return 0;
}
int revPrintDigits(int n)
{
    printf("%d\n", n%10);
    if(n/10 > 0)
        revPrintDigits(n/10);

    return 0;
}
