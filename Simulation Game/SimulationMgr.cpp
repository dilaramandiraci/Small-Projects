/**
* Author : Dilara Mandiraci
* ID: 22101643
* Section : 1
* Homework : 3
* Description : This file has the main of the game which has the main loop.
 * First it reads the file txt, creates foods and creatures.
 * First puts creatures to the vector and puts the foods to the spawn queue.
 * When time is spawn time, it will poll the food from the spawn queue and put it to the quality queue.
 * Game has some phases. Phase names are clearly stated in the function names.
 * Below functions are also created to facilitate running the loop and to increase understandibility of the code */
#include <iostream>
#include "Food.h"
#include "SpawnQueue.h"
#include "QualityQueue.h"
#include "Creature.h"
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <vector>

using namespace std;

void printLocationsOfCreatures(vector<Creature>& creatures)
{
    for (auto& c: creatures) {
        cout << "Creature " << c.getId() << ": " << fixed << setprecision(2) << c.getX() <<
        ", "<< fixed << setprecision(2) << c.getY() << endl;
    }
}

void decreaseHealthOfCreatures(vector<Creature>& creatures)
{
    for (auto& c: creatures){
        c.decreaseHealth();
    }
}

void updateAliveNo(vector<Creature>& creatures, int& aliveNo)
{
    int counter = 0;
    for (auto& c: creatures){
        if(!c.isDead())
        {
            counter++;
        }
    }
    aliveNo = counter;
}

void FoodConsumption(vector<Creature>& creatures, QualityQueue& bestfoods)
{
    for (auto& c: creatures){
        if(!c.isDead())
        {
            if(!bestfoods.pqIsEmpty())
            {
                bool canEat = c.eat(bestfoods.pqPeak());
                if(canEat)
                {
                    bestfoods.pqDelete();  //update best food
                }
            }
        }
    }
}

void fight(vector<Creature>& creatures)
{
    for (int i = 0; i < creatures.size(); i++){
        if(!creatures[i].isDead())
        {
            for(int j = 0; j < creatures.size(); j++)
            {
                if(j != i  && !creatures[j].isDead())
                {
                    creatures[i].kill(creatures[j]);
                }
            }
        }
    }
}

void movePhase(vector<Creature>& creatures, Food& bestfood)
{
    for(auto& c: creatures)
    {
        if(!c.isDead())
        {
            c.move(bestfood);
        }
    }
}

int main(int argc, char **argv) {

    const string datafile = argv[1];
    ifstream fileData;
    fileData.open(datafile.c_str(), ios_base::in);

    if (!fileData.is_open()) {
        cout << "ERROR: File cannot open!" << endl;
        return 1;
    }

    int aliveCreatureNo;
    fileData >> aliveCreatureNo;

    vector<Creature> creatures;
    QualityQueue qualityQueue;
    SpawnQueue spawnQueue;

    for (int i = 0; i < aliveCreatureNo; i++) {
        char pass;
        int idC;
        double xC;
        double yC;
        int healthC;
        fileData >> idC >> pass >> xC >> pass >> yC >> pass >> healthC;
        Creature aCreature(idC, xC, yC, healthC);

        creatures.push_back(aCreature);
    }

    sort(creatures.begin(), creatures.end());

    while(fileData.eof()==false)
    {
        char pass = ',';
        int idF;
        double xF;
        double yF;
        int spawnF;
        int qualityF;
        fileData >> idF >> pass >> xF >> pass >> yF >> pass >> spawnF >> pass>> qualityF;
        Food aFood(idF, xF, yF, spawnF, qualityF);
        spawnQueue.pqInsert(aFood);
    }

    fileData.close();

    int time = 0;
    while(true)
    {

        printLocationsOfCreatures(creatures);

        if(!spawnQueue.pqIsEmpty())
        {
            while(spawnQueue.pqPeak().canSpawn(time) && !spawnQueue.pqIsEmpty())
            {
                Food f1 = spawnQueue.pqPeak();
                spawnQueue.pqDelete();


                if(!qualityQueue.isFull())
                {
                    qualityQueue.pqInsert(f1);
                }

            }
        }

        fight(creatures);



        if(!qualityQueue.pqIsEmpty())
        {
            FoodConsumption(creatures, qualityQueue);

            if(!qualityQueue.pqIsEmpty())
            {
                Food currentBestFood = qualityQueue.pqPeak();
                movePhase(creatures, currentBestFood);
            }

        }

        decreaseHealthOfCreatures(creatures);

        updateAliveNo(creatures,aliveCreatureNo);


        if(aliveCreatureNo == 0) //spawnQueue.pqIsEmpty() && qualityQueue.pqIsEmpty() && aliveCreatureNo <= 0
        {
            break;
        }

        time ++;
    }
    return 0;
}
