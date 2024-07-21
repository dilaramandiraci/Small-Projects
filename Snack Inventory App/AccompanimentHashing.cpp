/**
* Title: Balanced search trees and hashing
* Author : Dilara Mandiraci
* ID: 22101643
* Section : 1
* Homework : 4
* Description : This is the method implementations of AccompanimentHashing class */

#include "AccompanimentHashing.h"
AccompanimentHashing::AccompanimentHashing() {

}

int AccompanimentHashing::hash(string aComp) {
    string key = aComp;
    int ascii = 0;
    for (char c : key) {
        ascii += int(c);
    }
    return ascii % tableSize;
}

void AccompanimentHashing::insert(Accompaniment aComp) {
    if(exists(aComp.accName))
    {
        return;
    }
    int key = hash(aComp.accName);
    if(table[key].accName == "") //exact position is empty
    {
        table[key] = aComp;
    }
    else{
        int counter = 1;
        while (true) {
            int otherKey = (key + (counter * counter)) % tableSize;
            if (table[otherKey].accName.empty()) {
                table[otherKey] = aComp;
                break;
            }
            counter++;
        }
    }
}

void AccompanimentHashing::removeAcc(string first, string second) {
    if(first == second)
    {
        return;
    }
    string aComp;
    if(first<second)
    {
        aComp = first+second;
    }
    else
    {
        aComp = second+first;
    }
    int key = hash(aComp);
    bool found = false;
    Accompaniment& removal = table[key];

    if( table[key].accName == aComp) //!table[key].accName.empty() &&
    {
        removal = table[key]; //found at the exact position
        found = true;

    }
    else
    {
        int counter = 1;
        while (!found && counter <= tableSize) {
            int otherKey = (key + counter * counter) % tableSize;
            if (table[otherKey].accName == aComp) { //!table[otherKey].accName.empty() &&
                removal = table[otherKey];
                found = true;
                table[otherKey].accName = "";
                table[otherKey].second = nullptr;
                table[otherKey].first = nullptr;
            }
            counter++;
        }
    }

    if(found)
    {
        removal.second->item->removeAccompaniment(*removal.first->item);
        removal.first->item->removeAccompaniment(*removal.second->item);
        table[key].accName = "";
        table[key].second = nullptr;
        table[key].first = nullptr;
    }
}

bool AccompanimentHashing::isThere(string first, string second) {
    if(first == second)
    {
        return false;
    }
    string aName;
    if(first<second)
    {
        aName = first+second;
    }
    else
    {
        aName = second+first;
    }
    int key = hash(aName);
    if(table[key].accName == aName)
    {
        return true; //found at the exact position
    }
    else
    {
        int counter = 1;
        while (counter <= tableSize) {
            int otherKey = (key + counter * counter) % tableSize;
            if (table[otherKey].accName == aName) {
                return true;
            }
            counter++;
        }
    }
    return false;
}

//this method is same with the above one but in terms of arguments this one used internally
bool AccompanimentHashing::exists(string aName) {
    int key = hash(aName);
    if(!table[key].accName.empty() && table[key].accName == aName)
    {
        return true; //found at the exact position
    }
    else
    {
        int counter = 0;
        while (counter < tableSize) { //counter * counter <= tableSize
            int otherKey = (key + counter * counter) % tableSize;
            if (!table[otherKey].accName.empty() && table[otherKey].accName == aName) {
                return true;
            }
            counter++;
        }
    }
    return false;
}