#include <stdlib.h>
#include "apc.h"

BigNumber *subtractMagnitude(BigNumber *a, BigNumber *b)
{
    BigNumber *result = createEmptyBigNumber();
    Node *pa = a->tail;
    Node *pb = b->tail;
    int borrow = 0;
    while (pa != NULL)
    {
        int digitA = pa->digit;
        int digitB = (pb != NULL) ? pb->digit : 0;
        int diff = digitA - digitB - borrow;
        if (diff < 0)
        {
            diff += 10;
            borrow = 1;
        }
        else
        {
            borrow = 0;
        }
        insertAtFirst(result, diff);
        pa = pa->prev;
        if (pb != NULL)
        {
            pb = pb->prev;
        }
    }
    removeLeadingZeros(result);
    return result;
}

BigNumber *subtractBigNumbers(BigNumber *a, BigNumber *b)
{
    b->sign = -b->sign;
    BigNumber *result = addBigNumbers(a, b);
    b->sign = -b->sign;
    return result;
}
