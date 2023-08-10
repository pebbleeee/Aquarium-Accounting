#include <iostream>
#include <ctime>
#include <cstring>
#include <cstdlib>
#include "Fish.h"

using namespace std;

Fish::Fish() : AquaticAnimal()
{
    type = "fish";
}

void Fish::next_day()
{
    hunger += 2.0;

    if (rand() % 4 == 0)
    {
        disease = 'Y';
    }
    if (hunger > 10)
    {
        health -= 20.0;
    }
}
void Fish::interact()
{
    cout << "BLUB BLUB" << endl;
    cout << "      /`·.¸" << endl;
    cout << "     /¸...¸`:·" << endl;
    cout << "  ¸.·´  ¸   `·.¸.·´)" << endl;
    cout << " : © ):´;      ¸  {" << endl;
    cout << " `·.¸ `·  ¸.·´\`·¸)" << endl;
    cout << "     `\\´´\'" << endl;
}