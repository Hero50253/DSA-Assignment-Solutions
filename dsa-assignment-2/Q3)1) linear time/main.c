#include <stdio.h>

int find_missing_linear_basic(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        if (arr[i] != i + 1) {
            return i + 1;
        }
    }
    return size + 1;
}

int main() {
    int arr[] = {1, 2, 3, 5, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    int missing = find_missing_linear_basic(arr, size);
    printf("Missing number (linear basic): %d\n", missing);
    return 0;
}
