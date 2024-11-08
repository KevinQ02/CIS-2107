
// Kevin Quiroz
// 1/26/2024
// Computer Systems and Low-Level Programming 
// Lab 02. Paycheck_and_Revenue 
#include <stdio.h> 
#include <math.h> 
#include <stdlib.h> 

int main() {
    double itemPrice, itemQuantity, discount, discountAmount, total, cost;
    double fractpart, intpart;

    puts("Welcome to the 'Temple' Store\n");
    printf("Enter item price: ");
    scanf("%lf", &itemPrice);

    if (itemPrice < 0) {
        puts("This is not a valid item price.");
        puts("Please run the program again");
        exit(1);
    }

    printf("Enter quantity: ");
    scanf("%lf", &itemQuantity);
    
    fractpart = modf(itemQuantity, &intpart);

    if (itemQuantity <= 0 || fractpart > 0) {
        puts("This is not a valid quantity order.");
        puts("Please run the program again");
        exit(1);
    }

    if (itemQuantity >= 150) {
        discount = 25;
    } else if (itemQuantity >= 100) {
        discount = 15;
    } else if (itemQuantity >= 50) {
        discount = 10;
    } else {
        discount = 0;
    }

    cost = itemPrice * itemQuantity;
    discountAmount = cost * discount / 100;
    total = cost - discountAmount;

    printf("The item price is: $%.1lf\n", itemPrice);
    printf("The order is: %.0lf item(s)\n", itemQuantity);
    printf("The cost is: $%.1lf\n", cost);
    printf("The discount is: %.1lf%%\n", discount);
    printf("The discount amount is: $%.1lf\n", discountAmount);
    printf("The total is: $%.1lf\n", total);
    puts("Thank you for using 'Temple' store");
    return 0;
}
