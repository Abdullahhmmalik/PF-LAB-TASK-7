#include <stdio.h>

int main(void) {
    int rooms[4][6];
    int i, j, vacancies, maxVacancies = -1, bestFloor = 0, found = 0;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 6; j++) {
            do {
                printf("Enter room status for floor %d, room %d (1 = occupied, 0 = vacant): ", i + 1, j + 1);
                if (scanf("%d", &rooms[i][j]) != 1) {
                    return 1;
                }
            } while (rooms[i][j] != 0 && rooms[i][j] != 1);
        }
    }

    for (i = 0; i < 4; i++) {
        vacancies = 0;
        for (j = 0; j < 6; j++) {
            if (rooms[i][j] == 0) {
                vacancies++;
            }
        }
        printf("Floor %d vacancies: %d\n", i + 1, vacancies);
        if (vacancies > maxVacancies) {
            maxVacancies = vacancies;
            bestFloor = i;
        }
    }

    printf("Floor with the most vacancies: Floor %d (%d vacant rooms)\n", bestFloor + 1, maxVacancies);
    printf("Runs of at least 3 consecutive vacant rooms:\n");

    for (i = 0; i < 4; i++) {
        for (j = 0; j <= 3; j++) {
            if (rooms[i][j] == 0 && rooms[i][j + 1] == 0 && rooms[i][j + 2] == 0) {
                printf("Floor %d, starting room %d\n", i + 1, j + 1);
                found = 1;
            }
        }
    }

    if (!found) {
        printf("No floor has 3 or more consecutive vacant rooms.\n");
    }

    return 0;
}
