#include <stdio.h>
int main() {
    int num, i;
    unsigned long long factorial = 1;
    printf("Enter an integer: ");
    if (scanf("%d", &num) != 1) {
        return 1;
    }
    if (num<0) {
        printf("Error: Factorial of a negative number doesn't exist. \n");
        return 1;
    } else{
        for (i = 1; i <= num; ++i) {
            factorial *= i;
        }
        printf("Factorial of %d = %llu\n", num, factorial);
    }
    return 0;
}