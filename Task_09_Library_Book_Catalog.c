#include <stdio.h>
#include <ctype.h>

int main(void) {
    char titles[5][50];
    char searchLetter;
    int copies[5];
    int i, j, vowels, mostCopies = 0, found = 0;
    char ch;

    for (i = 0; i < 5; i++) {
        printf("Enter title of book %d: ", i + 1);
        if (scanf(" %49[^\n]", titles[i]) != 1) {
            return 1;
        }
        printf("Enter number of copies: ");
        if (scanf("%d", &copies[i]) != 1 || copies[i] < 0) {
            return 1;
        }
    }

    printf("\n%-5s %-35s %s\n", "No.", "Title", "Copies");
    for (i = 0; i < 5; i++) {
        printf("%-5d %-35s %d\n", i + 1, titles[i], copies[i]);
    }

    printf("\nVowel Count\n");
    for (i = 0; i < 5; i++) {
        vowels = 0;
        for (j = 0; titles[i][j] != '\0'; j++) {
            ch = (char)tolower((unsigned char)titles[i][j]);
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                vowels++;
            }
        }
        printf("%s: %d vowels\n", titles[i], vowels);
    }

    printf("\nEnter a letter to search for titles starting with it: ");
    if (scanf(" %c", &searchLetter) != 1) {
        return 1;
    }
    searchLetter = (char)tolower((unsigned char)searchLetter);

    printf("Matching titles:\n");
    for (i = 0; i < 5; i++) {
        if (tolower((unsigned char)titles[i][0]) == searchLetter) {
            printf("%s\n", titles[i]);
            found = 1;
        }
    }
    if (!found) {
        printf("No titles start with that letter.\n");
    }

    for (i = 1; i < 5; i++) {
        if (copies[i] > copies[mostCopies]) {
            mostCopies = i;
        }
    }
    printf("Title with the most copies: %s (%d copies)\n", titles[mostCopies], copies[mostCopies]);

    return 0;
}
