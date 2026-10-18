#include <stdio.h>

int main(void) {
    int stock[3][4][5];
    int b, s, slot, total, fullestBuilding = 0, fullestShelf = 0;
    int fullestTotal = -1, found = 0;

    for (b = 0; b < 3; b++) {
        for (s = 0; s < 4; s++) {
            for (slot = 0; slot < 5; slot++) {
                printf("Enter item count for building %d, shelf %d, slot %d: ", b + 1, s + 1, slot + 1);
                if (scanf("%d", &stock[b][s][slot]) != 1) {
                    return 1;
                }
                if (stock[b][s][slot] < 0) {
                    printf("Item count cannot be negative.\n");
                    return 1;
                }
            }
        }
    }

    printf("\nTotal Stock per Building\n");
    for (b = 0; b < 3; b++) {
        total = 0;
        for (s = 0; s < 4; s++) {
            for (slot = 0; slot < 5; slot++) {
                total += stock[b][s][slot];
            }
        }
        printf("Building %d: %d\n", b + 1, total);
    }

    for (b = 0; b < 3; b++) {
        for (s = 0; s < 4; s++) {
            total = 0;
            for (slot = 0; slot < 5; slot++) {
                total += stock[b][s][slot];
            }
            if (total > fullestTotal) {
                fullestTotal = total;
                fullestBuilding = b;
                fullestShelf = s;
            }
        }
    }

    printf("Fullest shelf: Building %d, Shelf %d (Total items = %d)\n", fullestBuilding + 1, fullestShelf + 1, fullestTotal);
    printf("Slots needing restock:\n");

    for (b = 0; b < 3; b++) {
        for (s = 0; s < 4; s++) {
            for (slot = 0; slot < 5; slot++) {
                if (stock[b][s][slot] < 5) {
                    printf("Building %d, Shelf %d, Slot %d [%d][%d][%d]: needs restock\n",
                           b + 1, s + 1, slot + 1, b, s, slot);
                    found = 1;
                }
            }
        }
    }

    if (!found) {
        printf("No slots need restock.\n");
    }

    return 0;
}
