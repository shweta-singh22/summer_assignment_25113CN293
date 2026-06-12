#include <stdio.h>
#include <math.h>

int isArmstrong(int n) {
    int original = n, sum = 0, digits = 0, temp = n;

    // count digits
    while(temp != 0) {
        digits++;
        temp /= 10;
    }

    temp = n;

    // calculate sum of powers
    while(temp != 0) {
        int remainder = temp % 10;
        sum += pow(remainder, digits);
        temp /= 10;
    }

    if(sum == original)
        return 1;
    else
        return 0;
}

int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    if(isArmstrong(num))
        printf("Armstrong number");
    else
        printf("Not an Armstrong number");

    return 0;
}