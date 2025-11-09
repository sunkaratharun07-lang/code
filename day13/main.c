#include <stdio.h>

int main() {
    int total_passengers, count = 1;
    float total_revenue = 0, highest_fare = 0, lowest_fare = 999999;

printf("========= srm smart bus fare calculator =========\n");
printf("enter number of passengers: ");
scanf("%d", &total_passengers);

    while (count <= total_passengers) {
        char name[50];
        int age, time;
        float distance, base_fare, final_fare;
        char note[100] = "";

printf("--- passenger %d ---\n", count);
printf("enter name: ");
scanf("%s", name);
printf("enter age: ");
scanf("%d", &age);
printf("enter distance (in km): ");
scanf("%f", &distance);
printf("enter travel time (24-hour format): ");
scanf("%d", &time);

        base_fare = distance * 10;
        final_fare = base_fare;

             if (age < 12) {
            final_fare = final_fare * 0.5;
printf("passenger: %s | base fare: rs%.0f | child discount applied", name, base_fare);
        } 
        else if (age >= 60) {
            final_fare = final_fare * 0.7;
printf("passenger: %s | base fare: rs%.0f | senior citizen discount applied", name, base_fare);
        } 
        else {
printf("passenger: %s | base fare: rs%.0f | no discount applied", name, base_fare);
        }

             if ((time >= 8 && time <= 10) || (time >= 17 && time <= 20)) {
            final_fare = final_fare * 1.2;
printf(" + peak hour surcharge applied");
        }

             if (final_fare < 20) {
            final_fare = 20;
        }

printf(" | final fare: rs%.2f\n", final_fare);

            total_revenue = total_revenue + final_fare;

        if (final_fare > highest_fare) {
            highest_fare = final_fare;
        }
        if (final_fare < lowest_fare) {
            lowest_fare = final_fare;
        }

        count++;
    }
printf("========= daily summary =========\n");
printf("total passengers: %d\n", total_passengers);
printf("total revenue collected: rs%.2f\n", total_revenue);
printf("highest fare: rs%.2f\n", highest_fare);
printf("lowest fare: rs%.2f\n", lowest_fare);
printf("=================================\n");

    return 0;
}
