#include <stdio.h>

int main() {
    int totalcustomers,customercount=1;
    float totalrevenue=0;
    
printf("smart canteen billing system\n");
printf("enter total number of customers: ");
scanf("%d", &totalcustomers);

    while (customercount<=totalcustomers) {
     int numitems,itemcode,quantity,itemcount=1;
     float total=0,discount=0,finalbill=0,price;

printf("customer %d\n", customercount);
printf("Enter number of items: ");
scanf("%d", &numitems);


        while (itemcount<=numitems) {
printf("enter item code:");
scanf("%d", &itemcode);
printf("enter quantity: ");
scanf("%d", &quantity);

            if (itemcode == 1) {
   price = 80;
printf("Sandwich x %d = %.2f\n", quantity, price*quantity);
                total += price*quantity;
            } else if (itemcode == 2) {
   price = 120;
printf("Burger x %d = %.2f\n", quantity, price*quantity);
                total += price*quantity;
            } else if (itemcode == 3) {
   price = 150;
printf("Pizza Slice x %d = %.2f\n", quantity, price*quantity);
                total += price*quantity;
            } else if (itemcode == 4) {
   price = 60;
printf("Coffee x %d =%.2f\n", quantity, price*quantity);
                total += price*quantity;
            } else if (itemcode == 5) {
   price = 50;
printf("Juice x %d =%.2f\n", quantity, price*quantity);
                total += price * quantity;
            } else {
printf("invalid item code! Please try again.\n");
                itemcount--;
            }

            itemcount++;
        }

           if (total > 500) {
            discount = total*0.10;
        } else {
            discount = 0;
        }

        finalbill=total-discount;

printf("customer %d bill:\n", customercount);
printf("total: %.2f\n", total);
        if (discount > 0)
printf("discount (10%%): %.2f\n", discount);
printf("final bill: %.2f\n", finalbill);

        totalrevenue += finalbill;
        customercount++;
    }

printf("canteen summary\n");
printf("total customers served: %d\n", totalcustomers);
printf("total revenue:%.2f\n", totalrevenue);
   

    return 0;
}
