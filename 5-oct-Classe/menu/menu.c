//word count interattivo
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 100
#define OPT 5

int inserisci       (char * s);
int contaParole     (char * s);
int contaRighe      (char * s);
int contaCaratteri  (char * s);
int esci            (char * s);
int StampaMenu      (char * s);

int main()
{
    char s[N] = "";
    int opt;

    int (*menu[OPT])(char *) = {inserisci, contaParole, contaRighe, contaCaratteri, esci};

    while(1)
    {
        StampaMenu(s);
        
        fflush(stdin);
        scanf("%d", &opt);
        fflush(stdin);

        (*menu[opt])(s);

    }

    return 0;
}

int inserisci       (char * s)
{
    printf("inserisci una stringa\n");

    fflush(stdin);
    scanf("%[^EOF]", s);
    fflush(stdin);
    
    return strlen(s);
}

int contaParole     (char * s)
{
    int     count = 0;
    char    copia[ strlen(s) + 1];

    strcpy( copia, s); 

    char *token = strtok(copia, " \n\t\r");
    while(token != NULL)
    {
        count++;
        token = strtok(NULL, " \n\t\r");
    }
    printf("ci sono %d parole\n", count);
    return count;
}
int contaRighe      (char * s)
{
    int     count = 0;
    char    copia[ strlen(s) + 1];

    strcpy( copia, s); 

    char *token = strtok(copia, "\n");
    while(token != NULL)
    {
        count++;
        token = strtok(NULL, "\n");
    }
    printf("ci sono %d righe\n", count);
    return count;
}
int contaCaratteri  (char * s)
{
    printf("ci sono %lu caratteri\n", strlen(s));
    return strlen(s);
}
int esci            (char * s)
{
    printf("chiusura in corso\n");
    exit(0);
    return 0;
}

int StampaMenu      (char * s)
{
    return printf("La tua stringa e':\n %s\n Scegli un'opzione :\n 0 - Inserimento nuova string \n 1 - Contare parole stringa corrente. \n 2 - Conta le righe della stringa \n 3 - conta i caratteri della stringa \n 4 - per uscire\n", s);
}