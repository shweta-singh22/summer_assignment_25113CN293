#include <stdio.h>
#include <string.h>

#define MAX 100

struct Book {
    int id;
    char name[50];
    char author[50];
    int issued; // 0 = available, 1 = issued
};

int main() {
    struct Book b[MAX];
    int count = 0, choice, i, id, found;

    do {
        printf("\n===== LIBRARY MANAGEMENT SYSTEM =====\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Search Book\n");
        printf("4. Issue Book\n");
        printf("5. Return Book\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {

            case 1:
                if(count < MAX) {
                    printf("Enter Book ID: ");
                    scanf("%d", &b[count].id);
                    printf("Enter Book Name: ");
                    scanf("%s", b[count].name);
                    printf("Enter Author Name: ");
                    scanf("%s", b[count].author);
                    b[count].issued = 0;
                    count++;
                    printf("✅ Book added!\n");
                } else {
                    printf("❌ Library full!\n");
                }
                break;

            case 2:
                if(count == 0) {
                    printf("No books available!\n");
                } else {
                    printf("\n--- Book List ---\n");
                    for(i = 0; i < count; i++) {
                        printf("ID: %d | Name: %s | Author: %s | Status: %s\n",
                               b[i].id, b[i].name, b[i].author,
                               b[i].issued ? "Issued" : "Available");
                    }
                }
                break;

            case 3:
                printf("Enter Book ID to search: ");
                scanf("%d", &id);
                found = 0;
                for(i = 0; i < count; i++) {
                    if(b[i].id == id) {
                        printf("Found: %d %s %s (%s)\n",
                               b[i].id, b[i].name, b[i].author,
                               b[i].issued ? "Issued" : "Available");
                        found = 1;
                        break;
                    }
                }
                if(!found) printf("❌ Book not found!\n");
                break;

            case 4:
                printf("Enter Book ID to issue: ");
                scanf("%d", &id);
                found = 0;
                for(i = 0; i < count; i++) {
                    if(b[i].id == id) {
                        if(b[i].issued) {
                            printf("❌ Already issued!\n");
                        } else {
                            b[i].issued = 1;
                            printf("✅ Book issued!\n");
                        }
                        found = 1;
                        break;
                    }
                }
                if(!found) printf("❌ Book not found!\n");
                break;

            case 5:
                printf("Enter Book ID to return: ");
                scanf("%d", &id);
                found = 0;
                for(i = 0; i < count; i++) {
                    if(b[i].id == id) {
                        if(!b[i].issued) {
                            printf("❌ Book was not issued!\n");
                        } else {
                            b[i].issued = 0;
                            printf("✅ Book returned!\n");
                        }
                        found = 1;
                        break;
                    }
                }
                if(!found) printf("❌ Book not found!\n");
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