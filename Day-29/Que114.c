#include <stdio.h>

#define MAX 100

int main() {
    int arr[MAX], n = 0;
    int choice, i, num, found;
    int sum, max, min;

    do {
        printf("\n===== ARRAY OPERATIONS MENU =====\n");
        printf("1. Insert Elements\n");
        printf("2. Display Array\n");
        printf("3. Sum and Average\n");
        printf("4. Largest and Smallest\n");
        printf("5. Linear Search\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {

            case 1:
                printf("Enter number of elements: ");
                scanf("%d", &n);
                printf("Enter elements:\n");
                for(i = 0; i < n; i++) {
                    scanf("%d", &arr[i]);
                }
                break;

            case 2:
                if(n == 0) {
                    printf("Array is empty!\n");
                    break;
                }
                printf("Array elements: ");
                for(i = 0; i < n; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;

            case 3:
                if(n == 0) {
                    printf("Array is empty!\n");
                    break;
                }
                sum = 0;
                for(i = 0; i < n; i++) {
                    sum += arr[i];
                }
                printf("Sum = %d\n", sum);
                printf("Average = %.2f\n", (float)sum / n);
                break;

            case 4:
                if(n == 0) {
                    printf("Array is empty!\n");
                    break;
                }
                max = min = arr[0];
                for(i = 1; i < n; i++) {
                    if(arr[i] > max) max = arr[i];
                    if(arr[i] < min) min = arr[i];
                }
                printf("Largest = %d\n", max);
                printf("Smallest = %d\n", min);
                break;

            case 5:
                if(n == 0) {
                    printf("Array is empty!\n");
                    break;
                }
                printf("Enter element to search: ");
                scanf("%d", &num);
                found = 0;
                for(i = 0; i < n; i++) {
                    if(arr[i] == num) {
                        printf("✅ Found at position %d\n", i + 1);
                        found = 1;
                        break;
                    }
                }
                if(!found) {
                    printf("❌ Element not found!\n");
                }
                break;

            case 6:
                printf("🙏 Exiting...\n");
                break;

            default:
                printf("❌ Invalid choice!\n");
        }

    } while(choice != 6);

    return 0;
}