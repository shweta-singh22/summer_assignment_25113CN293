#include <stdio.h>
#include <string.h>

#define MAX 100

struct Contact {
    char name[50];
    char phone[15];
};

int main() {
    struct Contact c[MAX];
    int count = 0;
    int choice, i, found;
    char searchName[50];

    do {
        printf("\n===== CONTACT MANAGEMENT SYSTEM =====\n");
        printf("1. Add Contact\n");
        printf("2. View Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {

            case 1:
                if(count >= MAX) {
                    printf("❌ Contact list full!\n");
                    break;
                }
                printf("Enter name: ");
                scanf("%s", c[count].name);
                printf("Enter phone: ");
                scanf("%s", c[count].phone);
                count++;
                printf("✅ Contact added!\n");
                break;

            case 2:
                if(count == 0) {
                    printf("No contacts available!\n");
                    break;
                }
                printf("\n--- Contact List ---\n");
                for(i = 0; i < count; i++) {
                    printf("%d. %s - %s\n", i+1, c[i].name, c[i].phone);
                }
                break;

            case 3:
                printf("Enter name to search: ");
                scanf("%s", searchName);
                found = 0;

                for(i = 0; i < count; i++) {
                    if(strcmp(c[i].name, searchName) == 0) {
                        printf("📞 Found: %s - %s\n", c[i].name, c[i].phone);
                        found = 1;
                        break;
                    }
                }

                if(!found) {
                    printf("❌ Contact not found!\n");
                }
                break;

            case 4:
                printf("Enter name to delete: ");
                scanf("%s", searchName);
                found = 0;

                for(i = 0; i < count; i++) {
                    if(strcmp(c[i].name, searchName) == 0) {
                        int j;
                        for(j = i; j < count - 1; j++) {
                            c[j] = c[j + 1];
                        }
                        count--;
                        printf("🗑️ Contact deleted!\n");
                        found = 1;
                        break;
                    }
                }

                if(!found) {
                    printf("❌ Contact not found!\n");
                }
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