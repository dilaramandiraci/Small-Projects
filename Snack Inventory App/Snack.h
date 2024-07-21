/**
* Title: Balanced search trees and hashing
* Author : Dilara Mandiraci
* ID: 22101643
* Section : 1
* Homework : 4
* Description : Header file of Snack class */

#ifndef HW4CS202_SNACK_H
#define HW4CS202_SNACK_H
#include <string>
#include <iostream>
#include "linkedList.h"
using namespace std;

class linkedList;
class Node;

class Snack {
public:
    string name;
    linkedList* accList;

    Snack(string aName);
    Snack();
    ~Snack();
    void addAccompaniment(Snack& aSnack);
    void removeAccompaniment(Snack& aSnack);
    void listAccompaniments();
};


#endif //HW4CS202_SNACK_H
