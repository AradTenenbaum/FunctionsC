#ifndef _MEMORY_H
#define _MEMORY_H

typedef unsigned char BYTE;

void memoryAndFileValidation(void* ptr);
void** allocateMultiArray(int rows, int cols, int elementSize);

#endif 
