#include <stdio.h>
#define SIZE 5

int main() {
    int upper_triangular[SIZE*(SIZE+1)/2];
    int i, j, index;

    printf("Enter elements of upper triangular matrix:\n");
    for (i = 0; i < SIZE; i++) {
        for (j = i; j < SIZE; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &upper_triangular[i*SIZE - (i*(i-1))/2 + (j - i)]);
        }
    }

    printf("Matrix:\n");
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (i <= j)
                printf("%d ", upper_triangular[i*SIZE - (i*(i-1))/2 + (j - i)]);
            else
                printf("0 ");
        }
        printf("\n");
    }
    return 0;
}
