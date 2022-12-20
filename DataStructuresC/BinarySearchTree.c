#include <stdio.h>

int binarysearch(int arr[], int target) {
    int start = 0;
    int end = sizeof(arr) / sizeof(arr[0]);
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (target < arr[mid]) {
            end = mid - 1;
        } else if (target > arr[mid]) {
            start = mid + 1;
        } else {
            return mid;
        }
    }
    return -1;
}
int main() {
    int arr[] = {2, 3, 4, 20, 30};
    int x = 30;
    int result = binarysearch(arr, x);
    printf("Element is found at %d", result);
}

