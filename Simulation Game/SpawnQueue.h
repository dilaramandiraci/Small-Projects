/**
* Author : Dilara Mandiraci
* ID: 22101643
* Section : 1
* Homework : 3
* Description : implementations of SpawnQueue class */
#ifndef CS202HW3_SPAWNQUEUE_H
#define CS202HW3_SPAWNQUEUE_H
#include "SpawnHeap.h"
#include <iostream>

using namespace std;

class SpawnQueue{

public:
    // priority-queue operations:
    //void timepassedUtil();
    bool pqIsEmpty();
    void pqInsert(const Food& newItem) ;
    void pqDelete();
    Food& pqPeak();

private:
    SpawnHeap h;

};
#endif //CS202HW3_SPAWNQUEUE_H
