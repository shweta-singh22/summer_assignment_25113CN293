#include <stdio.h>
int main() {
    long long num;
    printf("Enter an integer: ");
    if (scanf("%lld", &num) != 1) {
        return 1;
    }
    // Handle negative numbers by converting to positive
    long long n = (num < 0) ? -num : num;
    if (n == 0) {
        printf("Every non-zero number is a factor of 0.\n");
        return 0;
    }
    printf("Factors of %lld are: ", num);
    for (long long i = 1; i <= n; i++) {
        if (n % i == 0) {
            // If original number was nrgative, factors can be both positive and negative.
            // Standard C programming lab assignments usually expect positive  factors.
            printf("%lld", i);
        }
    }
    printf("\n");
    return 0;
}