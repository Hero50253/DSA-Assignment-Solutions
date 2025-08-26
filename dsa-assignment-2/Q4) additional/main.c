#include <stdio.h>

void sort012(int arr[], int n) {
    int low = 0, mid = 0, high = n - 1;
    int temp;

    while (mid <= high) {
        if (arr[mid] == 0) {
            // Swap arr[low] and arr[mid]
            temp = arr[low];
            arr[low] = arr[mid];
            arr[mid] = temp;
            low++;
            mid++;
        } else if (arr[mid] == 1) {
            mid++;
        } else {
            // arr[mid] == 2, swap arr[mid] and arr[high]
            temp = arr[mid];
            arr[mid] = arr[high];
            arr[high] = temp;
            high--;
        }
    }
}

int main() {
    int n, i;
    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter elements (only 0s, 1s, and 2s):\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    sort012(arr, n);

    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
