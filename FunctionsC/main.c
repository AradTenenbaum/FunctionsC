#include <stdio.h>
#include "string.h"
#include "memory.h"
#include "list.h"
#include "tree.h"
#include "bit.h"
#include "file.h"

int isMoreThan30(TreeNode* t) {
	if (t->data > 30) return 1;
	return 0;
}

int isLessThan30(TreeNode* t) {
	if (t->data < 30) return 1;
	return 0;
}

void main(int argc, char* argv[]) {
	
	int arr[] = { 1, 90, -1, 32, -1, 34, 60, 22, -1, 10, -1, 2, 10, 44, 10 };

	Tree t = BuildTreeFromArray(arr, 15);

	printByLevels(t);

	printf("Sequence: %d\n", findLongestSequenceByFunction(t, isLessThan30));
}