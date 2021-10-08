#include <stdio.h>
#include <string.h>
#define N 10
#define STATES 8

typedef enum {
    S0, S1, S2, S3, S4, S5, S6, ERR
} State;

State sC(char c, State s);
State s3(char c, State s);
State s4(char c, State s);
State s6er(char c, State s);



int main()
{

    State s = S0;
    char str[N];
    
    State (*automa[STATES])(char, State) = {sC, sC, sC, s3, s4, sC, s6er, s6er}; 

    scanf("%[^\n]", str);

    for(int i = 0; i < strlen(str); i++)
    {
        s = (*automa[s])(str[i], s);
        printf("%c %d\n", str[i], s);
    }

    if(s == S6)
        printf("parola accettata\n");
    else
        printf("parola non accettata\n");

    return 0;
}
State s6er(char c, State s)
{
    return ERR;
}

State sC(char c, State s)
{
    if(c >= 'A' && c <= 'Z')
    {
        return s+1;
    }
    return ERR;
    
}
State s4(char c, State s)
{
    if(c == '1')
        return S4;
    if(c >= 'A' & c <= 'Z')
        return S5;
    return ERR;
}

State s3(char c, State s)
{
    if(c == '1')
        return S4;
    return ERR;
}
