#include "lib.h"

int main() {
    char expr[100];
    printf("Enter an expression: ");
    fgets(expr, sizeof(expr), stdin);
    double result = calculator(expr);
    printf("Result: %g\n", result);
    return 0;
}
