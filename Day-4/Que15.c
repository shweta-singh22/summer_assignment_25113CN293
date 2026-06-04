  #include <stdio.h>
  int main() {
    long long num, originalNum, remainder, result = 0;
    int n = 0;
    printf("Enter an integer: ");
    if (scanf("%lld", &num) != 1) {
        return 1;
    }
    if (num < 0) {
        printf("Not an Armstrong number\n");
        return 0;
    }
    originalNum = num;
    // Count the number of digits
    long long temp = num;
    while (temp != 0) {
        temp /= 10;
        ++n;
    }
    // Handle case for 0
    if (num == 0) {
        n = 1;
    }
    temp = num;
    while (temp != 0) {
        remainder = temp % 10;
        // Compute power of remainder manually
        long long power = 1;
        for (int i = 0; i < n; i++) {
            power *= remainder;
        }
        result += power;
        temp /= 10;
    }
    if (result == originalNum) {
        printf("Armstrong number\n");
    } else {
        printf("Not an Armstrong number\n");
    }
    return 0;
  }