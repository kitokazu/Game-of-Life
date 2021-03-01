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
    m_generation1 = "";
    m_generation2 = "";
    m_generation3 = "";
    m_generation4 = "";
    m_generation5 = "";

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
    //delete [] this->generations;
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
    //Got this from Professor
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
    for (int i = 0; i < m_rows; ++i) {
        for (int j = 0; j < m_columns; ++j) {
            cout << m_grid[i][j].getAvgNeighbors();
        }
        cout << endl;
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

bool Board::isStable() {
    if (m_currGeneration < 4) {
        return false;
    }
    if (m_generation1 == m_generation3) return true;
    if(m_generation1 == m_generation2) return true;
    if(m_generation1 == m_generation4) return true;
    if(m_generation1 == m_generation5) return true;
    if(m_generation2 == m_generation3) return true;
    if(m_generation2 == m_generation4) return true;
    if(m_generation2 == m_generation5) return true;
    if(m_generation3 == m_generation4) return true;
    if(m_generation3 == m_generation5) return true;
    if(m_generation4 == m_generation5) return true;
    return false;
}

void Board::setGeneration() {
    if (m_currGeneration%5 == 0) {m_generation1 = "";}
    if (m_currGeneration%5 == 1) {m_generation2 = "";}
    if (m_currGeneration%5 == 2) {m_generation3 = "";}
    if (m_currGeneration%5 == 3) {m_generation4 = "";}
    if (m_currGeneration%5 == 4) {m_generation5 = "";}

    for (int i = 0; i < m_rows; ++i) {
        for (int j = 0; j < m_columns; ++j) {

            if (m_currGeneration%5 == 0) {
                m_generation1 += m_grid[i][j].printCell();
            }
            if (m_currGeneration%5 == 1) {
                m_generation2 += m_grid[i][j].printCell();
            }
            if (m_currGeneration%5 == 2) {
                m_generation3 += m_grid[i][j].printCell();
            }
            if (m_currGeneration%5 == 3) {
                m_generation4 += m_grid[i][j].printCell();
            }
             if (m_currGeneration%5 == 4) {
                m_generation5 += m_grid[i][j].printCell();
            }
            
        }
    }
    
    cout << m_generation1 << endl;
    cout << m_generation2 << endl;
    cout << m_generation3 << endl;
    cout << m_generation4 << endl;
    cout << m_generation5 << endl;  
    cout << endl;

}




void Board::showNeighbors() {
    for (int i = 0; i < m_rows; ++i) {
        for (int j = 0; j < m_columns; ++j) {
            cout << m_grid[i][j].getAmtNeighbors();
        }
        cout << endl;
    }
    cout << endl;
}





