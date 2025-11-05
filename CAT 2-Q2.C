/*
Name:Samuel Munyua Gicheru
Reg:CT100/G/26198/25
Description:A-c-program-to-calculate-hours-worked-in-a-week
*/

#include <stdio.h>

int main() {
    float hours, rate, grossPay, taxes, netPay;
    
    // Get input from the user
    printf("Enter hours worked in a week: ");
    scanf("%f", &hours);
    printf("Enter hourly wage: ");
    scanf("%f", &rate);

    // Calculate gross pay
    if (hours > 40)
        grossPay = (40 * rate) + ((hours - 40) * rate * 1.5);
    else
        grossPay = hours * rate;

    // Calculate taxes
    if (grossPay <= 600)
        taxes = 0.15 * grossPay;
    else
        taxes = (0.15 * 600) + (0.20 * (grossPay - 600));

    // Calculate net pay
    netPay = grossPay - taxes;

    // Display results
    printf("\nGross Pay: $%.2f", grossPay);
    printf("\nTaxes: $%.2f", taxes);
    printf("\nNet Pay: $%.2f\n", netPay);

    return 0;
}