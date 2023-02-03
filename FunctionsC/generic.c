#include "generic.h"
#include <stdio.h>
#include <stdbool.h>

// Generic binary search
int binSearch(void* Arr, int Size, int ElemSize,
    void* Item, int (*compare)(void*, void*)) {

    bool found = false;
    int left = 0;
    int right = Size - 1;
    int place;

    int compRes;

    // By the given algorithem
    while (left <= right && !found) {
        place = (left + right) / 2;
        // Compare function, send data by the location
        compRes = compare(((BYTE*)Arr + place * ElemSize), (BYTE*)Item);
        if (compRes == 0) {
            found = true;
        }
        else if (compRes < 0) {
            left = place + 1;
        }
        else {
            right = place - 1;
        }

    }

    return found;
}


// Swap 2 generic variables values
void swap(void* a, void* b, int elemSize)
{
    int i;
    BYTE temp;
    BYTE* first = (BYTE*)a;
    BYTE* second = (BYTE*)b;
    for (i = 0; i < elemSize; i++)
    {
        temp = *(first + i);
        *(first + i) = *(second + i);
        *(second + i) = temp;
    }
}
// @Hadar Binsky

// Sort generic array
void sort(void* arr, int numElem, int elemSize, int (*compare)(void*, void*))
{
    int i, j;
    for (i = numElem - 1; i > 0; i--)
        for (j = 0; j < i; j++)
            if (compare((BYTE*)arr + j * elemSize, (BYTE*)arr + (j + 1) * elemSize) > 0)
                swap((BYTE*)arr + j * elemSize, (BYTE*)arr + (j + 1) * elemSize, elemSize);
}
// @Hadar Binsky


// Generic function, run from begin until stop returns 1
// Get next adress using advance, 
// Run a function func for each element
void Run(void* begin, int(*stop)(void*), void (*func)(void*), void* (*advance)(void*)) {
    void* curr = begin;
    while (!stop(curr)) {
        func(curr);
        curr = advance(curr);
    }
}