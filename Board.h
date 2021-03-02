//Header file for the board class
#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <string>
#include "Cell.h"

using namespace std;

class Board {
    private:
    
    protected:
        Cell **m_grid;
        Cell *m_currentCells;
        string generations [4];
        int m_currGeneration;
        int m_rows;
        int m_columns;
        float m_populationDensity;
        string m_inputFile;
        string m_generation1;
        string m_generation2;
        string m_generation3;
        string m_generation4;
        string m_generation5;

    public:
        Board();
        Board(int height, int width, float popDens);
        Board(int height, int width, string inputFile);
        ~Board();
        string getBoard();
        void generateBoard();
        void fileToBoard();
        void setBoard();
        void printBoard();
        void populateBoard();
        void updateBoard();
        void setGeneration();
        bool isStable();

};
#endif