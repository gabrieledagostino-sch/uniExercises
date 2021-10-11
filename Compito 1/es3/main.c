#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define N 100

typedef struct point{
    double x;
    double y;
}Point;

int compare (const void*a , const void *b);

int main(int argc, char** argv)
{
    size_t n;
    Point arr[N];

    scanf("%d", &n);

    for (size_t i = 0; i < n; i++)
    {
        double x,y;
        scanf("%lf %lf", &x,&y);
        arr[i].x = x;
        arr[i].y = y;
    }

    Point last = arr[n-1];

    qsort(arr, n, sizeof(Point), compare);

    for (size_t i = 0; i < n; i++)
    {
        double d = sqrt(pow((arr[i].x - last.x), 2) + pow((arr[i].y - last.y), 2));
        if(d < 5) printf("%.2f %.2f\n", arr[i].x, arr[i].y);
    }
    

    return 0;
}

int compare (const void*a , const void *b)
{
    Point ap = *(Point*)a;
    Point bp = *(Point*)b;

    if(ap.x == bp.x)
        return bp.y - ap.y;
    return ap.x - bp.x;

}