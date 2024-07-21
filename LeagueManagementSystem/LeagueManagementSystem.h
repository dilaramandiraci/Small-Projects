/**
 * @file LeagueManagementSystem.h
 * @author Dilara Mandıracı section 1 22101643
 * @brief 
 * @version 0.1
 * @date 2022-11-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once
#include <string>
#include "Team.h"

class LeagueManagementSystem {
    public:
        LeagueManagementSystem();
        ~LeagueManagementSystem();

        void addTeam( const string name, const int year );
        void removeTeam( const string name );


        void addPlayer( const string teamName, const string playerName,
                        const int jersey, const int salary );
        void removePlayer( const string teamName, const string playerName );

        void transferPlayer( const string playerName,
                             const string departTeamName, const string arriveTeamName );

        void showAllTeams() const;
        void showTeam( const string name ) const;
        void showPlayer( const string name ) const;

    private:
        Team **teams;
        int noOfTeams;
    };
