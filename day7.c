#include <stdio.h>

int main() {
    int choice;
    float balance = 10000.0;
    float amount;
    
printf("welcome to simple bank system\n");
    
       do {
        printf("MENU\n");
        printf("1. deposit money\n");
        printf("2. withdraw money\n");
        printf("3. check balance\n");
        printf("4. exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);
        
        if (choice==1) {
            printf("enter amount to deposit:");
            scanf("%f", &amount);
            
            if (amount>0) {
                if (amount>25000) {
                    float bonus=amount*0.01;
                    amount=amount+bonus;
                    printf("bonus of %.2f added\n", bonus);
                }
                balance += amount;
                balance -= 5;
printf("%.2f deposited successfully (5 service charge applied).\n",amount);
printf("updated Balance: %.2f\n", balance);
            } else {
printf("invalid deposit amount\n");
            }
        }
        else if (choice==2) {
printf("enter amount to withdraw:");
scanf("%f", &amount);
            
            if (amount>0) {
                if (amount>balance) {
printf("warning insufficient balance withdrawal not allowed\n");
                } else {
                    balance -= amount;
                    balance -= 5;  // service charge
printf("₹%.2f withdrawn successfully (5 service charge applied)\n", amount);
printf("updated Balance:%.2f\n", balance);
                }
            } else {
printf("invalid withdrawal amount\n");
            }
        }
        else if (choice==3) {
         
printf("current balance:%.2f\n", balance);
        }
        else if (choice==4) {

printf("thank you for using simple bank system\n");
        }
        else {
printf("invalid choice please select between 1 and 4\n");
        }

    } while (choice !=4);
    
printf("session ended goodbye\n");

return 0;
}
