#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <vector>

using namespace std;

class MyString // primary class as directed by instruction document
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

    // getter
    int getLength() // returns length of private member var 'content'
    {
        return length;
    };

    // setter
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
    return EXIT_SUCCESS;
}
