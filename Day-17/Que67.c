#include <stdio.h>

int main() {
    int arr1[100], arr2[100], inter[100];
    int n1, n2, k = 0, found;

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

    for(int i = 0; i < n1; i++) {
        found = 0;

        for(int j = 0; j < n2; j++) {
            if(arr1[i] == arr2[j]) {
                // check if already added
                for(int x = 0; x < k; x++) {
                    if(inter[x] == arr1[i]) {
                        found = 1;
                        break;
                    }
                }

                if(!found) {
                    inter[k++] = arr1[i];
                }
            }
        }
    }

    printf("Intersection of arrays:\n");
    for(int i = 0; i < k; i++) {
        printf("%d ", inter[i]);
    }

    return 0;
}