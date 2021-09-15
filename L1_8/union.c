//Scrivere un programma che gestisce pazienti in un ospedale. I pazienti sono identificati da un id numerico. 
//Possono essere o pazienti con diabete, o pazienti con malattie cardiovasculari. 
//Per ogni tipo di  paziente sono disponibili  diversi di variabili cliniche. 
//Per i pazienti con diabete abbiamo la glicemia (float) e il peso (float), 
//per i pazienti cardio abbiamo pressione (int) e frequenza cardiaca (int). 
//Il programma legge un numero n da tastiera, seguito da n pazienti. 
//Per ogni paziente abbiamo il tipo di malattia su la prima riga, e le due variabili di interesse sulla seconda riga. 
//Il programma stampa tutti i pazienti che hanno la stessa malattia dell'ultimo paziente  inserito.
#include <stdio.h>
#define N 500


typedef enum{
    CARDIO,
    DIABETE
} Diagnosi;

typedef struct{
    float glicemia;
    float peso;
}Diabete;

typedef struct{
    int pressione;
    int freq;
}Cardio;

typedef union{
    Diabete datiDiabete;
    Cardio datiInfarto;
} DatiMalattia;

typedef struct{
    int ID;
    Diagnosi malattia;
    DatiMalattia dati;
}Paziente;

int main()
{
    int n;
    Paziente A[N];

    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        Paziente inp;
        inp.ID = i;

        scanf("%d", &(inp.malattia));

        if(inp.malattia == CARDIO)  scanf("%d %d", &A[i].dati.datiInfarto.freq, &A[i].dati.datiInfarto.pressione);
        else                        scanf("%f %f", &A[i].dati.datiDiabete.glicemia, &A[i].dati.datiDiabete.peso);

        A[i].ID = inp.ID;
        A[i].malattia = inp.malattia;
        A[i].dati = A[i].dati;
    }

    Paziente ultimo = A[n-1];

    for(int i = 0; i < n; i++){
        if(A[i].malattia == ultimo.malattia)
            printf("%d\n", A[i].ID);
    }

    return 0;
}