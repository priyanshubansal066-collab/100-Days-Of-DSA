#include <stdio.h>

int lowerBound(int arr[], int n, int target) {
    int low = 0, high = n - 1;
    int ans = n;

    while(low <= high) {
        int mid = (low + high) / 2;

        if(arr[mid] >= target) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int upperBound(int arr[], int n, int target) {
    int low = 0, high = n - 1;
    int ans = n;

    while(low <= high) {
        int mid = (low + high) / 2;

        if(arr[mid] > target) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    int arr[] = {1, 2, 4, 4, 5, 6};
    int n = 6;
    int target = 4;

    int lb = lowerBound(arr, n, target);
    int ub = upperBound(arr, n, target);

    printf("Lower Bound index: %d\n", lb);
    printf("Upper Bound index: %d\n", ub);

    return 0;
}