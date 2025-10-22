#include<stdio.h>
int main()
{
    float basic_salary, hra_percent, da_percent, tax_percent;
    float hra, da, tax, gross_salary;
    float net_monthlysalary;
    int is_above_50000;
    
    printf("enter basic salary:");
    scanf("%f",&basic_salary);

    printf("enter hra%%:");
    scanf("%f",&hra_percent);

    printf("enter da%%:");
    scanf("%f",&da_percent);

    printf("enter tax%%:");
    scanf("%f",&tax_percent);

    hra = basic_salary*(hra_percent/100);
    da = basic_salary *(da_percent/100);
    tax= basic_salary*(tax_percent/100);
    gross_salary = basic_salary+ hra + da - tax;

    if(gross_salary>50000)
    is_above_50000=1;
    else
    is_above_50000=0;

    net_monthlysalary=gross_salary/12;

    printf("hra=%.2f",hra);
    printf("da=%.2f",da);
    printf("tax=%.2f",tax);
    printf("gross_salary=%.2f",gross_salary);
    printf("is gross salary above 50000? %d\n", is_above_50000);
    printf("net monthly salary = %.2f\n",net_monthlysalary);

    return 0;
}
