#include "bit.h"
#include <stdio.h>

// Swap bytes with xor only
void bitSwap(BYTE* x, BYTE* y) {
	*x = *x ^ *y;
	*y = *x ^ *y;
	*x = *x ^ *y;
}

// Check if a bit is set
int isBitISet(BYTE ch, int i)
{
	BYTE mask = 1 << i;
	return mask & ch;
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
