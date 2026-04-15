#include <stdio.h>
#include <string.h>

int main() {
    int n;
    printf("Enter number of votes: ");
    scanf("%d", &n);

    char votes[n][20];

    printf("Enter votes (candidate names):\n");
    for(int i = 0; i < n; i++) {
        scanf("%s", votes[i]);
    }

    int count[n];

    // Initialize count array
    for(int i = 0; i < n; i++) {
        count[i] = 0;
    }

    // Count votes
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(strcmp(votes[i], votes[j]) == 0) {
                count[i]++;
            }
        }
    }

    // Find max votes
    int max = 0, index = 0;
    for(int i = 0; i < n; i++) {
        if(count[i] > max) {
            max = count[i];
            index = i;
        }
    }

    printf("Winner: %s\n", votes[index]);
    printf("Votes: %d\n", max);

    return 0;
}