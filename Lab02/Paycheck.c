#include <stdio.h> 
#include <math.h> 
#include <stdlib.h> 

int main() { 
    double employeeNumber, fractpart, intpart;
    double hourlySalary, regularPay, netPay, overtime;
    int weeklyTime, extraHours;

    printf("Welcome to 'TEMPLE HUMAN RESOURCES'\n");

    printf("Enter Employee Number:\n");
    scanf("%lf", &employeeNumber); 
    fractpart = modf(employeeNumber, &intpart); 

    if (intpart < 0.0 || fractpart > 0.0) { 
        printf("This is not a valid Employee Number.\nPlease run the program again.\nThank you for using TEMPLE HUMAN RESOURCES\n"); 
        exit(1); 
    } 

    printf("Enter Hourly Salary:\n");  
    scanf("%lf", &hourlySalary); 
    if (hourlySalary <= 0) { 
        printf("This is not a valid hourly salary.\nPlease run the program again.\nThank you for using TEMPLE HUMAN RESOURCES\n");
        exit(1);
    }

    printf("Enter Weekly Time:\n");  
    scanf("%d", &weeklyTime);
    if (weeklyTime <= 0) {
        printf("This is not a weekly time.\nPlease run the program again.\nThank you for using TEMPLE HUMAN RESOURCES\n");
        exit(1);
    }

    if (weeklyTime <= 40) { 
        regularPay = weeklyTime * hourlySalary;
        netPay = regularPay;
        overtime = 0;
    } else {
        extraHours = weeklyTime - 40;
        regularPay = 40 * hourlySalary;
        netPay = regularPay + (extraHours * 1.5 * hourlySalary); 
        overtime = netPay - regularPay;
    }

    printf("========================\n");
    printf("Employee #: %d\n", (int) employeeNumber);
    printf("Hourly Salary: $%.2lf\n", hourlySalary);
    printf("Weekly Time: %d\n", weeklyTime);
    printf("Regular Pay: $%.2lf\n", regularPay);
    printf("Overtime Pay: $%.2lf\n", overtime);
    printf("Net Pay: $%.2lf\n", netPay);
    printf("========================\n");
    printf("Thank you for using 'TEMPLE HUMAN RESOURCES'\n");
    return 0;
}
