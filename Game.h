#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <ctime>
#include <cstring>
#include <cstdlib>
#include "FishTank.h"

using namespace std;

class Game {
private:
    double balance;

public:
    void setBalance(double b);
    double getBalance();
    void load_game(FishTank tank1, string fname);
    void save_game(FishTank tank1, string fname);
    void showInfo(FishTank tank1);
    void feedAnimals(FishTank &tank1);
    void treatFish(FishTank &tank1, int id);
    void sellFish(FishTank &tank1, int id);
    void buyFish(FishTank &tank1);
    void treatTurtle(FishTank &tank1, int id);
    void sellTurtle(FishTank &tank1, int id);
    void buyTurtle(FishTank &tank1);
    void avalibleAnimals(FishTank tank1);
    void interactFish(FishTank tank1, int id);
    void interactTurtle(FishTank tank1, int id);
    void cycle(FishTank &tank1);
    void DEATH(FishTank &tank1);
    // next day (update all the fishes funcitons)
    // interact(which fish to interact)
};
#endif