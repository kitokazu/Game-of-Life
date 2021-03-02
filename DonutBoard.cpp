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
    m_generation5 = "";
};

//overloaded constructor
DonutBoard::DonutBoard(int height, int width, float popDens) {
    m_rows = height;
    m_columns = width;
    m_populationDensity = popDens;
    m_currGeneration = 0;
}

//overloaded constructor
DonutBoard::DonutBoard(int height, int width, string inputFile) {
    m_rows = height;
    m_columns = width;
    m_inputFile = inputFile;
}

//Deconstructor
DonutBoard::~DonutBoard() {
    delete [] m_currentCells;
    for (int i = 0; i < m_rows; ++i) {
        delete [] m_grid[i];
    }
    delete [] m_grid;
};

//Sets the neighbors for each cell in the grid
//Have bunch of conditionals to check for neighbors
void DonutBoard::setNeighbors() {
    for (int i = 0; i < m_rows; ++i) {
        for (int j = 0; j < m_columns; ++j) {
            int neighbors = 0;

            //If its on the left side
            if (j == 0) {
                //If its on the opposite side
                if (m_grid[i][j+m_columns-1].isAlive()){
                    ++neighbors;
                }
                //Bounds
                if (i != 0) {
                    //Mirror upper right
                    if (m_grid[i-1][j+m_columns-1].isAlive()) {
                        ++neighbors;
                    }
                }
                if (i != m_rows - 1) {
                    //Mirror bottom right
                    if (m_grid[i+1][j+m_columns-1].isAlive()) {
                        ++neighbors;
                    }
                }
            }
            
            //If its on the right side
            if (j == m_columns - 1) {
                //If its on the opposite side
                if (m_grid[i][0].isAlive()){
                    ++neighbors;
                }
                //Bounds
                if (i != 0) {
                    //Mirror upper left
                    if (m_grid[i-1][0].isAlive()) {
                        ++neighbors;
                    }
                }
                if (i != m_rows - 1) {
                    //Mirror bottom left
                    if (m_grid[i+1][0].isAlive()) {
                        ++neighbors;
                    }
                }
            }

            //MIRROR MODE TOP
            if (i == 0)  {
                //Opposite side from top
                if (m_grid[i+m_rows-1][j].isAlive()) {
                    ++neighbors;
                }
                //Bounds
                if (j != 0) {
                    //Mirror left
                    if (m_grid[i+m_rows-1][j-1].isAlive()) {
                        ++neighbors;
                    }
                } else if (j == 0) {
                    //Bottom Right
                    if (m_grid[i+m_rows-1][j+m_columns-1].isAlive()) {
                        ++neighbors;
                    }
                }
                if (j != m_columns - 1) {
                    //Mirror Right
                    if (m_grid[i+m_rows-1][j+1].isAlive()) {
                        ++neighbors;
                    }
                } else if (j == m_columns - 1) {
                    //Bottom left
                    if (m_grid[i+m_rows-1][0].isAlive()) {
                        ++neighbors;
                    }
                }
            }

            //MIRRO MODE BOTTOM
            if (i == m_rows - 1)  {
                //Opposite side from top
                if (m_grid[0][j].isAlive()) {
                    ++neighbors;
                }
                //Bounds
                if (j != 0) {
                    //Mirror left
                    if (m_grid[0][j-1].isAlive()) {
                        ++neighbors;
                    }
                } else if (j == 0) {
                    //Top right
                    if (m_grid[0][j+m_columns-1].isAlive()) {
                        ++neighbors;
                    }
                }

                if (j != m_columns - 1) {
                    //Mirror Right
                    if (m_grid[0][j+1].isAlive()) {
                        ++neighbors;
                    }
                } else if (j == m_columns - 1) {
                    //top left
                    if (m_grid[0][0].isAlive()) {
                        ++neighbors;
                    }
                }
            }


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
            //Sets the amount of neighbors
            m_grid[i][j].setAmtNeighbors(neighbors);
            //Sets the amouunt of average neigbors for the corresponding cell
            m_grid[i][j].setAvgNeighbors(m_currGeneration%3);
        }
    }
}


