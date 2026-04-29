#include <stdio.h>
#include <stdlib.h>

// sort function
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// check if possible
int canPlace(int stalls[], int n, int cows, int dist) {
    int count = 1;
    int lastPos = stalls[0];

    for(int i = 1; i < n; i++) {
        if(stalls[i] - lastPos >= dist) {
            count++;
            lastPos = stalls[i];
        }
        if(count >= cows)
            return 1;
    }
    return 0;
}

int aggressiveCows(int stalls[], int n, int cows) {
    qsort(stalls, n, sizeof(int), compare);

    int low = 1;
    int high = stalls[n - 1] - stalls[0];
    int ans = 0;

    while(low <= high) {
        int mid = (low + high) / 2;

        if(canPlace(stalls, n, cows, mid)) {
            ans = mid;
            low = mid + 1;   // try bigger distance
        } else {
            high = mid - 1;
        }
    }
    return ans;
}

int main() {
    int stalls[] = {1, 2, 4, 8, 9};
    int n = 5;
    int cows = 3;

    printf("Maximum minimum distance: %d", aggressiveCows(stalls, n, cows));

    return 0;
}