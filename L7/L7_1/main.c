/*********************************************************** *
 * 
 *  Scrivere un programma che legge da tastiera 3 sequenze di caratteri, una per
 *  riga, e determina, attraverso una funzione ricorsiva, se siano o no palindrome.
 *  Ogni sequenza ha il carattere ’*’ nel centro (vedi esercizio lezione 10).
 * 
 * *********************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 1024

unsigned short int isPalindroma(char* s, size_t len);

int main()
{
    char s[1024];

    for(size_t i = 0; i < 3; i++)
    {
        scanf("%s", s);
        unsigned short int x = isPalindroma(s, strlen(s));
        if(x) printf("palindrome\n");
        else  printf("non palindrome\n");
    }

    return 0;
}

unsigned short int isPalindroma(char *s, size_t len)
{
    if(len <= 1) return 1;
    
    return s[0] == s[len-1] && isPalindroma(s+1, len-2);
}