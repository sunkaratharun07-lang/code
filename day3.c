#include<stdio.h>
int main()
{
float units,totalbill,charge;
float fixedmetercharge = 50;

printf("Total units used:");
scanf("%f",&units);

if (units <= 100) 
charge = units*3;
else if (units <= 200)
charge = (100*3) + ((units-100)*4.5);
else if (units <= 300)
charge = (100*3)+(200*4.5) + ((units-200)*6);
else if (units > 300)
charge = (100*3) + (200*4.5) + (300*6) + ((units-300)*8);

totalbill = charge+ fixedmetercharge;

printf("units used:%.0f\n",units);
printf("your total bill is:%.2f",totalbill);

return 0;
}