#include <stdio.h>

int main() {
    char str[200];
    int freq[256] = {0};
    int i = 0, max = 0;
    char ch;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Count frequency
    while(str[i] != '\0') {
        if(str[i] != '\n') {
            freq[(int)str[i]]++;
        }
        i++;
    }

    // Find maximum occurring character
    for(i = 0; i < 256; i++) {
        if(freq[i] > max) {
            max = freq[i];
            ch = (char)i;
        }
    }

    printf("Maximum occurring character = %c\n", ch);
    printf("Frequency = %d\n", max);

    return 0;
}