/**
 * @file Path.cpp
 * @author Dilara Mandiraci 22101643 section1
 * @brief 
 * @version 0.1
 * @date 2022-12-29
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "Path.h"

Path :: Path(stack<Flight> mypath)
{
    total = 0;
    while (!mypath.empty())
    {
        total += mypath.top().cost;
        listpath.push_front(mypath.top());
        mypath.pop();
    }
}

Path :: Path()
{
    total = 0;
}