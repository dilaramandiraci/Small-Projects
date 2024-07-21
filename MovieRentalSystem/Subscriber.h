#pragma once
#include <iostream>
#include <string>
#include "Action.h"
#include "Node.h"
#include "Movie.h"
using namespace std;
class Subscriber
{
public:
    int subscriberId;
    Node<Action>* transactions;
    int movieNumber;
public:
    Subscriber(int id);
    Subscriber();
    ~Subscriber();
    void setAction(int id, string status);
    void print()
    {
        cout<<subscriberId;
    }
    void movieRentedS()
    {
        movieNumber++;
    }

    void movieReturnedS()
    {
        movieNumber--;
    }

    int getdata() const
    {
        return subscriberId;
    }

    bool canSubsRemoveFromSystem()
    {
        if(movieNumber == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool ReturnMovie(int movId)
    {
        Node<Action>* curr = transactions;
        while(curr!=nullptr)
        {
            if((curr->item.getId()==movId) && (curr->item.getStatus() == "not returned"))
            {
                curr->item.setStatus("returned");
                movieNumber--;
                return true;
            }
            curr = curr->next;
        }
        return false;
    }

    void printTransactionsOfSubscriber()
    {
        Node<Action>* curr = transactions;
        if(curr == nullptr)
        {
            cout << "Subscriber " << subscriberId <<" has not rented any movies" << endl;
        }
        else
        {
            cout << "Subscriber "<< subscriberId <<" has rented the following movies:" << endl;
        }
        while(curr!=nullptr)
        {
            curr->item.printAction();
            curr = curr->next;
        }
    }

/* friend bool operator > (Subscriber& subs1,Subscriber& subs)
{
    return subs1.getdata() > subs.getdata();
} */

/* friend ostream& operator<<(ostream& out, Subscriber subs){
    out << subs.subscriberId << endl;
    return out;
} */
    
};

Subscriber::Subscriber(int id)
{
    this->subscriberId = id;
    transactions = nullptr; 
    movieNumber = 0; 
}

Subscriber::Subscriber()
{
    this->subscriberId = 0;   
}

Subscriber::~Subscriber()
{
    Node<Action>* curr = transactions;
    while(curr!=nullptr)
    {
        curr = transactions->next;
        delete transactions;
        transactions = curr;
    }
}

void Subscriber:: setAction(int id, string status)
{
    Action addedAction(id,status);  //BÖYLE Mİ VERİLMELİ???
    Node<Action>* eklenecek = new Node<Action>(addedAction);
    //eklenecek->item = addedAction;

    Node<Action>* curr = transactions;
    Node<Action>* prev = nullptr;

    while((curr!=nullptr) && id > curr->item.getId() )    
    {

        prev = curr;
        curr = curr->next;

    }

    while(curr!=nullptr)  ////DEĞİŞİKLİK YAPTIM BU WHILE YOKTU
    {
        if(id==curr->item.getId())
        {
            if(status == "not returned")
            {
                prev = curr;
                curr = curr->next;
            }

        }
        else
        {
            break;
        }
    }
    
    if(prev==nullptr)
    {
        eklenecek->next = transactions;
        transactions = eklenecek;
    }
    else
    {       
        eklenecek->next = curr;
        prev->next=eklenecek;
    }
}

