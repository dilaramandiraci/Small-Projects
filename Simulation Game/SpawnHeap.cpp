/**
* Author : Dilara Mandiraci
* ID: 22101643
* Section : 1
* Homework : 3
* Description : implementations oF SpawnHeap class */
#include "SpawnHeap.h"

SpawnHeap::SpawnHeap() {
    size = 0;
}

bool SpawnHeap::heapIsEmpty() {
    if(size==0)
        return true;
    return false;
}

void SpawnHeap::heapInsert(const Food &newItem) {
    if (size >= MAX_HEAP){
        cout<< "Heap if full" <<endl;
        return;
    }

    items[size] = newItem;

    int place = size;
    int parent = (place - 1)/2;
    while ((place > 0) &&
           (items[place].getSpawnTime() < items[parent].getSpawnTime())) {
        Food temp = items[parent];
        items[parent] = items[place];
        items[place] = temp;

        place = parent;
        parent = (place - 1)/2;
    }
    ++size;
}

void SpawnHeap::heapDelete() {
    if(size!=0) {

        items[0] = items[--size];
        heapRebuild(0);
    }
}

void SpawnHeap::heapRebuild(int root) {
    int child = 2 * root + 1;
    if ( child < size ) {
        int rightChild = child + 1;

        if ( (rightChild < size) &&
             (items[rightChild].getSpawnTime() <items[child].getSpawnTime()) )
            child = rightChild;

        if ( items[root].getSpawnTime() > items[child].getSpawnTime() ) {
            Food temp = items[root];
            items[root] = items[child];
            items[child] = temp;

            heapRebuild(child);
        }

    }
}

Food& SpawnHeap::peak() {
    return items[0];
}

