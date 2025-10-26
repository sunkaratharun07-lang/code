#include <stdio.h>

int main() {
    float s1, s2, s3, s4, s5;
    float total, percentage, attendance; 
    char grade;

    
    printf("Enter marks of 5 subjects: ");
    scanf("%f %f %f %f %f", &s1, &s2, &s3, &s4, &s5);

    printf("Enter attendance percentage: ");
    scanf("%f", &attendance);

    
    if ((s1 >= 0 && s1 <= 100) && (s2 >= 0 && s2 <= 100) && 
        (s3 >= 0 && s3 <= 100) && (s4 >= 0 && s4 <= 100) && (s5 >= 0 && s5 <= 100))
 {

        total = s1 + s2 + s3 + s4 + s5;
        percentage = total / 5;

        
        if (attendance < 75) {
            grade = 'F';
            printf("Final Grade: %c\n", grade);
            printf("Remarks: Fail (Low Attendance)\n");
        } 
        else {
            
            if (percentage >= 45 && percentage <= 49 && attendance >= 90) {
                percentage = percentage + 5;
                if (percentage > 100)
                    percentage = 100;
            }

            
            if (percentage >= 90) {
                grade = 'A';
                printf("Final Grade: A+\n");
                printf("Remarks: Excellent\n");
            }

            else if (percentage >= 80) {
                grade = 'A';
                printf("Final Grade: %c\n", grade);
                printf("Remarks: Very Good\n");

            }
            else if (percentage >= 70) {
                grade = 'B';
                printf("Final Grade: %c\n", grade);
                printf("Remarks: Good\n");
            }
            else if (percentage >= 60) {
                grade = 'C';
                printf("Final Grade: %c\n", grade);
                printf("Remarks: Average\n");
            }
            else if (percentage >= 50) {
                grade = 'D';
                printf("Final Grade: %c\n", grade);
                printf("Remarks: Pass\n");
            }
            else {
                grade = 'F';
                printf("Final Grade: %c\n", grade);
                printf("Remarks: Fail\n");
            }
        }
    }
       return 0;
}
