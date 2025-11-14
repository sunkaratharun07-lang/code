#include <stdio.h>

int main() {
    int productid[10];
    char productname[10][50];
    int quantity[10];
    float price[10];

    int count = 0;
    int choice;
    int i;

    while (1) {
        printf("\n--- inventory menu ---\n");
        printf("1. add products\n");
        printf("2. display all products\n");
        printf("3. calculate inventory values\n");
        printf("4. search product by id\n");
        printf("5. exit\n");
        printf("enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            if (count >= 10) {
                printf("you cannot add more than 10 products.\n");
            } else {
                printf("enter product id: ");
                scanf("%d", &productid[count]);

                printf("enter product name: ");
                scanf("%s", productname[count]);

                printf("enter quantity: ");
                scanf("%d", &quantity[count]);

                printf("enter price: ");
                scanf("%f", &price[count]);

                count++;
            }
        }

        else if (choice == 2) {
            if (count == 0) {
                printf("no products available.\n");
            } else {
                printf("\n--- product list ---\n");
                for (i = 0; i < count; i++) {
                    printf("id: %d | name: %s | quantity: %d | price: %.2f\n",
                           productid[i], productname[i], quantity[i], price[i]);
                }
            }
        }

        else if (choice == 3) {
            if (count == 0) {
                printf("no products available.\n");
            } else {
                float totalvalue = 0;
                float highestvalue = quantity[0] * price[0];
                float lowestvalue = quantity[0] * price[0];
                int highindex = 0;
                int lowindex = 0;

                for (i = 0; i < count; i++) {
                    float value = quantity[i] * price[i];
                    totalvalue += value;

                    if (value > highestvalue) {
                        highestvalue = value;
                        highindex = i;
                    }
                    if (value < lowestvalue) {
                        lowestvalue = value;
                        lowindex = i;
                    }
                }

                printf("total inventory value: %.2f\n", totalvalue);

                printf("highest value product: %s (value = %.2f)\n",
                       productname[highindex], highestvalue);

                printf("lowest value product: %s (value = %.2f)\n",
                       productname[lowindex], lowestvalue);
            }
        }

        else if (choice == 4) {
            if (count == 0) {
                printf("no products available.\n");
            } else {
                int searchid;
                int found = 0;

                printf("enter product id to search: ");
                scanf("%d", &searchid);

                for (i = 0; i < count; i++) {
                    if (productid[i] == searchid) {
                        printf("product found:\n");
                        printf("id: %d | name: %s | quantity: %d | price: %.2f\n",
                               productid[i], productname[i], quantity[i], price[i]);
                        found = 1;
                        break;
                    }
                }

                if (found == 0) {
                    printf("product not found.\n");
                }
            }
        }

        else if (choice == 5) {
            printf("exiting...\n");
            break;
        }

        else {
            printf("invalid choice. try again.\n");
        }
    }

    return 0;
}
