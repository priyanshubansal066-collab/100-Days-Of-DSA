#include <stdio.h>

#define MAX 1000

int main() {
    int arr[] = {1, -1, 3, 2, -2, -3, 3};
    int n = 7;

    int sum = 0, maxLen = 0;

    // Hash map (simple array for prefix sum)
    int map[10000];
    for(int i = 0; i < 10000; i++) map[i] = -1;

    for(int i = 0; i < n; i++) {
        sum += arr[i];

        if(sum == 0) {
            maxLen = i + 1;
        }

        if(map[sum + 5000] != -1) {
            int len = i - map[sum + 5000];
            if(len > maxLen)
                maxLen = len;
        } else {
            map[sum + 5000] = i;
        }
    }

    printf("Largest subarray length with zero sum: %d", maxLen);

    return 0;
}