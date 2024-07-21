/**
 * @file Path.h
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
#include "Flight.h"
#include <stack>
#include <list>
using namespace std;

class Path
{
public:
    int total;
    list<Flight> listpath;

    Path(stack<Flight> mypath);
    Path();
};