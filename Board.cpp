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
    delete [] m_grid;
    delete [] m_currentCells;
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

    for (int i = 0; i < population; ++i) {
        cellArray[i] = 0;
    }
    
    //Setting the number of cells based on population density
    //FIX REPEATING RANDOM NUMBERS
    for (int i = 0; i < population; ++i) {
      randomNum = rand()%gridSize + 1;
      for (int j = 0; j < population; ++j) {
        if (cellArray[j] == randomNum)  {
            randomNum = rand()%gridSize + 1;
            }
        }
        cellArray[i] = randomNum;
        cout << cellArray[i] << endl;
    } 


    //Filling the array with X
    //Setting the Cell class
    for (int i = 0; i < m_rows; ++i) {
        for (int j = 0; j < m_columns; ++j) {
            for (int k = 0; k < population; ++k) {
                if (cellArray[k] == (i*10 + j)) {
                    m_grid[i][j].setStatus(true);
                }
            }
        }
    }

}

void Board::updateBoard() {
    if (m_currGeneration > 3) {

    } else if (m_currGeneration == 0) {
        for (int i = 0; i < m_rows; ++i) {
            for (int j = 0; j < m_columns; ++j) {
                cout << m_grid[i][j].getNeighbors();
            } cout << endl;
        }
    } 
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
        }
    }
}

void Board::printBoard() {
    cout << "Number of rows: " << m_rows << endl;
    cout << "Number of columns: " << m_columns << endl;
    for (int i = 0; i < m_rows; ++i) {
        for (int j = 0; j < m_columns; ++j) {
            cout << m_grid[i][j].printCell();
        }
        cout << endl;
    }
}





