#include <stdio.h>
int main() {
    long long num;
    long long product = 1;
    long long remainder;
    int hasDigits = 0;
    printf("Enter an integer: ");
    if (scanf("%lld", &num) != 1) {
        return 1;
    }
    if (num == 0) {
        product = 0;
    } else {
        if (num < 0) {
            num = -num;
        }
        while (num != 0) {
            remainder = num % 10;
            product *= remainder;
            num /= 10;
            hasDigits = 1;
        }
    }
    printf("Product of digits: %lld\n", product);
    return 0;
}