#include <stdio.h>
int main() {
    long long num1, num2;
    long long a, b, temp;
    printf("Enter two integer: ");
    if (scanf("%lld %lld", &num1, &num2) != 2) {
        return 1;
    }
    a = (num1 < 0) ? -num1 : num1;
    b = (num2 < 0) ? -num2 : num2;
    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    printf("GCD of %lld and %lld is %lld\n", num1, num2, a);
    return 0;
}