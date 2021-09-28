#include <stdio.h>

int main()
{
    char c;
    if(scanf("%[a-z]", &c) != 1)
      printf("invalid input: must be lowercase letter");
    else
      printf("%c", c+('A'-'a'));

    return 0;
}