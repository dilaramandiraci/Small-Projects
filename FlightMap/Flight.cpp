/**
 * @file Flight.cpp
 * @author Dilara Mandiraci 22101643 section1
 * @brief 
 * @version 0.1
 * @date 2022-12-29
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "Flight.h"

Flight::Flight(string adeparture, string adestination, int aflightId, int acost)
{
    departure = adeparture;
    destination = adestination;
    flightId = aflightId;
    cost = acost;
    isEmpty = false;
}

Flight::Flight()
{
    isEmpty = true;
    destination = "";
    departure = "";
}