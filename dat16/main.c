#include <stdio.h>

int main() {
    int prices[5] = {50, 30, 80, 120, 60};
    char items[5][20] = {"coffee", "tea", "sandwich", "burger", "pastry"};
    int total_quantity[5] = {0, 0, 0, 0, 0};

    int num_customers, i, j;
    int total_revenue = 0;

    printf("========= cafe order management system =========\n");
    printf("menu:\n");
    printf("item no.\titem name\tprice (rs)\n");
    for(i = 0; i < 5; i++) {
        printf("%d\t\t%s\t\t%d\n", i+1, items[i], prices[i]);
    }

    printf("\nenter total number of customers (max 10): ");
    scanf("%d", &num_customers);

    if(num_customers > 10) {
        printf("maximum of 10 customers allowed.\n");
        num_customers = 10;
    }

    for(i = 0; i < num_customers; i++) {
        int num_items, item_no, qty, total_bill = 0;

        printf("\n--- customer %d ---\n", i+1);
        printf("enter number of items: ");
        scanf("%d", &num_items);

        for(j = 0; j < num_items; j++) {
            printf("enter item number and quantity: ");
            scanf("%d %d", &item_no, &qty);

            if(item_no >= 1 && item_no <= 5) {
                total_bill += prices[item_no - 1] * qty;
                total_quantity[item_no - 1] += qty;
            } else {
                printf("invalid item number! skipping.\n");
            }
        }

        printf("total bill for customer %d: rs%d\n", i+1, total_bill);
        total_revenue += total_bill;
    }

    // calculating summary
    int most_index = 0, least_index = 0;
    int total_items_sold = 0;

    for(i = 0; i < 5; i++) {
        total_items_sold += total_quantity[i];
        if(total_quantity[i] > total_quantity[most_index]) {
            most_index = i;
        }
        if(total_quantity[i] < total_quantity[least_index]) {
            least_index = i;
        }
    }

    printf("\n========= cafe summary =========\n");
    printf("total revenue: rs%d\n", total_revenue);
    printf("total items sold: %d\n", total_items_sold);
    printf("most ordered item: %s\n", items[most_index]);
    printf("least ordered item: %s\n", items[least_index]);
    printf("================================\n");

    return 0;
}
