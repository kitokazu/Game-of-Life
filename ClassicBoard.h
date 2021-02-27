//Header file for Classic Board Mode
#ifndef CLASSICBOARD_H
#define CLASSICBOARD

#include "Board.h"
using namespace std;

class ClassicBoard : public Board {
    private:
    protected:
    public:
        ClassicBoard();
        ClassicBoard(int height, int width, float popDens);
        ~ClassicBoard();
        void setNeighbors();
};

#endif