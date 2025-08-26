#include <stdio.h>
#define SIZE 5

int main() {
    int diagonal[SIZE], i, j;
    printf("Enter diagonal elements:\n");
    for (i = 0; i < SIZE; i++) {
        scanf("%d", &diagonal[i]);
    }

    printf("Matrix:\n");
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (i == j)
                printf("%d ", diagonal[i]);
            else
                printf("0 ");
        }
        printf("\n");
    }
    return 0;
}
