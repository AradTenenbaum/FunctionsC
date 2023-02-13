#include <stdio.h>
#include "string.h"
#include "memory.h"
#include "list.h"
#include "tree.h"
#include "bit.h"
#include "file.h"
#include "generic.h"

void main(int argc, char* argv[]) {
	int arr[] = {-1, 9, 5, -1, 7, -1, 7, 6, 10};
	Tree t = BuildTreeFromArray(arr, 9);
	printByLevels(t);

	printf("is min path: %d\n", minDiffSortedPaths(t));
}