#include <stdlib.h>
#include "apc.h"

BigNumber *addMagnitude(BigNumber *a, BigNumber *b)
{
    BigNumber *result = createEmptyBigNumber();
    Node *pa = a->tail;
    Node *pb = b->tail;
    int carry = 0;
    while (pa != NULL || pb != NULL || carry != 0)
    {
        int digitA = (pa != NULL) ? pa->digit : 0;
        int digitB = (pb != NULL) ? pb->digit : 0;
        int sum = digitA + digitB + carry;
        carry = sum / 10;
        insertAtFirst(result, sum % 10);
        if (pa != NULL)
        {
            pa = pa->prev;
        }
        if (pb != NULL)
        {
            pb = pb->prev;
        }
    }
    removeLeadingZeros(result);
    return result;
}

BigNumber *addBigNumbers(BigNumber *a, BigNumber *b)
{
    BigNumber *result = NULL;
    if (a->sign == b->sign)
    {
        result = addMagnitude(a, b);
        result->sign = a->sign;
    }
    else
    {
        int cmp = compareMagnitude(a, b);
        if (cmp == 0)
        {
            result = createEmptyBigNumber();
            insertAtFirst(result, 0);
            result->sign = 1;
        }
        else if (cmp > 0)
        {
            result = subtractMagnitude(a, b);
            result->sign = a->sign;
        }
        else
        {
            result = subtractMagnitude(b, a);
            result->sign = b->sign;
        }
    }
    if (result->head != NULL && result->head == result->tail && result->head->digit == 0)
    {
        result->sign = 1;
    }
    return result;
}
