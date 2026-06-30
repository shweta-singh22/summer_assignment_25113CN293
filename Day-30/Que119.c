#include <stdio.h>
#include <string.h>

#define MAX 100

struct Employee {
    int id;
    char name[50];
    float salary;
};

int main() {
    struct Employee e[MAX];
    int count = 0;
    int choice, i, id, found;

    do {
        printf("\n===== EMPLOYEE MANAGEMENT SYSTEM =====\n");
        printf("1. Add Employee\n");
        printf("2. View Employees\n");
        printf("3. Search Employee\n");
        printf("4. Update Employee\n");
        printf("5. Delete Employee\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {

            case 1:
                if(count >= MAX) {
                    printf("❌ Record full!\n");
                    break;
                }
                printf("Enter Employee ID: ");
                scanf("%d", &e[count].id);
                printf("Enter Name: ");
                scanf("%s", e[count].name);
                printf("Enter Salary: ");
                scanf("%f", &e[count].salary);
                count++;
                printf("✅ Employee added!\n");
                break;

            case 2:
                if(count == 0) {
                    printf("No records found!\n");
                    break;
                }
                printf("\n--- Employee List ---\n");
                for(i = 0; i < count; i++) {
                    printf("ID: %d | Name: %s | Salary: %.2f\n",
                           e[i].id, e[i].name, e[i].salary);
                }
                break;

            case 3:
                printf("Enter Employee ID to search: ");
                scanf("%d", &id);
                found = 0;

                for(i = 0; i < count; i++) {
                    if(e[i].id == id) {
                        printf("✅ Found: %s | Salary: %.2f\n",
                               e[i].name, e[i].salary);
                        found = 1;
                        break;
                    }
                }

                if(!found) {
                    printf("❌ Employee not found!\n");
                }
                break;

            case 4:
                printf("Enter Employee ID to update: ");
                scanf("%d", &id);
                found = 0;

                for(i = 0; i < count; i++) {
                    if(e[i].id == id) {
                        printf("Enter new name: ");
                        scanf("%s", e[i].name);
                        printf("Enter new salary: ");
                        scanf("%f", &e[i].salary);
                        printf("✅ Record updated!\n");
                        found = 1;
                        break;
                    }
                }

                if(!found) {
                    printf("❌ Employee not found!\n");
                }
                break;

            case 5:
                printf("Enter Employee ID to delete: ");
                scanf("%d", &id);
                found = 0;

                for(i = 0; i < count; i++) {
                    if(e[i].id == id) {
                        int j;
                        for(j = i; j < count - 1; j++) {
                            e[j] = e[j + 1];
                        }
                        count--;
                        printf("🗑️ Employee deleted!\n");
                        found = 1;
                        break;
                    }
                }

                if(!found) {
                    printf("❌ Employee not found!\n");
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