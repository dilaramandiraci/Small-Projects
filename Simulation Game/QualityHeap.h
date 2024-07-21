/**
* Author : Dilara Mandiraci
* ID: 22101643
* Section : 1
* Homework : 3
* Description : QualityHeap class puts the high quality food in priority.
 * If two foods have same quality, low id one will be prioritazed. */
#ifndef CS202HW3_QUALITYHEAP_H
#define CS202HW3_QUALITYHEAP_H
#include "Food.h"

using namespace std;
const int MAX_HEAP_2 = 50;

class QualityHeap{
public:
    QualityHeap();				// default constructor
    // copy constructor and destructor are supplied by the compiler
    bool heapIsEmpty();
    void heapInsert(const Food& newItem);
    void heapDelete();
    Food& peak();
    bool isFull(){
        return size == MAX_HEAP_2;
    }
protected:
    void heapRebuild(int root);		// Converts the semiheap rooted at
    // index root into a heap
private:
    Food items[MAX_HEAP_2];	// array of heap items
    int  size;            	// number of heap items

};
#endif //CS202HW3_QUALITYHEAP_H
