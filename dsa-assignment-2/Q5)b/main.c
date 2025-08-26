#include <stdio.h>
#define SIZE 5

int main() {
    int lower[SIZE-1], main_diag[SIZE], upper[SIZE-1];
    int i, j;

    printf("Enter main diagonal elements:\n");
    for (i = 0; i < SIZE; i++) scanf("%d", &main_diag[i]);
    printf("Enter lower diagonal elements:\n");
    for (i = 0; i < SIZE-1; i++) scanf("%d", &lower[i]);
    printf("Enter upper diagonal elements:\n");
    for (i = 0; i < SIZE-1; i++) scanf("%d", &upper[i]);

    printf("Matrix:\n");
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (i == j)
                printf("%d ", main_diag[i]);
            else if (i == j + 1)
                printf("%d ", lower[j]);
            else if (j == i + 1)
                printf("%d ", upper[i]);
            else
                printf("0 ");
        }
        printf("\n");
    }
    return 0;
}
