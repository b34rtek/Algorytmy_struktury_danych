#include "MinHeap.h"

void initHeap(MinHeap& heap, int maxSize) {
    heap.data = new Field*[maxSize];
    heap.size = 0;
    heap.capacity = maxSize;
}

void heapPush(MinHeap& heap, Field* field) {
    int i = heap.size++;
    heap.data[i] = field;

    while (i > 0) {
        int parent = (i - 1) / 2;
        if (heap.data[parent]->cost <= heap.data[i]->cost) break;

        Field* temp = heap.data[parent];
        heap.data[parent] = heap.data[i];
        heap.data[i] = temp;
        i = parent;
    }
}

Field* heapPop(MinHeap& heap) {
    if (heap.size == 0) return nullptr;

    Field* top = heap.data[0];
    heap.data[0] = heap.data[--heap.size];

    int i = 0;
    while (true) {
        int L = 2 * i + 1;
        int R = 2 * i + 2;
        int min = i;

        if (L < heap.size && heap.data[L]->cost < heap.data[min]->cost) min = L;
        if (R < heap.size && heap.data[R]->cost < heap.data[min]->cost) min = R;
        
        if (min == i) break;

        Field* temp = heap.data[i];
        heap.data[i] = heap.data[min];
        heap.data[min] = temp;
        i = min;
    }
    return top;
}

void cleanupHeap(MinHeap& heap) {
    delete[] heap.data;
}