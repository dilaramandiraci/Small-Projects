#pragma once
#include <iostream>
#include <string>
#include "Node.h"
#include "Action.h"
using namespace std;

class Movie
{
public:
    int id;
    int mevcutcopy;
    int origCopyNo;
    Node<Action> *transactions;

public:
    Movie(int id, int copyNumber);
    Movie()
    {
    }
    ~Movie();
    void setAction(int id, string status);

    void printMovie()
    {
        cout << id << " " << origCopyNo << endl;
    }

    void movieRented()
    {
        mevcutcopy--;
    }

    void movieGeldi()
    {
        mevcutcopy++;
    }

    void movieReturned(int subscriberId)
    {
        Node<Action> *curr = transactions;
        while (curr != nullptr)
        {
            if (curr->item.getId() == subscriberId && curr->item.getStatus() == "not returned")
            {
                curr->item.setStatus("returned");
                break;
            }
            curr = curr->next;
        }
    }

    int getdata()
    {
        return id;
    }

    void printTransactionsOfMovie()
    {
        Node<Action> *curr = transactions;
        if (curr == nullptr)
        {
            cout << "Movie " << id << " has not been rented by any subscriber" << endl;
        }
        else
        {
            cout << "Movie " << id << " has been rented by the following subscribers:" << endl;
        }
        while (curr != nullptr)
        {
            curr->item.printAction();
            curr = curr->next;
        }
    }

    void deleteSubsFromActions(int subscriberId)
    {
        Node<Action> *curr = transactions;
        Node<Action> *prev = nullptr;
        while (curr != nullptr)
        {
            if (curr->item.getId() == subscriberId)
            {
                if (curr == transactions)
                {
                    transactions = transactions->next;
                    delete curr;
                    curr = transactions;

                }
                else
                {
                    prev->next = curr->next;
                    delete curr;
                    curr = prev->next;
                }
                // break;
            }
            else
            {
                prev = curr;
                curr = curr->next; //yeni curr.next;
            }
            
        }
    }

};

Movie::Movie(int id, int copyNumber)
{
    this->id = id;
    origCopyNo = copyNumber;
    mevcutcopy = copyNumber;
    transactions = nullptr;
}

Movie::~Movie()
{
    Node<Action> *curr = transactions;
    while (curr != nullptr)
    {
        curr = transactions->next;
        delete transactions;
        transactions = curr;
    }
    // actionları sil
}

void Movie::setAction(int id, string status)
{
    Action addedAction(id, status); // BÖYLE Mİ VERİLMELİ???
    Node<Action> *eklenecek = new Node<Action>;
    eklenecek->item = addedAction;

    Node<Action> *curr = transactions;
    Node<Action> *prev = nullptr;

    while ((curr != nullptr) && (id > curr->item.getId()))
    {
        prev = curr;
        curr = curr->next;
    }

    if (prev == nullptr)
    {
        eklenecek->next = transactions;
        transactions = eklenecek; // transactions->next = eklenecek;
    }
    else
    {
        eklenecek->next = curr;
        prev->next = eklenecek;
    }
}
