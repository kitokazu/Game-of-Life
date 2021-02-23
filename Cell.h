#ifndef CELL_H
#define CELL_H

using namespace std;

class Cell {
    private:
    protected: 
        int m_currRow;
        int m_currColumn;
        bool m_alive;
        int m_neighbors;
    public:
        Cell();
        ~Cell();
        char printCell();
        void setLocation(int row, int column);
        void setStatus(bool alive);
        void setNeighbors(int neighbors);
        int getNeighbors();
        int getRow();
        int getColumn();

        bool isAlive();

};

#endif