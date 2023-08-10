#ifndef FISH_H
#define FISH_H

#include <iostream>
#include <ctime>
#include <cstring>
#include <cstdlib>
#include "AquaticAnimal.h"

using namespace std;

class Fish : public AquaticAnimal
{
private:
    string type;

public:
    Fish();
    void interact() override;
    void next_day() override;
};

#endif