#include <stdio.h>
#include <string.h>

#define MAX 100

struct Account {
    int accNo;
    char name[50];
    float balance;
};

int main() {
    struct Account a[MAX];
    int count = 0, choice, i, accNo, found;
    float amount;

    do {
        printf("\n===== BANK SYSTEM =====\n");
        printf("1. Create Account\n");
        printf("2. Display Accounts\n");
        printf("3. Deposit\n");
        printf("4. Withdraw\n");
        printf("5. Search Account\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {

            case 1:
                if(count < MAX) {
                    printf("Enter Account Number: ");
                    scanf("%d", &a[count].accNo);
                    printf("Enter Name: ");
                    scanf("%s", a[count].name);
                    printf("Enter Initial Balance: ");
                    scanf("%f", &a[count].balance);
                    count++;
                    printf("✅ Account created!\n");
                } else {
                    printf("❌ Limit reached!\n");
                }
                break;

            case 2:
                if(count == 0) {
                    printf("No accounts found!\n");
                } else {
                    for(i = 0; i < count; i++) {
                        printf("AccNo: %d | Name: %s | Balance: %.2f\n",
                               a[i].accNo, a[i].name, a[i].balance);
                    }
                }
                break;

            case 3:
                printf("Enter Account Number: ");
                scanf("%d", &accNo);
                found = 0;
                for(i = 0; i < count; i++) {
                    if(a[i].accNo == accNo) {
                        printf("Enter amount to deposit: ");
                        scanf("%f", &amount);
                        if(amount > 0) {
                            a[i].balance += amount;
                            printf("✅ Deposited!\n");
                        } else {
                            printf("❌ Invalid amount!\n");
                        }
                        found = 1;
                        break;
                    }
                }
                if(!found) printf("❌ Account not found!\n");
                break;

            case 4:
                printf("Enter Account Number: ");
                scanf("%d", &accNo);
                found = 0;
                for(i = 0; i < count; i++) {
                    if(a[i].accNo == accNo) {
                        printf("Enter amount to withdraw: ");
                        scanf("%f", &amount);
                        if(amount > a[i].balance) {
                            printf("❌ Insufficient balance!\n");
                        } else if(amount <= 0) {
                            printf("❌ Invalid amount!\n");
                        } else {
                            a[i].balance -= amount;
                            printf("✅ Withdraw successful!\n");
                        }
                        found = 1;
                        break;
                    }
                }
                if(!found) printf("❌ Account not found!\n");
                break;

            case 5:
                printf("Enter Account Number to search: ");
                scanf("%d", &accNo);
                found = 0;
                for(i = 0; i < count; i++) {
                    if(a[i].accNo == accNo) {
                        printf("Found: %d %s %.2f\n",
                               a[i].accNo, a[i].name, a[i].balance);
                        found = 1;
                        break;
                    }
                }
                if(!found) printf("❌ Account not found!\n");
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