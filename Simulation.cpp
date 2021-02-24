#include "Simulation.h"
#include "Board.h"
#include <time.h>
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

Simulation::Simulation() {
    m_mode = 0;
    m_rows = 0;
    m_columns = 0;
    m_popDensity = 0.0;
}

Simulation::Simulation(int mode, int rows, int columns, float popDensity) {
    m_mode = mode;
    m_rows = rows;
    m_columns = columns;
    m_popDensity = popDensity;
}

Simulation::~Simulation() {

}

void Simulation::run() {
    int userInput;
    cout << "What mode would you like to run it in?" << endl;
    cout << "1. Pause" << endl << "2. Enter" << endl << "3. File" << endl;
    cin >> userInput;
    if (userInput == 1) {
        pauseMode();
        return;
    }

}


void Simulation::pauseMode() {
    if (m_mode == 1) {
        Board* myBoard = new Board(m_rows, m_columns, m_popDensity);
        //Generating grid
        myBoard->generateBoard();

        //Generation 0
        myBoard->populateBoard();
        myBoard->printBoard();
        sleep(1);

        while(true) {
            myBoard->setNeighbors();
            myBoard->updateBoard();
            myBoard->printBoard();
            sleep(1);
        }
    }
}

//sleeps the progrmam for the specified number of seconds
void Simulation::sleep(int seconds) {
    clock_t t;
    t = clock() + (seconds * CLOCKS_PER_SEC);
    while (clock() < t) {}
}


