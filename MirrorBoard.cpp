#include "MirrorBoard.h"
#include <iostream>
#include <string>

using namespace std;

//Default constructor
MirrorBoard::MirrorBoard() {
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
MirrorBoard::MirrorBoard(int height, int width, float popDens) {
    m_rows = height;
    m_columns = width;
    m_populationDensity = popDens;
    m_currGeneration = 0;
}

//Deconstructor
MirrorBoard::~MirrorBoard() {
    delete [] m_currentCells;
    for (int i = 0; i < m_rows; ++i) {
        delete [] m_grid[i];
    }
    delete [] m_grid;
};

// bool MirrorBoard::isStable() {
//      if (m_currGeneration < 4) {
//         return false;
//     }
//     if (m_generation1 == m_generation3) return true;
//     if(m_generation1 == m_generation2) return true;
//     if(m_generation1 == m_generation4) return true;
//     if(m_generation1 == m_generation5) return true;
//     if(m_generation2 == m_generation3) return true;
//     if(m_generation2 == m_generation4) return true;
//     if(m_generation2 == m_generation5) return true;
//     if(m_generation3 == m_generation4) return true;
//     if(m_generation3 == m_generation5) return true;
//     if(m_generation4 == m_generation5) return true;
//     return false;
// }

// void MirrorBoard::setGeneration() {
//     if (m_currGeneration%5 == 0) {m_generation1 = "";}
//     if (m_currGeneration%5 == 1) {m_generation2 = "";}
//     if (m_currGeneration%5 == 2) {m_generation3 = "";}
//     if (m_currGeneration%5 == 3) {m_generation4 = "";}
//     if (m_currGeneration%5 == 4) {m_generation5 = "";}

//     for (int i = 0; i < m_rows; ++i) {
//         for (int j = 0; j < m_columns; ++j) {

//             if (m_currGeneration%5 == 0) {
//                 m_generation1 += m_grid[i][j].printCell();
//             }
//             if (m_currGeneration%5 == 1) {
//                 m_generation2 += m_grid[i][j].printCell();
//             }
//             if (m_currGeneration%5 == 2) {
//                 m_generation3 += m_grid[i][j].printCell();
//             }
//             if (m_currGeneration%5 == 3) {
//                 m_generation4 += m_grid[i][j].printCell();
//             }
//              if (m_currGeneration%5 == 4) {
//                 m_generation5 += m_grid[i][j].printCell();
//             }
            
//         }
//     }
    
//     cout << m_generation1 << endl;
//     cout << m_generation2 << endl;
//     cout << m_generation3 << endl;
//     cout << m_generation4 << endl;
//     cout << m_generation5 << endl;  
//     cout << endl;

// }




void MirrorBoard::setNeighbors() {
    for (int i = 0; i < m_rows; ++i) {
        for (int j = 0; j < m_columns; ++j) {
            int neighbors = 0;
            //If its on the top
            if (i == 0) {
                if (m_grid[i][j].isAlive()) {
                    ++neighbors;
                }
                //If its not on the top left
                if (j != 0) {
                    if (m_grid[i][j-1].isAlive()) {
                        ++neighbors;
                    }
                //if its on the top left 
                } else if ((j == 0) && (m_grid[i][j].isAlive())) {
                    ++neighbors;
                    //++neighbors;
                } 

                //If its not on the top right
                if (j != m_columns - 1) {
                    if (m_grid[i][j+1].isAlive()) {
                        ++neighbors;
                    }
                } else if ((j == m_columns - 1) && (m_grid[i][j].isAlive())) {
                    ++neighbors;
                    //++neighbors;
                }


            }
            
            //If its on the bottom 
            if (i == m_rows - 1) {
                if (m_grid[i][j].isAlive()) {
                    ++neighbors;
                }
                //If its not on the bottom left
                if (j != 0) {
                    //If its not on the bottom left
                    if (m_grid[i][j-1].isAlive())  {
                        ++neighbors;
                    }
                    
                } else if ((j == 0) && (m_grid[i][j].isAlive())) {
                    //If its not on the bottom left
                    ++neighbors;
                }

                //Not on Bottom right
                if (j != m_columns - 1) {
                    //If its not on the bottom right
                    if (m_grid[i][j+1].isAlive())  {
                        ++neighbors;
                    }
                    
                } else if ((j == m_columns - 1) && (m_grid[i][j].isAlive())) {
                    //If its not on the bottom left
                    ++neighbors;
                }
            }

            //If its on the left side and not on the top or bottom
            if (j == 0) {
                if (m_grid[i][j].isAlive()) {
                    ++neighbors;
                }
                if ((i != 0) && (m_grid[i-1][j].isAlive())) {
                    ++neighbors;
                }
                if ((i != m_rows - 1) && (m_grid[i+1][j].isAlive())) {
                    ++neighbors;
                }
            }

            //If its on the right side and not on the top or bottom
            if (j == m_columns - 1) {
                if (m_grid[i][j].isAlive()) {
                    ++neighbors;
                }
                if ((i != 0) && (m_grid[i-1][j].isAlive())) {
                    ++neighbors;
                }
                if ((i != m_rows - 1) && (m_grid[i+1][j].isAlive())) {
                    ++neighbors;
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
            m_grid[i][j].setAmtNeighbors(neighbors);
            m_grid[i][j].setAvgNeighbors(m_currGeneration%3);
        }
    }
}

// void MirrorBoard::showNeighbors() {
//     for (int i = 0; i < m_rows; ++i) {
//         for (int j = 0; j < m_columns; ++j) {
//             cout << m_grid[i][j].getAmtNeighbors();
//         }
//         cout << endl;
//     }
//     cout << endl;
// }