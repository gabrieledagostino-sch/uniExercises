#include <stdio.h>

int main()
{
    int arr[10];
    
    for(int i = 0; i < 10; i++)
    {
        scanf("%d", arr+i);
    }

    for(int i = 9; i >= 0; i--)
    {
        if(arr[i]%2==0) arr[i] /= 2;

        printf("%d\n", arr[i]);
    }

    return 0;
}
