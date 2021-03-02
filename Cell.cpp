#include <iostream>
#include <string>
#include "Cell.h"
using namespace std;

//Default Constructor
Cell::Cell() {    
    m_currRow = -1;
    m_currColumn = -1;
    m_alive = false;
    // m_tempAlive = false;
    m_neighbors = -1;
    m_firstN = 0;
    m_secondN = 0;
    m_thirdN = 0;
    m_numGenerations = 0.0;
    m_avgNeighbors = 0;
};

//Destructor
Cell::~Cell() {
};

//sets the status of the cell to alive or dead
void Cell::setStatus(bool alive) {
    m_alive = alive;
}

//Returns if then cell is alive
bool Cell::isAlive() {
    return m_alive;
}

//prints X if the cell is alive
//prints - if the cell is dead
char Cell::printCell() {
    if (m_alive) {
        return 'X';
    } else {
        return '-';
    }
};

//Returns the amount of neigbors
int Cell::getAmtNeighbors() {
    return m_neighbors;
}

//sets the amount of neighbors
void Cell::setAmtNeighbors(int neighbors) {
    m_neighbors = neighbors;
}

//sets the location of neighbors
void Cell::setLocation(int row, int column) {
    m_currRow = row;
    m_currColumn = column;
}

//returns the row
int Cell::getRow(){
    return m_currRow;
}
//returns the columns
int Cell::getColumn(){
    return m_currColumn;
}

//Calculates the average amount of neighbors based off the previous 3
void Cell::setAvgNeighbors(int gen) {
    //If the generation number % 3 is: 
    if (gen == 0) {
        m_firstN = m_neighbors;
    }
    else if (gen == 1)  {
        m_secondN = m_neighbors;
    }
    else if (gen == 2) {
        m_thirdN = m_neighbors;
    }
    if(m_numGenerations < 3) {
        ++m_numGenerations;
    }
    //cout << m_firstN << m_secondN << m_thirdN << m_numGenerations << endl;
    m_avgNeighbors = (m_firstN + m_secondN + m_thirdN) / m_numGenerations;
}

//returns teh avg amount of neighbors
float Cell::getAvgNeighbors() {
    return m_avgNeighbors;
}

