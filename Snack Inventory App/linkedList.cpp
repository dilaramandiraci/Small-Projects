/**
* Title: Balanced search trees and hashing
* Author : Dilara Mandiraci
* ID: 22101643
* Section : 1
* Homework : 4
* Description : Header file of linkedList class */

#include "linkedList.h"

linkedList::linkedList() {
    head = nullptr;
    size=0;
}
linkedList::~linkedList() {
    Node* curr = head;
    while (curr!=nullptr)
    {
        Node* temp = curr;
        curr = curr->next;
        delete temp;
    }
}

void linkedList::insert(Snack& data) {
    if(exists(data.name))
    {
        return;
    }
    Node* newNode = new Node();
    newNode->item = &data;
    newNode->next = head;
    head = newNode;
    size++;
}

void linkedList:: remove(Snack& data) {
    if (head == nullptr) {
        return;
    }
    Node* current = head;
    Node* previous = nullptr;

    while (current != nullptr && current->item->name != data.name) {
        previous = current;
        current = current->next;
    }
    //no element not found
    if (current == nullptr) {
        return;
    }

    if (previous == nullptr) {
        head = head->next;
    }
    else {
        previous->next = current->next;
    }

    Node* curr = head;
    if(curr == nullptr)
    {
        head = current;
        current->next = nullptr;
        size--;
        return;
    }

    while(curr->next!= nullptr)
    {
        curr = curr->next;
    }

    curr->next = current;
    current->next = nullptr;
    size--;
}

void linkedList::display() {
    Node* curr = head;
    int i=0;
    while (curr != nullptr && i<size) {
        if(i!=size-1)
        {
            cout << curr->item->name << " ";
        }
        else
        {
            cout << curr->item->name;
        }
        curr = curr->next;
        i++;
    }
        cout << endl;
}

bool linkedList:: exists(string data) {
    Node* curr = head;
    int i = 0;
    while (curr != nullptr && i < size) {
        if (curr->item->name == data) {
            return true;
        }
        curr = curr->next;
        i++;
    }
    return false;
}

Node* linkedList::getNode(string name) {
    Node* curr = head;
    int i = 0;
    while (curr != nullptr && i < size) {
        if (curr->item->name == name) {
            return curr;
        }
        curr = curr->next;
        i++;
    }
    return nullptr;
}