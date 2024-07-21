/**
* Author : Dilara Mandiraci
* ID: 22101643
* Section : 1
* Homework : 3
* Description : This is the header file of the Food Class */
#ifndef CS202HW3_FOOD_H
#define CS202HW3_FOOD_H
#include <iostream>
using namespace std;

class Food{
private:
    double x;
    double y;
    int id;
    int quality;
    int spawnTime;
public:
    //<ID>,<X>,<Y>,<Quality>,<Spawn Time>
    Food();
    Food(int _id, double _x, double _y, int _quality, int _spawntime);
    int getQuality();
    int getId();
    int getSpawnTime();
    bool canSpawn(int _time);
    const double getX();
    const double getY();

};
#endif //CS202HW3_FOOD_H
