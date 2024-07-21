/**
* Author : Dilara Mandiraci
* ID: 22101643
* Section : 1
* Homework : 3
* Description : Header File of the QualityQueue class, pops the high quality food */
#ifndef CS202HW3_QUALITYQUEUE_H
#define CS202HW3_QUALITYQUEUE_H
#include "Food.h"
#include "QualityHeap.h"


class QualityQueue {
public:
    // priority-queue operations:
    bool pqIsEmpty();
    void pqInsert(const Food& newItem) ;
    void pqDelete();
    Food& pqPeak();
    bool isFull();

private:
    QualityHeap h;
};

#endif //CS202HW3_QUALITYQUEUE_H
