/**
 * @file Team.cpp
 * @author Dilara Mandıracı section 1 22101643
 * @brief 
 * @version 0.1
 * @date 2022-11-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include "Team.h"
#include <string>
using namespace std;

Team::Team(string aTeamName, int year)
{
    teamName = aTeamName;
    foundingYear = year;
    noOfPlayers = 0;
    players = nullptr;
    totalSalary = 0;
}

Team::Team()
{
    noOfPlayers = 0;
    players = nullptr;
}

Team::~Team()
{
    if (players != nullptr)
    {
        delete[] players;
    }
}

void Team::setProperties(string aTeamName, int year)
{
    teamName = aTeamName;
    foundingYear = year;
}

string Team::getteamname()
{
    return teamName;
}

Player* Team::getPlayers()
{
    return players;
}

int Team::getNoOfPlayers()
{
    return noOfPlayers;
}

void Team::playeraddedtoteam(int salary)
{
    noOfPlayers++;
    totalSalary = totalSalary + salary;
}

void Team::playerremovedfromteam(int salary)
{
    if (players != nullptr)
    {
        noOfPlayers--;
        totalSalary = totalSalary - salary;
    }
}

void Team::setPlayerPointer(Player *ptr)
{
    if (players != nullptr)
    {
        delete[] players;
    }
    players = ptr;
}

void Team::addPlayer(const string playerName, const int jersey, const int salary)
{
    Player *outarr = new Player[noOfPlayers + 1];

    int j = 0;

    for (int i = 0; i < noOfPlayers; i++)
    {
        outarr[j] = players[i]; // inarr[i]
        j++;
    }

    Player b(teamName, playerName, jersey, salary);
    outarr[j] = b;

    // outarr[j].setProperties(teamName, playerName, jersey, salary);
    if (players != nullptr)
    {
        delete[] players;
    }
    players = outarr;
}

void Team::removePlayer(string playerName)
{
    if (noOfPlayers == 1)
    {
        totalSalary -= players[0].getSalaray();
        delete[] players;
        players = nullptr;
    }

    else
    {
        Player *outarr = new Player[noOfPlayers - 1];

        int j = 0;

        for (int i = 0; i < noOfPlayers; i++)
        {
            if (players[i].getPlayerName() != playerName)
            {
                outarr[j] = players[i];
                j++;
            }
            else
            {
                totalSalary -= players[i].getSalaray();
                players[i].~Player();
            }
        }

        delete[] players;
        players = outarr;
    }

    noOfPlayers--;
}

void Team::printPropertiesofTeam()
{
    cout << teamName << ", " << foundingYear << ", " << noOfPlayers << " players, "
         << totalSalary << " TL total salary " << endl;
}