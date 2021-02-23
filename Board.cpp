#include "Board.h"
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
};

//overloaded constructor
Board::Board(int height, int width, float popDens) {
    m_rows = height;
    m_columns = width;
    m_populationDensity = popDens;
}

//Deconstructor
Board::~Board() {
    delete [] m_grid;
};

void Board::generateBoard() {
    //Dynamic array (size of rows) of pointers
    m_grid = new char*[m_rows];

    //Each i-th pointer points to a dynamic array
    for (int i = 0; i < m_rows; ++i) {
        m_grid[i] = new char[m_columns];
    }

    //Filling the array with characters
    for (int i = 0; i < m_rows; ++i) {
        for (int j = 0; j < m_columns; ++j) {
            m_grid[i][j] = '-';
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
    for (int i = 0; i < m_rows; ++i) {
        for (int j = 0; j < m_columns; ++j) {
            for (int k = 0; k < population; ++k) {
                if (cellArray[k] == (i*10 + j)) {
                    m_grid[i][j] = 'X';
                }
            }
        }
    }

}

    // //int *result = std::find(myArray, end, 0);
    // if (result != end) {
    //  // found value at "result" pointer location...
    // }    

            // do {            
        //     randomNum = rand()%gridSize + 1;
        //     cout << randomNum << endl;
        //     for (int j = 0; j < population; ++i) {
        //         if (randomNum == cellArray[j]) {
        //             loop = true;
        //             break;
        //         }    
        //     }
        // } while (loop);

        // bool duplicate = false;
        // while (!duplicate) {
        //     randomNum = rand()%gridSize + 1;
        //     for (int j = 0; j < population; ++i) {
        //         cout << "initial loop" << endl;
        //         if (randomNum == cellArray[j]) {
        //             cout << "made it in loop" << endl;
        //             duplicate = true;
        //             break;
        //         }    
        //     }
        //     if (!duplicate) {
        //         cellArray[i] = randomNum;
        //         break;
        //     } else {
        //         duplicate = false;
        //     }
        // }

    
    


void Board::printBoard() {
    cout << "Number of rows: " << m_rows << endl;
    cout << "Number of columns: " << m_columns << endl;
    for (int i = 0; i < m_rows; ++i) {
        for (int j = 0; j < m_columns; ++j) {
            cout << m_grid[i][j];
        }
        cout << endl;
    }
}





