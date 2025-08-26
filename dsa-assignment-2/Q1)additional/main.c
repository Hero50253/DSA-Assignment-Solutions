#include <stdio.h>
#include <stdlib.h>

// Function to count pairs with difference k
int countPairsWithDiffK(int arr[], int n, int k) {
    int count = 0;
    int i, j;

    // Simple nested loop to check all pairs
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            int diff = arr[i] - arr[j];
            if (diff < 0) diff = -diff; // absolute value

            if (diff == k) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    int n, k, i;
    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter value of k: ");
    scanf("%d", &k);

    int result = countPairsWithDiffK(arr, n, k);
    printf("Number of pairs with difference %d is: %d\n", k, result);

    return 0;
}
