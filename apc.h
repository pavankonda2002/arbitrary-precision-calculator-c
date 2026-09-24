#ifndef APC_H
#define APC_H

typedef struct Node
{
    int digit;
    struct Node *next;
    struct Node *prev;
} Node;

typedef struct BigNumber
{
    Node *head;
    Node *tail;
    int sign;
    int length;
} BigNumber;

Node *createNode(int digit);
BigNumber *createEmptyBigNumber(void);
void insertAtFirst(BigNumber *num, int digit);
void insertAtLast(BigNumber *num, int digit);
void freeBigNumber(BigNumber *num);
void printBigNumber(BigNumber *num);
int isValidNumberString(const char *str);
BigNumber *createBigNumberFromString(const char *str);
void removeLeadingZeros(BigNumber *num);
int compareMagnitude(BigNumber *a, BigNumber *b);

BigNumber *addMagnitude(BigNumber *a, BigNumber *b);
BigNumber *addBigNumbers(BigNumber *a, BigNumber *b);

BigNumber *subtractMagnitude(BigNumber *a, BigNumber *b);
BigNumber *subtractBigNumbers(BigNumber *a, BigNumber *b);

BigNumber *multiplyBigNumbers(BigNumber *a, BigNumber *b);

BigNumber *divideBigNumbers(BigNumber *a, BigNumber *b);
#endif
