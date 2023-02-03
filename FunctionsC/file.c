#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include "file.h"
#include <stdlib.h>
#include "memory.h"

// Get file size
long int fileSize(FILE* fp)
{
	long int res;
	long int saver = ftell(fp);
	fseek(fp, 0, SEEK_END);
	res = ftell(fp);
	fseek(fp, saver, SEEK_SET);
	return res;
}
// @Hadar Binsky

// Print text file
void printTxtFile(String fname, int maxLineLength) {

	String line = malloc(sizeof(char)* maxLineLength);
	memoryAndFileValidation(line);
	FILE* file = fopen(fname, "r");
	memoryAndFileValidation(file);

	while (fgets(line, maxLineLength, file) != NULL) {
		printf("%s", line);
	}

	fclose(file);
}