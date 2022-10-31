#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <numeric> //accessing vector summing
#include <iomanip> //accesses setting precision

using namespace std;

// make useful structure
typedef struct personStats
{
    string firstName;
    string MiddleI;
    string lastName;
    double personalTotalSales;
    double averageWeeklySales;
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

personStats readandOutputPersonStats(vector<string> &fileContent, int numWeeks, int &lineReference)
{
    int initialLineReference = lineReference;
    double averageSales;
    double personTotal = 0.0;
    int week = 1;
    double dayTotal;
    personStats personalStats;

    // read in personal info for each employee
    istringstream ss(fileContent[lineReference]);
    ss >> personalStats.firstName;
    ss >> personalStats.MiddleI;
    ss >> personalStats.lastName;

    // calculate person's average and total sales
    for (week = 1; week <= numWeeks; week++)
    {
        istringstream sst(fileContent[lineReference + week]); // read in line of sales values
        for (int i = 1; i <= 5; i++)
        {
            sst >> dayTotal; // read in each sales value to dayTotal before adding to persontoal in next line
            personTotal += dayTotal;
        }
    }
    personalStats.personalTotalSales = personTotal;            // assign personaltotal
    personalStats.averageWeeklySales = personTotal / numWeeks; // assign personAverage

    //output info for the person
    cout << personalStats.lastName << " had a total of $" << personalStats.personalTotalSales << " over " << numWeeks << " weeks. For an average of $" << personalStats.averageWeeklySales << " a week." << endl;

    return personalStats; // return the person's info.
}

int main()
{
    string outputName;
    vector<string> fileContent;

    // prompt user for initial filename
    cout << "what would you like your output file to be called?";
    cin >> outputName;
    cout << setprecision(8);
    bool success = getFileContent("theSales.txt", outputName, fileContent); // get file content from 'theSales.txt'and put it into vector.

    if (success)
    {
        // initilize line reference and running total
        int lineReference = 0;
        double runningTotal = 0;

        // read file header data (remember base 0)
        int numPersons = stoi(fileContent[lineReference++]); // read number of persons in text file then increment to next line
        int numWeeks = stoi(fileContent[lineReference++]);   // read number of weeks per person in text file then increment to next line
        int person = 1;
        // output and increment information
        for (person = 0; person < numPersons; lineReference += numWeeks + 1)
        {
            // get personal stats for current person and output them
            personStats currentPerson = readandOutputPersonStats(fileContent, numWeeks, lineReference);
            runningTotal += currentPerson.personalTotalSales;

            // increment person
            person++;
        }
        cout << "The Grand total of sales across the sample of " << numWeeks << " is $" << runningTotal << ". for an average of $" << runningTotal / numWeeks << " per week." << endl;
    }
    else
    {
        cout << "ERROR: File does not exist!" << endl;
    }

    return EXIT_SUCCESS;
}
