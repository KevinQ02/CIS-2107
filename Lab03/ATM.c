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

#include
    // variables
int main(void){
    int PinNum;
    void Showmenu;
    void Balance;
    int WithdrawAmmt;
    int BillsWithdrawn;
    int Desposit;
    int Transactions;

    printf("Welcome please enter your 4 digit Pin number:")

   // initialization phase


   // processing phase
}