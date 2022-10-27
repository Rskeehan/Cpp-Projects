#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <vector>

using namespace std;

int main() 
{
    //Constants
    const double PI            = 3.14159;
    const int CIRCLE_CHOICE    = 1;
    const int RECTANGLE_CHOICE = 2;
    const int TRIANGLE_CHOICE  = 3;
    const int QUIT_CHOICE      = 4;

    int loopVar = 0;

    while (loopVar!=1)
    {

        //display a message
        cout << "Geometry Calculator "<< endl << endl
            <<"1. Calculate the area of a Circle"<< endl
            <<"2. Calculate the area of a Rectangle"<< endl
            <<"3. Calculate the area of a Triangle"<< endl
            <<"4. Quit" << endl << endl
            <<"Enter your choice (1-4): " ;

        int choice;

        cin>> choice;

        switch (choice)
        {
            case CIRCLE_CHOICE:
                double radius;
                double circleArea;

                cout << "Input the circle's radius: ";
                cin >> radius;

                circleArea = PI*radius*radius;
                
                cout << endl << "The area of the circle is: " << circleArea << endl <<endl <<endl;

                break;
            case RECTANGLE_CHOICE:
                int length, width;
                double rectangleArea;
                
                cout << "input rectangle length: ";
                cin >> length;
                cout << endl << "input rectangle width: ";
                cin >> width;

                rectangleArea = length*width;

                cout << "The area of the rectangle is " << rectangleArea << endl <<endl <<endl;

                break;
            case TRIANGLE_CHOICE:
                int base, height;
                double triangleArea;

                cout << endl << "input triangle width: ";
                cin >> base;
                cout << "input triangle height: ";
                cin >> height;

                triangleArea = base*height*.5;

                cout << "The area of the triangle is: " << triangleArea << endl <<endl <<endl;

                break;
            case QUIT_CHOICE:
                cout << "No select made.";
                loopVar = 1;
                break;
        }
    }
    
    return EXIT_SUCCESS;
}