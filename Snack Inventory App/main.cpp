/**
* Title: Balanced search trees and hashing
* Author : Dilara Mandiraci
* ID: 22101643
* Section : 1
* Homework : 4
* Description : Main function should be run in the command line while format ./hw4 "input" */
#include <iostream>
#include "Snack.h"
#include "SnackHashing.h"
#include "AccompanimentHashing.h"
#include <sstream>
using namespace std;

int main(int argc, char **argv) {
    const string allCommands = argv[1];
    stringstream ss(allCommands);
    string nextCommand;

    SnackHashing snackTable;
    AccompanimentHashing accTable;
    vector<Snack*> allSnacks;

    while(ss>>nextCommand)
    {
        if (nextCommand == "X") {
            break;  // finish
        }

        else if(nextCommand == "S")
        {
            string newSnack;
            ss>>newSnack;

            auto * s = new Snack(newSnack);
            allSnacks.push_back(s);
            snackTable.insert(s);
        }

        else if(nextCommand == "C")
        {
            string acc1;
            string acc2;
            ss>>acc1;
            ss>>acc2;

            snackTable.addAcc(acc1,acc2,accTable);
        }

        else if(nextCommand == "L")
        {
            string snackk;
            ss>>snackk;

            if(snackTable.there(snackk))
            {
                snackTable.getSnack(snackk).listAccompaniments();
            }
        }

        else if(nextCommand == "D")
        {
            string acc1;
            string acc2;
            ss>>acc1;
            ss>>acc2;

            accTable.removeAcc(acc1, acc2);
        }

        else if(nextCommand == "Q")
        {
            string acc1;
            string acc2;
            ss>>acc1;
            ss>>acc2;

            bool answer = accTable.isThere(acc1,acc2);
            if(answer)
            {
                cout << "Yes" << endl;
            }
            else
                cout << "No" << endl;
        }

    }

    for(auto c:allSnacks)
    {
        delete c;
    }

    return 0;
}
