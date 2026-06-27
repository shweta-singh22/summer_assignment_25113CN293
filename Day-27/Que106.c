#include <stdio.h>
#include <string.h>

#define MAX_EMPLOYEES 100

struct Employee {
    int id;
    char name[50];
    char designation[30];
    float salary;
};

struct Employee employees[MAX_EMPLOYEES];
int employeeCount = 0;

void addEmployee() {
    if (employeeCount >= MAX_EMPLOYEES) {
        printf("System full! Cannot add more records.\n");
        return;
    }

    struct Employee e;
    printf("Enter Employee ID: ");
    if (scanf("%d", &e.id) != 1) return;

    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].id == e.id) {
            printf("Error: Employee with ID %d already exists!\n", e.id);
            return;
        }
    }

    printf("Enter Name: ");
    getchar(); 
    scanf("%[^\n]s", e.name);

    printf("Enter Designation: ");
    getchar();
    scanf("%[^\n]s", e.designation);

    printf("Enter Salary: ");
    if (scanf("%f", &e.salary) != 1) return;

    employees[employeeCount] = e;
    employeeCount++;

    printf("Employee record added successfully!\n");
}

void displayEmployees() {
    if (employeeCount == 0) {
        printf("No employee records found!\n");
        return;
    }

    printf("\n---------------------------------------------------------\n");
    printf("%-10s %-25s %-15s %-10s\n", "ID", "Name", "Designation", "Salary");
    printf("---------------------------------------------------------\n");
    
    for (int i = 0; i < employeeCount; i++) {
        printf("%-10d %-25s %-15s %-.2f\n", 
               employees[i].id, employees[i].name, employees[i].designation, employees[i].salary);
    }
    printf("---------------------------------------------------------\n");
}

void searchEmployee() {
    if (employeeCount == 0) {
        printf("No records available to search!\n");
        return;
    }

    int searchId;
    printf("Enter Employee ID to search: ");
    if (scanf("%d", &searchId) != 1) return;

    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].id == searchId) {
            printf("\nEmployee Found!\n");
            printf("ID          : %d\n", employees[i].id);
            printf("Name        : %s\n", employees[i].name);
            printf("Designation : %s\n", employees[i].designation);
            printf("Salary      : %.2f\n", employees[i].salary);
            return;
        }
    }

    printf("Employee with ID %d not found.\n", searchId);
}

int main() {
    int choice;

    while (1) {
        printf("\n=== Employee Management System ===\n");
        printf("1. Add Employee Record\n");
        printf("2. Display All Employee Records\n");
        printf("3. Search Employee by ID\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        
        if (scanf("%d", &choice) != 1) {
            return 1;
        }

        switch (choice) {
            case 1:
                addEmployee();
                break;
            case 2:
                displayEmployees();
                break;
            case 3:
                searchEmployee();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}