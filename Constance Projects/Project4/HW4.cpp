#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <numeric>
using namespace std;

// make useful structure
typedef struct personStats
{
    string firstName;
    string MiddleI;
    string lastName;
    double personalTotalSales;
    double averageWeeklySales;
    double overallTotalSales;
} personStats;

bool getFileContent(string filename, string outputFilename, vector<string> &lines)
{
    ifstream inFile;

    inFile.open(filename); // open the file

    // verify the file opened, and proceed to gather the data if it does
    if (inFile)
    {
        string line;
        while (getline(inFile, line)) // read each line of file, line by line
        {
            lines.push_back((line)); // add current line to vector holding contents of file
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

personStats readandOutputPersonStats(vector<string> &fileContent, int numWeeks, int runningTotal, int &lineReference)
{
    int initialLineReference = lineReference;
    double averageSales;
    double personTotal = 0.0;
    int week = 1;
    double dayTotal;
    personStats personalStats;

    //read in personal info for each employee
    istringstream ss(fileContent[lineReference]);
    ss >> personalStats.firstName;
    ss >> personalStats.MiddleI;
    ss >> personalStats.lastName;
    cout << personalStats.firstName << " " << personalStats.lastName << " had an average sale of: " <<endl;

    while (week <= numWeeks);
    {
        cout << "calculations for week " << week << " of " << numWeeks;

        istringstream sst(fileContent[lineReference+week]);
        for (int i = 1; i <=5; i++)
        {
            sst >> dayTotal;
            personTotal += dayTotal;
            cout << "The day total is " << dayTotal <<endl;
            cout << "the persons current total is: " <<personTotal << endl <<endl;
        }
    }
    
    

    return personalStats;
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
        // initilize line reference and running total
        int i = 0, runningTotal = 0;

        // read file header data (remember base 0)
        int numPersons = stoi(fileContent[i++]); // read number of persons in text file then increment to next line
        int numWeeks = stoi(fileContent[i++]);   // read number of weeks per person in text file then increment to next line

        personStats currentPerson = readandOutputPersonStats(fileContent, numWeeks, runningTotal, i);
        i += numWeeks + 1; //increment i for next loop
    }
    else
    {
        cout << "ERROR: File does not exist!" << endl;
    }

    return EXIT_SUCCESS;
}
