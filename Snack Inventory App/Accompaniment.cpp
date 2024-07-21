/**
* Title: Balanced search trees and hashing
* Author : Dilara Mandiraci
* ID: 22101643
* Section : 1
* Homework : 4
* Description : This is the cpp file of Accompaniment class
*/
#include "Accompaniment.h"
Accompaniment::Accompaniment(string name, Snack& snack1, Snack& snack2) {
    accName = name;
    first = snack1.accList->getNode(snack2.name);
    second = snack2.accList->getNode(snack1.name);
}

Accompaniment::Accompaniment() {
    accName = "";
    first = nullptr;
    second = nullptr;
}

Accompaniment::~Accompaniment() {

}

