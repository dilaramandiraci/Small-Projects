/**
 * @file Team.h
 * @author Dilara Mandıracı section 1 22101643
 * @brief 
 * @version 0.1
 * @date 2022-11-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once
#include "Player.h"
using namespace std;

class Team
{
public:
    Team(string aTeamName, int year);
    Team();
    ~Team();

    void setProperties(string aTeamName, int year);


    string getteamname();
    Player *getPlayers();
    int getNoOfPlayers();

    void playeraddedtoteam(int salary);
    void playerremovedfromteam(int salary);

    void setPlayerPointer(Player *ptr);

    void addPlayer(const string playerName, const int jersey, const int salary);
    void removePlayer (string playerName);
  
    void printPropertiesofTeam();
  

private:
    string teamName;
    int noOfPlayers;
    int foundingYear;
    Player *players;
    int totalSalary;
};
