#include<stdio.h>
int main()
{
float mealcost,tax ,tip,totalbill, eachshare,you,friend1,friend2;

printf("enter meal cost:");
scanf("%f",&mealcost);

tax=mealcost*0.05;
tip=mealcost*0.10;
totalbill = mealcost+tax+tip;

eachshare = totalbill/3;

you=eachshare+(eachshare/2);
friend1=eachshare+(eachshare/2);
friend2=0;

printf("totalbill:%.2f\n",totalbill);
printf("bill to be pay as follows:\n");
printf("you: %.2f\n",you);
printf("friend1: %.2f\n",friend1);
printf("friend2: %.2f\n",friend2);

return 0;
}
