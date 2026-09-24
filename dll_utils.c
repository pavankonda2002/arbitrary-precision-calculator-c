#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "apc.h"

Node *createNode(int digit)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->digit = digit;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

BigNumber *createEmptyBigNumber(void)
{
    BigNumber *num = (BigNumber *)malloc(sizeof(BigNumber));
    if (num == NULL)
    {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    num->head = NULL;
    num->tail = NULL;
    num->sign = 1;
    num->length = 0;
    return num;
}

void insertAtFirst(BigNumber *num, int digit)
{
    Node *newNode = createNode(digit);
    if (num->head == NULL)
    {
        num->head = newNode;
        num->tail = newNode;
    }
    else
    {
        newNode->next = num->head;
        num->head->prev = newNode;
        num->head = newNode;
    }
    num->length++;
}

void insertAtLast(BigNumber *num, int digit)
{
    Node *newNode = createNode(digit);
    if (num->tail == NULL)
    {
        num->head = newNode;
        num->tail = newNode;
    }
    else
    {
        newNode->prev = num->tail;
        num->tail->next = newNode;
        num->tail = newNode;
    }
    num->length++;
}

void freeBigNumber(BigNumber *num)
{
    if (num == NULL)
    {
        return;
    }
    Node *current = num->head;
    while (current != NULL)
    {
        Node *temp = current;
        current = current->next;
        free(temp);
    }
    free(num);
}

void printBigNumber(BigNumber *num)
{
    if (num == NULL || num->head == NULL)
    {
        printf("0");
        return;
    }
    if (num->sign == -1)
    {
        printf("-");
    }
    Node *current = num->head;
    while (current != NULL)
    {
        printf("%d", current->digit);
        current = current->next;
    }
}

int isValidNumberString(const char *str)
{
    int i = 0;
    int len = (int)strlen(str);
    if (len == 0)
    {
        return 0;
    }
    if (str[0] == '-' || str[0] == '+')
    {
        i = 1;
    }
    if (i == len)
    {
        return 0;
    }
    for (; i < len; i++)
    {
        if (!isdigit((unsigned char)str[i]))
        {
            return 0;
        }
    }
    return 1;
}

BigNumber *createBigNumberFromString(const char *str)
{
    BigNumber *num = createEmptyBigNumber();
    int startIndex = 0;
    int len = (int)strlen(str);
    if (str[0] == '-')
    {
        num->sign = -1;
        startIndex = 1;
    }
    else if (str[0] == '+')
    {
        num->sign = 1;
        startIndex = 1;
    }
    for (int i = startIndex; i < len; i++)
    {
        insertAtLast(num, str[i] - '0');
    }
    removeLeadingZeros(num);
    return num;
}

void removeLeadingZeros(BigNumber *num)
{
    while (num->head != NULL && num->head->digit == 0 && num->head != num->tail)
    {
        Node *temp = num->head;
        num->head = num->head->next;
        if (num->head != NULL)
        {
            num->head->prev = NULL;
        }
        free(temp);
        num->length--;
    }
    if (num->head != NULL && num->head == num->tail && num->head->digit == 0)
    {
        num->sign = 1;
    }
}

int compareMagnitude(BigNumber *a, BigNumber *b)
{
    if (a->length != b->length)
    {
        return (a->length > b->length) ? 1 : -1;
    }
    Node *pa = a->head;
    Node *pb = b->head;
    while (pa != NULL)
    {
        if (pa->digit != pb->digit)
        {
            return (pa->digit > pb->digit) ? 1 : -1;
        }
        pa = pa->next;
        pb = pb->next;
    }
    return 0;
}
