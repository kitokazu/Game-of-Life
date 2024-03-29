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
        float m_avgNeighbors;
        float m_firstN;
        float m_secondN;
        float m_thirdN;
        int m_numGenerations;
    public:
        Cell();
        ~Cell();
        char printCell();
        void setLocation(int row, int column);
        void setStatus(bool alive);
        void setAmtNeighbors(int neighbors);
        void setAvgNeighbors(int gen);
        float getAvgNeighbors();
        int getAmtNeighbors();
        int getRow();
        int getColumn();
        bool isAlive();
    
};

#endif