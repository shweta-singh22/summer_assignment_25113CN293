#include <stdio.h>
int main() {
    long long num;
    long long sum = 0;
    printf("Enter an integer: ");
    if (scanf("%lld", &num) != 1) {
        return 1;
    }
    if (num <= 0) {
        printf("Not a perfect number\n");
        return 0;
    }
    for (long long i = 1; i <= num / 2; i++) {
        if (num % i == 0) {
            sum += i;
        }
    }
    if (sum == num) {
        printf("Perfect number\n");
    } else {
        printf("Not a perfect number\n");
    }
    return 0;
}