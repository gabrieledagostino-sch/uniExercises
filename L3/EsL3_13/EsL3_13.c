 /**********************************************************************************
 *  Esercizio
 *  Scrivere una funzione ricorsiva Pot2 che dato un numero n intero positivo
 *  calcoli e restituisca il numero F(n) definito dalle seguente relazione:
 *  F(1) = 2
 *  F(n) = 2F(n − 1) se n ≥ 2
 *  Scrivere poi un programma che acquisisca da tastiera un numero intero
 *  positivo n (con controllo dell’input) e stampi F(n) calcolato con la funzione
 *  Pot2.
 **********************************************************************************/
#include <stdio.h>

int Pot2(int n);

int main()
{
    int n;

    while (scanf("%d", &n) != 1 || n <= 0)
    {
        scanf("%*[^\n]\n");
        printf("Errore. Inserisci un numero intero positivo\n");
    }
    
    int pot2 = Pot2(n);

    printf("%d\n", pot2);

}

int Pot2(int n)
{
    if(n == 1)
        return 2;
    return 2 * Pot2(n-1);
}