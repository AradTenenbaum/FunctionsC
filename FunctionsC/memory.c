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