#include <stdio.h>

int main(void) {
    int seats[5][8];
    int i, j, freeRow, totalFree = 0;

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 8; j++) {
            do {
                printf("Enter status for row %d, seat %d (0 = empty, 1 = booked): ", i + 1, j + 1);
                if (scanf("%d", &seats[i][j]) != 1) {
                    return 1;
                }
            } while (seats[i][j] != 0 && seats[i][j] != 1);
        }
    }

    printf("\nSeating Map\n");
    for (i = 0; i < 5; i++) {
        freeRow = 0;
        printf("Row %d: ", i + 1);
        for (j = 0; j < 8; j++) {
            if (seats[i][j] == 0) {
                printf(". ");
                freeRow++;
            } else {
                printf("X ");
            }
        }
        printf("| Free seats: %d\n", freeRow);
        totalFree += freeRow;
    }

    printf("Total free seats: %d\n", totalFree);
    return 0;
}
