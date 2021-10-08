#include <stdio.h>

char * cpyString(char* source, char* destination)
{
    while((*destination++ = *source++));

    return destination;
}

int main()
{
    char s[] = "source";
    char d[20];

    cpyString(s, d);
    printf("%s, %s\n", s, d);

    return 0;
}