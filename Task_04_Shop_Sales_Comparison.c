#include <stdio.h>

int main(void) {
    double sales[3][5];
    double branchTotals[3] = {0.0, 0.0, 0.0};
    double productTotals[5] = {0.0, 0.0, 0.0, 0.0, 0.0};
    int i, j, bestBranch = 0, lowestProduct = 0;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 5; j++) {
            printf("Enter sales for branch %d, product %d: ", i + 1, j + 1);
            if (scanf("%lf", &sales[i][j]) != 1) {
                return 1;
            }
            branchTotals[i] += sales[i][j];
            productTotals[j] += sales[i][j];
        }
    }

    printf("\nTotal Sales per Branch\n");
    for (i = 0; i < 3; i++) {
        printf("Branch %d: %.2f\n", i + 1, branchTotals[i]);
        if (branchTotals[i] > branchTotals[bestBranch]) {
            bestBranch = i;
        }
    }

    printf("\nTotal Sales per Product\n");
    for (j = 0; j < 5; j++) {
        printf("Product %d: %.2f\n", j + 1, productTotals[j]);
        if (productTotals[j] < productTotals[lowestProduct]) {
            lowestProduct = j;
        }
    }

    printf("Best-selling branch: Branch %d (Total = %.2f)\n", bestBranch + 1, branchTotals[bestBranch]);
    printf("Product with lowest overall sales: Product %d (Total = %.2f)\n", lowestProduct + 1, productTotals[lowestProduct]);
    return 0;
}
