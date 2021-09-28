#include <stdio.h>
#include <math.h>

int main()
{
    unsigned short int choice;
    float initPrice, percentage;
    


    //input
    scanf("%hu", &choice);
    scanf("%f", &initPrice);
    scanf("%f", &percentage);
    
    float endPrice = initPrice + percentage * initPrice * 0.01 * pow(-1, !choice);

    int conditions =  (choice != 0 && choice != 1) ||
                      percentage < 0               ||
                      percentage > 100             ||
                      initPrice < 0;
    
    if(conditions){
      printf("invalid input\n");
      return 0;
    }
    char  prezz[] = "Prezzo_Init",
          perc[]  = "Percentuale",
          scont[] = "Prezzo_scontato",
          ivat[]  = "Prezzo_ivato";
    //output
    if(choice == 0)
    {
      printf("%20s\t%20s\t%20s\n",prezz, perc, scont);
    }else{
      printf("%20s\t%20s\t%20s\n",prezz, perc, ivat);
    }
    printf("%20.2f\t%20.2f\t%20.2f\n", initPrice, percentage, endPrice);

    return 0;
}




