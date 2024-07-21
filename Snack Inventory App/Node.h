/**
* Title: Balanced search trees and hashing
* Author :Dilara Mandiraci
* ID: 22101643
* Section : 1
* Homework : 4
* Description : Header file of Node class */
#ifndef NODE
#define NODE

#include "Snack.h"
#include <iostream>
#include <string>
//using namespace std;

class Snack;
class linkedList;

class Node
{
public:
    Snack* item;
    Node *next;

    Node();
    ~Node();
};

#endif