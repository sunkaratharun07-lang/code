
int main()
{
    int total_customers;
    int cust = 1;
    int total_rooms = 0;
    float total_revenue = 0;
    float highest_bill = 0;
    float lowest_bill = 0;

    printf("========= smart hotel room booking system =========\n");
    printf("enter total number of customers : ");
    scanf("%d", &total_customers);

    while (cust <= total_customers)
    {
        char name[50];
        int room_type, days;
        char breakfast, wifi, gym;
        float rate = 0, base_fare = 0, add_services = 0, subtotal = 0;
        float discount = 0, gst = 0, final_bill = 0;

        printf("\n--- customer %d ---\n", cust);
        printf("enter name : ");
        scanf("%s", name);

        printf("enter room type (1-deluxe, 2-super deluxe, 3-suite) : ");
        scanf("%d", &room_type);

        if (room_type == 1)
            rate = 2500;
        else if (room_type == 2)
            rate = 4000;
        else if (room_type == 3)
            rate = 6000;
        else
        {
            printf("invalid room type entered ! defaulting to deluxe room.\n");
            rate = 2500;
        }

        printf("enter number of days : ");
        scanf("%d", &days);

        printf("breakfast (y/n) : ");
        scanf(" %c", &breakfast);
        printf("wi-fi (y/n) : ");
        scanf(" %c", &wifi);
        printf("gym access (y/n) : ");
        scanf(" %c", &gym);

        base_fare = rate * days;

        if (breakfast == 'y' || breakfast == 'Y')
            add_services = add_services + (300 * days);
        if (wifi == 'y' || wifi == 'Y')
            add_services = add_services + (100 * days);
        if (gym == 'y' || gym == 'Y')
            add_services = add_services + (200 * days);

        subtotal = base_fare + add_services;

        if (subtotal > 10000)
            discount = 0.10 * subtotal;
        else
            discount = 0;

        gst = 0.12 * (subtotal - discount);
        final_bill = subtotal - discount + gst;

        printf("base fare : rs%.0f\n", base_fare);
        printf("additional services : rs%.0f\n", add_services);
        printf("subtotal : rs%.0f\n", subtotal);
        if (discount > 0)
            printf("discount (10%%) : rs%.0f\n", discount);
        else
            printf("discount : rs0\n");
        printf("gst (12%%) : rs%.0f\n", gst);
        printf("final bill : rs%.0f\n", final_bill);

        total_rooms = total_rooms + 1;
        total_revenue = total_revenue + final_bill;

        if (cust == 1)
        {
            highest_bill = final_bill;
            lowest_bill = final_bill;
        }
        else
        {
            if (final_bill > highest_bill)
                highest_bill = final_bill;
            if (final_bill < lowest_bill)
                lowest_bill = final_bill;
        }

        cust = cust + 1;
    }

    printf("\n========= hotel summary =========\n");
    printf("total rooms booked : %d\n", total_rooms);
    printf("total revenue : rs%.0f\n", total_revenue);
    printf("highest bill : rs%.0f\n", highest_bill);
    printf("lowest bill : rs%.0f\n", lowest_bill);
    printf("=================================\n");

    return 0;
}
