/**
* Title: Balanced search trees and hashing
* Author : Dilara Mandiraci
* ID: 22101643
* Section : 1
* Homework : 4
* Description : Header file of SnackHashing class sepearte chaining hash table */

#ifndef HW4CS202_SNACKHASHING_H
#define HW4CS202_SNACKHASHING_H
#include <string>
#include <iostream>
#include "Snack.h"
#include <vector>
#include "AccompanimentHashing.h"
#include "linkedList.h"
using namespace std;

class SnackHashing {
public:
    linkedList* table [11];
    int sizeOfTable = 11;


    SnackHashing();
    ~SnackHashing();
    int hash(string aSnack);
    void insert(Snack* aSnack);
    Snack& getSnack(string aSnack);
    bool there(string name);
    void addAcc(string first, string second, AccompanimentHashing& table);
};


#endif //HW4CS202_SNACKHASHING_H
