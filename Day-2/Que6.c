#include <stdio.h>
int main() {
    long long num;
    long long reversed = 0;
    long long remainder;
    printf("Enter an integer: ");
    if (scanf("%lld", &num) !=1) {
        return 1;
    }
    int isNegative = 0;
    if (num < 0) {
        isNegative = 1;
        num = -num;
    }
    while (num != 0) {
        remainder = num % 10;
        reversed = reversed * 10 + remainder;
        num /= 10;
    }
    if (isNegative) {
        reversed = -reversed;
    }
    printf("Reversed number: %lld\n", reversed);
    return 0;
}

