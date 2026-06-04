#include <stdio.h>
int main() {
    int n;
    long long t1 = 0, t2 = 1, nextTerm;
    printf("Enter the value of n: ");
    if (scanf("%d", &n) != 1) {
        return 1;
    }
    if ( n < 1) {
        printf("Invalid input\n");
        return 0;
    }
    if (n == 1) {
        printf("The 1st Fibonacci term is %lld\n", t1);
        return 0;
    }
    for (int i = 3; i <= n; ++i) {
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
    }
    printf("The %dth Fibonnaci term is %lld\n", n t2);
    return 0;
}