#include <stdio.h>

int main(void) {
    double temp[7][4];
    const char *slots[4] = {"Morning", "Noon", "Evening", "Night"};
    int i, j, hotDay = 0, hotSlot = 0, coldDay = 0, coldSlot = 0;
    double noonTotal = 0.0, noonAverage;

    for (i = 0; i < 7; i++) {
        for (j = 0; j < 4; j++) {
            printf("Enter temperature for day %d, %s: ", i + 1, slots[j]);
            if (scanf("%lf", &temp[i][j]) != 1) {
                return 1;
            }
        }
    }

    for (i = 0; i < 7; i++) {
        noonTotal += temp[i][1];
        for (j = 0; j < 4; j++) {
            if (temp[i][j] > temp[hotDay][hotSlot]) {
                hotDay = i;
                hotSlot = j;
            }
            if (temp[i][j] < temp[coldDay][coldSlot]) {
                coldDay = i;
                coldSlot = j;
            }
        }
    }

    noonAverage = noonTotal / 7.0;
    printf("\nHottest reading: %.2f on day %d, %s\n", temp[hotDay][hotSlot], hotDay + 1, slots[hotSlot]);
    printf("Coldest reading: %.2f on day %d, %s\n", temp[coldDay][coldSlot], coldDay + 1, slots[coldSlot]);
    printf("Weekly noon average: %.2f\n", noonAverage);
    printf("Days with noon temperature above the weekly noon average:\n");

    for (i = 0; i < 7; i++) {
        if (temp[i][1] > noonAverage) {
            printf("Day %d: %.2f\n", i + 1, temp[i][1]);
        }
    }

    return 0;
}
