/**
* Author : Dilara Mandiraci
* ID: 22101643
* Section : 1
* Homework : 3
* Description : This file includes the implementations of the methods of Food class */
#include "Food.h"

Food::Food() {
    id=0;
    x=0;
    y=0;
    quality=0;
    spawnTime=0;
}

Food::Food(int _id, double _x, double _y, int _quality, int _spawntime) {
    id = _id;
    x = _x;
    y = _y;
    quality = _quality;
    spawnTime = _spawntime;
}

bool Food::canSpawn(int _time) {
    if(_time == spawnTime)
    {
        return true;
    }
    return false;
}

int Food::getQuality() {
    return quality;
}

int Food::getId() {
    return id;
}

int Food::getSpawnTime() {
    return spawnTime;
}

const double Food::getX() {
    return x;
}

const double Food::getY() {
    return y;
}