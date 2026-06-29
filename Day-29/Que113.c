#include <stdio.h>

int main() {
    int choice;
    float a, b;

    do {
        printf("\n===== MENU DRIVEN CALCULATOR =====\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if(choice >= 1 && choice <= 4) {
            printf("Enter two numbers: ");
            scanf("%f %f", &a, &b);
        }

        switch(choice) {
            case 1:
                printf("Result = %.2f\n", a + b);
                break;

            case 2:
                printf("Result = %.2f\n", a - b);
                break;

            case 3:
                printf("Result = %.2f\n", a * b);
                break;

            case 4:
                if(b != 0)
                    printf("Result = %.2f\n", a / b);
                else
                    printf("❌ Division by zero not allowed!\n");
                break;

            case 5:
                printf("🙏 Exiting...\n");
                break;

            default:
                printf("❌ Invalid choice!\n");
        }

    } while(choice != 5);

    return 0;
}