#include <stdio.h>
#include <stdbool.h>
int main() {
    long long num;
    bool isPrime = true;
    printf("Enter an integer: ");
    if (scanf("%lld", &num) != 1) {
        return 1;
    }
    if (num <= 1) {
        isPrime = false;
    } else {
        for (long long i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                isPrime = false;
                break;
            }
        }
    }
    if (isPrime) {
        printf("Prime\n");
    } else {
        printf("Not a prime\n");
    }
    return 0;
}