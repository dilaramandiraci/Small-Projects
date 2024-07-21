/**
 * @file Flight.h
 * @author Dilara Mandiraci 22101643 section1 
 * @brief 
 * @version 0.1
 * @date 2022-12-29
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once
#include <iostream>
#include <string>
using namespace std;

class Flight
{
public:
    string departure;
    string destination;
    int flightId;
    int cost;
    bool isEmpty;

    Flight(string adeparture, string adestination, int aflightId, int acost);
    Flight();
};