#include <stdio.h>
#include <stdbool.h>
int main() {
    long long limit;
    printf("Enter the upper limit to find the largest prime number: ");
    if (scanf("%lld", &limit) != 1) {
        return 1;
    }
    if (limit < 2) {
        printf("No prime numbers exist below 2. \n");
        return 0;
    }
    // Loop bakwards from the limit to find the largest prime immediately
    for (long long i = limit; i>= 2; i--) {
        bool isPrime = true;
        for (long long j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) {
            printf("The largest prime number up to %lld is %lld\n", limit, i);
            return 0;
        }
    }
    return 0;
}