#include "Simulation.h"
#include "Board.h"
#include "DonutBoard.h"
#include "ClassicBoard.h"
#include "MirrorBoard.h"
#include <time.h>
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

//Constructor
Simulation::Simulation() {
    m_mode = 0;
    m_rows = 0;
    m_columns = 0;
    m_popDensity = 0.0;
    m_inputFile = " ";
}

//Overloaded constructor
Simulation::Simulation(int mode, int rows, int columns, float popDensity) {
    m_mode = mode;
    m_rows = rows;
    m_columns = columns;
    m_popDensity = popDensity;
}

Simulation::~Simulation() {

}

//Runs the simulation based on the random generation
void Simulation::run() {
    //User input for the choices for the mode
    int userInput;
    cout << "What mode would you like to run it in?" << endl;
    cout << "1. Pause" << endl << "2. Enter" << endl << "3. File" << endl;
    cin >> userInput;
    //Pauses after it prints out the generation
    if (userInput == 1) {
        pauseMode();
        return;
    }
    //Continues as long as the user presses enter
    if (userInput == 2) {
        enterMode();
        return;
    }
    //Writes to the file
    if (userInput == 3) {
        fileMode();
        return;
    }

}


//Mode to write to the file
void Simulation::fileMode() {
    //Output file name
    string outputFile;
    //For output
    ofstream outFS;
    cout << "Enter output file name: " << endl;
    cin >> outputFile;

    //Opens the file but it alson appends to the file
    outFS.open(outputFile);

    //If there is a problem opening the output file
    if(!outFS.is_open()) {
        cout << "Could not open file" << endl;
        return;
    }

    //Regular Board
    if (m_mode == 1) {
        ClassicBoard* myBoard = new ClassicBoard(m_rows, m_columns, m_popDensity);
        //Generating grid
        myBoard->generateBoard();

        //Generation 0
        //Populates the original board
        myBoard->populateBoard();
        //Sets the generation of the board
        myBoard->setGeneration();
        //Writes to the file
        outFS << myBoard->getBoard() << endl;
        //Sets the neighbors for each generation
        myBoard->setNeighbors();
        while(true) {
            //Updates the board
            myBoard->updateBoard();
            //Setes the generation
            myBoard->setGeneration();
            //Sets the generation
            myBoard->setNeighbors();
            //WRites to the file
            outFS << myBoard->getBoard() << endl;
            //If the generation is considered stable
            if (myBoard->isStable()) {
                cout << "A STABLE GENERATION HAS BEEN REACHED" << endl;
                break;
            }
        }
    }

    //Donut Mode
    if (m_mode == 2) {
        DonutBoard* myBoard = new DonutBoard(m_rows, m_columns, m_popDensity);
        //Generating grid
        myBoard->generateBoard();

        //Generation 0
        myBoard->populateBoard();
        myBoard->setGeneration();
        outFS << myBoard->getBoard() << endl;
        myBoard->setNeighbors();
        while(true) {
            //myBoard->showNeighbors();
            myBoard->updateBoard();
            myBoard->setGeneration();
            myBoard->setNeighbors();
            outFS << myBoard->getBoard() << endl;
            //myBoard->testNeighbors();
            // myBoard->showNeighbors();
            if (myBoard->isStable()) {
                //myBoard->showNeighbors();
                cout << "A STABLE GENERATION HAS BEEN REACHED" << endl;
                break;
            }
        }
    }

    //Mirror Mode
    if (m_mode == 3) {
        MirrorBoard* myBoard = new MirrorBoard(m_rows, m_columns, m_popDensity);
        //Generating grid
        myBoard->generateBoard();

        //Generation 0
        myBoard->populateBoard();
        myBoard->setGeneration();
        outFS << myBoard->getBoard() << endl;
        myBoard->setNeighbors();
        while(true) {
            //myBoard->showNeighbors();
            myBoard->updateBoard();
            myBoard->setGeneration();
            myBoard->setNeighbors();
            outFS << myBoard->getBoard() << endl;
            //myBoard->testNeighbors();
            // myBoard->showNeighbors();
            if (myBoard->isStable()) {
                //myBoard->showNeighbors();
                cout << "A STABLE GENERATION HAS BEEN REACHED" << endl;
                break;
            }
        }
    }

    outFS.close();
}

