#include <stdio.h>
int main() {
    long long lower, upper;
    printf("Enter lower limit and upper limit: ");
    if (scanf("%lld %lld", &lower, &upper) != 2) {
        return 1;
    }
    printf("Armstrong numbers between %lld and %lld are:\n", lower, upper);
    if (lower < 0) {
        lower = 0;
    }
    for (long long i = lower; i <= upper; i++) {
        long long temp = i;
        long long originalNum = i;
        long long remainder;
        long long result = 0;
        int n = 0;
        // Count number of digits
        if (temp == 0) {
            n = 1;
        } else {
            while (temp != 0) {
                temp /= 10;
                ++n;
            }
        }
        temp = originalNum;
        while (temp != 0) {
            remainder = temp % 10;
            // Compute power manually
            long long power = 1;
            for (int j = 0; j < n; j++) {
                power *= remainder;
            }
            result += power;
            temp /= 10;
        }
        if (result == originalNum) {
            printf("%lld", i);
        }
    }
    printf("\n");
    return 0;
}