#include <stdio.h>

int main() {
    int a[10][10];
    int n, i, j;
    int primarySum = 0, secondarySum = 0;

    printf("Enter order of square matrix: ");
    scanf("%d", &n);

    printf("Enter matrix elements:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    // Finding diagonal sums
    for(i = 0; i < n; i++) {
        primarySum += a[i][i];               // Main diagonal
        secondarySum += a[i][n - i - 1];     // Secondary diagonal
    }

    printf("Primary diagonal sum = %d\n", primarySum);
    printf("Secondary diagonal sum = %d\n", secondarySum);

    return 0;
}