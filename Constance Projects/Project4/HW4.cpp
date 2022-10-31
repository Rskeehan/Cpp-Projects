#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <vector>
#include <fstream>

using namespace std;

void writeStats(string filename, string outputFilename)
{
    ifstream inFile;
    
    inFile.open(filename); // open the file

    // verify the file opened, and proceed to gather the data if it does
    if (inFile)
    {
        //read the data from the file
        int numPersons, weeks; //declare initial variables.

        inFile >> numPersons >> weeks; // get data for reading loops

        //print info for debugging purposes
        cout << "there are " << numPersons << " persons in the data." <<endl;
        cout << "and there are " << weeks << " weeks of data." <<endl; 

        inFile.close(); // close the file
    } 
    else
    cout << "The file doesn't exist." << endl;      
}

void writeInfo(ifstream inFile, int numPers, int weeks, string outFile) // method for writing file output
{
    // code here to write output file
}

double readandCalcPersonStats(int weeks,double runningTotal)
{
    cout << "the ";
}

int main()
{
    ifstream inFile;
    string outputName;

    //prompt user for initial filename
    cout << "what would you like your output file to be called?";
    cin >> outputName;

    writeStats("theSales.txt", outputName); //write the data from 'theSales.txt' to your preferred filename.

    
    
    return EXIT_SUCCESS;
}
