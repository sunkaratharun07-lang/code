#include <stdio.h>

#define LIMIT 20

int prod_id[LIMIT];
int prod_qty[LIMIT];
int prod_price[LIMIT];
int total_products = 0;
int rack_data[3][3];

void add() {
    int pid, q, p;
    int i, exists = 0;

    if (total_products >= LIMIT) {
        printf("warehouse capacity reached\n");
        return;
    }

    printf("enter product id: ");
    scanf("%d", &pid);

    for (i = 0; i < total_products; i++) {
        if (prod_id[i] == pid) exists = 1;
    }

    if (exists) {
        printf("id already exists\n");
        return;
    }

    printf("enter quantity: ");
    scanf("%d", &q);
    printf("enter price: ");
    scanf("%d", &p);

    if (q <= 0 || p <= 0) {
        printf("invalid value\n");
        return;
    }

    prod_id[total_products] = pid;
    prod_qty[total_products] = q;
    prod_price[total_products] = p;
    total_products++;

    printf("product saved\n");
}

void search() {
    int pid, i;
    printf("enter id: ");
    scanf("%d", &pid);

    for (i = 0; i < total_products; i++) {
        if (prod_id[i] == pid) {
            printf("id:%d qty:%d price:%d\n", prod_id[i], prod_qty[i], prod_price[i]);
            return;
        }
    }
    printf("not found\n");
}

void update() {
    int pid, i, mode, amount;
    printf("enter id: ");
    scanf("%d", &pid);

    for (i = 0; i < total_products; i++) {

        if (prod_id[i] == pid) {
            printf("1 add  2 subtract: ");
            scanf("%d", &mode);

            printf("enter amount: ");
            scanf("%d", &amount);

            if (mode == 1) {
                prod_qty[i] += amount;
            } else if (mode == 2) {
                if (prod_qty[i] - amount >= 0)
                    prod_qty[i] -= amount;
                else {
                    printf("cannot reduce below zero\n");
                    return;
                }
            }
            printf("new quantity: %d\n", prod_qty[i]);
            return;
        }
    }
    printf("not found\n");
}

void rack_report() {
    int i, j;
    int max, min;
    int rmax = 0, cmax = 0, rmin = 0, cmin = 0;
    int total = 0;

    printf("enter 9 rack values:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            scanf("%d", &rack_data[i][j]);
        }
    }

    max = min = rack_data[0][0];

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            int v = rack_data[i][j];
            total += v;

            if (v > max) { max = v; rmax = i; cmax = j; }
            if (v < min) { min = v; rmin = i; cmin = j; }
        }
    }

    printf("max %d at (%d,%d)\n", max, rmax, cmax);
    printf("min %d at (%d,%d)\n", min, rmin, cmin);
    printf("total %d\n", total);
}

void stock_values() {
    int i;
    int maxv = -1, minv = 1000000000;
    int maxid = -1, minid = -1;
    long long grand = 0;

    for (i = 0; i < total_products; i++) {
        int val = prod_qty[i] * prod_price[i];
        printf("id:%d value:%d\n", prod_id[i], val);

        if (val > maxv) { maxv = val; maxid = prod_id[i]; }
        if (val < minv) { minv = val; minid = prod_id[i]; }

        grand += val;
    }

    printf("highest: id %d = %d\n", maxid, maxv);
    printf("lowest: id %d = %d\n", minid, minv);
    printf("total value: %lld\n", grand);
}

void show_all() {
    int i;
    printf("id qty price stockvalue\n");

    for (i = 0; i < total_products; i++) {
        printf("%d %d %d %d\n",
               prod_id[i],
               prod_qty[i],
               prod_price[i],
               prod_qty[i] * prod_price[i]);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n1 add 2 search 3 update 4 rack 5 values 6 show 7 exit\n");
        scanf("%d", &choice);

        if (choice == 1) add();
        else if (choice == 2) search();
        else if (choice == 3) update();
        else if (choice == 4) rack_report();
        else if (choice == 5) stock_values();
        else if (choice == 6) show_all();
        else if (choice == 7) break;
    }

    return 0;
}
