//Header file for the mirror boar mode
#ifndef MIRRORBOARD_H
#define MIRRORBOARD_H

#include "Board.h"
using namespace std;

class MirrorBoard : public Board{
    public:
        MirrorBoard();
        MirrorBoard(int height, int width, float popDens);
        ~MirrorBoard();
        void setNeighbors();
        void showNeighbors();
        // bool isStable();
        // void setGeneration();
    private:
        
};
#endif