#include <stdio.h>

char str[100];

int length(char s[]) {
    int i = 0;
    while(s[i] != '\0') i++;
    return i;
}

void reverse(char s[]) {
    int i, len = length(s);
    char temp;
    for(i = 0; i < len/2; i++) {
        temp = s[i];
        s[i] = s[len - i - 1];
        s[len - i - 1] = temp;
    }
}

int palindrome(char s[]) {
    int i, len = length(s);
    for(i = 0; i < len/2; i++) {
        if(s[i] != s[len - i - 1])
            return 0;
    }
    return 1;
}

void toUpper(char s[]) {
    int i = 0;
    while(s[i] != '\0') {
        if(s[i] >= 'a' && s[i] <= 'z') {
            s[i] = s[i] - 32;
        }
        i++;
    }
}

int main() {
    int choice;

    do {
        printf("\n===== STRING OPERATIONS MENU =====\n");
        printf("1. Input String\n");
        printf("2. Display String\n");
        printf("3. Find Length\n");
        printf("4. Reverse String\n");
        printf("5. Check Palindrome\n");
        printf("6. Convert to Uppercase\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {

            case 1:
                printf("Enter string: ");
                scanf("%s", str);
                break;

            case 2:
                printf("String: %s\n", str);
                break;

            case 3:
                printf("Length = %d\n", length(str));
                break;

            case 4:
                reverse(str);
                printf("Reversed String: %s\n", str);
                break;

            case 5:
                if(palindrome(str))
                    printf("✅ Palindrome\n");
                else
                    printf("❌ Not Palindrome\n");
                break;

            case 6:
                toUpper(str);
                printf("Uppercase String: %s\n", str);
                break;

            case 7:
                printf("🙏 Exiting...\n");
                break;

            default:
                printf("❌ Invalid choice!\n");
        }

    } while(choice != 7);

    return 0;
}