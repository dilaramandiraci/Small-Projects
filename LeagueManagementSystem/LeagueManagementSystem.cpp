/**
 * @file LeagueManagementSystem.cpp
 * @author Dilara Mandıracı section 1 22101643
 * @brief 
 * @version 0.1
 * @date 2022-11-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
using namespace std;
#include "LeagueManagementSystem.h"

LeagueManagementSystem::LeagueManagementSystem()
{
    teams = nullptr;
    noOfTeams = 0;
}
LeagueManagementSystem::~LeagueManagementSystem()
{
    if (teams != nullptr)
    {
        for (int i = 0; i < noOfTeams; i++)
        {
            delete teams[i];
        }
        delete[] teams;
    }
}

void LeagueManagementSystem::showAllTeams() const
{
    cout << "Teams in the league management system: " << endl;
    if (teams == nullptr)
    {
        cout << "None" << endl;
        return;
    }

    else
    {
        for (int i = 0; i < noOfTeams; i++)
        {
            Team *check = teams[i];
            teams[i]->printPropertiesofTeam();
        }
    }
}

void LeagueManagementSystem ::addTeam(const string name, const int year)
{
    int j = 0;
    int index = -1;

    for (int i = 0; i < noOfTeams; i++)
    {
        if ((*teams[i]).getteamname() == name)
        {
            index = i;
        }
    }

    if (index < 0)  //noOfTeams >= 0 &&
    {
        Team **outarr = new Team *[noOfTeams + 1];

        for (int i = 0; i < noOfTeams; i++)
        {
            outarr[j] = teams[i];
            j++;
        }

        Team *b = new Team(name, year);
        outarr[j] = b;

        if (teams != nullptr)
        {
            delete[] teams;
        }
        teams = outarr;
        noOfTeams++;
        cout << "Added team " << name << endl;
    }

    else
    {
        cout << "Cannot add team. Team " << name << " already exists." << endl;
    }
}

void LeagueManagementSystem ::removeTeam(const string name)
{
    int j = 0;
    int index = -1;

    for (int i = 0; i < noOfTeams; i++)
    {
        if ((*teams[i]).getteamname() == name)
        {
            index = i;
        }
    }

    if (noOfTeams == 1 && index >= 0)
    {
        delete teams[0];
        delete[] teams;
        teams = nullptr;
        noOfTeams--;
        cout << "Removed team " << name << endl;
        return;
    }

    if (noOfTeams > 1 && index >= 0)
    {
        Team **outarr = new Team *[noOfTeams - 1];
        for (int i = 0; i < noOfTeams; i++)
        {
            if (teams[i]->getteamname() != name)
            {
                outarr[j] = teams[i];
                j++;
            }
            else
            {
                delete teams[i];
            }
        }

        cout << "Removed team " << name << endl;

        delete[] teams;
        teams = outarr;
        noOfTeams--;
    }
    else
    {
        cout << "Cannot remove team. Team " << name << " does not exist." << endl;
    }
}

void LeagueManagementSystem ::addPlayer(const string teamName, const string playerName, const int jersey, const int salary)
{
    int teamindex = -1;
    int playerexist = -1;
    int jerseyexist = -1;

    if (noOfTeams > 0)
    {
        for (int i = 0; i < noOfTeams; i++)
        {
            if (teams[i]->getteamname() == teamName)
            {
                teamindex = i;
            }
        }
    }

    if (teamindex < 0)
    {
        cout << "Cannot add player. Team " << teamName << " does not exist" << endl;
        return;
    }

    const int size = teams[teamindex]->getNoOfPlayers();

    for (int i = 0; i < size; i++)
    {
        if (teams[teamindex]->getPlayers()[i].getPlayerName() == playerName)
        {
            playerexist = 1;
        }

        if (teams[teamindex]->getPlayers()[i].getJersey() == jersey)
        {
            jerseyexist = 1;
        }
    }

    if (playerexist > 0)
    {
        cout << "Cannot add player. Player " << playerName << " already exists in team " << teamName << endl;
        return;
    }

    else if (jerseyexist > 0)
    {
        cout << "Cannot add player. Jersey number " << jersey << " already exists in team " << teamName << endl;
        return;
    }

    if (playerexist < 0 && jerseyexist < 0 && teamindex >= 0)
    {
        teams[teamindex]->addPlayer(playerName, jersey, salary);
        teams[teamindex]->playeraddedtoteam(salary);
        cout << "Added player " << playerName << " to team " << teamName << endl;
    }
}

void LeagueManagementSystem ::removePlayer(const string teamName, const string playerName)
{
    int teamindex = -1;
    int playerexist = -1;
    int removedPlayerSalary = -1;

    if (noOfTeams > 0)
    {
        for (int i = 0; i < noOfTeams; i++)
        {
            if (teams[i]->getteamname() == teamName)
            {
                teamindex = i;
            }
        }
    }

    if (teamindex < 0)
    {
        cout << "Cannot remove player. Team " << teamName << " does not exist" << endl;
        return;
    }

    int size = teams[teamindex]->getNoOfPlayers();

    for (int i = 0; i < size; i++)
    {
        if (teams[teamindex]->getPlayers()[i].getPlayerName() == playerName)
        {
            playerexist = 1;
        }
    }

    if (playerexist < 0)
    {
        cout << "Cannot remove player. Player " << playerName << " does not exist." << endl;
        return;
    }

    if (noOfTeams > 0 && playerexist > 0 && teamindex >= 0)
    {
        teams[teamindex]->removePlayer(playerName);
        cout << "Removed player " << playerName << " from team " << teamName << endl;
    }
}

void LeagueManagementSystem ::transferPlayer(const string playerName, const string departTeamName, const string arriveTeamName)
{
    int depTeamIndex = -1;
    int arrTeamIndex = -1;
    int playerExistAtDeptTeam = -1;
    int jerseyExist = -1;
    int jersey = 0;
    int salary = 0;

    // if dept team exist
    if (noOfTeams > 0)
    {
        for (int i = 0; i < noOfTeams; i++)
        {
            if (teams[i]->getteamname() == departTeamName)
            {
                depTeamIndex = i;
            }
        }
    }
    if (depTeamIndex < 0)
    {
        cout << "Cannot transfer player. Team " << departTeamName << " doesn't exist." << endl;
        return;
    }

    // if player exist at dept team
    int deptsize = teams[depTeamIndex]->getNoOfPlayers();
    for (int i = 0; i < deptsize; i++)
    {
        if (teams[depTeamIndex]->getPlayers()[i].getPlayerName() == playerName)
        {
            playerExistAtDeptTeam = i;
            jersey = teams[depTeamIndex]->getPlayers()[i].getJersey();
            salary = teams[depTeamIndex]->getPlayers()[i].getSalaray();
        }
    }
    if (playerExistAtDeptTeam < 0)
    {
        cout << "Cannot transfer player. Player " << playerName << " doesn't exist." << endl;
        return;
    }

    // if arrive team exist
    if (noOfTeams > 0)
    {
        for (int i = 0; i < noOfTeams; i++)
        {
            if (teams[i]->getteamname() == arriveTeamName)
            {
                arrTeamIndex = i;
            }
        }
    }
    if (arrTeamIndex < 0)
    {
        cout << "Cannot transfer player. Team " << arriveTeamName << " doesn't exist." << endl;
        return;
    }

    // if jersey don't exist at arrive team
    int arrsize = teams[arrTeamIndex]->getNoOfPlayers();
    for (int i = 0; i < arrsize; i++)
    {
        if (teams[arrTeamIndex]->getPlayers()[i].getJersey() == jersey)
        {
            jerseyExist = 1;
        }
    }
    if (jerseyExist > 0)
    {
        cout << "Cannot transfer player. Jersey number " << teams[depTeamIndex]->getPlayers()[playerExistAtDeptTeam].getJersey()
             << " is already exist in team " << arriveTeamName << endl;
        return;
    }

    else
    {
        teams[depTeamIndex]->removePlayer(playerName);
        teams[arrTeamIndex]->addPlayer(playerName, jersey, salary);
        teams[arrTeamIndex]->playeraddedtoteam(salary);
        cout << "Transferred player " << playerName << "  from team " << departTeamName << " to team " << arriveTeamName << endl;
    }
}

void LeagueManagementSystem ::showTeam(const string name) const
{
    int index = -1;

    for (int i = 0; i < noOfTeams; i++)
    {
        if ((*teams[i]).getteamname() == name)
        {
            index = i;
        }
    }
    if (index >= 0)
    {
        cout << "Team: " << endl;
        teams[index]->printPropertiesofTeam();
        cout << "Players: " << endl;
        for (int i = 0; i < teams[index]->getNoOfPlayers(); i++)
        {
            teams[index]->getPlayers()[i].printPropertiesofPlayer();
        }
    }

    else
    {
        cout << "Team " << name << " does not exist." << endl;
    }
}

void LeagueManagementSystem ::showPlayer(const string name) const
{
    int team = 0;
    int player = -1;

    for (int i = 0; i < noOfTeams; i++)
    {
        for (int j = 0; j < teams[i]->getNoOfPlayers(); j++)
        {
            if (teams[i]->getPlayers()[j].getPlayerName() == name)
            {
                player = 1;
                cout << "Player: " << endl;
                teams[i]->getPlayers()[j].printPropertiesofPlayer();
                cout << "Plays in team " << teams[i]->getteamname() << endl;
                return;
            }
        }
    }

    cout << "Player " << name << " does not exist." << endl;
}
