#include <stdio.h>

int main() {
     
    int coefficients[] = {6, 5, 4, -3, 2, 8, -7};
    int n = sizeof(coefficients) / sizeof(coefficients[0]);
 
    int x_value = 3;

    
    int result = coefficients[0];

    
    int multiplications = 0;
    int additions = 0;

     
    for (int i = 1; i < n; ++i) {
        result = result * x_value + coefficients[i];
        multiplications++;
        additions++;
    }

     
    printf("P(%d) = %d\n", x_value, result);
    printf("Number of multiplications: %d\n", multiplications);
    printf("Number of additions: %d\n", additions);
    printf("Number of iterations: %d\n", n - 1);

    return 0;
}
