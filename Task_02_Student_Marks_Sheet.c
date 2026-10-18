#include <stdio.h>

int main(void) {
    int marks[6][4];
    int i, j, total, bestSubject = 0;
    double subjectTotals[4] = {0.0, 0.0, 0.0, 0.0};
    double bestAverage;

    for (i = 0; i < 6; i++) {
        for (j = 0; j < 4; j++) {
            printf("Enter marks for student %d, subject %d: ", i + 1, j + 1);
            if (scanf("%d", &marks[i][j]) != 1) {
                return 1;
            }
            subjectTotals[j] += marks[i][j];
        }
    }

    printf("\nStudent Results\n");
    for (i = 0; i < 6; i++) {
        total = 0;
        for (j = 0; j < 4; j++) {
            total += marks[i][j];
        }
        printf("Student %d: Total = %d, Average = %.2f\n", i + 1, total, total / 4.0);
    }

    printf("\nSubject Class Averages\n");
    bestAverage = subjectTotals[0] / 6.0;
    for (j = 0; j < 4; j++) {
        double average = subjectTotals[j] / 6.0;
        printf("Subject %d: %.2f\n", j + 1, average);
        if (average > bestAverage) {
            bestAverage = average;
            bestSubject = j;
        }
    }

    printf("Best-performing subject: Subject %d (Average = %.2f)\n", bestSubject + 1, bestAverage);
    return 0;
}
