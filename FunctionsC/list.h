#ifndef _LIST_H
#define _LIST_H
#include <stdbool.h>

struct list_node
{
	int* dataPtr;
	struct list_node* next;
}typedef ListNode;

struct list
{
	ListNode* head;
	ListNode* tail;
}typedef List;

void makeEmptyList(List* lst);
bool isEmptyList(List* lst);
void insertDataToEndList(List* lst, int data);
freeList(List* lst);
printList(List* lst);

#endif 
