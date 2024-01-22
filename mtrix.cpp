#include <stdio.h>

#define ROWS_A 4
#define COLS_A 4
#define ROWS_B 4
#define COLS_B 4

void multiplyMatrices(int A[ROWS_A][COLS_A], int B[ROWS_B][COLS_B], int result[ROWS_A][COLS_B]) {
     
    for (int i = 0; i < ROWS_A; i++) {
        for (int j = 0; j < COLS_B; j++) {
            result[i][j] = 0;
        }
    }
 
    for (int i = 0; i < ROWS_A; i++) {
        for (int j = 0; j < COLS_B; j++) {
            for (int k = 0; k < COLS_A; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    int A[ROWS_A][COLS_A] = {{1, 2, 3, 4},
                             {5, 6, 7, 8},
                             {9, 10, 11, 12},
                             {13, 14, 15, 16}};

    int B[ROWS_B][COLS_B] = {{17, 18, 19, 20},
                             {21, 22, 23, 24},
                             {25, 26, 27, 28},
                             {29, 30, 31, 32}};

    int result[ROWS_A][COLS_B];

     
    multiplyMatrices(A, B, result);

    
    printf("Resultant Matrix:\n");
    for (int i = 0; i < ROWS_A; i++) {
        for (int j = 0; j < COLS_B; j++) {
            printf("%d\t", result[i][j]);
        }
        printf("\n");
    }

    
    int totalIterations = ROWS_A * COLS_B * COLS_A;  
    int multiplications = totalIterations;  
    int additions = totalIterations - 1; 

    printf("Total number of iterations: %d\n", totalIterations);
    printf("Total number of multiplications: %d\n", multiplications);
    printf("Total number of additions: %d\n", additions);

    return 0;
}
