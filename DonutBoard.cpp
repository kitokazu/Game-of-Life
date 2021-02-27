#include "DonutBoard.h"
#include <iostream>
#include <string>

using namespace std;

//Default constructor
DonutBoard::DonutBoard() {
    m_rows = 0;
    m_columns = 0;
    m_populationDensity = 0;
    m_currGeneration = 0;
    m_generation1 = "";
    m_generation2 = "";
    m_generation3 = "";
    m_generation4 = "";
};

//overloaded constructor
DonutBoard::DonutBoard(int height, int width, float popDens) {
    m_rows = height;
    m_columns = width;
    m_populationDensity = popDens;
    m_currGeneration = 0;
}

//Deconstructor
DonutBoard::~DonutBoard() {
    delete [] m_currentCells;
    for (int i = 0; i < m_rows; ++i) {
        delete [] m_grid[i];
    }
    delete [] m_grid;
};



