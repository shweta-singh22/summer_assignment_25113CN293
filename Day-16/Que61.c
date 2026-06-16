#include <stdio.h>

int main() {
    int n, arr[100];
    int sum = 0, total = 0, missing;

    printf("Enter number of elements (n-1): ");
    scanf("%d", &n);

    printf("Enter elements (from 1 to n with one missing):\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    // total sum from 1 to n+1
    int N = n + 1;
    total = (N * (N + 1)) / 2;

    missing = total - sum;

    printf("Missing number = %d", missing);

    return 0;
}