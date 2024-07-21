/**
* Author : Dilara Mandiraci
* ID: 22101643
* Section : 1
* Homework : 3
* Description : This file includes the implementations of the functions of Creature Class */
#include "Creature.h"
#include "cmath"
#include <math.h>
Creature::Creature(int _id, double xCor, double yCor, int _health) {
    id = _id;
    x = xCor;
    y = yCor;
    health = _health;
    dead = false;
}

void Creature::decreaseHealth() {
    health--;
    if(health==0)
    {
        dead = true;
    }
}

bool Creature::eat(Food &bestFood) {
    double distance = ::sqrt( pow(x - bestFood.getX(), 2) + pow(y - bestFood.getY(), 2));
    if(distance < 1)
    {
        health += bestFood.getQuality();
        return true;
    }
    else
    {
        return false;
    }
}

void Creature::move(Food bestFood){
    double unitDistance;
    if(health<10)
    {
        unitDistance = 1;
    }
    else
    {
        unitDistance = double (double(10) / health);
    }

    //unitDistance = round(unitDistance * 100) / 100.0;

    /*unitDistance = unitDistance *100;
    unitDistance = ::ceil(unitDistance);
    unitDistance = unitDistance /100;*/

    double distance = ::sqrt( pow(x - bestFood.getX(), 2) + pow(y - bestFood.getY(), 2));
    //double after = distance - unitDistance;
    //after = ::round(after * 100) / 100.0;
    double Ux = double(bestFood.getX() - x) / double(distance);
    //Ux = ::round(Ux*100) / 100.0;
    double Uy = double(bestFood.getY() - y) / double(distance);
    //Uy = ::round(Uy*100) / 100.0;

    x = x + (double(Ux) * double(unitDistance));
    //x= ::round(x*100)/100.0;
    y = y + (double(Uy) * double(unitDistance));
    //y= ::round(y*100)/100.0;
}

bool Creature::kill(Creature &other) {
    double distance = sqrt( pow(x - other.x, 2) + pow(y - other.y, 2));
    if(distance < 2 && health >= other.health)
    {
        other.dead = true;
        return true;
    }
    else
    {
        return false;
    }
}

double Creature::getX() {
    return x;
}

double Creature::getY() {
    return y;
}

int Creature::getId() {
    return id;
}

int Creature::getHealth() {
    return health;
}

bool Creature::isDead() {
    return dead;
}