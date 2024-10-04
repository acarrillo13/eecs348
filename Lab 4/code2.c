#include <stdio.h>
void converter( float temp, int convert, int scale){//function to convert given temp to desired scale
    float newtemp;
    if(convert == 1){
        if(scale == 1){
            printf("\nConverted temperature: %.2f °C",temp);
        }
        else if(scale == 2){
            newtemp = (temp - 32.0) * (5.0/9.0);
            printf("\nConverted temperature: %.2f °C", newtemp);
        }
        else if(scale == 3){
            newtemp = temp - 273.15;
            printf("\nConverted temperature: %.2f °C",newtemp);
        }
        else{
            printf("\nInvalid input");
        }
    }
    else if (convert == 2){
        if(scale == 1){
            newtemp = ((9.0/5.0)*temp) + 32.0;
            printf("\nConverted temperature: %.2f °F",newtemp);
        }
        else if(scale == 2){
            printf("\nConverted temperature: %.2f °F",temp);
        }
        else if(scale == 3){
            newtemp = (((9.0/5.0)*temp) + 32.0) - 273.15;
            printf("\nConverted temperature: %.2f °F",newtemp);
        }
        else{
            printf("\nInvalid input");
        }
    }
    else if (convert == 3){
        if(scale == 1){
            newtemp = temp + 273.15;
            printf("\nConverted temperature: %.2f °K",newtemp);
        }
        else if(scale == 2){
            newtemp = (temp - 32.0) * (5.0/9.0) + 273.15;
            printf("\nConverted temperature: %.2f °K",newtemp);
        }
        else if(scale == 3){
            printf("\nConverted temperature: %.2f °K",temp);
        }
        else{
            printf("\nInvalid input");
        }
    }
    else{
        printf("\nInvalid input");
    }
}

void weatherReport(float temp, int scale){//will print out the weather report given the temp 
     float ctemp;
    if(scale == 1){
        ctemp = temp;
    }
    else if(scale == 2){
        ctemp = (temp - 32.0) * (5.0/9.0);;
    }
    else if(scale == 3){
        ctemp = temp - 273.15;
    }
    ///v hot, hot, comfortible, cold, v cold
    if(ctemp >= 40.0){
        printf("\nTemperature category: Very Hot\nWeather advisory: Drink lots of water and wear sunscreen");
    }
    else if(ctemp >= 30){
        printf("\nTemperature category: Warm\nWeather advisory: Stay hydrated");
    }
    else if(ctemp >= 20){
        printf("\nTemperature category: comfortible\nWeather advisory: Great day outside, stay comfortible");
    }
    else if(ctemp >= 10){
        printf("\nTemperature category: Chilly\nWeather advisory: Wear a coat");
    }
    else{
        printf("\nTemperature category: Very Cold\nWeather advisory: Bundle up or stay home");
    }
}

int main()
{
    int scale, convert;
    float temp;
    printf("Enter the temperature: ");
    scanf("%f", &temp);
    printf("Choose the current scale (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
    scanf("%d", &scale);
    printf("Convert to (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
    scanf("%d", &convert);
    
    converter(temp,convert,scale);
    
    weatherReport(temp, scale);
    
    return 0;
}