#include <stdio.h>
#define NMAX 100
#define bool unsigned short int

int main()
{

    int n;
    int arr[NMAX];
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        while(scanf("%d", arr+i) != 1){
            printf("error in input, enter an integer value and press enter\n");
            fflush(stdin);
            //scanf("%*[^\n]\n");
        }
    }
    for(int i = 0; i < n; i++){
        bool cond = (arr[i]%2==0) || (i < n-1 && arr[i] < 0 && arr[i+1] >= 0);
        if(cond){
            printf("%d\n",arr[i]);
        }
    }
    
    return 0;
}