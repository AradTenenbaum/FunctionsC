#include <stdio.h>
#include "string.h"
#include "memory.h"
#include "list.h"
#include "tree.h"
#include "bit.h"
#include "file.h"
#include "generic.h"

void main(int argc, char* argv[]) {
	int arr[] = {-1, -1, -1, -1, 7, -1, 8, 6, 6};
	Tree t = BuildTreeFromArray(arr, 9);
	printByLevels(t);

	printf("is balanced: %d\n", isBalanced(t));
}