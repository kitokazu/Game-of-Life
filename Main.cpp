#include <iostream>
#include <string>
#include <ctime>
#include "Board.h"
#include "Simulation.h"
#include "FileSimulation.h"
#include "ReadFile.h"

using namespace std;

int main(int argc, char **argv) {
    //Whether the user will provide a file or not
    int type;
    //Classic, Donut, or Mirror
    int mode;
    //Numbers of rows in the grid
    int rows;
    //Number of columns in the grid
    int columns;
    //The population density for the grid
    float popDens;


    cout << "Select an option: " << endl;
    cout << "1. Read from file. \n2. Generate grid" << endl;
    cin >> type;
    cout << "What boundry mode would you like to run the program?" << endl;
    cout << "1. Classic" << endl << "2. Donut" << endl << "3. Mirror" << endl;
    cin >> mode;

    //Option to have the grid from a file
    if (type == 1) {
        //The input text file
        string inputFile;
        //Instance to convert the text file to rows/columns
        ReadFile* readfile = new ReadFile();

        cout << "What is the name of the input file?" << endl;
        //Gets the input file from the user
        cin >> inputFile;
        //Gets and Sets the rows and columns
        readfile->fileToNumbers(inputFile);
        rows = readfile->getRows();
        columns = readfile->getColumns();

        //Creats the simulation and calls FileSimulation
        FileSimulation* simulation = new FileSimulation(mode,rows,columns,inputFile);
        simulation->run();
        delete simulation;
    }
    

    if (type == 2) {
        //Gets user input
        cout << "Enter number of rows: " << endl;
        cin >> rows;
        cout << "Enter number of columns: " << endl;
        cin >> columns;
        cout << "Enter population density: (0 to 1)" << endl;
        cin >> popDens;
        //Creates simulation
        Simulation* simulation = new Simulation(mode,rows,columns,popDens);
        simulation->run();
        delete simulation;
    }

};