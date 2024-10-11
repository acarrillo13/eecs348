#include <stdio.h>
#include <string.h>

int main()
{
    float figs[12];
    float figure;
    printf("Enter 12 Sales Figures:\n");
    for(int i = 0; i < 12; i++){
        scanf("%f", &figure);
        figs[i] = figure;
    }
    
    char *months[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    printf("\nMonthly Sales Report for 2024\nMonth\tSales\n");
    for(int i = 0; i < 12; i++){
        printf("%s\t%.2f\n", months[i], figs[i]);
    }
    
    float max = figs[0], min = figs[0];
    float total = 0, average = 0;
    int monthmin = 0, monthmax = 0;
    
    // Find minimum, maximum, and total sales
    for(int i = 0; i < 12; i++){
        if(figs[i] > max){
            max = figs[i];
            monthmax = i;
        }
        if(figs[i] < min){
            min = figs[i];
            monthmin = i;
        }
        total += figs[i];
    }
    average = total / 12;
    printf("\nSales Summary Report\nMinimum sales: %.2f\t%s\nMaximum sales: %.2f\t%s\nAverage sales: %.2f\n",
           min, months[monthmin], max, months[monthmax], average);
    
    // Six Month Moving Average Report
    printf("\nSix Month Moving Average Report\n");
    for(int i = 0; i <= 6; i++){
        average = (figs[0 + i] + figs[1 + i] + figs[2 + i] + figs[3 + i] + figs[4 + i] + figs[5 + i]) / 6;
        printf("%s-%s:\t%.2f\n", months[i], months[i + 5], average);
    }
    
    // Sales Report (Highest to Lowest)
    float temp;
    char *tempMonth;
    printf("\nSales Report (Highest to Lowest)\n");
    for(int i = 0; i < 11; i++) {
        for(int j = 0; j < 11 - i; j++) {
            if(figs[j] < figs[j + 1]) {
                // Swap sales figures
                temp = figs[j];
                figs[j] = figs[j + 1];
                figs[j + 1] = temp;

                // Swap corresponding months
                tempMonth = months[j];
                months[j] = months[j + 1];
                months[j + 1] = tempMonth;
            }
        }
    }
    
    for (int i = 0; i < 12; i++){
        printf("%s\t$%.2f\n", months[i], figs[i]);
    }
    return 0;
}
