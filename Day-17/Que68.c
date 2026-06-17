#include <stdio.h>

int main() {
    int arr1[100], arr2[100];
    int n1, n2, found;

    printf("Enter size of first array: ");
    scanf("%d", &n1);

    printf("Enter elements of first array:\n");
    for(int i = 0; i < n1; i++) {
        scanf("%d", &arr1[i]);
    }

    printf("Enter size of second array: ");
    scanf("%d", &n2);

    printf("Enter elements of second array:\n");
    for(int i = 0; i < n2; i++) {
        scanf("%d", &arr2[i]);
    }

    printf("Common elements are:\n");

    for(int i = 0; i < n1; i++) {
        for(int j = 0; j < n2; j++) {
            if(arr1[i] == arr2[j]) {
                found = 0;

                // avoid duplicates in output
                for(int k = 0; k < i; k++) {
                    if(arr1[k] == arr1[i]) {
                        found = 1;
                        break;
                    }
                }

                if(!found) {
                    printf("%d ", arr1[i]);
                }
            }
        }
    }

    return 0;
}