#include <stdio.h>

int main() {
    char str[200];
    int freq[256] = {0};
    int i = 0;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Traverse and check repeating
    while(str[i] != '\0') {
        if(str[i] != '\n') {
            freq[(int)str[i]]++;

            if(freq[(int)str[i]] == 2) {
                printf("First repeating character = %c\n", str[i]);
                return 0;
            }
        }
        i++;
    }

    printf("No repeating character found\n");

    return 0;
}