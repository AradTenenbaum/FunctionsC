#include <stdio.h>
#include "string.h"
#include "memory.h"
#include "list.h"

void main() {
	List l;
	makeEmptyList(&l);
	insertDataToEndList(&l, 5);
	insertDataToEndList(&l, 6);
	insertDataToEndList(&l, 10);

	printList(&l);
	insertDataToEndList(&l, 10);
	printList(&l);

}