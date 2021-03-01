#include "ClassicBoard.h"
#include <iostream>
#include <string>

using namespace std;

//Default constructor
ClassicBoard::ClassicBoard() {
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
ClassicBoard::ClassicBoard(int height, int width, float popDens) {
    m_rows = height;
    m_columns = width;
    m_populationDensity = popDens;
    m_currGeneration = 0;
}

//Deconstructor
ClassicBoard::~ClassicBoard() {
    delete [] m_currentCells;
    for (int i = 0; i < m_rows; ++i) {
        delete [] m_grid[i];
    }
    delete [] m_grid;
};

void ClassicBoard::setNeighbors() {
    for (int i = 0; i < m_rows; ++i) {
        for (int j = 0; j < m_columns; ++j) {
            int neighbors = 0;
            //Upperbound
            if (i != 0) {
                //Above
                if(m_grid[i-1][j].isAlive()) {
                    neighbors++;
                }
                //LeftBound
                if (j != 0) {
                    //Upper Left
                    if(m_grid[i-1][j-1].isAlive()) {
                        neighbors++;
                    }
                }
                //RightBound
                if (j != m_columns - 1) {
                    //Upper Right
                    if(m_grid[i-1][j+1].isAlive()) {
                        neighbors++;
                    }
                }
            }
        
            //Lowerbound
            if (i != m_rows - 1) {
                //Below
                if(m_grid[i+1][j].isAlive()) {
                    neighbors++;
                }
                //LeftBound
                if (j != 0) {
                    //Bottom Left
                    if(m_grid[i+1][j-1].isAlive()) {
                        neighbors++;
                    }
                }
                //RightBound
                if (j != m_columns - 1) {
                    //Bottom Right
                    if(m_grid[i+1][j+1].isAlive()) {
                        neighbors++;
                    }
                }
            }
            //RightBound
            if (j != m_columns - 1) {
                //Right
                if(m_grid[i][j+1].isAlive()) {
                    neighbors++;
                }
            }
            //LeftBound
            if (j != 0) {
                //Left
                if(m_grid[i][j-1].isAlive()) {
                    neighbors++;
                }
            }
            m_grid[i][j].setAmtNeighbors(neighbors);
            m_grid[i][j].setAvgNeighbors(m_currGeneration%3);
            
        }
    }
}
