#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "apc.h"

int main(int argc, char *argv[])
{
    char num1Str[1024];
    char num2Str[1024];
    char operatorChar;
    if (argc == 4)
    {
        strncpy(num1Str, argv[1], sizeof(num1Str) - 1);
        num1Str[sizeof(num1Str) - 1] = '\0';
        operatorChar = argv[2][0];
        strncpy(num2Str, argv[3], sizeof(num2Str) - 1);
        num2Str[sizeof(num2Str) - 1] = '\0';
    }
    else
    {
        printf("Arbitrary Precision Calculator\n");
        printf("Enter first number: ");
        scanf("%1023s", num1Str);
        printf("Enter operator (+, -, *, /): ");
        scanf(" %c", &operatorChar);
        printf("Enter second number: ");
        scanf("%1023s", num2Str);
    }
    if (!isValidNumberString(num1Str) || !isValidNumberString(num2Str))
    {
        printf("Error: Invalid number format\n");
        return EXIT_FAILURE;
    }
    BigNumber *a = createBigNumberFromString(num1Str);
    BigNumber *b = createBigNumberFromString(num2Str);
    BigNumber *result = NULL;
    switch (operatorChar)
    {
        case '+':
            result = addBigNumbers(a, b);
            break;
        case '-':
            result = subtractBigNumbers(a, b);
            break;
        case '*':
            result = multiplyBigNumbers(a, b);
            break;
        case '/':
         result = divideBigNumbers(a, b);
            break;
        default:
            printf("Error: Unsupported operator '%c'\n", operatorChar);
            freeBigNumber(a);
            freeBigNumber(b);
            return EXIT_FAILURE;
    }

        if (result == NULL)
    {
        if (operatorChar == '/')
            printf("Error: Division by zero\n");
        else
            printf("Error: Operation failed\n");

        freeBigNumber(a);
        freeBigNumber(b);
        return EXIT_FAILURE;
    }

    printf("Result: ");
    printBigNumber(result);
    printf("\n");
    freeBigNumber(a);
    freeBigNumber(b);
    freeBigNumber(result);
    return EXIT_SUCCESS;
}
