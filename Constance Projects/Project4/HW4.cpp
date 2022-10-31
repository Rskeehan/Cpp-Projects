#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

bool getFileContent(string filename, string outputFilename, vector<string> &lines)
{
    ifstream inFile;

    inFile.open(filename); // open the file

    // verify the file opened, and proceed to gather the data if it does
    if (inFile)
    {
        string line;
        while (getline(inFile,line)) //read each line of file, line by line
        {
            lines.push_back((line)); //add current line to vector holding contents of file
        }
        
        inFile.close(); // close the file
        
        return true;
    }
    else
    {
        cout << "The file doesn't exist." << endl;
        return false;
    }
}

void writeInfo(ifstream inFile, int numPers, int weeks, string outFile) // method for writing file output
{
    // code here to write output file
}

double readandCalcPersonStats(int weeks, double runningTotal)
{
    double averageSales;
    cout << "The ";

    return runningTotal;
}

int main()
{
    string outputName;
    vector<string> fileContent;

    // prompt user for initial filename
    cout << "what would you like your output file to be called?";
    cin >> outputName;

    bool success = getFileContent("theSales.txt", outputName, fileContent); // get file content from 'theSales.txt'and put it into vector.

    if (success)
    {
        
    }
    else
    {
        cout << "ERROR: File does not exist!" <<endl;
    }
    

    return EXIT_SUCCESS;
}
