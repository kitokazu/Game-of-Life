#include <iostream>
#include <string>
#include "Board.h"
#include "Readfile.h"
#include "Simulation.h"
#include <fstream>

using namespace std;

ReadFile::ReadFile() {
    m_rows = "";
    m_rows = "";
};


//Converts the text file to rows and columns for the program
void ReadFile::fileToNumbers(string file) {
  //For input
  ifstream inFS;  
  //string
  string fileSentence;
  //Opening input file
  inFS.open(file);
  //If the input file does not exist
   if(!inFS.is_open()) {
     cout << "Error opening file" << endl;
     return;
   }
   //The first line is the rows
   getline(inFS,m_rows);
   //the second line is the columns
   getline(inFS,m_columns);
   inFS.close();
   return;
}

int ReadFile::getRows() {
    cout << m_rows;
    return stoi(m_rows);
}

int ReadFile::getColumns() {
    cout << m_columns;
    return stoi(m_columns);
}





