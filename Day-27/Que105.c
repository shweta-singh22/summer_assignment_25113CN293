#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100

struct Student {
    int rollNo;
    char name[50];
    char branch[20];
    float gpa;
};

struct Student students[MAX_STUDENTS];
int studentCount = 0;

void addStudent() {
    if (studentCount >= MAX_STUDENTS) {
        printf("System full! Cannot add more records.\n");
        return;
    }

    struct Student s;
    printf("Enter Roll Number: ");
    if (scanf("%d", &s.rollNo) != 1) return;

    for (int i = 0; i < studentCount; i++) {
        if (students[i].rollNo == s.rollNo) {
            printf("Error: Student with Roll Number %d already exists!\n", s.rollNo);
            return;
        }
    }

    printf("Enter Name: ");
    getchar(); 
    scanf("%[^\n]s", s.name);

    printf("Enter Branch: ");
    scanf("%s", s.branch);

    printf("Enter GPA: ");
    if (scanf("%f", &s.gpa) != 1) return;

    students[studentCount] = s;
    studentCount++;

    printf("Student record added successfully!\n");
}

void displayStudents() {
    if (studentCount == 0) {
        printf("No student records found!\n");
        return;
    }

    printf("\n---------------------------------------------------------\n");
    printf("%-10s %-25s %-10s %-5s\n", "Roll No", "Name", "Branch", "GPA");
    printf("---------------------------------------------------------\n");
    
    for (int i = 0; i < studentCount; i++) {
        printf("%-10d %-25s %-10s %-.2f\n", 
               students[i].rollNo, students[i].name, students[i].branch, students[i].gpa);
    }
    printf("---------------------------------------------------------\n");
}

void searchStudent() {
    if (studentCount == 0) {
        printf("No records available to search!\n");
        return;
    }

    int searchRoll;
    printf("Enter Roll Number to search: ");
    if (scanf("%d", &searchRoll) != 1) return;

    for (int i = 0; i < studentCount; i++) {
        if (students[i].rollNo == searchRoll) {
            printf("\nStudent Found!\n");
            printf("Roll Number : %d\n", students[i].rollNo);
            printf("Name        : %s\n", students[i].name);
            printf("Branch      : %s\n", students[i].branch);
            printf("GPA         : %.2f\n", students[i].gpa);
            return;
        }
    }

    printf("Student with Roll Number %d not found.\n", searchRoll);
}

int main() {
    int choice;

    while (1) {
        printf("\n=== Student Record Management System ===\n");
        printf("1. Add Student Record\n");
        printf("2. Display All Student Records\n");
        printf("3. Search Student by Roll Number\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        
        if (scanf("%d", &choice) != 1) {
            return 1;
        }

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                searchStudent();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}