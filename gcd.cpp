#include <stdio.h>

int euclideanGCD(int a, int b, int *modOperations, int *assignmentOperations) {
    *modOperations = 0;
    *assignmentOperations = 0;

    while (b != 0) {
        *assignmentOperations += 1;
        int temp = b;
        b = a % b;
        a = temp;
        *modOperations += 1;
    }

    return a;
}

int main() {
    int num1 = 15265, num2 = 15;
    int modOperations, assignmentOperations;

    int gcd = euclideanGCD(num1, num2, &modOperations, &assignmentOperations);

    printf("GCD of %d and %d is %d\n", num1, num2, gcd);
    printf("Number of mod operations: %d\n", modOperations);
    printf("Number of assignment operations: %d\n", assignmentOperations);

    return 0;
}
