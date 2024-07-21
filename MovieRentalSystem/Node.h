#pragma once
#include <iostream>
#include <string>
using namespace std;

template <class ItemType>
class Node {
    public:
        ItemType item;
        Node< ItemType> * next;

        Node()
        {};

        Node(const ItemType& it)
        {
            item = it;
            next = nullptr;
        }

        Node(const ItemType& it, Node< ItemType> * nextnd)
        {
            item = it;
            next = nextnd;
        }

};

// template class Node<Movie>;
// template class Node<Subscriber>;
// template class Node<Action>;
