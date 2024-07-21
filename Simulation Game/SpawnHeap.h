/**
* Author : Dilara Mandiraci
* ID: 22101643
* Section : 1
* Homework : 3
* Description : SpawnHeap class puts the priority to the food who has earliest spawn time */
#ifndef CS202HW3_SPAWNHEAP_H
#define CS202HW3_SPAWNHEAP_H
#include "Food.h"

using namespace std;
const int MAX_HEAP = 50;

class SpawnHeap{
public:
    SpawnHeap();
    bool heapIsEmpty();
    void heapInsert(const Food& newItem);
    void heapDelete(); //food & vardı
    Food& peak();

protected:
    void heapRebuild(int root);
private:
    Food items[MAX_HEAP];	// array of heap items
    int  size;            	// number of heap items
    
};
#endif //CS202HW3_SPAWNHEAP_H
