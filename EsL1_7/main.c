#include <stdio.h>
#include <math.h>

int main()
{
    unsigned short int choice;
    float initPrice, percentage;
    int conditions =  choice == 0         ||
                      choice == 1         ||
                      percentage < 0      ||
                      percentage > 100    ||
                      initPrice < 0;
    if(conditions){
      printf("invalid input\n");
      return 0;
    }


    //input
    scanf("%f", &choice);
    scanf("%f", &initPrice);
    scanf("%f", &percentage);
    
    float endPrice = initPrice + percentage * initPrice * 0.01 * pow(-1, choice);

    //output
    if(choice)
    {
      printf("Prezzo_Init\tPercentuale\tPrezzo_scontato\n");
    }else{
      printf("Prezzo_Init\tPercentuale\tPrezzo_ivato\n");
    }
    printf("%20.2f%20.2f%20.2f", initPrice, percentage, endPrice);

    return 0;
}





