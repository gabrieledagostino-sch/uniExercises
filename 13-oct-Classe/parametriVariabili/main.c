#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#define N 100


int elliSum (int c, ...);
int argvSum (int argc, char ** argv);
 
int main(int argc, char ** argv)
{
    int Nums[N];


    for(int i = 1; i < argc; i++)
    {
        Nums[i-1] = atoi(argv[i]);
        printf("%d ", Nums[i-1]);
    }printf("\n");

    printf("%d %d %d\n", argc, elliSum(3, Nums[0], Nums[2], Nums[3]), argvSum(argc-1, argv+1));
    
}

int elliSum(int c, ...)
{
    va_list params;
    va_start(params, c);
    int s = 0;
    for (size_t i = 0; i < c; i++)
    {
        s += va_arg(params, int);
    }
    va_end(params);
    return s;
    
}

int argvSum (int argc, char ** argv)
{
    int s = 0;
    for (size_t i = 0; i < argc; i++)
    {
        s += atoi(argv[i]);
    }
    return s;
}