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
        string m_generation1;
        string m_generation2;
        string m_generation3;
        string m_generation4;

    public:
        Board();
        Board(int height, int width, float popDens);
        ~Board();
        void generateBoard();
        void printBoard();
        void populateBoard();
        void updateBoard();
        void testNeighbors();
        void setGeneration();
        bool isStable();

};
#endif