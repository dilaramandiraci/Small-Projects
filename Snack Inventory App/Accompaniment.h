/**
* Title: Balanced search trees and hashing
* Author : Dilara Mandiraci
* ID: 22101643
* Section : 1
* Homework : 4
* Description : This is the header file of Accompaniment class
 * Accompaniment class which has at least three fields. First field is for the accompaniment name.
The accompaniment name will be the concatenation of the names of two snacks in the group in alphabetical order.
 For example, the group of snacks "Apple" and "Chips" will be "AppleChips".
 The second field will be a pointer to the node corresponding to the Apple object in the
 linked list of Chips’ group/accompaniments, and the third field will be a pointer to the node for Chips in the linked list of Apple’s group/accompaniments. */
#ifndef HW4CS202_ACCOMPANIMENT_H
#define HW4CS202_ACCOMPANIMENT_H
#include <string>
#include <iostream>
#include "Snack.h"
#include "linkedList.h"
#include "Node.h"
using namespace std;

class Accompaniment {
public:
    string accName;
    Node* first;
    Node* second;
    Accompaniment(string name, Snack& snack1, Snack& snack2);
    Accompaniment();
    ~Accompaniment();
};


#endif //HW4CS202_ACCOMPANIMENT_H
