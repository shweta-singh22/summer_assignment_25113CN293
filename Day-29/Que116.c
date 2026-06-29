#include <stdio.h>
#include <string.h>

#define MAX 100

struct Product {
    int id;
    char name[50];
    int quantity;
    float price;
};

int main() {
    struct Product p[MAX];
    int count = 0;
    int choice, i, id, found;

    do {
        printf("\n===== INVENTORY MANAGEMENT SYSTEM =====\n");
        printf("1. Add Product\n");
        printf("2. View Products\n");
        printf("3. Search Product\n");
        printf("4. Update Quantity\n");
        printf("5. Delete Product\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {

            case 1:
                if(count >= MAX) {
                    printf("❌ Inventory full!\n");
                    break;
                }
                printf("Enter Product ID: ");
                scanf("%d", &p[count].id);
                printf("Enter Product Name: ");
                scanf("%s", p[count].name);
                printf("Enter Quantity: ");
                scanf("%d", &p[count].quantity);
                printf("Enter Price: ");
                scanf("%f", &p[count].price);
                count++;
                printf("✅ Product added!\n");
                break;

            case 2:
                if(count == 0) {
                    printf("No products available!\n");
                    break;
                }
                printf("\n--- Product List ---\n");
                for(i = 0; i < count; i++) {
                    printf("ID: %d | Name: %s | Qty: %d | Price: %.2f\n",
                           p[i].id, p[i].name, p[i].quantity, p[i].price);
                }
                break;

            case 3:
                printf("Enter Product ID to search: ");
                scanf("%d", &id);
                found = 0;

                for(i = 0; i < count; i++) {
                    if(p[i].id == id) {
                        printf("✅ Found: %s | Qty: %d | Price: %.2f\n",
                               p[i].name, p[i].quantity, p[i].price);
                        found = 1;
                        break;
                    }
                }

                if(!found) {
                    printf("❌ Product not found!\n");
                }
                break;

            case 4:
                printf("Enter Product ID to update: ");
                scanf("%d", &id);
                found = 0;

                for(i = 0; i < count; i++) {
                    if(p[i].id == id) {
                        printf("Enter new quantity: ");
                        scanf("%d", &p[i].quantity);
                        printf("✅ Quantity updated!\n");
                        found = 1;
                        break;
                    }
                }

                if(!found) {
                    printf("❌ Product not found!\n");
                }
                break;

            case 5:
                printf("Enter Product ID to delete: ");
                scanf("%d", &id);
                found = 0;

                for(i = 0; i < count; i++) {
                    if(p[i].id == id) {
                        int j;
                        for(j = i; j < count - 1; j++) {
                            p[j] = p[j + 1];
                        }
                        count--;
                        printf("🗑️ Product deleted!\n");
                        found = 1;
                        break;
                    }
                }

                if(!found) {
                    printf("❌ Product not found!\n");
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