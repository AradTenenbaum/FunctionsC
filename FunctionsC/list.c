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

// insert the node to end of the list
void insertNodeSortedList(List* lst, ListNode* newNode)
{
    if (isEmptyList(lst) == true)
    {
        lst->head = newNode;
        lst->tail = newNode;
    }
    else if (*(lst->head->dataPtr) > *(newNode->dataPtr))
    {
        newNode->next = lst->head;
        lst->head = newNode;
    }
    else if (*(lst->tail->dataPtr) < *(newNode->dataPtr)) {
        lst->tail->next = newNode;
        lst->tail = newNode;
    }
    else {
        ListNode* curr = lst->head;
        ListNode* prev = NULL;
        while (curr && *(curr->dataPtr) < *(newNode->dataPtr)) {
            prev = curr;
            curr = curr->next;
        }
        prev->next = newNode;
        newNode->next = curr;
    }
}

// Create a node and insert into the end of the list
void insertDataToEndList(List* lst, int data)
{
    ListNode* newTail;
    newTail = createNewListNode(data, NULL);
    insertNodeToEndList(lst, newTail);
}

// Create a node and insert after a node that is smaller than it
void insertDataSortedList(List* lst, int data)
{
    ListNode* newNode;
    newNode = createNewListNode(data, NULL);
    insertNodeSortedList(lst, newNode);
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