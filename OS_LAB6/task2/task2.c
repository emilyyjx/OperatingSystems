#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>

/* Declare your functions here */
int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
int divide(int a, int b);

int main(void) {
    int a = 6, b = 3, result = 0;
    char operation;

    // Array of function pointers
    int (*operations[4])(int, int) = { add, subtract, multiply, divide };

    printf("Operand ‘a’ : %d | Operand ‘b’ : %d\n", a, b);
    printf("Specify the operation to perform (0 : add | 1 : subtract | 2 : Multiply | 3 : divide | 4 : exit): ");
    operation = getchar();

    if (operation == '4') return 0; // Exit if the user inputs '4'

    // Call the appropriate function based on user input
    result = operations[operation - '0'](a, b);

    // Print the result
    printf("Result: %d\n", result);

    return 0;
}

/* Define your functions here */
int add(int a, int b) {
    printf("Adding ‘a’ and ‘b’\n");
    return a + b;
}

int subtract(int a, int b) {
    printf("Subtracting ‘b’ from ‘a’\n");
    return a - b;
}

int multiply(int a, int b) {
    printf("Multiplying ‘a’ and ‘b’\n");
    return a * b;
}

int divide(int a, int b) {
    if (b != 0) {
        printf("Dividing ‘a’ by ‘b’\n");
        return a / b;
    } else {
        printf("Error: Division by zero\n");
        return 0;
    }
}
