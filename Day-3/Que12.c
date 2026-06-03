#include <stdio.h>
int main() {
    long long num1, num2;
    long long a, b, temp, gcd, lcm;
    printf("Enter two integers: ");
    if (scanf("%lld %lld", &num1, &num2) !=2) {
     return 1;   
    }
    a = (num1 < 0) ? -num1 : num1;
    b = (num2 < 0) ? -num2 : num2;
    long long original_a = a;
    long long original_b = b;
    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp; 
    }
    gcd = a;
    if (gcd == 0) {
        lcm = 0;
    } else {
        lcm = (original_a / gcd) * original_b;
    }
    printf("LCM of %lld and %lld is %lld\n", num1, num2, lcm);
    return 0;
}