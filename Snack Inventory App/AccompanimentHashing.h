/**
* Title: Balanced search trees and hashing
* Author : Dilara Mandiraci
* ID: 22101643
* Section : 1
* Homework : 4
* Description : This is the header file of AccompanimentHashing class
 * It is a 71 quadratic hashtable, hasfunction works with ASCII of strings*/
#ifndef HW4CS202_ACCOMPANIMENTHASHING_H
#define HW4CS202_ACCOMPANIMENTHASHING_H
#include "Accompaniment.h"


class AccompanimentHashing {
public:
    Accompaniment table [71];
    int tableSize = 71;

    AccompanimentHashing();
    //~AccompanimentHashing();
    int hash(string aComp);
    void insert(Accompaniment aComp);
    Accompaniment& getAcc(Accompaniment aComp);

    void removeAcc(string first, string second);
    bool isThere(string first, string second);
    bool exists(string accName);
};


#endif //HW4CS202_ACCOMPANIMENTHASHING_H
