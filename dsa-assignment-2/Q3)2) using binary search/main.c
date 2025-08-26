#include <stdio.h>

int find_missing_binary_basic(int arr[], int size) {
    int low = 0;
    int high = size - 1;
    
    while (low <= high) {
        int mid = (low + high) / 2;
        
        if (arr[mid] == mid + 1) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    
    return low + 1;
}

int main() {
    int arr[] = {1, 2, 3, 4, 6, 7};
    int size = sizeof(arr) / sizeof(arr[0]);
    int missing = find_missing_binary_basic(arr, size);
    printf("Missing number (binary basic): %d\n", missing);
    return 0;
}
