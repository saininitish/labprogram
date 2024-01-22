#include <stdio.h>

long long leftToRightBinaryExponentiation(int base, int exponent) {
    long long result = 1;

    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result *= base;
        }

        base *= base;
        exponent /= 2;
    }

    return result;
}

int main() {
    int base1 = 4;
    int exponent1 = 512;
    printf("%d^%d = %lld\n", base1, exponent1, leftToRightBinaryExponentiation(base1, exponent1));

    int base2 = 3;
    int exponent2 = 31;
    printf("%d^%d = %lld\n", base2, exponent2, leftToRightBinaryExponentiation(base2, exponent2));

    return 0;
}
