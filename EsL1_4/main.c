#include <stdio.h>

int main()
{

    int n1,n2;

    scanf("%d", &n1);
    scanf("%d", &n2);
    if(n2>n1)   n1 = n2;
    scanf("%d", &n2);



    if(n1 > n2)
    {
        printf("%d\n",n1);
    }else{
        printf("%d\n",n2);
    }


    return 0;
}