#include "list.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "memory.h"

void makeEmptyList(List* lst)
{
    lst->head = NULL;
    lst->tail = NULL;
}

bool isEmptyList(List* lst)
{
    if (lst->head == NULL)
        return true;
    else
        return false;
}

ListNode* createNewListNode(int data, ListNode* next)
{
    ListNode* output;
    // Create the node
    output = (ListNode*)malloc(sizeof(ListNode));
    memoryAndFileValidation(output);

    output->dataPtr = malloc(sizeof(int));
    memoryAndFileValidation(output->dataPtr);
    *output->dataPtr = data;
    // Point the node to the next
    output->next = next;
    return output;
}

// insert the node to end of the list
void insertNodeToEndList(List* lst, ListNode* newTail)
{
    if (isEmptyList(lst) == true)
    {
        lst->head = newTail;
        lst->tail = newTail;
    }
    else
    {
        lst->tail->next = newTail;
        lst->tail = newTail;
    }
}

// Create a node and insert into the end of the list
void insertDataToEndList(List* lst, int data)
{
    ListNode* newTail;
    newTail = createNewListNode(data, NULL);
    insertNodeToEndList(lst, newTail);
}

// Free the list
freeList(List* lst)
{
    ListNode* current = lst->head;
    ListNode* next = lst->head->next;
    free(current->dataPtr);
    free(current);
    while (next != NULL)
    {
        current = next;
        next = next->next;
        free(current->dataPtr);
        free(current);
    }
}

// Print the list
printList(List* lst)
{
    ListNode* current = lst->head;
    while (current != NULL)
    {
        printf("%d", *(current->dataPtr));
        // Avoid space at the end
        if (current->next != NULL) printf(" ");
        current = current->next;
    }
    printf("\n");
}