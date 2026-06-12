#include <stdio.h>

int isPalindrome(int n) {
    int original = n, reversed = 0;

    while(n != 0) {
        reversed = reversed * 10 + (n % 10);
        n /= 10;
    }

    if(original == reversed)
        return 1;
    else
        return 0;
}

int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    if(isPalindrome(num))
        printf("Palindrome number");
    else
        printf("Not a palindrome number");

    return 0;
}