#include <stdio.h>
#include <math.h>

int main(){
    float a,b,c;
    char opIn;

    scanf("%f", &a);
    scanf("%f", &b);
    fflush(stdin);
    scanf("%c", &opIn);
    
    switch (opIn)
    {
    case '+':
        c = a+b;
        break;
    case '-':
        c = a-b;
        break;
    case '*':
        c = a*b;
        break;
    case '/':
        c = a/b;
        break;
    case '%':
        c = ((int)floor(a)) % ((int)floor(b));
        break;
    
    default:
        printf("invalid operator");
        return 0;
    }

    printf("%f", c);
    return 0;

}