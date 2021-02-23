#include <iostream>
#include <string>
#include "Cell.h"
using namespace std;

Cell::Cell() {    
    m_currRow = -1;
    m_currColumn = -1;
    m_alive = false;
    m_neighbors = -1;
};

Cell::~Cell() {
};

void Cell::setStatus(bool alive) {
    m_alive = alive;
}

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


