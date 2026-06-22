#include <stdio.h>

int main() {
    char str[200];
    int i = 0, j = 0;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Remove spaces
    while(str[i] != '\0') {
        if(str[i] != ' ' && str[i] != '\n') {
            str[j] = str[i];
            j++;
        }
        i++;
    }
    str[j] = '\0';  // End string

    printf("String without spaces: %s\n", str);

    return 0;
}