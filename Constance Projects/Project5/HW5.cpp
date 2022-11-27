#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <vector>

using namespace std;

class MyString
{
private:
    char content[32];
    int length;

public:
    MyString() // default constructor
    {
        length = 0;
        content[32] = {};
    };

    // getters
    int getLength() // returns length of private member var 'content'
    {
        return length;
    };

    bool pushBack(char inchar) // adds a char to the 'content' char stack if possible`
    {
        bool successfullyAdded;
        if (length >= 32)
        {
            successfullyAdded = false;
        }
        else
        {
            content[length] = inchar; // adds character to top of stack
            length += 1;              // tracks top of content stack

            successfullyAdded = true;
        }

        return successfullyAdded; // return result
    }
};

int main()
{
    // Code here
    return EXIT_SUCCESS;
};
