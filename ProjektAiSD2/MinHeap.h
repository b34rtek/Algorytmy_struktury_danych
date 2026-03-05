#ifndef MINHEAP_H
#define MINHEAP_H

#include "Structures.h"

struct MinHeap {
    Field** data;
    int size;
    int capacity;
};

void initHeap(MinHeap& heap, int maxSize);
void heapPush(MinHeap& heap, Field* field);
Field* heapPop(MinHeap& heap);
void cleanupHeap(MinHeap& heap);

#endif