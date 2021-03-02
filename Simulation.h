#ifndef SIMULATION_H
#define SIMULATION_H
#include <string>

using namespace std;

class Simulation{
    private:
    protected:
        int m_mode;
        int m_rows;
        int m_columns;
        float m_popDensity;
        string m_inputFile;

    public:
        Simulation();
        Simulation(int mode, int rows, int columns, float popDensity);
        ~Simulation();
        void run();
        void pauseMode();
        void enterMode();
        //void getFile();
        void fileMode();
        void sleep(int seconds);
};


#endif