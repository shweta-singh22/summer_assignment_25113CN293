#include <stdio.h>
#include <stdbool.h>
int main() {
    long long lower, upper;
    printf("Enter lower limit and upper limit: ");
    if (scanf("%lld %lld", &lower, &upper) != 2) {
        return 1;
    }
    printf("Prime numbers between %lld and %lld are:\n", lower, upper);
    if (lower < 2) {
        lower = 2;
    }
    for (long long i = lower; i <= upper; i++) {
        bool isPrime = true;
        for (long long j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) {
            printf("%lld", i);
        }
    }
    printf("\n");
    return 0
}