#include <stdio.h>

int main() {
    int balance,choice=0,amount,transactions=0,max_transactions=5,n;

    printf("========= mini atm simulator =========\n");

    do {
    printf("enter your initial balance: rs");
        if (scanf("%d", &balance) != 1) {
    printf("invalid input! please enter a valid number.\n");

            while(getchar() != '\n');
            balance=0;
            continue;
        }
        if (balance<500) {
    printf("minimum initial balance should be rs500.\n");
        }
    } while (balance<500);

    printf("initial balance: rs%d\n", balance);

    while (choice != 4 && transactions<max_transactions) {
    printf("1. check balance\n");
    printf("2. deposit\n");
    printf("3. withdraw\n");
    printf("4. exit\n");
    printf("enter your choice: ");

        if (scanf("%d", &choice) != 1) {
    printf("invalid input! please enter a number between 1 and 4.\n");
            while(getchar() != '\n');
            continue;
        }

        if (choice == 1) {
    printf("your current balance: rs%d\n", balance);
            transactions++;
        }
        else if (choice == 2) {
    printf("enter amount to deposit: rs");
            if (scanf("%d", &amount) != 1) {
    printf("invalid input! please enter a valid number.\n");
                while(getchar() != '\n');
                continue;
            }
            if (amount<= 0) {
    printf("invalid amount! please enter a positive value.\n");
            } else {
                balance = balance + amount;
    printf("amount deposited successfully!\n");
                transactions++;
            }
        }
        else if (choice == 3) {
    printf("enter amount to withdraw: rs");
            if (scanf("%d", &amount) != 1) {
    printf("invalid input! please enter a valid number.\n");
                while(getchar() != '\n');
                continue;
            }
            if (amount <= 0) {
    printf("invalid amount! please enter a positive value.\n");
            } else if (amount >balance-500) {
    printf("insufficient balance! minimum rs500 must remain in your account.\n");
            } else {
                balance = balance - amount;
    printf("withdrawal successful! remaining balance: rs%d\n", balance);
                transactions++;
            }
        }
        else if (choice==4) {
    printf("thank you for banking with us!\n");
            break;
        }
        else {
    printf("invalid choice! please select between 1 and 4.\n");
        }

        if (transactions == max_transactions) {
    printf("you have reached the maximum transaction limit of %d.\n", max_transactions);
        }
    }

    printf("========= transaction summary =========\n");
    printf("total transactions: %d\n", transactions);
    printf("final balance: rs%d\n", balance);
    printf("session ended.\n");

    return 0;
}
