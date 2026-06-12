#include <stdio.h>

int isPerfect(int n) {
    int sum = 0;

    for(int i = 1; i <= n / 2; i++) {
        if(n % i == 0) {
            sum += i;
        }
    }

    if(sum == n && n != 0)
        return 1;
    else
        return 0;
}

int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    if(isPerfect(num))
        printf("Perfect number");
    else
        printf("Not a perfect number");

    return 0;
}