/**
 * @file FlightMap.cpp
 * @author Dilara Mandiraci 22101643 section1
 * @brief
 * @version 0.1
 * @date 2022-12-29
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "FlightMap.h"
using namespace std;

FlightMap::FlightMap(const string cityFile, const string flightFile)
{
    cityCount = 0;
    flightcount = 0;

    ifstream file1;
    ifstream file2;

    file1.open(cityFile.c_str(), ios_base::in);
    file2.open(flightFile.c_str(), ios_base::in);

    // generating the map of all cities in the flightsystem

    int index = 0;
    string newcity;

    while (getline(file1, newcity))
    {
        allcities.insert(pair<string, int>(newcity, index));
        index++;
        cityCount++;
    }

    for (int i = 0; i < cityCount; i++)
    {
        list<Flight> list1;
        mygraph.push_back(list1);
    }

    string column;
    string departure = "";
    string destination = "";
    int flightId;
    int cost;

    while (getline(file2, column))
    {
        int pos = column.find(";");
        departure = column.substr(0, pos);
        column = column.substr(pos + 1, column.length());

        pos = column.find(";");
        destination = column.substr(0, pos);
        column = column.substr(pos + 1, column.length());

        pos = column.find(";");
        flightId = stoi(column.substr(0, pos));
        column = column.substr(pos + 1, column.length());

        cost = stoi(column);

        int indexOfcity = allcities.at(departure);
        Flight fl(departure, destination, flightId, cost);
        flightcount++;
        mygraph[indexOfcity].push_front(fl);
    }

    cout << cityCount << " cities and " << flightcount << " flights have been loaded" << endl;
}

FlightMap::~FlightMap() {} // DESTRUCTOR

void FlightMap::displayAllCities() const
{
    cout << "The list of the cities that HPAir serves is given below:" << endl;
    for (const auto &city : allcities)
    {
        cout << city.first << ", ";
    }
    cout << endl;
}

void FlightMap::displayAdjacentCities(const string cityName) const
{
    int index = allcities.at(cityName);
    list<string> adjacents;

    for (auto flight : mygraph.at(index))
    {
        adjacents.push_front(flight.destination);
    }

    adjacents.sort();

    cout << "The cities adjacent to " << cityName << " are:" << endl;
    cout << cityName << " -> ";

    for (auto cname : adjacents)
    {
        cout << cname << ", ";
    }
    cout << endl;
}

void FlightMap::displayFlightMap() const
{
    cout << "The whole flight map is given below:" << endl;
    for (auto city : allcities)
    {
        cout << city.first << " -> ";

        int index = allcities.at(city.first);
        list<string> adjacents;

        for (auto flight : mygraph.at(index))
        {
            adjacents.push_front(flight.destination);
        }
        adjacents.sort();
        for (auto cname : adjacents)
        {
            cout << cname << ", ";
        }

        cout << endl;
    }
}

void FlightMap::findFlights(const string deptCity, const string destCity)
{
    cout << "Request is to fly from " << deptCity << " to " << destCity << ":" << endl;

    stack<Flight> path;
    list<Path> allpaths;
    list<Flight> visited;
    Flight topflight, nextFlight;
    Flight baseFlight;
    bool nopath = false;

    while (true)
    {
        if (path.empty())
        {
            baseFlight = getFlight(visited, deptCity);

            if (baseFlight.isEmpty)
            {
                break;
            }

            path.push(baseFlight);
            if (!isVisited(visited, baseFlight))
            {
                visited.push_front(baseFlight);
            }

            if (baseFlight.destination == destCity)
            {
                Path p1(path);
                allpaths.push_back(p1);
                nopath = true;
                path.pop();
            }

            if (path.empty())
            {
                baseFlight = getFlight(visited, deptCity);
                if (baseFlight.isEmpty)
                {
                    break;
                }
                path.push(baseFlight);
                if (!isVisited(visited, baseFlight))
                {
                    visited.push_front(baseFlight);
                }
            }
        }

        topflight = path.top();
        nextFlight = getFlight(visited, topflight.destination);

        if (nextFlight.isEmpty)
        {
            string dept = path.top().destination;
            string dest = destCity;

            removeVisited(visited, dept, dest);

            path.pop();

            continue;
        }

        else if (nextFlight.destination == deptCity)
        {
            if (!isVisited(visited, nextFlight))
            {
                visited.push_front(nextFlight);
            }
        }

        else
        {
            path.push(nextFlight);
            if (!isVisited(visited, nextFlight))
            {
                visited.push_front(nextFlight);
            }
        }

        if (nextFlight.destination == destCity)
        {
            Path p1(path);
            allpaths.push_back(p1);
            nopath = true;
            path.pop();
        }
    }

    if (nopath == false)
    {
        cout << "Sorry. HPAir does not fly from " << deptCity << " to " << destCity << "." << endl;
    }
    else
    {
        allpaths.sort([](const Path &lhs, const Path &rhs)
                      { return lhs.total < rhs.total; });

        for (auto p : allpaths)
        {
            for (auto flist : p.listpath)
            {
                cout << "Flight #" << flist.flightId << " from " << flist.departure << " to " << flist.destination << ", Cost: " << flist.cost << " TL" << endl;
            }

            cout << "Total Cost: " << p.total << " TL" << endl;
        }
    }
}

bool FlightMap::isVisited(list<Flight> &alist, Flight aflight)
{
    for (auto f : alist)
    {
        if (f.departure == aflight.departure && f.destination == aflight.destination)
        {
            return true;
        }
    }
    return false;
}

void FlightMap::removeVisited(list<Flight> &alist, string depttt, string destt)
{
    for (auto &f : alist)
    {
        if (f.departure == depttt && f.destination == destt)
        {
            f.departure = "";
            f.destination = "";
        }
    }
}

Flight FlightMap::getFlight(list<Flight> &alist, string destCity)
{
    int ind = allcities.at(destCity);

    for (auto flight : mygraph.at(ind))
    {
        if (!isVisited(alist, flight))
        {
            return flight;
        }
    }
    Flight empty;
    return empty;
}

bool FlightMap::isLast(Flight f, string destCity)
{
    if (f.destination == destCity)
    {
        return true;
    }
    return false;
}
