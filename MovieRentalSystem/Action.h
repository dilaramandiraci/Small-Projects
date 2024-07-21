#pragma once
#include <iostream>
#include <string>
#include"Movie.h"
using namespace std;
class Action
{
private:
    int id;
    string status;  
public:
    Action(int actionid , string returnStatus);
    ~Action();
    Action()
    {

    }
    string getStatus()
    {
        return status;
    }

    void setStatus(string astatus)
    {
        status = astatus;
    }

    int getId();

    void printAction()
    {
        cout << id << " " << status << endl;
    }
};

Action::Action(int actionid , string returnStatus)
{
    id = actionid;
    status = returnStatus;
}

Action::~Action()
{
}

int Action::getId()
{
    return id;
}

//insert needs to be written to add actions in action order.

//operator > needs to overload for movie,subs

//get node entry e göre, mesela 1111 subs a movie ekleneceği 
//zaman 1111 olan subs ı getirmesi lazım