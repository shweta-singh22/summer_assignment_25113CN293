#include <stdio.h>

int main() {
    int arr1[50], arr2[50], merged[100];
    int n1, n2, i, j, k;

    printf("Enter size of first array: ");
    scanf("%d", &n1);

    printf("Enter elements of first sorted array:\n");
    for(i = 0; i < n1; i++) {
        scanf("%d", &arr1[i]);
    }

    printf("Enter size of second array: ");
    scanf("%d", &n2);

    printf("Enter elements of second sorted array:\n");
    for(i = 0; i < n2; i++) {
        scanf("%d", &arr2[i]);
    }

    i = j = k = 0;

    // Merge arrays
    while(i < n1 && j < n2) {
        if(arr1[i] < arr2[j]) {
            merged[k++] = arr1[i++];
        } else {
            merged[k++] = arr2[j++];
        }
    }

    // Copy remaining elements
    while(i < n1) {
        merged[k++] = arr1[i++];
    }

    while(j < n2) {
        merged[k++] = arr2[j++];
    }

    // Print merged array
    printf("Merged array:\n");
    for(i = 0; i < k; i++) {
        printf("%d ", merged[i]);
    }

    return 0;
}