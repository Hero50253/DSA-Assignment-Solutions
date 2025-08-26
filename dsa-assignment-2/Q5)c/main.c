#include <stdio.h>
#define SIZE 5

int main() {
    int lower_triangular[SIZE*(SIZE+1)/2];
    int i, j, index;

    printf("Enter elements of lower triangular matrix:\n");
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j <= i; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &lower_triangular[i*(i+1)/2 + j]);
        }
    }

    printf("Matrix:\n");
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (i >= j)
                printf("%d ", lower_triangular[i*(i+1)/2 + j]);
            else
                printf("0 ");
        }
        printf("\n");
    }
    return 0;
}
