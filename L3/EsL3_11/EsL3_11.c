#include <stdio.h>

int diff_abs(float *a, float *b);

int main()
{   
    float a,b;
    scanf("%f", &a);
    scanf("%f", &b);

    diff_abs(&a, &b);

    printf("%.2f\n%.2f\n",a,b);
    return 0;
}


int diff_abs(float *a, float *b)
{
    float temp = *a;
    *a = *a - *b;
    *b = *b - temp;
    return 0;
}
