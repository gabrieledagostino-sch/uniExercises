/**********************************************************************************************************************
 * Si realizzi un programma che traduce testo dall’inglese a Pig Latin. Per
 * tradurre una parola in Pig Latin, usare le regole:
 * • Se la parola comincia con una vocale, la traduzione `e la parola stessa
 * con ’way’ aggiunto alla fine.
 * • Se la parola comincia con consonanti, la versione Pig Latin trasferisce
 * 
 * alla fine della parola tutte le consonanti fino alla prima vocale, aggiun-
 * gendo ”ay” alla fine.
 * 
 * • La lettera ’y’ viene considerata consonante se compare all’inizio di una
 * parola, altrimenti viene considerata vocale.
 * • Se la parola originale comincia con una maiuscola, la parola finale deve
 * cominciare con una maiuscola.
 * Scrivere una funzione che fa la traduzione per ogni parola:
 * char* en2piglatin(char* );
 * La funzione main deve offrire all’utente un menu testuale: 1. per inserire
 * una nuova frase che finisce con un ’\n’, 2. per visualizzare l’ultima frase
 * inserita con lettere maiuscole, 3. per visualizzare la traduzione Pig Latin, 4.
 * per uscire. Si pu`o assumere che una frase contiene solo delle parole separate
 * da spazio.
 * Usare pointer a funzioni per costruire il menu.
 *********************************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define N 1025

char   lastInput[N];


int     insert          (                       );              //inserts a new string to the one insterted by the user
int     capsCo          (                       );              //prints the last string inserted in all caps
int     transl          (                       );              //prints the last string inserted as piglatin
int     end             (                       );              //closes the program
int     isVowel         (int c                  );              //returns true if the character is a vowel (a,e,i,o,u,y)
char*   vowelStart      (char* s                );              //converts the string s to piglatin when it starts with a vowel
char*   consonantStart  (char* s                );              //converts the string s to piglatin when it starts with a consonant
char*   readLine        (char *s, size_t maxSize);              //reads the next line of input (until a '\n')

char*   en2piglatin     (const char * s         );              //translates the string to piglating

int (*menu[4])() = {&insert, &capsCo, &transl, &end};           //press 1 to insert a new string, 2 to print it all caps, 3 for translating it, 4 to quit

int main()
{
    int op = 0;
    char s[10] = "";

    while(1)
    {
        printf("Scegliere l'operazione:\n");
        
        readLine(s, 10);
        op = atoi(s);
        
        (*menu[op-1])();
    }

    return 0;
}


/********************************************************************************************************************************* *
 * 
 * Menu functions
 * 
 * *********************************************************************************************************************************/

//Closes the program, printing Ciao! be4, closes it by calling stdlib::exit()
int     end             (                       )
{
    printf("Ciao!\n");
    exit(0);

    return 0;
}

//let's the user insert a new string, the string is global
int     insert          (                       )
{
    printf("Inserire stringa:\n");
    readLine(lastInput, N);
    return 0;
}

//Prints the last queried string in caps
int     capsCo          (                       )
{
    int l = strlen(lastInput);
    
    for (size_t i = 0; i < l; i++)
    {
        if(islower(lastInput[i]))
            printf("%c", toupper(lastInput[i]));
        else
            printf("%c", lastInput[i]);
    }
    return printf("\n");
}

//Prints the piglatin conversion of the last queried string
int     transl          (                       )               //TBI
{

    char* translated = en2piglatin(lastInput);

    printf("%s\n", translated);

    return 0;
}


/********************************************************************************************************************************* *
 * 
 * Support functions
 * 
 * *********************************************************************************************************************************/

//return 1 if c is a vowel, 0 otherwise
int     isVowel         (int c                  )
{
    switch (c)
    {
    case 'A':
    case 'E':
    case 'I':
    case 'O':
    case 'U':
    case 'Y':
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
    case 'y':
        return 1;
    
    default:
        return 0;
    }
}


//reads stdin until the first \n
char*   readLine        (char *s, size_t maxSize)
{
    char    c = 0;
    size_t  i;
    for (i = 0; i < maxSize-1 && (c = getchar()) != '\n' && c != EOF; i++)
    {
        s[i] =  c;
    }
    s[i++] = '\0';

    return s;
}


/********************************************************************************************************************************* *
 * 
 * Translate functions
 * 
 * *********************************************************************************************************************************/

//Translator
char*   en2piglatin     (const char * s          )
{
    char tokenString[N] = "";
    char adding[100] = "";
    char *result = malloc(N);
    *result = '\0';
    strcpy(tokenString, lastInput);
        
    char *tok = strtok(tokenString, " ");

    while(tok != NULL)
    {
        strcpy(adding, tok);
        if(!isVowel(tok[0]) || tok[0] == 'y')
            consonantStart(adding);
        else
            vowelStart(adding);
        
        strcat(result, adding);
        tok = strtok(NULL, " ");
    }
    result[strlen(result)-1] = '\0';
    return result;
}

//translation in case it starts with a consonant
char*   consonantStart  (char* s                )
{
    size_t l = strlen(s);                                   //string length
    int flag = isupper(s[0]);                               //says if the first letter was uppercase
    size_t i = 1;                                           //index
    char consonanti[100];                                   //will contain all the consonants till the first vowel
    
    for(; s[i] != '\0' && !isVowel(s[i]); i++);             //puts i to the first vowel
    
    strncpy(consonanti, s, i);                              //copies the consonants into consonanti
    consonanti[i] = '\0';                                   //closes the string
    if(flag) consonanti[0] = tolower(consonanti[0]);        //puts the first letter to lowercase if it was uppercase
    
    memcpy(s, s+i, l-i+1);                                  //copies the string into itself without the consonants part
    if(flag) s[0] = toupper(s[0]);                          //puts the first letter upper if it was
    strcat(s, consonanti);                                  
    strcat(s, "ay ");                                       
    return s;
}

//translation in case it starts with a vowel
char*   vowelStart      (char* s                )
{
    size_t l = strlen(s);
    size_t i;
    for (i = 1; s[i] != '\0'; i++);
    s[i] =   'w';
    s[i+1] = 'a';
    s[i+2] = 'y';
    s[i+3] = ' ';
    s[i+4] = '\0';
    return s;
}