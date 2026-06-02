#include <stdio.h>
int main() {
    long long num;
    long long reversed = 0;
    long long original;
    long long remainder;
    printf("Enter an integer: ");
    if (scanf("%lld", &num) != 1) {
        return 1;
    }
    if (num < 0) {
        printf("Not a palindrome\n");
        return 0;
    }
    original = num;
    while (num != 0) {
        remainder = num % 10;
        reversed = reversed * 10 + remainder;
        num /= 10;
    }
    if (original == reversed) {
        printf("Palindrome\n");
    } else {
        printf("Not a palindrome\n");
    }
    return 0;
}