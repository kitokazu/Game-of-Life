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
        int m_currGeneration;
        int m_rows;
        int m_columns;
        float m_populationDensity;

    public:
        Board();
        Board(int height, int width, float popDens);
        ~Board();
        void generateBoard();
        void printBoard();
        void populateBoard();
        void updateBoard();
        void setNeighbors();
        void testNeighbors();
};
#endif