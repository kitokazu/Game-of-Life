#ifndef FILEIMULATION_H
#define FILESIMULATION_H
#include "Simulation.h"
using namespace std;

class FileSimulation : public Simulation{
    private:
    protected:
        int m_mode;
        int m_rows;
        int m_columns;
        float m_popDensity;
        string m_inputFile;

    public:
        FileSimulation();
        FileSimulation(int mode, int rows, int columns,string inputFile);
        ~FileSimulation();
        void run();
        void pauseMode();
        void enterMode();
        void getFile();
        void fileMode();
        //void sleep(int seconds);
};


#endif