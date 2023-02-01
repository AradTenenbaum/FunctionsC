#include <stdio.h>
#include "string.h"
#include "memory.h"
#include "list.h"
#include "tree.h"

void main() {
	Tree t;
	int arr[] = {0, 5, 7, 6, 10,11, -1, 4, 2, 4};
	t = BuildTreeFromArray(arr, 10);
	printByLevels(t);
	printf("nodes: %d\n", numOfNodesInTree(t));
	printf("height: %d\n", getTreeHeight(&t));
}