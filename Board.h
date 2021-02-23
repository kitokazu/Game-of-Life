//Header file for the board class
#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <string>

using namespace std;

class Board {
    private:
    
    protected:
        char **m_grid;
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
};
#endif