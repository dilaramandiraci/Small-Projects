/**
* Title: Balanced search trees and hashing
* Author : Dilara Mandiraci
* ID: 22101643
* Section : 1
* Homework : 4
* Description : Implementations of Snack class */

#include "Snack.h"
Snack::Snack(string aName) {
    name = aName;
    accList= new linkedList();
}

Snack::Snack() {
    name= "";
    accList= new linkedList();
}
Snack::~Snack() {
    delete accList;
}
void Snack::addAccompaniment(Snack& aSnack) {
    //check if it is same with this snack
    if(aSnack.name == name)
    {
        return;
    }
    accList->insert(aSnack);
}

void Snack::removeAccompaniment(Snack& aSnack) {
    //check if it is same with this snack
    if(aSnack.name == name || !accList->exists(aSnack.name))
    {
        return;
    }
    accList->remove(aSnack);
}

void Snack::listAccompaniments() {
    accList->display();
}