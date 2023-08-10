#include <iostream>
#include <ctime>
#include <cstring>
#include <cstdlib>
#include "Turtle.h"

using namespace std;

Turtle::Turtle() : AquaticAnimal()
{
    type = "Turtle";
}

void Turtle::next_day()
{
    hunger += 1.5;

    if (rand() % 6 == 0)
    {
        disease = 'Y';
    }
    if (hunger > 10)
    {
        health -= 20.0;
    }
}
void Turtle::interact()
{
    cout << "SHRIEK SHRIEK STOMP" << endl;
    cout << "          __" << endl;
    cout << "    .,-;-;-,. /'_\"" << endl;
    cout << "  _/_/_/_|_\_\) /" << endl;
    cout << "'-<_><_><_><_>=/\"" << endl;
    cout << "  `/_/====/_/-'\_\"" << endl;
    cout << "   ""     ""    """ << endl;
}
