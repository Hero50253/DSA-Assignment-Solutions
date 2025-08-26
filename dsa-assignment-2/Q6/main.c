#include <stdio.h>

#define MAX 100 

typedef struct {
    int row;
    int col;
    int val;
} Element;

typedef struct {
    int rows;
    int cols;
    int nonZeroCount;
    Element elements[MAX];
} SparseMatrix;

void printSparseMatrix(SparseMatrix sm) {
    printf("Row Column Value\n");
    for (int i = 0; i < sm.nonZeroCount; i++) {
        printf("%3d %6d %6d\n", sm.elements[i].row, sm.elements[i].col, sm.elements[i].val);
    }
}

// (a) Transpose function: swaps row and col for each element
SparseMatrix transpose(SparseMatrix sm) {
    SparseMatrix result;
    result.rows = sm.cols;
    result.cols = sm.rows;
    result.nonZeroCount = sm.nonZeroCount;

    int k = 0;
    for (int c = 0; c < sm.cols; c++) {
        for (int i = 0; i < sm.nonZeroCount; i++) {
            if (sm.elements[i].col == c) {
                result.elements[k].row = sm.elements[i].col;
                result.elements[k].col = sm.elements[i].row;
                result.elements[k].val = sm.elements[i].val;
                k++;
            }
        }
    }
    return result;
}

// (b) Addition of two sparse matrices
SparseMatrix add(SparseMatrix sm1, SparseMatrix sm2) {
    SparseMatrix result;
    if (sm1.rows != sm2.rows || sm1.cols != sm2.cols) {
        printf("Matrix size mismatch for addition.\n");
        result.nonZeroCount = 0;
        return result;
    }

    result.rows = sm1.rows;
    result.cols = sm1.cols;

    int i = 0, j = 0, k = 0;
    while (i < sm1.nonZeroCount && j < sm2.nonZeroCount) {
        int pos1 = sm1.elements[i].row * sm1.cols + sm1.elements[i].col;
        int pos2 = sm2.elements[j].row * sm2.cols + sm2.elements[j].col;

        if (pos1 < pos2) {
            result.elements[k++] = sm1.elements[i++];
        } else if (pos1 > pos2) {
            result.elements[k++] = sm2.elements[j++];
        } else {
            int summed = sm1.elements[i].val + sm2.elements[j].val;
            if (summed != 0) {
                result.elements[k] = sm1.elements[i];
                result.elements[k].val = summed;
                k++;
            }
            i++; j++;
        }
    }

    // Copy remaining elements from sm1
    while (i < sm1.nonZeroCount) {
        result.elements[k++] = sm1.elements[i++];
    }

    // Copy remaining elements from sm2
    while (j < sm2.nonZeroCount) {
        result.elements[k++] = sm2.elements[j++];
    }

    result.nonZeroCount = k;
    return result;
}

// (c) Multiplication of two sparse matrices
SparseMatrix multiply(SparseMatrix sm1, SparseMatrix sm2) {
    SparseMatrix result;
    if (sm1.cols != sm2.rows) {
        printf("Matrix size mismatch for multiplication.\n");
        result.nonZeroCount = 0;
        return result;
    }

    result.rows = sm1.rows;
    result.cols = sm2.cols;
    result.nonZeroCount = 0;

    for (int i = 0; i < sm1.rows; i++) {
        for (int j = 0; j < sm2.cols; j++) {
            int sum = 0;
            for (int k = 0; k < sm1.nonZeroCount; k++) {
                if (sm1.elements[k].row == i) {
                    int col1 = sm1.elements[k].col;
                    for (int l = 0; l < sm2.nonZeroCount; l++) {
                        if (sm2.elements[l].row == col1 && sm2.elements[l].col == j) {
                            sum += sm1.elements[k].val * sm2.elements[l].val;
                        }
                    }
                }
            }
            if (sum != 0) {
                result.elements[result.nonZeroCount].row = i;
                result.elements[result.nonZeroCount].col = j;
                result.elements[result.nonZeroCount].val = sum;
                result.nonZeroCount++;
            }
        }
    }

    return result;
}

int main() {
    SparseMatrix m1, m2, trans, sum, prod;
    int i;

    // Input first sparse matrix
    printf("Enter rows, columns and non-zero elements count of 1st matrix: ");
    scanf("%d%d%d", &m1.rows, &m1.cols, &m1.nonZeroCount);
    printf("Enter row, col, value for each non-zero element (0-based indices):\n");
    for (i = 0; i < m1.nonZeroCount; i++) {
        scanf("%d%d%d", &m1.elements[i].row, &m1.elements[i].col, &m1.elements[i].val);
    }

    // Input second sparse matrix
    printf("\nEnter rows, columns and non-zero elements count of 2nd matrix: ");
    scanf("%d%d%d", &m2.rows, &m2.cols, &m2.nonZeroCount);
    printf("Enter row, col, value for each non-zero element (0-based indices):\n");
    for (i = 0; i < m2.nonZeroCount; i++) {
        scanf("%d%d%d", &m2.elements[i].row, &m2.elements[i].col, &m2.elements[i].val);
    }

    // Transpose of first matrix
    trans = transpose(m1);
    printf("\nTranspose of first matrix:\n");
    printSparseMatrix(trans);

    // Addition of matrices
    sum = add(m1, m2);
    printf("\nSum of matrices:\n");
    printSparseMatrix(sum);

    // Multiplication of matrices
    prod = multiply(m1, m2);
    printf("\nProduct of matrices:\n");
    printSparseMatrix(prod);

    return 0;
}
