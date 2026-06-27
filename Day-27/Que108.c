#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100

struct StudentMarksheet {
    int rollNo;
    char name[50];
    int physics;
    int chemistry;
    int mathematics;
    int totalMarks;
    float percentage;
    char grade[5];
};

struct StudentMarksheet marksheets[MAX_STUDENTS];
int recordCount = 0;

void calculateResult(struct StudentMarksheet *s) {
    s->totalMarks = s->physics + s->chemistry + s->mathematics;
    s->percentage = s->totalMarks / 3.0;

    if (s->physics < 33 || s->chemistry < 33 || s->mathematics < 33) {
        strcpy(s->grade, "Fail");
    } else if (s->percentage >= 85) {
        strcpy(s->grade, "A+");
    } else if (s->percentage >= 70) {
        strcpy(s->grade, "A");
    } else if (s->percentage >= 50) {
        strcpy(s->grade, "B");
    } else if (s->percentage >= 33) {
        strcpy(s->grade, "C");
    } else {
        strcpy(s->grade, "Fail");
    }
}

void addMarksheet() {
    if (recordCount >= MAX_STUDENTS) {
        printf("System full! Cannot add more records.\n");
        return;
    }

    struct StudentMarksheet s;
    printf("Enter Roll Number: ");
    if (scanf("%d", &s.rollNo) != 1) return;

    for (int i = 0; i < recordCount; i++) {
        if (marksheets[i].rollNo == s.rollNo) {
            printf("Error: Marksheet for Roll Number %d already exists!\n", s.rollNo);
            return;
        }
    }

    printf("Enter Name: ");
    getchar(); 
    scanf("%[^\n]s", s.name);

    printf("Enter Physics Marks (0-100): ");
    if (scanf("%d", &s.physics) != 1 || s.physics < 0 || s.physics > 100) return;

    printf("Enter Chemistry Marks (0-100): ");
    if (scanf("%d", &s.chemistry) != 1 || s.chemistry < 0 || s.chemistry > 100) return;

    printf("Enter Mathematics Marks (0-100): ");
    if (scanf("%d", &s.mathematics) != 1 || s.mathematics < 0 || s.mathematics > 100) return;

    calculateResult(&s);

    marksheets[recordCount] = s;
    recordCount++;

    printf("Marksheet record added successfully!\n");
}

void displayReportCard() {
    if (recordCount == 0) {
        printf("No marksheet records found!\n");
        return;
    }

    printf("\n---------------------------------------------------------------------------------\n");
    printf("%-10s %-20s %-7s %-7s %-7s %-7s %-12s %-6s\n", "Roll No", "Name", "Phy", "Chem", "Math", "Total", "Percentage", "Grade");
    printf("---------------------------------------------------------------------------------\n");
    
    for (int i = 0; i < recordCount; i++) {
        printf("%-10d %-20s %-7d %-7d %-7d %-7d %-12.2f %-6s\n", 
               marksheets[i].rollNo, marksheets[i].name, marksheets[i].physics, marksheets[i].chemistry, marksheets[i].mathematics, marksheets[i].totalMarks, marksheets[i].percentage, marksheets[i].grade);
    }
    printf("---------------------------------------------------------------------------------\n");
}

void searchMarksheet() {
    if (recordCount == 0) {
        printf("No records available to search!\n");
        return;
    }

    int searchRoll;
    printf("Enter Roll Number to generate marksheet: ");
    if (scanf("%d", &searchRoll) != 1) return;

    for (int i = 0; i < recordCount; i++) {
        if (marksheets[i].rollNo == searchRoll) {
            printf("\n========================================\n");
            printf("           STUDENT MARKSHEET            \n");
            printf("========================================\n");
            printf("Roll Number : %d\n", marksheets[i].rollNo);
            printf("Name        : %s\n", marksheets[i].name);
            printf("----------------------------------------\n");
            printf("Physics     : %d / 100\n", marksheets[i].physics);
            printf("Chemistry   : %d / 100\n", marksheets[i].chemistry);
            printf("Mathematics : %d / 100\n", marksheets[i].mathematics);
            printf("----------------------------------------\n");
            printf("Total Marks : %d / 300\n", marksheets[i].totalMarks);
            printf("Percentage  : %.2f%%\n", marksheets[i].percentage);
            printf("Final Grade : %s\n", marksheets[i].grade);
            printf("========================================\n");
            return;
        }
    }

    printf("Marksheet for Roll Number %d not found.\n", searchRoll);
}

int main() {
    int choice;

    while (1) {
        printf("\n=== Marksheet Generation System ===\n");
        printf("1. Add Student Marks\n");
        printf("2. Display All Student Reports\n");
        printf("3. Search and Print Detailed Marksheet\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        
        if (scanf("%d", &choice) != 1) {
            return 1;
        }

        switch (choice) {
            case 1:
                addMarksheet();
                break;
            case 2:
                displayReportCard();
                break;
            case 3:
                searchMarksheet();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}