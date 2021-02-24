#include <iostream>
#include <string>
#include <ctime>
#include "Board.h"
#include "Simulation.h"

using namespace std;

int main(int argc, char **argv) {
    int mode;

    //SPECIFY HERE TO HAVE RANDOM NUMBERS OR GET FROM FILE
    cout << "What boundry mode would you like to run the program?" << endl;
    cout << "1. Classic" << endl << "2. Donut" << endl << "3. Mirror" << endl;
    cin >> mode;
    Simulation* simulation = new Simulation(mode,5,5,0.7);
    simulation->run();

};