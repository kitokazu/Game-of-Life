#include "Board.h"
#include "Cell.h"
#include <iostream>
#include <string> 
#include <algorithm>
#include <iterator>

//for random seed
#include <time.h>

using namespace std;

//Default constructor
Board::Board() {
    m_rows = 0;
    m_columns = 0;
    m_populationDensity = 0;
    m_currGeneration = 0;
};

//overloaded constructor
Board::Board(int height, int width, float popDens) {
    m_rows = height;
    m_columns = width;
    m_populationDensity = popDens;
    m_currGeneration = 0;
}

//Deconstructor
Board::~Board() {
    delete [] m_currentCells;
    for (int i = 0; i < m_rows; ++i) {
        delete [] m_grid[i];
    }
    delete [] m_grid;
};

void Board::generateBoard() {
    //REMEMBER TO DELETE THE ARRAY USING A FOR LOOP

    //Dynamic array (size of rows) of pointers
    m_grid = new Cell*[m_rows];

    //Each i-th pointer points to a dynamic array
    for (int i = 0; i < m_rows; ++i) {
        m_grid[i] = new Cell[m_columns];
    }

    //Filling the array with characters
    for (int i = 0; i < m_rows; ++i) {
        for (int j = 0; j < m_columns; ++j) {
            Cell* cell = new Cell();
            m_grid[i][j] = *cell;
            cell->setLocation(i,j);
        }
    }    
}

//Populate the board with cells based on pop density
void Board::populateBoard() {
    int gridSize = m_rows * m_columns;
    int population = gridSize * m_populationDensity;
    int cellArray [population];
    int randomNum; 

    //generate random seed
    //Found this on the internet
    srand (time(NULL));

    cout << "Number of rows: " << m_rows << endl;
    cout << "Number of columns: " << m_columns << endl;

    //Population the board randomly
    //Got this from Professor german
    int count = 0;
    int r =0;
    int c = 0;
    while(count < population) {
        r = rand()%m_rows;
        c = rand()%m_columns;
        if (m_grid[r][c].isAlive()) {
            continue;
        }
        m_grid[r][c].setStatus(true);
        count++;
    }
}

void Board::updateBoard() {
    for (int i = 0; i < m_rows; ++i) {
        for (int j = 0; j < m_columns; ++j) {
            //Dies of lonliness
            if(m_grid[i][j].getAvgNeighbors() < 1.5) {
                m_grid[i][j].setStatus(false);
                //continue;
            } 
            //Stays alive/dead depending on what it was
            else if (m_grid[i][j].getAvgNeighbors() < 2.5) {
                //continue;
            }
            //Stays alive or new cell is born
            else if (m_grid[i][j].getAvgNeighbors() < 3.5) {
                m_grid[i][j].setStatus(true);
                //continue;
            }
            else if (m_grid[i][j].getAvgNeighbors() > 3.51) {
                m_grid[i][j].setStatus(false);
            }
            //cout << m_grid[i][j].getAvgNeighbors() << " ";
        } 
            //cout << endl;
    
    }
    ++m_currGeneration;
}



void Board::testNeighbors() {
    int neighbors = 0;
    for (int i = 0; i < m_rows; ++i) {
        for (int j = 0; j < m_columns; ++j) {
            cout << m_grid[i][j].isAlive();
        }
        cout << endl;
    }
}

void Board::setNeighbors() {
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
            m_grid[i][j].setNeighbors(neighbors);
            m_grid[i][j].setAvgNeighbors(m_currGeneration%3);
        }
       //cout << endl;
    }
}

void Board::printBoard() {
    cout << "Generation: " << m_currGeneration << endl;
    for (int i = 0; i < m_rows; ++i) {
        for (int j = 0; j < m_columns; ++j) {
            cout << m_grid[i][j].printCell();
        }
        cout << endl;
    }
    cout << endl;
}





