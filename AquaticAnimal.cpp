#include <iostream>
#include <ctime>
#include <cstring>
#include <cstdlib>
#include "AquaticAnimal.h"

using namespace std;

AquaticAnimal::AquaticAnimal()
{
    sell_price = 150;
    buy_price = 100;
    health = 100.0;
    disease = 'N';
    hunger = 0;
}

bool AquaticAnimal::check_environment(float ph_level, float temperature, float volume)
{
    if (ph_level < 5 || ph_level > 10)
    {
        cout << "The water pH level is not suitable for the animals." << endl;
        return false;
    }
    if (temperature < 10 || temperature > 30)
    {
        cout << "The water temperature is not suitable for the animals." << endl;
        return false;
    }
    if (volume < 5)
    {
        cout << "The water volume is not suitable for the animals." << endl;
    }
    else {
        return true;
    }
}

void AquaticAnimal::setSellPrice(float sp)
{
    sell_price = sp;
}

float AquaticAnimal::getSellPrice()
{
    return sell_price;
}

void AquaticAnimal::setBuyPrice(float bp)
{
    buy_price = bp;
}

float AquaticAnimal::getBuyPrice()
{
    return buy_price;
}

void AquaticAnimal::setHealth(float hp)
{
    health = hp;
}

float AquaticAnimal::getHealth()
{
    return health;
}

void AquaticAnimal::setDiseased(char d)
{
    disease = d;
}

char AquaticAnimal::isDiseased()
{
    return disease;
}

void AquaticAnimal::setHunger(float chomp)
{
    hunger = chomp;
}

float AquaticAnimal::getHunger() {
    return hunger;
}
void AquaticAnimal::show_info()
{
    cout << "Hunger: " << hunger << endl;
    cout << "Health: " << health << endl;
    cout << "Selling Price: " << sell_price << endl;
    if (disease == 'Y')
    {
        cout << "I AM SICK" << endl;
    }
    if (disease == 'N')
    {
        cout << "I AM NOT SICK" << endl;
    }
    cout << "------------------------" << endl;
}