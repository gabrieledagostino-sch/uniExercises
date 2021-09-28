 /***********************************************************************************************
 * 
 *      Realizzare una funzione ricorsiva che controlli che una sequenza di numeri
 *      interi positivi data in input sia ordinata in ordine strettamente crescente. La
 *      sequenza pu`o contenere duplicati, e l’acquisizione da tastiera (con controllo
 *      dell’input) termina quando si incontra il primo valore negativo (che non va
 *      considerato parte della sequenza). Si stampi in base al risultato della funzione
 *      descritta sopra se la sequenza `e in ordine strettamente crescente o no.
 * 
 ***********************************************************************************************/
#include <stdio.h>
#define bool unsigned short int
#define true 1
#define false 0

bool inp(int pred);

int main(){
    bool x = inp(-1);

    if(x)
    {
        printf("Sequenza in ordine strettamente crescente\n");
    }else{
        printf("Sequenza non in ordine strettamente crescente\n");
    }

    return 0;
}

bool inp(int pred){

    int n;
    while (scanf("%d", &n) != 1)
    {
        printf("Errore. Inserire un numero intero positivo oppure un numero intero negativo per terminare\n");
        scanf("%*[^\n]\n");
    }

    if(n < 0) return true;
    return inp(n) && (pred < n);

}

