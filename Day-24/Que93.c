#include <stdio.h>
#include <string.h>

int main() {
    char str1[100], str2[100], temp[200];

    printf("Enter first string: ");
    scanf("%s", str1);

    printf("Enter second string: ");
    scanf("%s", str2);

    // Check length first
    if(strlen(str1) != strlen(str2)) {
        printf("Not rotation\n");
        return 0;
    }

    // Concatenate str1 with itself
    strcpy(temp, str1);
    strcat(temp, str1);

    // Check if str2 is substring of temp
    if(strstr(temp, str2)) {
        printf("Strings are rotation of each other\n");
    } else {
        printf("Not rotation\n");
    }

    return 0;
}