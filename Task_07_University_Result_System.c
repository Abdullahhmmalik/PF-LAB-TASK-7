#include <stdio.h>

int main(void) {
    int marks[3][4][5];
    int d, s, sub, total, failed;
    double studentAverage, departmentTotals[3] = {0.0, 0.0, 0.0};
    double departmentAverages[3], highestDepartmentAverage;
    int topper[3] = {0, 0, 0};
    double topperAverage[3] = {-1.0, -1.0, -1.0};
    int highestDepartment = 0;

    for (d = 0; d < 3; d++) {
        for (s = 0; s < 4; s++) {
            for (sub = 0; sub < 5; sub++) {
                printf("Enter marks for department %d, student %d, subject %d: ", d + 1, s + 1, sub + 1);
                if (scanf("%d", &marks[d][s][sub]) != 1) {
                    return 1;
                }
            }
        }
    }

    printf("\nStudent Results\n");
    for (d = 0; d < 3; d++) {
        for (s = 0; s < 4; s++) {
            total = 0;
            failed = 0;
            for (sub = 0; sub < 5; sub++) {
                total += marks[d][s][sub];
                if (marks[d][s][sub] < 40) {
                    failed = 1;
                }
            }
            studentAverage = total / 5.0;
            departmentTotals[d] += studentAverage;
            printf("Department %d, Student %d: Average = %.2f", d + 1, s + 1, studentAverage);
            if (failed) {
                printf(" FAIL");
            }
            printf("\n");
            if (studentAverage > topperAverage[d]) {
                topperAverage[d] = studentAverage;
                topper[d] = s;
            }
        }
        departmentAverages[d] = departmentTotals[d] / 4.0;
        printf("Topper of Department %d: Student %d (Average = %.2f)\n", d + 1, topper[d] + 1, topperAverage[d]);
    }

    highestDepartmentAverage = departmentAverages[0];
    for (d = 1; d < 3; d++) {
        if (departmentAverages[d] > highestDepartmentAverage) {
            highestDepartmentAverage = departmentAverages[d];
            highestDepartment = d;
        }
    }

    printf("Department with highest overall average: Department %d (Average = %.2f)\n", highestDepartment + 1, highestDepartmentAverage);
    return 0;
}
