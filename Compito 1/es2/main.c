/*************************************************************************
 * 
 * Scrivere un programma che legge da standard input una parola codificata utilizando il codice di Cesare con lunghezza 8, e la decodifica. 
 * Si ricorda che il codice di Cesare di lunghezza codifica un carattere  con il carattere che si trova a  
 * posizioni dopo di  nel alfabeto, in modo circolare (a,b,c,...,x,y,z,a,b,c,..). 
 * Quindi per  la lettera 'a' diventa 'i' e la lettera 'z' diventa 'h'. Tutte le lettere maiuscole vanno trasformate in minuscole prima di essere decodificate. 
 * Il programma  contenere una funzione  che prende la parola codificata e restituisce un altra stringa con la parola originale. La funzione  chiama la funzione  
 * e ne stampa il risultato. Si può considerare che tutte le parole inserite in input contengono solo caratteri alfabetici, 
 * e che le parole non possono contenere più di 15 caratteri.
 * 
 * **********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SL 16

char* decode(char* s, int l, size_t len);
int charDecoder(int x, int size);

int main(int argc, char** argv)
{
    char s[SL];
    scanf("%s", s);
    char *decoded = decode(s, 8, strlen(s));
    printf("%s\n", decoded);
    return 0;
}

char* decode(char* s, int l, size_t len)
{
    char *d = malloc(len+1);

    for (size_t i = 0; i < len; i++)
    {
        d[i] = charDecoder(s[i], l);
    }
    d[len] = '\0';
    return d;
}

int charDecoder(int x, int size)
{
    if(isalpha(x))
    {
        if(isupper(x)) x = tolower(x);
        x -= size;
        if(x < 'a')
            x += 'z'-'a'+1;
    }
    return x;
}
