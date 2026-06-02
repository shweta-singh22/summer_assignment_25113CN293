#include <stdio.h>
int main() {
    long long num;
    int sum = 0, remainder;
    printf("Enter an integer: ");
    if (scanf("%lld", &num) != 1) {
        return 1;
    }
    if (num < 0) {
        num = -num;
    }
    while (num != 0) {
        remainder = num % 10;
        sum += remainder;
        num /= 10;
    }
    printf("Sum of digits : %d\n", sum);
    return 0;
}