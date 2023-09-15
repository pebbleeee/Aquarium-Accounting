// SUSHI GO.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "AquaticAnimal.h"
#include "Fish.h"
#include "Turtle.h"
#include "FishTank.h"
#include "Game.h"
using namespace std;

void menu1()
{
    cout << "      >>                                                                               >>                                                       >=>" << endl;
    cout << "     >>=>                                             >>                              >>=>                                                      >=>    >>" << endl;
    cout << "    >> >=>       >=>    >=>  >=>    >=> >=>  >> >==>     >=>  >=> >===>>=>>==>       >> >=>        >==>    >==>    >=>     >=>  >=> >==>>==>  >=>>==>     >==>>==>     >=>" << endl;
    cout << "   >=>  >=>    >>  >=>  >=>  >=>  >=>   >=>   >=>    >=> >=>  >=>  >=>  >>  >=>     >=>  >=>     >=>     >=>     >=>  >=>  >=>  >=>  >=>  >=>   >=>   >=>  >=>  >=>  >=>  >=>" << endl;
    cout << "  >=====>>=>   >>  >=>  >=>  >=> >=>    >=>   >=>    >=> >=>  >=>  >=>  >>  >=>    >=====>>=>   >=>     >=>     >=>    >=> >=>  >=>  >=>  >=>   >=>   >=>  >=>  >=> >=>   >=>" << endl;
    cout << " >=>      >=>   >==>=>  >=>  >=>  >=>   >=>   >=>    >=> >=>  >=>  >=>  >>  >=>   >=>      >=>   >=>     >=>     >=>  >=>  >=>  >=>  >=>  >=>   >=>   >=>  >=>  >=>  >=>  >=>" << endl;
    cout << ">=>        >=>     >=>    >==>=>   >==>>>==> >==>    >=>   >==>=> >==>  >>  >=>  >=>        >=>    >==>    >==>    >=>       >==>=> >==>  >=>    >=>  >=> >==>  >=>      >=>" << endl;
    cout << "                   >==>                                                                                                                                               >=>" << endl;
    cout << "------------------------" << endl;
    cout << "1.New Game " << endl;
    cout << "2.Load Game" << endl;
    cout << "------------------------" << endl;
}
void menu2()
{
    cout << "------------------------" << endl;
    cout << "What would you like to do?" << endl;
    cout << "1. Show Animal Info" << endl;
    cout << "2. Feed" << endl;
    cout << "3. Treat" << endl;
    cout << "4. Sell" << endl;
    cout << "5. Buy" << endl;
    cout << "6. Save Game" << endl;
    cout << "7. Interact with Animals" << endl;
    cout << "Enter your choice (1-7): " << endl;
    cout << "------------------------" << endl;
}



int main()

