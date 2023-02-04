#include "bit.h"
#include <stdio.h>
#include <stdbool.h>

// Swap bytes with xor only
void bitSwap(BYTE* x, BYTE* y) {
	*x = *x ^ *y;
	*y = *x ^ *y;
	*x = *x ^ *y;
}

// Check if a bit is set
bool isBitSet(BYTE ch, int i)
{
	BYTE mask = 1 << i;
    return (mask & ch) > 0;
}

// Print byte in binary format
void printByteAsBinary(BYTE x)
{
    BYTE z;
    for (z = 128; z > 0; z >>= 1)
    {
        printf(((x & z) == z) ? "1" : "0");
    }
    printf("\n");
}
