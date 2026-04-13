#include <stdio.h>

int main() {
    char str[100];
    int hash[256] = {0}; // for ASCII characters

    printf("Enter a string: ");
    scanf("%s", str);

    for(int i = 0; str[i] != '\0'; i++) {
        if(hash[str[i]] == 1) {
            printf("First repeated character: %c", str[i]);
            return 0;
        }
        hash[str[i]] = 1;
    }

    printf("No repeated character found");
    return 0;
}