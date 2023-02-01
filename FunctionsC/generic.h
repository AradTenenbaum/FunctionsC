#ifndef _GENERIC_H
#define _GENERIC_H

typedef unsigned char BYTE;

int binSearch(void* Arr, int Size, int ElemSize,
    void* Item, int (*compare)(void*, void*));
void swap(void* a, void* b, int elemSize);

#endif 
