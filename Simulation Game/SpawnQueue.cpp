/**
* Author : Dilara Mandiraci
* ID: 22101643
* Section : 1
* Homework : 3
* Description : SpawnQueue class pops the food who has earliest spawn time */
#include "SpawnQueue.h"

bool SpawnQueue::pqIsEmpty() {
    return h.heapIsEmpty();
}

void SpawnQueue::pqInsert(const Food &newItem) {
    h.heapInsert(newItem);
}

void SpawnQueue::pqDelete() {
    h.heapDelete();
}

Food& SpawnQueue::pqPeak() {
    Food& tepe = h.peak();
    return tepe;
}

