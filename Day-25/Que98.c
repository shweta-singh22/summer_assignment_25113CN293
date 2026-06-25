#include <stdio.h>

int main() {
    char str1[100], str2[100];
    int freq[256] = {0};
    int i;

    printf("Enter first string: ");
    scanf("%s", str1);

    printf("Enter second string: ");
    scanf("%s", str2);

    // Mark characters from first string
    for(i = 0; str1[i] != '\0'; i++) {
        freq[(int)str1[i]] = 1;
    }

    printf("Common characters: ");

    // Check characters in second string
    for(i = 0; str2[i] != '\0'; i++) {
        if(freq[(int)str2[i]] == 1) {
            printf("%c ", str2[i]);
            freq[(int)str2[i]] = 0; // avoid duplicates
        }
    }

    return 0;
}