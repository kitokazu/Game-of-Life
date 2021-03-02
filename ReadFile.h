#ifndef READFILE_H
#define READFILE_H
#include <string>
#include <iostream>

class ReadFile{
    private:
        string m_rows;
        string m_columns;
    public:
        ReadFile();
        ~ReadFile();
        void fileToNumbers(string file);
        int getRows();
        int getColumns();

        
   protected:

};
#endif