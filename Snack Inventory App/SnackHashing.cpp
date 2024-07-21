/**
* Title: Balanced search trees and hashing
* Author : Dilara Mandiraci
* ID: 22101643
* Section : 1
* Homework : 4
* Description : Implementations of SnackHashing class  */

#include "SnackHashing.h"
SnackHashing::SnackHashing() {
    for(int i = 0; i<11; i++)
    {
        table[i] = new linkedList();
    }
}
SnackHashing::~SnackHashing() {
    for(int i = 0; i<11; i++)
    {
        delete table[i];
    }
}

int SnackHashing::hash(string aSnack) {
    string key = aSnack;
    int ascii = 0;
    for (char c : key) {
        ascii += int(c);
    }
    return ascii % sizeOfTable;
}

void SnackHashing::insert(Snack* aSnack) {
    if(there(aSnack->name))
    {
        return;
    }
    int i = hash(aSnack->name);
    linkedList* list = table[i];
    list->insert(*aSnack);
    cout << "Snack '"<< aSnack->name <<"' created" <<endl;
}

Snack &SnackHashing::getSnack(string aSnack) {
    int key = hash(aSnack);
    linkedList* list = table[key];

    return *list->getNode(aSnack)->item;
}

bool SnackHashing::there(string name) {

    int i = hash(name);
    linkedList* list = table[i];
    return list->exists(name);
}

void SnackHashing::addAcc(string first, string second, AccompanimentHashing& table) {

    if(first==second)
    {
        return;
    }

    if(!there(first) || !there(second))
    {
        return;
    }
    if(table.isThere(first, second))
    {
        return;
    }

    Snack& fSnack = getSnack(first);
    Snack& sSnack = getSnack(second);

    fSnack.addAccompaniment(sSnack);
    sSnack.addAccompaniment(fSnack);

    string accName;

    if(first<second)
    {
        accName = first+second;
        Accompaniment ac(accName, sSnack, fSnack );
        table.insert(ac);
    }
    else
    {
        accName = second+first;
        Accompaniment ac(accName, fSnack, sSnack);
        table.insert(ac);
    }

}

