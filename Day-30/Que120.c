#include <stdio.h>
#include <string.h>

#define MAX 100

struct Student {
    int roll;
    char name[50];
    float marks;
};

struct Student s[MAX];
int count = 0;

// Function to add student
void addStudent() {
    if(count >= MAX) {
        printf("❌ Record full!\n");
        return;
    }
    printf("Enter Roll No: ");
    scanf("%d", &s[count].roll);
    printf("Enter Name: ");
    scanf("%s", s[count].name);
    printf("Enter Marks: ");
    scanf("%f", &s[count].marks);
    count++;
    printf("✅ Student added!\n");
}

// Function to display students
void displayStudents() {
    if(count == 0) {
        printf("No records found!\n");
        return;
    }
    printf("\n--- Student Records ---\n");
    for(int i = 0; i < count; i++) {
        printf("Roll: %d | Name: %s | Marks: %.2f\n",
               s[i].roll, s[i].name, s[i].marks);
    }
}

// Function to search student
void searchStudent() {
    int roll, found = 0;
    printf("Enter Roll No to search: ");
    scanf("%d", &roll);

    for(int i = 0; i < count; i++) {
        if(s[i].roll == roll) {
            printf("✅ Found: %s | Marks: %.2f\n",
                   s[i].name, s[i].marks);
            found = 1;
            return;
        }
    }
    if(!found)
        printf("❌ Student not found!\n");
}

// Function to update student
void updateStudent() {
    int roll, found = 0;
    printf("Enter Roll No to update: ");
    scanf("%d", &roll);

    for(int i = 0; i < count; i++) {
        if(s[i].roll == roll) {
            printf("Enter new name: ");
            scanf("%s", s[i].name);
            printf("Enter new marks: ");
            scanf("%f", &s[i].marks);
            printf("✅ Record updated!\n");
            found = 1;
            return;
        }
    }
    if(!found)
        printf("❌ Student not found!\n");
}

// Function to delete student
void deleteStudent() {
    int roll, found = 0;
    printf("Enter Roll No to delete: ");
    scanf("%d", &roll);

    for(int i = 0; i < count; i++) {
        if(s[i].roll == roll) {
            for(int j = i; j < count - 1; j++) {
                s[j] = s[j + 1];
            }
            count--;
            printf("🗑️ Student deleted!\n");
            found = 1;
            return;
        }
    }
    if(!found)
        printf("❌ Student not found!\n");
}

// Main function
int main() {
    int choice;

    do {
        printf("\n===== MINI PROJECT MENU =====\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: updateStudent(); break;
            case 5: deleteStudent(); break;
            case 6: printf("🙏 Exiting...\n"); break;
            default: printf("❌ Invalid choice!\n");
        }

    } while(choice != 6);

    return 0;
}