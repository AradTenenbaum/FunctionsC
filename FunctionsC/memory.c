#include <stdlib.h>
#include <stdio.h>
#include "memory.h"

// Check allocation
void memoryAndFileValidation(void* ptr) {
	if (ptr == NULL)
	{
		printf("File open/Memory allocation falied.\n");
		exit(1);
	}
}

// Swap 2 general variables values
void swap(void* a, void* b, int elemSize)
{
	int i;
	BYTE temp;
	BYTE* first = (BYTE*)a;
	BYTE* second = (BYTE*)b;
	for (i = 0; i < elemSize; i++)
	{
		temp = *(first + i);
		*(first + i) = *(second + i);
		*(second + i) = temp;
	}
}

// Return a general multi array by the given rows, cols and elementSize
void** allocateMultiArray(int rows, int cols, int elementSize) {
	void** arr;
	arr = (void**)malloc(elementSize * cols);
	memoryAndFileValidation(arr);
	for (int i = 0; i < cols; i++) {
		arr[i] = (void*)malloc(elementSize * rows);
		memoryAndFileValidation(arr[i]);
	}
	return arr;
}