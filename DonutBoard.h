//Header file for the donut board mode
#ifndef DONUTBOARD_H
#define DONUTBOARD_H

#include "Board.h"
using namespace std;

class DonutBoard : public Board {
    private:
    public:
        DonutBoard();
        DonutBoard(int height, int width, float popDens);
        ~DonutBoard();

        void setNeighbors();
        // void setGeneration();
        // bool isStable();
        
};

#endif

