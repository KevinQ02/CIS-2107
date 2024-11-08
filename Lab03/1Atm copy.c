/* Personal class notes
* 1) Pin: 3014   --> 3 tries after that it will terminate
    * Use "switch"
        1: Balance
        2: Withdraw
        3: Deposit
        4: Exit
    * Check amount in the account first
* 2) Startinng amount:5,000
* Welcome:
    1) Balace --> 5,000
    2) Withdraw
        --> limit 1,000 per day
        --> Must be in multiples of 20
        --> Inputs >1000 are invalid, <1,000 Valid
            --> If invalid amount is given 3 more tries are given, then program is terminated
        --> Ask if u want a recipt at the end
    3) Deposit
        --> limit is 10,000
        --> No coins can be deposited
    4) QUit
* Receipt is given for every withdrawal annd deposit transaction
    --> To get receipt user must enter 1
    --> This means the receipt will print on the screen :| *duh*
*CHECKLIST  
    --> Does the program catch 0s and negatives?
            --> Are u using ≤ 0 to validate?
    --> Does a user have only 3 attempts to ennter the correct PIN?
            --> Does ur programm call exit after 3 tries?
    --> Cann a user only withdraw multiples of 20?
    --> Coins cant be deposited
    --> Does ur code display any exit message which shows the total number of transactions made?
    --> Does ur program run on the server
*/
#include <stdio.h>
#include <stdlib.h>

void displayMenu();
int validatePIN();
void checkBalance(float balance);
void cashWithdrawal(float *balance);
void cashDeposit(float *balance);
void quit(int transactionsCount);


const int PIN = 3014;
const float withdrawalLimit = 1000.0;
const float depositLimit = 10000.0;

int main() {
    unsigned int userPIN, attempts = 0, transactionsCount = 0;
    float balance = 5000.0;
    int choice;

    printf("Welcome to the ATM!\n");

    while (attempts < 3 && !validatePIN()) {
        printf("Incorrect PIN. Please try again.\n");
        attempts++;
    }

    if (attempts >= 3) {
        printf("Too many incorrect attempts. Exiting.\n");
        exit(0);
    }

    do {
        displayMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                checkBalance(balance);
                transactionsCount++;
                break;
            case 2:
                cashWithdrawal(&balance);
                transactionsCount++;
                break;
            case 3:
                cashDeposit(&balance);
                transactionsCount++;
                break;
            case 4:
                quit(transactionsCount);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

void displayMenu() {
    printf("\nATM Menu:\n");
    printf("1. Check Balance\n");
    printf("2. Cash Withdrawal\n");
    printf("3. Cash Deposit\n");
    printf("4. Quit\n");
    printf("Enter your choice: ");
}

int validatePIN() {
    int enteredPIN;
    printf("Please enter your PIN: ");
    scanf("%d", &enteredPIN);
    return enteredPIN == PIN;
}

void checkBalance(float balance) {
    printf("Your current balance is: $%.2f\n", balance);
}

void cashWithdrawal(float *balance) {
    float amount;
    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);
    if (amount <= 0 || (int)amount % 20 != 0 || amount > *balance || amount > withdrawalLimit) {
        printf("Invalid amount. Please try again.\n");
    } else {
        *balance -= amount;
        printf("Withdrawal successful. New balance: $%.2f\n", *balance);
    }
}

void cashDeposit(float *balance) {
    float amount;
    int invalidAttempts = 0; 
    while (invalidAttempts < 3) {
        printf("Enter amount to deposit: ");
        scanf("%f", &amount);
        if (amount <= 0 || amount > depositLimit) {
            printf("Invalid amount. Please try again.\n");
            invalidAttempts++;
            if (invalidAttempts >= 3) {
                printf("Too many invalid attempts. Exiting.\n");
                exit(0);
            }
        } else {
            *balance += amount;
            printf("Deposit successful. New balance: $%.2f\n", *balance);
            break;
        }
    }
}

void quit(int transactionsCount) {
    printf("Thank you for using the ATM. You made %d transactions today.\n", transactionsCount);
    exit(0);
}
