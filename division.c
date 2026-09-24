#include <stdlib.h>
#include "apc.h"

/* Copy a BigNumber */
BigNumber *copyBigNumber(BigNumber *num)
{
    BigNumber *copy = createEmptyBigNumber();

    Node *temp = num->head;

    while (temp)
    {
        insertAtLast(copy, temp->digit);
        temp = temp->next;
    }

    copy->sign = num->sign;
    return copy;
}

/* Multiply by 10 and add one digit */
void appendDigit(BigNumber *num, int digit)
{
    if (num->head == NULL)
    {
        insertAtLast(num, digit);
        return;
    }

    insertAtLast(num, digit);
    removeLeadingZeros(num);
}

BigNumber *divideBigNumbers(BigNumber *a, BigNumber *b)
{
    /* Divide by zero */
    if (b->length == 1 && b->head->digit == 0)
    {
        return NULL;
    }

    /* If dividend < divisor */
    if (compareMagnitude(a, b) < 0)
    {
        BigNumber *zero = createEmptyBigNumber();
        insertAtLast(zero, 0);
        return zero;
    }

    BigNumber *quotient = createEmptyBigNumber();
    BigNumber *remainder = createEmptyBigNumber();

    Node *curr = a->head;

    while (curr)
    {
        appendDigit(remainder, curr->digit);

        int count = 0;

        while (compareMagnitude(remainder, b) >= 0)
        {
            BigNumber *temp = subtractMagnitude(remainder, b);
            freeBigNumber(remainder);
            remainder = temp;
            count++;
        }

        insertAtLast(quotient, count);

        curr = curr->next;
    }

    removeLeadingZeros(quotient);

    quotient->sign = (a->sign == b->sign) ? 1 : -1;

    if (quotient->head &&
        quotient->head == quotient->tail &&
        quotient->head->digit == 0)
    {
        quotient->sign = 1;
    }

    freeBigNumber(remainder);

    return quotient;
}