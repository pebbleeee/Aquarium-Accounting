#include <iostream>
#include <ctime>
#include <cstring>
#include <cstdlib>
#include "FishTank.h"

using namespace std;
FishTank::FishTank()
{
    temperature = 0;
    ph = 0;
    volume = 0;
    isFilter = true;
    numFish = 0;
    maxFish = 4;
    numTurtles = 0;
    maxTurtles = 2;
    fishlist = new Fish[maxFish];
    turtlelist = new Turtle[maxTurtles];
}


FishTank::FishTank(float temp, float _ph, float vol, char f)
{
    temperature = temp;
    ph = _ph;
    volume = vol;
    if (f == 'Y') {
        isFilter = true;
    }
    else if (f == 'N') {
        isFilter = false;
    }
    numFish = 0;
    maxFish = (vol * 2 - 2);
    numTurtles = 0;
    maxTurtles = 2;
    fishlist = new Fish[maxFish];
    turtlelist = new Turtle[maxTurtles];
}
FishTank& FishTank::operator=(const FishTank& other)
{
    if (this == &other)
    {
        return *this;
    }

    temperature = other.temperature;
    ph = other.ph;
    volume = other.volume;
    isFilter = other.isFilter;
    numFish = other.numFish;
    maxFish = other.maxFish;
    numTurtles = other.numTurtles;
    maxTurtles = other.maxTurtles;

    delete[] fishlist;
    fishlist = new Fish[maxFish];
    for (int i = 0; i < numFish; i++)
    {
        fishlist[i] = other.fishlist[i];
    }

    delete[] turtlelist;
    turtlelist = new Turtle[maxTurtles];
    for (int i = 0; i < numTurtles; i++)
    {
        turtlelist[i] = other.turtlelist[i];
    }

    return *this;
}


void FishTank::addFish(Fish animal)
{
    if (numFish >= maxFish)
    {
        cout << "TANK FULL" << endl;
    }
    else
    {
        fishlist[numFish + 1] = animal;
        numFish++;
    }
}
// use index

void FishTank::removeFish(int id)
{
    int i, j;
    for (i = 0; i < numFish; i++)
    {
        if(i == id)
        {
            for (j = i; j < numFish - 1; j++)
            {
                fishlist[j] = fishlist[j + 1];
            }
            numFish--;
            break;
        }
    }
}

void FishTank::addTurtle(Turtle animal)
{
    if (numTurtles >= maxTurtles)
    {
        cout << "TANK FULL" << endl;
    }
    else
    {
        turtlelist[numTurtles+1] = animal;
        numTurtles++;
    }
}
// use index

void FishTank::removeTurtle(int id)
{
    int i, j;
    for (i = 0; i < numTurtles; i++)
    {
        if(i == id)
        {
            for (j = id; j < numTurtles - 1; j++)
            {
                turtlelist[j] = turtlelist[j + 1];
            }
            numTurtles--;
        }
    }
}

void FishTank::setTemperature(float temp)
{
    temperature = temp;
}

float FishTank::getTemperature()
{
    return temperature;
}

void FishTank::setPh(float _ph)
{
    ph = _ph;
}

float FishTank::getPh()
{
    return ph;
}

void FishTank::setVolume(float vol)
{
    volume = vol;
}

float FishTank::getVolume()
{
    return volume;
}

void FishTank::setFilter(char filt)
{
    if (filt == 'Y')
    {
        isFilter = true;
    }
    else if (filt == 'N')
    {
        isFilter = false;
    }
}

bool FishTank::getFilter()
{
    return isFilter;
}

void FishTank::setNumFish(int f)
{
    numFish = f;
}

int FishTank::getNumFish()
{
    return numFish;
}

void FishTank::setNumTurtles(int t)
{
    numTurtles = t;
}

int FishTank::getNumTurtles()
{
    return numTurtles;
}

void FishTank::setMaxFish(int mf)
{
    maxFish = mf;
}

int FishTank::getMaxFish()
{
    return maxFish;
}

void FishTank::setMaxTurtles(int mt)
{
    maxTurtles = mt;
}

int FishTank::getMaxTurtles()
{
    return maxTurtles;
}