#include <stdio.h>

int main() {
    char str[100];
    int hash[256] = {0}; // ASCII characters

    printf("Enter a string: ");
    scanf("%s", str);

    // Step 1: Count frequency
    for(int i = 0; str[i] != '\0'; i++) {
        hash[str[i]]++;
    }

    // Step 2: Find first non-repeating
    for(int i = 0; str[i] != '\0'; i++) {
        if(hash[str[i]] == 1) {
            printf("First non-repeating character: %c", str[i]);
            return 0;
        }
    }

    printf("No non-repeating character found");
    return 0;
}