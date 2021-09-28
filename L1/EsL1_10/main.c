#include <stdio.h>
int main()
{
    long secs;
    scanf("%ld", &secs);
    
    if(secs < 0)
    {
        printf("invalid input");
        return 0;
    }
    
    int s,m,h;
    s = secs % 60;
    secs /= 60;
    m = secs % 60;
    secs /= 60;
    h = secs;
    printf("%d h %d min %d s\n",h,m,s);

    return 0;
}