//Continues when user presses enter
void Simulation::enterMode() {   
    //Regular Mode
    if (m_mode == 1) {
        ClassicBoard* myBoard = new ClassicBoard(m_rows, m_columns, m_popDensity);
        //Generating grid
        myBoard->generateBoard();

        //Generation 0
        myBoard->populateBoard();
        myBoard->setGeneration();
        myBoard->printBoard();
        myBoard->setNeighbors();
        while(true) {
            myBoard->updateBoard();
            myBoard->setGeneration();
            myBoard->setNeighbors();
            myBoard->printBoard();
            if (myBoard->isStable()) {
                cout << "A STABLE GENERATION HAS BEEN REACHED" << endl;
                break;
            }
            //Continues as long as the user presses enter
            cout << "Press Enter to Continue";
            cin.ignore();
            cout << endl;
        }
    }
    //Donut Mode
    if (m_mode == 2) {
        DonutBoard* myBoard = new DonutBoard(m_rows, m_columns, m_popDensity);
        //Generating grid
        myBoard->generateBoard();

        //Generation 0
        myBoard->populateBoard();
        myBoard->setGeneration();
        myBoard->printBoard();
        myBoard->setNeighbors();
        while(true) {
            //myBoard->showNeighbors();
            myBoard->updateBoard();
            myBoard->setGeneration();
            myBoard->setNeighbors();
            myBoard->printBoard();
            if (myBoard->isStable()) {

                cout << "A STABLE GENERATION HAS BEEN REACHED" << endl;
                break;
            }
            cout << "Press Enter to Continue";
            cin.ignore();
            cout << endl;
        }
    }
    //Mirror Mode
    if (m_mode == 3) {
        MirrorBoard* myBoard = new MirrorBoard(m_rows, m_columns, m_popDensity);
        //Generating grid
        myBoard->generateBoard();
        //Generation 0
        myBoard->populateBoard();
        myBoard->setGeneration();
        myBoard->printBoard();
        myBoard->setNeighbors();
        while(true) {
            myBoard->updateBoard();
            myBoard->setGeneration();
            myBoard->setNeighbors();
            myBoard->printBoard();
            if (myBoard->isStable()) {
   
                cout << "A STABLE GENERATION HAS BEEN REACHED" << endl;
                break;
            }
            cout << "Press Enter to Continue";
            cin.ignore();
            cout << endl;
        }
    }

}

//Pause mode
void Simulation::pauseMode() {

    if (m_mode == 1) {
        ClassicBoard* myBoard = new ClassicBoard(m_rows, m_columns, m_popDensity);
        //Generating grid
        myBoard->generateBoard();

        //Generation 0
        myBoard->populateBoard();
        myBoard->setGeneration();
        myBoard->printBoard();
        myBoard->setNeighbors();
        while(true) {
            myBoard->updateBoard();
            myBoard->setGeneration();
            myBoard->setNeighbors();
            myBoard->printBoard();
            if (myBoard->isStable()) {
                cout << "A STABLE GENERATION HAS BEEN REACHED" << endl;
                break;
            }
            sleep(1);
        }
    }
    
    if (m_mode == 2) {
        DonutBoard* myBoard = new DonutBoard(m_rows, m_columns, m_popDensity);
        //Generating grid
        myBoard->generateBoard();

        //Generation 0
        myBoard->populateBoard();
        myBoard->setGeneration();
        myBoard->printBoard();
        myBoard->setNeighbors();
        while(true) {
            myBoard->updateBoard();
            myBoard->setGeneration();
            myBoard->setNeighbors();
            myBoard->printBoard();
            if (myBoard->isStable()) {
                cout << "A STABLE GENERATION HAS BEEN REACHED" << endl;
                break;
            }
            sleep(1);
        }
    }

    if (m_mode == 3) {
        MirrorBoard* myBoard = new MirrorBoard(m_rows, m_columns, m_popDensity);
        //Generating grid
        myBoard->generateBoard();
        //Generation 0
        myBoard->populateBoard();
        myBoard->setGeneration();
        myBoard->printBoard();
        myBoard->setNeighbors();
        while(true) {
            myBoard->updateBoard();
            myBoard->setGeneration();
            myBoard->setNeighbors();
            myBoard->printBoard();
            if (myBoard->isStable()) {
                cout << "A STABLE GENERATION HAS BEEN REACHED" << endl;
                break;
            }
            sleep(1);
        }
    }

    //CHANGE CODE ABOVE TO A DO WHILE?
}

//sleeps the progrmam for the specified number of seconds
void Simulation::sleep(int seconds) {
    clock_t t;
    t = clock() + (seconds * CLOCKS_PER_SEC);
    while (clock() < t) {}
}


