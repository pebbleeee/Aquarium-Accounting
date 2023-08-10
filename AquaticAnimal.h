#ifndef AQUATICANIMAL_H
#define AQUATICANIMAL_H

#include <iostream>
#include <ctime>
#include <cstring>
#include <cstdlib>

using namespace std;

class AquaticAnimal
{
protected:
    float sell_price;
    float buy_price;
    float health;
    float hunger;
    char disease;

public:
    AquaticAnimal();
    bool check_environment(float ph_level, float temperature, float volume);
    virtual void interact() = 0;
    virtual void next_day() = 0;
    void setSellPrice(float sp);
    float getSellPrice();
    void setBuyPrice(float bp);
    float getBuyPrice();
    void setHealth(float hp);
    float getHealth();
    void setDiseased(char d);
    char isDiseased();
    void setHunger(float chomp);
    float getHunger();
    void show_info();

};

#endif