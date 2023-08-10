#ifndef FISHTANK_H
#define FISHTANK_H

#include <iostream>
#include <ctime>
#include <cstring>
#include <cstdlib>
#include "Fish.h"
#include "Turtle.h"
using namespace std;

class FishTank
{
protected:
    float temperature;
    float ph;
    float volume;
    bool isFilter;
    int numFish;
    int maxFish;
    int numTurtles;
    int maxTurtles;

public:
    Fish* fishlist;
    Turtle* turtlelist;
    FishTank();
    FishTank(float temp, float _ph, float vol, char f);
    FishTank& operator=(const FishTank& other);
    void addFish(Fish animal);
    void removeFish(int id);
    void addTurtle(Turtle animal);
    void removeTurtle(int id);
    void setTemperature(float temp);
    float getTemperature();
    void setPh(float _ph);
    float getPh();
    void setVolume(float vol);
    float getVolume();
    void setFilter(char filt);
    bool getFilter();
    void setNumFish(int f);
    int getNumFish();
    void setNumTurtles(int t);
    int getNumTurtles();
    void setMaxFish(int mf);
    int getMaxFish();
    void setMaxTurtles(int mf);
    int getMaxTurtles();
};
#endif