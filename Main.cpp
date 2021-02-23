#include <iostream>
#include <string>
#include "Board.h"

using namespace std;

int main(int argc, char **argv) {
    Board* myBoard = new Board(10,10,0.07);
    myBoard->generateBoard();
    myBoard->populateBoard();
    myBoard->printBoard();

};