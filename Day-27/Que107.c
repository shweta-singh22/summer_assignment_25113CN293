#include <stdio.h>
#include <string.h>

#define MAX_EMPLOYEES 100

struct SalaryRecord {
    int id;
    char name[50];
    float basicSalary;
    float allowances;
    float deductions;
    float netSalary;
};

struct SalaryRecord records[MAX_EMPLOYEES];
int recordCount = 0;

void calculateNetSalary(struct SalaryRecord *r) {
    r->netSalary = r->basicSalary + r->allowances - r->deductions;
}

void addSalaryRecord() {
    if (recordCount >= MAX_EMPLOYEES) {
        printf("System full! Cannot add more records.\n");
        return;
    }

    struct SalaryRecord r;
    printf("Enter Employee ID: ");
    if (scanf("%d", &r.id) != 1) return;

    for (int i = 0; i < recordCount; i++) {
        if (records[i].id == r.id) {
            printf("Error: Salary record for Employee ID %d already exists!\n", r.id);
            return;
        }
    }

    printf("Enter Name: ");
    getchar(); 
    scanf("%[^\n]s", r.name);

    printf("Enter Basic Salary: ");
    if (scanf("%f", &r.basicSalary) != 1) return;

    printf("Enter Allowances: ");
    if (scanf("%f", &r.allowances) != 1) return;

    printf("Enter Deductions: ");
    if (scanf("%f", &r.deductions) != 1) return;

    calculateNetSalary(&r);

    records[recordCount] = r;
    recordCount++;

    printf("Salary record added successfully!\n");
}

void displaySalarySlips() {
    if (recordCount == 0) {
        printf("No salary records found!\n");
        return;
    }

    printf("\n-----------------------------------------------------------------------------\n");
    printf("%-10s %-20s %-12s %-12s %-12s %-12s\n", "ID", "Name", "Basic", "Allowances", "Deductions", "Net Salary");
    printf("-----------------------------------------------------------------------------\n");
    
    for (int i = 0; i < recordCount; i++) {
        printf("%-10d %-20s %-12.2f %-12.2f %-12.2f %-12.2f\n", 
               records[i].id, records[i].name, records[i].basicSalary, records[i].allowances, records[i].deductions, records[i].netSalary);
    }
    printf("-----------------------------------------------------------------------------\n");
}

void searchSalaryRecord() {
    if (recordCount == 0) {
        printf("No records available to search!\n");
        return;
    }

    int searchId;
    printf("Enter Employee ID to search salary details: ");
    if (scanf("%d", &searchId) != 1) return;

    for (int i = 0; i < recordCount; i++) {
        if (records[i].id == searchId) {
            printf("\n--- Salary Slip Found ---\n");
            printf("ID           : %d\n", records[i].id);
            printf("Name         : %s\n", records[i].name);
            printf("Basic Salary : %.2f\n", records[i].basicSalary);
            printf("Allowances   : %.2f\n", records[i].allowances);
            printf("Deductions   : %.2f\n", records[i].deductions);
            printf("-------------------------\n");
            printf("Net Salary   : %.2f\n", records[i].netSalary);
            return;
        }
    }

    printf("Salary record for Employee ID %d not found.\n", searchId);
}

int main() {
    int choice;

    while (1) {
        printf("\n=== Salary Management System ===\n");
        printf("1. Add Salary Record\n");
        printf("2. Display All Salary Slips\n");
        printf("3. Search Salary Record by ID\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        
        if (scanf("%d", &choice) != 1) {
            return 1;
        }

        switch (choice) {
            case 1:
                addSalaryRecord();
                break;
            case 2:
                displaySalarySlips();
                break;
            case 3:
                searchSalaryRecord();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}