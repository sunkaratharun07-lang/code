#include <stdio.h>

int main()
{
    int age, health;
    char gender;
    float premium;

    printf("Enter age: ");
    scanf("%d", &age);

    printf("enter gender (M/F): ");
    scanf(" %c", &gender); 
    printf("enter the health condition (1 if healthy / 0 if unhealthy): ");
    scanf("%d", &health);

    if (age < 25)
    {
        if (health== 1)
            premium = 5000;
        else
        {
            printf("not eligible for insurance\n");
            return 0;
        }
    }
    else if (age>= 25 && age <=40)
    {
        premium = (health == 1) ? 7000 : 9500;  
    }
    else if (age >= 41 && age <= 60)
    {
        premium = (health == 1) ? 10000 : 13000; 
    }
    else if (age > 60)
    {
        if (health == 0)
        {
            printf("not eligible for insurance.\n");
            return 0;
        }
        else
        {
            premium = 15000;
        }
    }

    if (gender == 'F')
    {
        premium=premium-(premium * 0.10);
    }

    printf("age: %d\n", age);
    printf("gender: %c\n", gender);
    printf("health: %s\n", (health == 1) ? "healthy" : "unhealthy");
    printf("final premium: %.2f\n", premium);

    return 0;
}
