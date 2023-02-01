#include <stdlib.h>
#include <stdio.h>
#include "memory.h"

void memoryAndFileValidation(void* ptr) {
	if (ptr == NULL)
	{
		printf("File open/Memory allocation falied.\n");
		exit(1);
	}
}