#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <vector>
#include <fstream>

using namespace std;

void gatherData(string filename)
{
    ifstream inFile;
    
    inFile.open(filename); // open the file

    // verify the file opened, and proceed to gather the data if it does
    if (inFile)
    {
        //read the data from the file
        int numPersons, weeks;

        inFile >> numPersons >> weeks; // get data for reading loops

        //print info for debugging purposes
        cout << "there are " << numPersons << " persons in the data." <<endl;
        cout << "and there are " << weeks << " weeks of data." <<endl; 

        inFile.close(); // close the file
    } 
    else
    cout << "The file doesn't exist." << endl;      
}

void writeFile(ifstream inFile, int numPers, int weeks) // method for wriging file output
{
    // code here to write output file
}

int main()
{
    gatherData("theSales.txt");

    return EXIT_SUCCESS;
}
