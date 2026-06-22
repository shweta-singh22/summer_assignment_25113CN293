#include <stdio.h>

int main() {
    char str[200];
    int i = 0, count = 0;

    printf("Enter a sentence: ");
    fgets(str, sizeof(str), stdin);

    // Count words
    while(str[i] != '\0') {
        // Check for space followed by a character
        if((str[i] == ' ' || str[i] == '\n' || str[i] == '\t') 
            && (str[i+1] != ' ' && str[i+1] != '\n' && str[i+1] != '\t' && str[i+1] != '\0')) {
            count++;
        }
        i++;
    }

    // If sentence is not empty, add 1
    if(i > 1)
        count++;

    printf("Number of words = %d\n", count);

    return 0;
}