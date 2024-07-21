/**
* Author : Dilara Mandiraci
* ID: 22101643
* Section : 1
* Homework : 3
* Description : implementations of QualityHeap class */
#include "QualityHeap.h"

QualityHeap::QualityHeap() {
    size = 0;
}

bool QualityHeap::heapIsEmpty() {
    if(size==0)
        return true;
    return false;
}

Food& QualityHeap::peak() {
        return items[0];
}

void QualityHeap::heapInsert(const Food &newItem) {
    if (size >= MAX_HEAP_2){
        cout<< "Heap if full" <<endl;
        return;
    }

    // Place the new item at the end of the heap
    items[size] = newItem;

    // Trickle new item up to its proper position
    int place = size;
    int parent = (place - 1)/2;
    while ((place > 0) &&
           (items[place].getQuality() > items[parent].getQuality() ||
            (items[place].getQuality() == items[parent].getQuality() && items[place].getId() < items[parent].getId()))) {
        Food temp = items[parent];
        items[parent] = items[place];
        items[place] = temp;

        place = parent;
        parent = (place - 1)/2;
    }
    ++size;
}

void QualityHeap::heapDelete() {
    if (size == 0)
    {
        //throwHeapException("HeapException: Heap empty");
    }
    else {
        //Food rootItem = items[0];
        items[0] = items[--size];
        heapRebuild(0);
        //return rootItem;
    }
}

void QualityHeap::heapRebuild(int root) {
    int child = 2 * root + 1; 	// index of root's left child, if any
    if ( child < size ) {
        // root is not a leaf so that it has a left child
        int rightChild = child + 1; 	// index of a right child, if any
        // If root has right child, find larger child
        if ( (rightChild < size) &&
             (items[rightChild].getQuality() > items[child].getQuality()
             || (items[rightChild].getQuality() == items[child].getQuality() && items[rightChild].getId() < items[child].getId())))
            child = rightChild; 	// index of larger child

        // If root’s item is smaller than larger child, swap values
        if ( items[root].getQuality() < items[child].getQuality()
        || (items[root].getQuality() == items[child].getQuality() && items[root].getId() > items[child].getId())) {
            Food temp = items[root];
            items[root] = items[child];
            items[child] = temp;

            // transform the new subtree into a heap
            heapRebuild(child);
        }

    }
}


