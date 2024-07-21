/**
 * @file Player.cpp
 * @author Dilara Mandıracı section 1 22101643
 * @brief 
 * @version 0.1
 * @date 2022-11-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "Player.h"
using namespace std;

Player::Player()
{
    team = "";
    name = "";
    jersey = 0;
    salary = 0;
}

Player::~Player()
{
}

Player:: Player(string aTeam, string aName, int aJersey, int aSalary)
{
    team = aTeam;
    name = aName;
    jersey = aJersey;
    salary = aSalary;
}

void Player::setProperties(string aTeam, string aName, int aJersey, int aSalary)
{
    team = aTeam;
    name = aName;
    jersey = aJersey;
    salary = aSalary;
}

int Player:: getSalaray()
{
    return salary;
}

string Player:: getPlayerName()
{
    return name;
}

int Player::getJersey()
{
    return jersey;
}

void Player:: printPropertiesofPlayer()
{
    cout<< name << ", jersey " << jersey << ", " << salary << " TL salary." << endl;
}
