#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int compareStrings(const void* a, const void* b)
{
    char **as = (char**)a;
    char **bs = (char**)b;
    
    return -strcmp(*as,*bs);
}

int main()
{
    char *a[5] = {"sadol", "doaskd", "asdad", "asdaw", "doksa"};
    
    qsort(a, 5, sizeof(char*), compareStrings);
    for(int i = 0; i < 5; i++) printf("%s\n", a[i]);

    return 0;
}