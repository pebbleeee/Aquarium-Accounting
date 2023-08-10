#ifndef TURTLE_H
#define TURTLE_H

#include <iostream>
#include <ctime>
#include <cstring>
#include <cstdlib>
#include "AquaticAnimal.h"

using namespace std;

class Turtle : public AquaticAnimal
{
private:
    string type;

public:
    Turtle();
    void interact() override;
    void next_day() override;
};

#endif
