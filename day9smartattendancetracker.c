#include <stdio.h>

int main()
{
    int totalstudents, studentcount = 1, presentdays;
    int eligiblecount = 0, noteligiblecount = 0;
    float attendancepercent, totalattendance = 0.0, averageattendance;

    printf("Enter total number of students: ");
    scanf("%d", &totalstudents);

    while (studentcount <= totalstudents)
    {
        printf("Enter attendance for student %d (out of 30): ", studentcount);
        scanf("%d", &presentdays);

        attendancepercent = (presentdays / 30.0) * 100.0;
        totalattendance = totalattendance + attendancepercent;

        if (attendancepercent >= 75.0)
        {
            printf("Student %d: %.2f%% - Eligible\n", studentcount, attendancepercent);
            eligiblecount++;
        }
        else
        {
            printf("Student %d: %.2f%% - Not Eligible\n", studentcount, attendancepercent);
            noteligiblecount++;
        }

        studentcount++;
    }

    averageattendance = totalattendance / totalstudents;

    printf("Class Summary:\n");
    printf("Total Students: %d\n", totalstudents);
    printf("Eligible Students: %d\n", eligiblecount);
    printf("Not Eligible: %d\n", noteligiblecount);
    printf("Average Attendance: %.2f%%\n", averageattendance);

    return 0;
}