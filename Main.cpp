#include <iostream>
#include <string>
#include "Board.h"

using namespace std;

int main(int argc, char **argv) {
    Board* myBoard = new Board(5,5,0.5);
    //Generating grid
    myBoard->generateBoard();
    
    //Generation 0
    myBoard->populateBoard();
    myBoard->printBoard();

    //Generation 1
    myBoard->setNeighbors();
    myBoard->updateBoard();
    myBoard->printBoard();

    //Generation 2
    myBoard->setNeighbors();
    myBoard->updateBoard();
    myBoard->printBoard();

    //Generation 3
    myBoard->setNeighbors();
    myBoard->updateBoard();
    myBoard->printBoard();

    
    //Generation 4
    myBoard->setNeighbors();
    myBoard->updateBoard();
    myBoard->printBoard();
    
    
    //Generation 5
    myBoard->setNeighbors();
    myBoard->updateBoard();
    myBoard->printBoard();











};