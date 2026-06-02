#include <stdio.h>
int main() {
    int num, i;
    printf("Enter the number: ");
    if (scanf("%d", &num) != 1) {
        return 1;
    }
    for(i=1; i<=10; i++) {
        printf("%d * %d = %d\n", num, i, num * i);
    }
    return 0;
}