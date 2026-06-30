#include <stdio.h>
#include <string.h>

#define MAX 100

struct Student {
    int roll;
    char name[50];
    float marks;
};

int main() {
    struct Student s[MAX];
    int count = 0;
    int choice, i, roll, found;

    do {
        printf("\n===== STUDENT RECORD SYSTEM =====\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {

            case 1:
                if(count >= MAX) {
                    printf("❌ Record full!\n");
                    break;
                }
                printf("Enter Roll No: ");
                scanf("%d", &s[count].roll);
                printf("Enter Name: ");
                scanf("%s", s[count].name);
                printf("Enter Marks: ");
                scanf("%f", &s[count].marks);
                count++;
                printf("✅ Student added!\n");
                break;

            case 2:
                if(count == 0) {
                    printf("No records found!\n");
                    break;
                }
                printf("\n--- Student Records ---\n");
                for(i = 0; i < count; i++) {
                    printf("Roll: %d | Name: %s | Marks: %.2f\n",
                           s[i].roll, s[i].name, s[i].marks);
                }
                break;

            case 3:
                printf("Enter Roll No to search: ");
                scanf("%d", &roll);
                found = 0;

                for(i = 0; i < count; i++) {
                    if(s[i].roll == roll) {
                        printf("✅ Found: %s | Marks: %.2f\n",
                               s[i].name, s[i].marks);
                        found = 1;
                        break;
                    }
                }

                if(!found) {
                    printf("❌ Student not found!\n");
                }
                break;

            case 4:
                printf("Enter Roll No to update: ");
                scanf("%d", &roll);
                found = 0;

                for(i = 0; i < count; i++) {
                    if(s[i].roll == roll) {
                        printf("Enter new name: ");
                        scanf("%s", s[i].name);
                        printf("Enter new marks: ");
                        scanf("%f", &s[i].marks);
                        printf("✅ Record updated!\n");
                        found = 1;
                        break;
                    }
                }

                if(!found) {
                    printf("❌ Student not found!\n");
                }
                break;

            case 5:
                printf("Enter Roll No to delete: ");
                scanf("%d", &roll);
                found = 0;

                for(i = 0; i < count; i++) {
                    if(s[i].roll == roll) {
                        int j;
                        for(j = i; j < count - 1; j++) {
                            s[j] = s[j + 1];
                        }
                        count--;
                        printf("🗑️ Student deleted!\n");
                        found = 1;
                        break;
                    }
                }

                if(!found) {
                    printf("❌ Student not found!\n");
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