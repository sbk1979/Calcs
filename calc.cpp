#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
  {
    double starting_amt;
    double rate;
    double ending_amt[100];
    double contribution[100], contribution_total[100], interest[100];
    int nyears;
    
    printf("Enter the starting amount\n");
    scanf("%lf",&starting_amt);

    printf("Enter the interest rate\n");
    scanf("%lf",&rate);

    printf("Enter the number of years to be considered for the calculations \n");
    scanf("%d",&nyears);

    printf("Enter contribution for each year \n");
    
    ending_amt[0] = starting_amt;

    for(int i = 0; i < nyears; i++)
      {
        printf("\nFor year %d:",i+1);
        scanf("%lf",&contribution[i]);

        if (i == 0) contribution_total[i] = starting_amt + contribution[i];
        else        contribution_total[i] = contribution_total[i-1] + contribution[i];
        
        if (i == 0) interest[i] = 0.01*rate*(ending_amt[i] + contribution[i]);
        else        interest[i] = 0.01*rate*(ending_amt[i-1] + contribution[i]);

        if (i == 0) ending_amt[i] = (1.0 + 0.01*rate) * (ending_amt[i] + contribution[i]);
        else        ending_amt[i] = (1.0 + 0.01*rate) * (ending_amt[i-1] + contribution[i]);
      }

    printf("\n\n");

    for(int i = 0; i < nyears; i++)
      {
        printf("Year = %d    Total Contribution = %.2lf    Interest Earned = %.2lf     Ending Amount = %.2lf\n",i+1,contribution_total[i],interest[i],ending_amt[i]);
      }

  }
    


