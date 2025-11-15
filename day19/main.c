#include <stdio.h>

int main() {

    int attendance[5][5];
    int marks[5][5];
    char names[5][20];
    int i, j, ch;

    printf("enter names of 5 students:\n");
    for(i=0;i<5;i++){
        scanf("%s", names[i]);
    }

    printf("\nnow enter attendance (1 or 0):\n");
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            scanf("%d", &attendance[i][j]);
        }
    }

    printf("\nenter marks of all students:\n");
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            scanf("%d", &marks[i][j]);
        }
    }

    while(1){
        printf("\n========= menu =========\n");
        printf("1. display attendance matrix\n");
        printf("2. display marks matrix\n");
        printf("3. attendance report\n");
        printf("4. performance report\n");
        printf("5. grade report\n");
        printf("6. exit\n");
        printf("========================\n");
        printf("choice: ");
        scanf("%d", &ch);

        switch(ch){

            case 1:
                printf("\nattendance matrix:\n");
                for(i=0;i<5;i++){
                    for(j=0;j<5;j++){
                        printf("%d ", attendance[i][j]);
                    }
                    printf("\n");
                }
                break;

            case 2:
                printf("\nmarks matrix:\n");
                for(i=0;i<5;i++){
                    for(j=0;j<5;j++){
                        printf("%d ", marks[i][j]);
                    }
                    printf("\n");
                }
                break;

            case 3: {
                int pres[5], abs[5];
                int hi = 0, lo = 0;

                for(i=0;i<5;i++){
                    pres[i] = 0;
                    abs[i] = 0;
                    for(j=0;j<5;j++){
                        if(attendance[i][j] == 1) pres[i]++;
                        else abs[i]++;
                    }
                }

                for(i=1;i<5;i++){
                    if(pres[i] > pres[hi]) hi = i;
                    if(pres[i] < pres[lo]) lo = i;
                }

                printf("\nattendance report:\n");
                for(i=0;i<5;i++){
                    printf("%s : present %d, absent %d\n", names[i], pres[i], abs[i]);
                }

                printf("\nhighest attendance: %s\n", names[hi]);
                printf("lowest attendance: %s\n", names[lo]);
                }
                break;

            case 4: {
                int sum[5];
                int hi = 0, lo = 0;

                for(i=0;i<5;i++){
                    sum[i] = 0;
                    for(j=0;j<5;j++){
                        sum[i] += marks[i][j];
                    }
                }

                for(i=1;i<5;i++){
                    if(sum[i] > sum[hi]) hi = i;
                    if(sum[i] < sum[lo]) lo = i;
                }

                printf("\nperformance report:\n");
                for(i=0;i<5;i++){
                    printf("%s : total %d, average %.2f\n", names[i], sum[i], sum[i]/5.0);
                }

                printf("\nclass topper: %s\n", names[hi]);
                printf("lowest performer: %s\n", names[lo]);
                }
                break;

            case 5: {
                int total;
                float avg;
                char grade;

                printf("\ngrade report:\n");
                for(i=0;i<5;i++){
                    total = 0;
                    for(j=0;j<5;j++){
                        total += marks[i][j];
                    }

                    avg = total / 5.0;

                    if(avg >= 90) grade = 'A'+1;
                    else if(avg >= 80) grade = 'A';
                    else if(avg >= 70) grade = 'B';
                    else if(avg >= 60) grade = 'C';
                    else if(avg >= 50) grade = 'D';
                    else grade = 'F';

                    printf("%s -> %.2f : %c\n", names[i], avg, grade);
                }
                }
                break;

            case 6:
                return 0;

            default:
                printf("invalid\n");
        }
    }
}
