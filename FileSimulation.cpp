//This is for whent the user inputs a file instead of a randomly generated grid

#include <string>
#include <iostream>
#include <fstream>
#include "Board.h"
#include "FileSimulation.h"
#include "ClassicBoard.h"
#include "MirrorBoard.h"
#include "DonutBoard.h"
using namespace std;

//Constructor
FileSimulation::FileSimulation() {
    m_mode = 0;
    m_rows = 0;
    m_columns = 0;
    m_popDensity = 0.0;
    m_inputFile = " ";
}
//Overloaded constructor
FileSimulation::FileSimulation(int mode, int rows, int columns,string inputFile) {
    m_mode = mode;
    m_rows = rows;
    m_columns = columns;
    m_inputFile = inputFile;
}

FileSimulation::~FileSimulation() {
}

//method that runs the simulation 
//gives 3 options of how to run the simulation
void FileSimulation::run() {
    int userInput;
    cout << "What mode would you like to run it in?" << endl;
    cout << "1. Pause" << endl << "2. Enter" << endl << "3. File" << endl;
    cin >> userInput;
    //Pause - pauses a second after each generation
    if (userInput == 1) {
        pauseMode();
        return;
    }
    //Enter - goes to the next generation when the user presses enter
    if (userInput == 2) {
        enterMode();
        return;
    }
    //File - write to file
    if (userInput == 3) {
        getFile();
        return;
    }

}

//Pauses the simulation after each generation
void FileSimulation::pauseMode() {   
    if (m_mode == 1) {
        //Takes the rows and columns as wellas the input file
        ClassicBoard* myBoard = new ClassicBoard(m_rows, m_columns, m_inputFile);
        //generates the board
        myBoard->generateBoard();
        //converts the file to the grid
        myBoard->fileToBoard();

        //Generation 0
        //populates the board
        myBoard->populateBoard();
        //sets the generation
        myBoard->setGeneration();
        //prints the board
        myBoard->printBoard();
        //sets the corresponding neighbors
        myBoard->setNeighbors();

        while(true) {
            myBoard->updateBoard();
            //sets the generation
            myBoard->setGeneration();
            //sets the corresponding neighbors
            myBoard->setNeighbors();
            //prints the board
            myBoard->printBoard();
            //Checks if the board is stable
            if (myBoard->isStable()) {
                cout << "A STABLE GENERATION HAS BEEN REACHED" << endl;
                //stops if the generation is considered stable
                break;
            }
            //function to pause
            sleep(1);
        }
    }
    if (m_mode == 2) {
        DonutBoard* myBoard = new DonutBoard(m_rows, m_columns, m_inputFile);
        myBoard->generateBoard();
        myBoard->fileToBoard();

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
        MirrorBoard* myBoard = new MirrorBoard(m_rows, m_columns, m_inputFile);
        myBoard->generateBoard();
        myBoard->fileToBoard();

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

}


//Continues as long as the user presses enter
void FileSimulation::enterMode() {   
    if (m_mode == 1) {
        ClassicBoard* myBoard = new ClassicBoard(m_rows, m_columns, m_inputFile);
        myBoard->generateBoard();
        myBoard->fileToBoard();

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
            //This is where the program checks for the user to press enter
            cout << "Press Enter to Continue";
            cin.ignore();
            cout << endl;
        }
    }
    if (m_mode == 2) {
        DonutBoard* myBoard = new DonutBoard(m_rows, m_columns, m_inputFile);
        myBoard->generateBoard();
        myBoard->fileToBoard();

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
    if (m_mode == 3) {
        MirrorBoard* myBoard = new MirrorBoard(m_rows, m_columns, m_inputFile);
        myBoard->generateBoard();
        myBoard->fileToBoard();

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


//File mode. Outputs the generations to a file
void FileSimulation::getFile() {
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

    if (m_mode == 1) {
        ClassicBoard* myBoard = new ClassicBoard(m_rows, m_columns, m_inputFile);
        myBoard->generateBoard();
        myBoard->fileToBoard();
        myBoard->printBoard();

        //Generation 0
        myBoard->populateBoard();
        myBoard->setGeneration();
        //Writes to the file
        outFS << myBoard->getBoard() << endl;
        myBoard->setNeighbors();
        while(true) {
            myBoard->updateBoard();
            myBoard->setGeneration();
            myBoard->setNeighbors();
            //Writes to the file
            outFS << myBoard->getBoard() << endl;
            if (myBoard->isStable()) {
                cout << "A STABLE GENERATION HAS BEEN REACHED" << endl;
                break;
            }
        }
    }
    if (m_mode == 2) {
        DonutBoard* myBoard = new DonutBoard(m_rows, m_columns, m_inputFile);
        myBoard->generateBoard();
        myBoard->fileToBoard();
        myBoard->printBoard();

        //Generation 0
        myBoard->populateBoard();
        myBoard->setGeneration();
        //Writes to the file
        outFS << myBoard->getBoard() << endl;
        myBoard->setNeighbors();
        while(true) {
            myBoard->updateBoard();
            myBoard->setGeneration();
            myBoard->setNeighbors();
            //Writes to the file
            outFS << myBoard->getBoard() << endl;
            if (myBoard->isStable()) {
                cout << "A STABLE GENERATION HAS BEEN REACHED" << endl;
                break;
            }
        }
    }
    if (m_mode == 3) {
        MirrorBoard* myBoard = new MirrorBoard(m_rows, m_columns, m_inputFile);
        myBoard->generateBoard();
        myBoard->fileToBoard();
        myBoard->printBoard();

        //Generation 0
        myBoard->populateBoard();
        myBoard->setGeneration();
        outFS << myBoard->getBoard() << endl;
        myBoard->setNeighbors();
        while(true) {
            myBoard->updateBoard();
            myBoard->setGeneration();
            myBoard->setNeighbors();
            outFS << myBoard->getBoard() << endl;
            if (myBoard->isStable()) {
                cout << "A STABLE GENERATION HAS BEEN REACHED" << endl;
                break;
            }
        }
    }

    outFS.close();
}