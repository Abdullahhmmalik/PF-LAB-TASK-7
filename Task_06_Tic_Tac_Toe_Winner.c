#include <stdio.h>

int main(void) {
    char board[3][3];
    int i, j, xWins = 0, oWins = 0;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            do {
                printf("Enter cell %d,%d (X, O, or -): ", i + 1, j + 1);
                if (scanf(" %c", &board[i][j]) != 1) {
                    return 1;
                }
            } while (board[i][j] != 'X' && board[i][j] != 'O' && board[i][j] != '-');
        }
    }

    for (i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            if (board[i][0] == 'X') {
                xWins = 1;
            } else if (board[i][0] == 'O') {
                oWins = 1;
            }
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            if (board[0][i] == 'X') {
                xWins = 1;
            } else if (board[0][i] == 'O') {
                oWins = 1;
            }
        }
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        if (board[0][0] == 'X') {
            xWins = 1;
        } else if (board[0][0] == 'O') {
            oWins = 1;
        }
    }

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        if (board[0][2] == 'X') {
            xWins = 1;
        } else if (board[0][2] == 'O') {
            oWins = 1;
        }
    }

    printf("\nBoard\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }

    if (xWins && oWins) {
        printf("Invalid board: both X and O have winning lines.\n");
    } else if (xWins) {
        printf("Winner: X\n");
    } else if (oWins) {
        printf("Winner: O\n");
    } else {
        printf("Draw\n");
    }

    return 0;
}
