#include <iostream>
#include <string>
#include "Cell.h"
using namespace std;

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

Cell::~Cell() {
};

void Cell::setStatus(bool alive) {
    m_alive = alive;
}

// void Cell::setTempStatus(bool tempAlive) {
//     m_tempAlive = tempAlive;
// }

// bool Cell::isTempAlive(){
//     return m_tempAlive;
// }


bool Cell::isAlive() {
    return m_alive;
}

char Cell::printCell() {
    if (m_alive) {
        return 'X';
    } else {
        return '-';
    }
};

int Cell::getNeighbors() {
    return m_neighbors;
}

void Cell::setNeighbors(int neighbors) {
    m_neighbors = neighbors;
}

void Cell::setLocation(int row, int column) {
    m_currRow = row;
    m_currColumn = column;
}

int Cell::getRow(){
    return m_currRow;
}
int Cell::getColumn(){
    return m_currColumn;
}

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

float Cell::getAvgNeighbors() {
    return m_avgNeighbors;
}

void Cell::setGeneration(int gen) {
    // if (gen == 0) {
    //     firstN = m_currNeighbors;
    // }
    // else if (gen == 1)  {
    //     secondN = m_currNeighbors;
    // }
    // else if (gen == 2) {
    //     thirdn == m_currNeighors;
    // }
}

