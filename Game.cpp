#include <iostream>
#include <ctime>
#include <cstring>
#include <cstdlib>
#include "Game.h"
#include <fstream>

using namespace std;


void Game::setBalance(double b) {
    balance = b;
}

double Game::getBalance() {
    return balance;
}

void Game::load_game(FishTank tank1, string fname)
{
    ifstream inFS;
    inFS.open(fname);
    int i;
    float t, p, v;
    int nF, nT;
    char F;
    inFS >> balance;
    inFS >> t >> p >> v >> F >> nF >> nT;
    tank1.setTemperature(t);
    tank1.setPh(p);
    tank1.setVolume(v);
    tank1.setFilter(F);
    tank1.setNumFish(nF);
    tank1.setNumTurtles(nT);
    if (tank1.getVolume() < 6) {
        tank1.setMaxFish(4);
        tank1.setMaxTurtles(2);
    }
    else if (tank1.getVolume() >= 6) {
        tank1.setMaxFish((tank1.getVolume() * 2 - 2));
        tank1.setMaxTurtles(2);
    }
    delete[] tank1.fishlist;
    tank1.fishlist = new Fish[tank1.getMaxFish()];
    delete[] tank1.turtlelist;
    tank1.turtlelist = new Turtle[tank1.getMaxTurtles()];
    float hp, hun;
    char sick;
    for (i = 0; i < tank1.getNumFish(); i++)
    {
        inFS >> hp;
        tank1.fishlist[i].setHealth(hp);
        inFS >> sick;
        tank1.fishlist[i].setDiseased(sick);
        inFS >> hun;
        tank1.fishlist[i].setHunger(hun);
    }
    for (i = 0; i < tank1.getNumTurtles(); i++)
    {
        inFS >> hp;
        tank1.turtlelist[i].setHealth(hp);
        inFS >> sick;
        tank1.turtlelist[i].setDiseased(sick);
        inFS >> hun;
        tank1.turtlelist[i].setHunger(hun);
    }
    inFS.close();
}

void Game::save_game(FishTank tank1, string fname)
{
    ofstream outFS;
    outFS.open(fname);
    int i;
    char filter;
    if (tank1.getFilter()) {
        filter = 'Y';
    }
    else if(!tank1.getFilter()) {
        filter = 'N';
    }
    outFS << balance << " ";
    outFS << tank1.getTemperature() << " " << tank1.getPh() << " " << tank1.getVolume() << " " << filter << " ";
    outFS << tank1.getNumFish() << " " << tank1.getNumTurtles() << endl;
    for (i = 0; i < tank1.getNumFish(); i++)
    {
        outFS << tank1.fishlist[i].getHealth() << " " << tank1.fishlist[i].isDiseased() << " " << tank1.fishlist[i].getHunger() << endl;
    }
    for (i = 0; i < tank1.getNumTurtles(); i++)
    {
        outFS << tank1.turtlelist[i].getHealth() << " " << tank1.turtlelist[i].isDiseased() << " " << tank1.turtlelist[i].getHunger() << endl;
    }
    outFS.close();
}

void Game::showInfo(FishTank tank1)
{
    cout << "Balance: $" << balance << endl;
    cout << "Here are your Fish:" << endl;
    for (int i = 0; i < tank1.getNumFish(); i++)
    {
        cout << "Fish " << i+1 << endl;
        tank1.fishlist[i].show_info();
    }
    cout << "------------------------" << endl;
    cout << "Here are your Turtles:" << endl;
    for (int i = 0; i < tank1.getNumTurtles(); i++)
    {
        cout << "Turtle " << i+1 << endl;
        tank1.turtlelist[i].show_info();
    }
}

void Game::feedAnimals(FishTank &tank1)
{
    for (int i = 0; i < tank1.getNumFish(); i++)
    {
        tank1.fishlist[i].setHunger(0);
    }
    for (int i = 0; i < tank1.getNumTurtles(); i++)
    {
        tank1.turtlelist[i].setHunger(0);
    }
}

void Game::treatFish(FishTank &tank1, int id)
{
    tank1.fishlist[id].setDiseased('N');
}

void Game::sellFish(FishTank &tank1, int id)
{
    tank1.removeFish(id);
    balance += 150;
}

void Game::buyFish(FishTank& tank1)
{
    Fish fish;
    if (fish.check_environment(tank1.getPh(), tank1.getTemperature(), tank1.getVolume())) {
        tank1.addFish(fish);
        balance -= 100;
    }
    else if (!fish.check_environment(tank1.getPh(), tank1.getTemperature(), tank1.getVolume())) {
        cout << "Tank uninhabitable, START OVER" << endl;
    }
}

void Game::treatTurtle(FishTank &tank1, int id)
{
    tank1.turtlelist[id].setDiseased('N');
}

void Game::sellTurtle(FishTank &tank1, int id)
{
    tank1.removeTurtle(id);
    balance += 150;
}

void Game::buyTurtle(FishTank &tank1)
{
    Turtle turtle;
    if (turtle.check_environment(tank1.getPh(), tank1.getTemperature(), tank1.getVolume())) {
        tank1.addTurtle(turtle);
        balance -= 100;
    }
    else if (!turtle.check_environment(tank1.getPh(), tank1.getTemperature(), tank1.getVolume())) {
        cout << "Tank uninhabitable, START OVER" << endl;
    }
}

void Game::avalibleAnimals(FishTank tank1)
{
    cout << "SHOP" << endl;
    cout << "Avalible Animals:" << endl;
    cout << "Fish -> Cost: 100" << endl;
    cout << "Turtle -> Cost: 100" << endl;
}

void Game::interactFish(FishTank tank1, int id)
{
    tank1.fishlist[id].interact();
}

void Game::interactTurtle(FishTank tank1, int id)
{
    tank1.turtlelist[id].interact();
}

void Game::cycle(FishTank &tank1)
{
    cout << "Another day passes" << endl;
    for (int i = 0; i < tank1.getNumFish(); i++) {
        tank1.fishlist[i].next_day();
    }
    for (int i = 0; i < tank1.getNumTurtles(); i++) {
        tank1.turtlelist[i].next_day();
    }
}

void Game::DEATH(FishTank& tank1)
{
    for (int i = 0; i < tank1.getNumFish(); i++) {
        if (tank1.fishlist[i].isDiseased() == 'Y') {
            cout << "FISH " << i + 1 << " HAS DIED" << endl;
            tank1.removeFish(i);
            i--;
        }
    }
    for (int i = 0; i < tank1.getNumTurtles(); i++) {
        if (tank1.turtlelist[i].isDiseased() == 'Y') {
            cout << "TURTLE " << i + 1 << " HAS DIED" << endl;
            tank1.removeFish(i);
            i--;
        }
    }
}