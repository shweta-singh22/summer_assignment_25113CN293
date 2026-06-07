#include <stdio.h>

int main() {
    int x, n;
    long long result = 1;

    printf("Enter base (x): ");
    scanf("%d", &x);

    printf("Enter power (n): ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Please enter a positive number.\n");
        return 1;
    }

    for(int i = 1; i <= n; i++) {
        result = result * x;
    }

    printf("Result: %lld", result);

    return 0;
}