#include <stdio.h>
#include <string.h>

#define MAX 100

struct Book {
    int id;
    char name[50];
    int issued; // 0 = available, 1 = issued
};

int main() {
    struct Book b[MAX];
    int count = 0;
    int choice, i, id, found;

    do {
        printf("\n===== MINI LIBRARY SYSTEM =====\n");
        printf("1. Add Book\n");
        printf("2. View Books\n");
        printf("3. Search Book\n");
        printf("4. Issue Book\n");
        printf("5. Return Book\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {

            case 1:
                if(count >= MAX) {
                    printf("❌ Library full!\n");
                    break;
                }
                printf("Enter Book ID: ");
                scanf("%d", &b[count].id);
                printf("Enter Book Name: ");
                scanf("%s", b[count].name);
                b[count].issued = 0;
                count++;
                printf("✅ Book added!\n");
                break;

            case 2:
                if(count == 0) {
                    printf("No books available!\n");
                    break;
                }
                printf("\n--- Book List ---\n");
                for(i = 0; i < count; i++) {
                    printf("ID: %d | Name: %s | Status: %s\n",
                           b[i].id,
                           b[i].name,
                           b[i].issued ? "Issued" : "Available");
                }
                break;

            case 3:
                printf("Enter Book ID to search: ");
                scanf("%d", &id);
                found = 0;

                for(i = 0; i < count; i++) {
                    if(b[i].id == id) {
                        printf("✅ Found: %s | Status: %s\n",
                               b[i].name,
                               b[i].issued ? "Issued" : "Available");
                        found = 1;
                        break;
                    }
                }

                if(!found) {
                    printf("❌ Book not found!\n");
                }
                break;

            case 4:
                printf("Enter Book ID to issue: ");
                scanf("%d", &id);
                found = 0;

                for(i = 0; i < count; i++) {
                    if(b[i].id == id) {
                        if(b[i].issued == 0) {
                            b[i].issued = 1;
                            printf("📖 Book issued!\n");
                        } else {
                            printf("❌ Already issued!\n");
                        }
                        found = 1;
                        break;
                    }
                }

                if(!found) {
                    printf("❌ Book not found!\n");
                }
                break;

            case 5:
                printf("Enter Book ID to return: ");
                scanf("%d", &id);
                found = 0;

                for(i = 0; i < count; i++) {
                    if(b[i].id == id) {
                        if(b[i].issued == 1) {
                            b[i].issued = 0;
                            printf("📚 Book returned!\n");
                        } else {
                            printf("❌ Book was not issued!\n");
                        }
                        found = 1;
                        break;
                    }
                }

                if(!found) {
                    printf("❌ Book not found!\n");
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