/**
 * @file Player.h
 * @author Dilara Mandıracı section 1 22101643
 * @brief 
 * @version 0.1
 * @date 2022-11-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once
#include <iostream>
#include <string>
using namespace std;

class Player{
public:
    Player();
    ~Player();

    Player(string aTeam, string aName, int aJersey, int aSalary);

    int getSalaray();
    string getPlayerName();
    int getJersey();

    void setProperties(string aTeam, string aName, int aJersey, int aSalary);

    void printPropertiesofPlayer();

private:
    string team;
    string name;
    int jersey;
    int salary;
};


