#include <stdio.h>

int main() {
    char str1[100], str2[100];
    int freq[256] = {0};
    int i = 0;

    printf("Enter first string: ");
    fgets(str1, sizeof(str1), stdin);

    printf("Enter second string: ");
    fgets(str2, sizeof(str2), stdin);

    // Count frequency of first string
    while(str1[i] != '\0') {
        if(str1[i] != '\n')
            freq[(int)str1[i]]++;
        i++;
    }

    i = 0;

    // Subtract frequency using second string
    while(str2[i] != '\0') {
        if(str2[i] != '\n')
            freq[(int)str2[i]]--;
        i++;
    }

    // Check all frequencies
    for(i = 0; i < 256; i++) {
        if(freq[i] != 0) {
            printf("Not anagram strings\n");
            return 0;
        }
    }

    printf("Anagram strings\n");

    return 0;
}