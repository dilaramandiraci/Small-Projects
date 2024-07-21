/**
 * @file FlightMap.h
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
#include <map>
#include <list>
#include <vector>
#include <fstream>
#include <list>
#include <sstream>
#include <stack>
#include "Path.h"
#include "Flight.h"

using namespace std;


class FlightMap
{
public:
    FlightMap(const string cityFile, const string flightFile);
    ~FlightMap();
    void displayAllCities() const;
    void displayAdjacentCities(const string cityName) const;
    void displayFlightMap() const;
    void findFlights(const string deptCity, const string destCity);


    map<string, int> allcities; //map of all cities
    vector<list <Flight> > mygraph; 
    int cityCount;
    int flightcount;

private:
    bool isVisited(list<Flight> & alist , Flight aflight);
    Flight getFlight(list<Flight> & alist ,string destCity);
    void visit(list<Flight> & alist ,Flight flight);
    bool isLast(Flight f, string destCity);
    void removeVisited(list<Flight> &alist, string depttt, string destt);

};