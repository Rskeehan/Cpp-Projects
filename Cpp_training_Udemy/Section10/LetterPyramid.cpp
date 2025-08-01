#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int main()
{
    string input;
    
    cout << "Enter a string to build a pyramid: ";
    getline(cin, input);

    vector<string> pyramid;
    string rowSpaceString; 
    string rowString;
    string lastRow;
    const size_t stringSize {input.size()};
    int currentRow {0};
    string lastHalf;


    for (char c: input)
    {
        //get a string for spaces in current row
        rowSpaceString = string(stringSize-(currentRow+1), ' ');

        if (currentRow == 0)
        {
            rowString = rowSpaceString + c + rowSpaceString;
            pyramid.push_back(rowString);
        }else
        {
            // get first half of previous row
            lastRow = pyramid.at(currentRow-1);
            // Extracts the left half of the previous row including the center character to maintain pyramid symmetry
            lastHalf = lastRow.substr(0,(lastRow.size() / 2) + 1);

            // remove spaces from lastHalf string
            lastHalf.erase(remove(lastHalf.begin(), lastHalf.end(), ' '), lastHalf.end());

            //reverse last half
            string lastHalfReversed(lastHalf.rbegin(),lastHalf.rend());

            //build the rowstring
            rowString = rowSpaceString + lastHalf + c + lastHalfReversed + rowSpaceString;
            pyramid.push_back(rowString);
        }

        currentRow++;
    }    

    // Print the pyramid
    int i = 1;
    for (const string& row : pyramid)
    {
        
        cout << i << "|" << row << endl;
        i++;
    }

    return 0;
}