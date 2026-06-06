#include <stdio.h>
int main() {
    long long num, originalNum, remainder;
    long long totalSum = 0;
    printf("Enter an integer: ");
    if (scanf("%lld", &num) != 1) {
        return 1;
    }
    if (num <= 0) {
        if (num == 0) {
            printf("Not a strong number\n");
        } else {
            printf("Not a strong number\n");
        }
        return 0;
    }
    originalNum = num;
    while (num > 0) {
        remainder = num % 10;
        // Calculate factorial manually
        long long fact = 1;
        for (int i = 1; i <= remainder; i++) {
            fact *= i;
        }
        totalSum += fact;
        num /= 10;
    }
    if (totalSum == originalNum) {
        printf("Strong number\n");
    } else {
        printf("Not a strong number\n");
    }
    return 0;
}