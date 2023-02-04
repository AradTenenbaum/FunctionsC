#ifndef _BIT_H
#define _BIT_H
#include <stdbool.h>

typedef unsigned char BYTE;

void bitSwap(BYTE* x, BYTE* y);
bool isBitSet(BYTE ch, int i);
void printByteAsBinary(BYTE x);


#endif 
