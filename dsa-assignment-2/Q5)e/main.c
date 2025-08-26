/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main()
{#include <stdio.h>
#define SIZE 5

int main() {
    int symmetric[SIZE*(SIZE+1)/2];
    int i, j;

    printf("Enter elements of symmetric matrix (lower triangle only):\n");
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j <= i; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &symmetric[i*(i+1)/2 + j]);
        }
    }

    printf("Matrix:\n");
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (i >= j)
                printf("%d ", symmetric[i*(i+1)/2 + j]);
            else
                printf("%d ", symmetric[j*(j+1)/2 + i]); // symmetry
        }
        printf("\n");
    }
    return 0;
}

    printf("Hello World");

    return 0;
}
