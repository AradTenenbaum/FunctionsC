#include <stdio.h>
#include "file.h"


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