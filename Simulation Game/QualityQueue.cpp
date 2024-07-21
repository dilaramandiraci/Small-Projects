/**
* Author : Dilara Mandiraci
* ID: 22101643
* Section : 1
* Homework : 3
* Description : implementations of QualityQueue class */
#include "QualityQueue.h"
bool QualityQueue::pqIsEmpty() {
    return h.heapIsEmpty();
}

void QualityQueue::pqInsert(const Food &newItem) {
    h.heapInsert(newItem);
}

void QualityQueue::pqDelete() {
     h.heapDelete();
}
Food& QualityQueue::pqPeak() {
    Food& tepe = h.peak();
    return tepe;
}

bool QualityQueue::isFull() {
    if(h.isFull())
    {
        return true;
    }
    else
    {
        return false;
    }
}