#include <stdio.h>

int main() {
    int rows;

    printf("Enter number of rows: ");
    scanf("%d", &rows);

    for(int i = 1; i <= rows; i++) {
        // spaces
        for(int j = 1; j <= rows - i; j++) {
            printf(" ");
        }

        // increasing characters
        for(int j = 0; j < i; j++) {
            printf("%c", 'A' + j);
        }

        // decreasing characters
        for(int j = i - 2; j >= 0; j--) {
            printf("%c", 'A' + j);
        }

        printf("\n");
    }

    return 0;
}