#include <stdio.h>

int main() {
    int student,corporate;
    float dataused,extradata,extracost,totalbill,discount,basecost;
    char planname,Gold,Platinum,Silver;
    

    printf("monthly data used in GB:");
    scanf("%f", &dataused);

    printf("student status (1 for yes, 0 for no):");
    scanf("%d", &student);

    printf("corporate status (1 for yes, 0 for no):");
    scanf("%d", &corporate);

       if (dataused>100) {
        printf("excessive usage – plan not allowed\n");
    } 
    else {
        if (dataused<30) {
            basecost=299;
            planname=Silver;
            extradata = (dataused> 1*30) ? (dataused-30):0;
            extracost = (dataused >30) ? (dataused-30)*50:0;
        }
        else if (dataused >=30 && dataused<=60) {
            basecost = 499;
            planname=Gold;
            extracost = (dataused>60) ? (dataused-60)*40 : 0;
        }
        else {
            basecost = 799;
            planname=Platinum;
            extracost = (dataused >90) ? (dataused - 90)*30 : 0;
        }

            totalbill = basecost + extracost;

        if (student==1 && corporate ==1)
            discount = (0.15 > 0.10) ? 0.15 : 0.10; else if (student==1)
            discount=0.15;
        else if (corporate==1)
            discount = 0.10;
        else
            discount = 0.0;

        totalbill=totalbill-(totalbill*discount);

        printf("selected plan       : %s\n", planname);
        printf("monthly data used   : %.2f GB\n", dataused);
        printf("base plan cost      : %.2f\n", basecost);
        printf("extra data charges  : %.2f\n", extracost);
        printf("discount applied    : %.2f%%\n", discount * 100);
        printf("total payable amount: %.2f\n", totalbill);
    }

    return 0;
}
