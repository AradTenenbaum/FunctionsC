#ifndef _FILE_H
#define _FILE_H
#include <stdio.h>
#include "string.h"

long int fileSize(FILE* fp);
void printTxtFile(String fname, int maxLineLength);

#endif 
