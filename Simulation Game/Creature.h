/**
* Author : Dilara Mandiraci
* ID: 22101643
* Section : 1
* Homework : 3
* Description : This is the header file of the Creature Class */
#ifndef CS202HW3_CREATURE_H
#define CS202HW3_CREATURE_H

#include <iostream>
#include "Food.h"
using namespace std;

class Creature {

private:
    int id;
    double x;
    double y;
    int health;
    bool dead;

public:
    Creature(int _id, double  xCor, double  yCor, int _health);
    bool eat(Food& bestFood);
    bool kill(Creature& other);
    void move(Food bestFood);
    void decreaseHealth();
    int getId();
    int getHealth();
    bool isDead();
    double getX();
    double getY();

    friend bool operator<(const Creature& c1, const Creature& c2){
        if(c1.id < c2.id)
        {
            return true;
        }
        return false;
    }
};


#endif //CS202HW3_CREATURE_H