{
    menu1();
    Game game1;
    FishTank tank1;
    int choice;
    int counter = 0;
    cin >> choice;
    if (choice == 1) {
        float t, p, v;
        char f;
        cout << "AQUARIUM ACCOUNTING" << endl << endl;
        cout << "(please note your temperature should be between 10 and 30 degrees, your ph between 5 and 10, and your volume above 5)" << endl;
        cout << "(Make sure you don't go negative....)" << endl;
        cout << "Enter fish tank's temperature (in Celsius): " << endl;
        cin >> t;
        cout << "Enter fish tank's pH level: " << endl;
        cin >> p;
        cout << "Enter fish tank's volume (in liters): " << endl;
        cin >> v;
        cout << "Does the fish tank have a filtration system? (Y/N): " << endl;
        cin >> f;
        FishTank copy1(t, p, v, f);
        tank1 = copy1;
        game1.setBalance(500);
    }
    else if (choice == 2) {
        cout << "Please enter the name of the load file:" << endl;
        string fname;
        cin >> fname;
        game1.load_game(tank1, fname);
    }
    menu2();
    int option;
    while (cin >> option) {
        if (option == 1) {
            game1.showInfo(tank1);
            cout << "Enter your choice (1-7): " << endl;
        }
        else if (option == 2) {
            game1.feedAnimals(tank1);
            cout << "YOUR ANIMALS ARE FULL!" << endl;
            counter += 1;
            if (counter == 4) {
                game1.DEATH(tank1);
                game1.cycle(tank1);
                counter = 0;
            }
            if (game1.getBalance() < 0) {
                cout << "GAME OVER THE FEDS CAME KNOCKING YOUR IN THE NEGATIVES" << endl;
                return 0;
            }
            else if (game1.getBalance() >= 2000) {
                cout << "YOU WIN WOOOOOO" << endl;
                return 0;
            }
            cout << "Enter your choice (1-7): " << endl;
        }
        else if (option == 3) {
            cout << "Would you like to treat a fish or turtle? (F/T)" << endl;
            char sick;
            cin >> sick;
            if (sick == 'F') {
                cout << "Which fish would you like to treat? (enter #)" << endl;
                int id;
                cin >> id;
                id = id - 1;
                game1.treatFish(tank1, id);
                cout << "FISH TREATED!" << endl;
                counter += 1;
                if (counter == 4) {
                    game1.DEATH(tank1);
                    game1.cycle(tank1);
                    counter = 0;
                }
                if (game1.getBalance() < 0) {
                    cout << "GAME OVER THE FEDS CAME KNOCKING YOUR IN THE NEGATIVES" << endl;
                    return 0;
                }
                else if (game1.getBalance() >= 2000) {
                    cout << "YOU WIN WOOOOOO" << endl;
                    return 0;
                }
                cout << "Enter your choice (1-7): " << endl;
            }
            else if (sick == 'T') {
                cout << "Which turtle would you like to treat? (enter #)" << endl;
                int id;
                cin >> id;
                id = id - 1;
                game1.treatTurtle(tank1, id);
                cout << "TURTLE TREATED!" << endl;
                counter += 1;
                if (counter == 4) {
                    game1.DEATH(tank1);
                    game1.cycle(tank1);
                    counter = 0;
                }
                if (game1.getBalance() < 0) {
                    cout << "GAME OVER THE FEDS CAME KNOCKING YOUR IN THE NEGATIVES" << endl;
                    return 0;
                }
                else if (game1.getBalance() >= 2000) {
                    cout << "YOU WIN WOOOOOO" << endl;
                    return 0;
                }
                cout << "Enter your choice (1-7): " << endl;
            }
        }
        else if (option == 4) {
            cout << "Would you like to sell a Fish or a turtle(F/T)" << endl;
            char sell;
            cin >> sell;
            if (sell == 'F') {
                cout << "Which fish would you like to sell? (enter #)" << endl;
                int id;
                cin >> id;
                id = id - 1;
                game1.sellFish(tank1, id);
                cout << "FISH SOLD!" << endl;
                counter += 1;
                if (counter == 4) {
                    game1.DEATH(tank1);
                    game1.cycle(tank1);
                    counter = 0;
                }
                if (game1.getBalance() < 0) {
                    cout << "GAME OVER THE FEDS CAME KNOCKING YOUR IN THE NEGATIVES" << endl;
                    return 0;
                }
                else if (game1.getBalance() >= 2000) {
                    cout << "YOU WIN WOOOOOO" << endl;
                    return 0;
                }
                cout << "Enter your choice (1-7): " << endl;
            }
            else if (sell == 'T') {
                cout << "Which turtle would you like to sell? (enter #)" << endl;
                int id;
                cin >> id;
                id = id - 1;
                game1.sellTurtle(tank1, id);
                cout << "TURTLE SOLD!" << endl;
                counter += 1;
                if (counter == 4) {
                    game1.DEATH(tank1);
                    game1.cycle(tank1);
                    counter = 0;
                }
                if (game1.getBalance() < 0) {
                    cout << "GAME OVER THE FEDS CAME KNOCKING YOUR IN THE NEGATIVES" << endl;
                    return 0;
                }
                else if (game1.getBalance() >= 2000) {
                    cout << "YOU WIN WOOOOOO" << endl;
                    return 0;
                }
                cout << "Enter your choice (1-7): " << endl;
            }
        }
        else if (option == 5) {
            game1.avalibleAnimals(tank1);
            cout << "Would you like to buy a Fish or a turtle(F/T)" << endl;
            char buy;
            cin >> buy;
            if (buy == 'F') {
                game1.buyFish(tank1);
                cout << "FISH BOUGHT!" << endl;
                counter += 1;
                if (counter == 4) {
                    game1.DEATH(tank1);
                    game1.cycle(tank1);
                    counter = 0;
                }
                if (game1.getBalance() < 0) {
                    cout << "GAME OVER THE FEDS CAME KNOCKING YOUR IN THE NEGATIVES" << endl;
                    return 0;
                }
                else if (game1.getBalance() >= 2000) {
                    cout << "YOU WIN WOOOOOO" << endl;
                    return 0;
                }
                cout << "Enter your choice (1-7): " << endl;
            }
            else if (buy == 'T') {
                game1.buyTurtle(tank1);
                cout << "TURTLE BOUGHT!" << endl;
                counter += 1;
                if (counter == 4) {
                    game1.DEATH(tank1);
                    game1.cycle(tank1);
                    counter = 0;
                }
                if (game1.getBalance() < 0) {
                    cout << "GAME OVER THE FEDS CAME KNOCKING YOUR IN THE NEGATIVES" << endl;
                    return 0;
                }
                else if (game1.getBalance() >= 2000) {
                    cout << "YOU WIN WOOOOOO" << endl;
                    return 0;
                }
                cout << "Enter your choice (1-7): " << endl;
            }
        }
        else if (option == 6) {
            string fname;
            cout << "Enter file name:" << endl;
            game1.save_game(tank1, fname);
        }
        else if (option == 7) {
            cout << "Would you like to interact with your fishes or turtles? (F/T)" << endl;
            char I;
            cin >> I;
            if (I == 'F') {
                cout << "Which fish would you like to interact with? (enter #)" << endl;
                int id;
                cin >> id;
                id -= 1;
                game1.interactFish(tank1, id);
                cout << "Enter your choice (1-7): " << endl;
            }
            else if (I == 'T') {
                cout << "Which turtle would you like to interact with? (enter #)" << endl;
                int id;
                cin >> id;
                id -= 1;
                game1.interactTurtle(tank1, id);
                cout << "Enter your choice (1-7): " << endl;
            }
        }
    }
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
