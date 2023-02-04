#include <stdio.h>
#include "string.h"
#include "memory.h"
#include "list.h"
#include "tree.h"
#include "bit.h"
#include "file.h"
#include "generic.h"

int is_a(char** text) {
	return (*text)[0] == 'a';
}

int isEven(int* num) {
	return *num % 2 == 0;
}

void main(int argc, char* argv[]) {
	char* arr[] = {"abc", "bbc", "abngg", "wnba", "FBI", "H20", "Example"};
	int intArr[] = { 2, 3, 4, 10, 11, 24, 12, 23, 65 };
	int size = 0;
	int* newArr = Retrive(intArr, 9, sizeof(int), isEven, &size);
	for (int i = 0; i < size; i++)
	{
		printf("%d ", newArr[i]);
	}
}