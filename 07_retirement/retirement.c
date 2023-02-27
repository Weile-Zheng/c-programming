#include <stdio.h>
#include <stdlib.h>

typedef struct retire_info{
    int months;
    double contribution; 
    double rate_of_return; 

} retire_info;

void retirement (int startAge, double initial, retire_info working, retire_info retired){
    double balance = initial; 
    int ageYear = startAge/12;
    int ageMonths = startAge%12;

    for(int i = 0; i < working.months + retired.months; i++){
        printf("Age %3d month %2d you have $%.2lf\n", ageYear, ageMonths, balance);
        if(ageMonths==12){
            ageYear++;
            ageMonths =0;
        }

        if(i<working.months){
            balance = balance + balance*(working.rate_of_return/12)+working.contribution;
        }
        else{
            balance = balance + balance*(retired.rate_of_return/12)+retired.contribution;
        }
        ageMonths++;
    }
}


int main(){
    retire_info working;
    retire_info retired;
    working.months = 489;
    working.contribution = 1000;
    working.rate_of_return = 0.045;
    retired.months=384;
    retired.contribution=-4000;
    retired.rate_of_return = 0.01;
    retirement(327,21345,working,retired);
    return EXIT_SUCCESS;
}
