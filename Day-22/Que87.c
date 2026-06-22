#include <stdio.h>

int main() {
    char str[200];
    int freq[256] = {0};  // ASCII characters
    int i = 0;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Count frequency
    while(str[i] != '\0') {
        if(str[i] != '\n') {
            freq[(int)str[i]]++;
        }
        i++;
    }

    // Print frequency
    printf("Character frequencies:\n");
    for(i = 0; i < 256; i++) {
        if(freq[i] != 0) {
            printf("%c = %d\n", i, freq[i]);
        }
    }

    return 0;
}