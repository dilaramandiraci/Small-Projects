/**
* Title: Balanced search trees and hashing
* Author : Dilara Mandiraci
* ID: 22101643
* Section : 1
* Homework : 4
* Description : Implementations of linkedList class */

#ifndef LISTHW4_LINKEDLIST_H
#define LISTHW4_LINKEDLIST_H

#include <iostream>
#include <string>
#include "Snack.h"
#include "Node.h"
using namespace std;

class Snack;
class Node;

class linkedList {
private:
    Node* head;
    int size;

public:
    // Constructor
    linkedList();
    ~linkedList();
    // Insert a new node at the beginning of the list
    void insert(Snack& data) ;
    void remove(Snack& data) ;
    void display();
    bool exists(string data);
    Node* getNode(string name);

};


#endif //LISTHW4_LINKEDLIST_H
