#include <stdlib.h>
#include "apc.h"

BigNumber *multiplyBigNumbers(BigNumber *a, BigNumber *b)
{
    if ((a->length == 1 && a->head->digit == 0) || (b->length == 1 && b->head->digit == 0))
    {
        BigNumber *zero = createEmptyBigNumber();
        insertAtFirst(zero, 0);
        zero->sign = 1;
        return zero;
    }
    int resultSize = a->length + b->length;
    int *buffer = (int *)calloc(resultSize, sizeof(int));
    if (buffer == NULL)
    {
        exit(EXIT_FAILURE);
    }
    Node *pa = a->tail;
    int i = 0;
    while (pa != NULL)
    {
        Node *pb = b->tail;
        int j = 0;
        int carry = 0;
        while (pb != NULL)
        {
            int product = pa->digit * pb->digit + buffer[i + j] + carry;
            buffer[i + j] = product % 10;
            carry = product / 10;
            pb = pb->prev;
            j++;
        }
        int position = i + j;
        while (carry != 0)
        {
            int sum = buffer[position] + carry;
            buffer[position] = sum % 10;
            carry = sum / 10;
            position++;
        }
        pa = pa->prev;
        i++;
    }
    BigNumber *result = createEmptyBigNumber();
    for (int k = 0; k < resultSize; k++)
    {
        insertAtFirst(result, buffer[k]);
    }
    free(buffer);
    removeLeadingZeros(result);
    result->sign = (a->sign == b->sign) ? 1 : -1;
    if (result->head != NULL && result->head == result->tail && result->head->digit == 0)
    {
        result->sign = 1;
    }
    return result;
}
