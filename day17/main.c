#include <stdio.h>

int main() {
    char name[50], regno[20], section[5];
    int n, i, choice;
    float salary[10], total = 0, avg, temp;
    float highest, lowest;
    int above = 0, below = 0;

    printf("========= employee salary analysis system =========\n");
    printf("enter student name: ");
    scanf(" %[^\n]", name);
    printf("enter registration number: ");
    scanf("%s", regno);
    printf("enter section: ");
    scanf("%s", section);

    printf("enter number of employees (max 10): ");
    scanf("%d", &n);

    if (n > 10) {
        printf("number of employees cannot exceed 10.\n");
        return 0;
    }

    printf("enter salaries:\n");
    for(i = 0; i < n; i++) {
        printf("%d: ", i + 1);
        scanf("%f", &salary[i]);
    }

    do {
        printf("\n========= menu =========\n");
        printf("1. display all salaries\n");
        printf("2. display total and average salary\n");
        printf("3. display highest and lowest salary\n");
        printf("4. count employees above and below average\n");
        printf("5. display sorted salaries (ascending)\n");
        printf("6. exit\n");
        printf("========================\n");
        printf("enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("\nall salaries:\n");
            for (i = 0; i < n; i++) {
                printf("%.2f ", salary[i]);
            }
            printf("\n");
        }

        else if (choice == 2) {
            total = 0;
            for (i = 0; i < n; i++) {
                total += salary[i];
            }
            avg = total / n;
            printf("total salary = %.2f\n", total);
            printf("average salary = %.2f\n", avg);
        }

        else if (choice == 3) {
            highest = salary[0];
            lowest = salary[0];
            for (i = 1; i < n; i++) {
                if (salary[i] > highest)
                    highest = salary[i];
                if (salary[i] < lowest)
                    lowest = salary[i];
            }
            printf("highest salary = %.2f\n", highest);
            printf("lowest salary = %.2f\n", lowest);
        }

        else if (choice == 4) {
            total = 0;
            for (i = 0; i < n; i++) {
                total += salary[i];
            }
            avg = total / n;
            above = 0;
            below = 0;
            for (i = 0; i < n; i++) {
                if (salary[i] > avg)
                    above++;
                else if (salary[i] < avg)
                    below++;
            }
            printf("average salary = %.2f\n", avg);
            printf("employees above average = %d\n", above);
            printf("employees below average = %d\n", below);
        }

        else if (choice == 5) {
            for (i = 0; i < n - 1; i++) {
                for (int j = 0; j < n - i - 1; j++) {
                    if (salary[j] > salary[j + 1]) {
                        temp = salary[j];
                        salary[j] = salary[j + 1];
                        salary[j + 1] = temp;
                    }
                }
            }
            printf("salaries in ascending order:\n");
            for (i = 0; i < n; i++) {
                printf("%.2f ", salary[i]);
            }
            printf("\n");
        }

        else if (choice == 6) {
            printf("exiting program...\n");
        }

        else {
            printf("invalid choice! please try again.\n");
        }

        printf("\nsubmitted by: %s | reg no: %s | section: %s\n", name, regno, section);
        printf("challenge day 17 - code2grow program\n");

    } while (choice != 6);

    return 0;
}
