// Section 9
// Challenge
/*
    This challenge is about using a collection (list) of integers and allowing the user
    to select options from a menu to perform operations on the list.

Before you begin. Write out the steps you need to take and decide in what order they should be done.
Think about what loops you should use as well as what you will use for your selection logic.

This exercise can be challenging! It may likely take a few attempts before you complete it -- that's OK!

Finally, be sure to test your program as you go and at the end.

Hint: Use a vector!

Additional functionality if you wish to extend this program.

- search for a number in the list and if found display the number of times it occurs in the list
- clearing out the list (make it empty again) (Hint: the vector class has a .clear() method)
- don't allow duplicate entries
- come up with your own ideas!

Good luck!

*/
#include <iostream>
#include <vector>

using namespace std;

int main()
{

    char choice;
    vector<int> numbers;

    //     Your program should display a menu options to the user as follows:

    //     P - Print numbers
    //     A - Add a number
    //     M - Display mean of the numbers
    //     S - Display the smallest number
    //     L - Display the largest number
    //     Q - Quit

    //     Enter your choice:

    // The program should only accept valid choices from the user, both upper and lowercase selections should be allowed.
    do
    {

        cout << "P - Print numbers" << std::endl;
        cout << "A - Add a number" << std::endl;
        cout << "M - Display mean of the numbers" << std::endl;
        cout << "S - Display the smallest number" << std::endl;
        cout << "L - Display the largest number" << std::endl;
        cout << "C - Clear the List" << std::endl;
        cout << "Q - Quit\n";
        cout << "Enter your choice: " ;
        cin >> choice;
        cout << endl;

        switch (choice)
        {
            /*
        If the user enters 'P' or 'p', you should display all of the elements (ints) in the list.
        If the list is empty you should display "[] - the list is empty"
        If the list is not empty then all the list element should be displayed inside square brackets separated by a space.
        For example, [ 1 2 3 4 5 ]
        */
        case 'P':
        case 'p':
        {
            if (numbers.empty()) {
                cout << "[] - the list is empty" << endl;
            } else {
                cout << "[ ";
                for (auto num : numbers) {
                    cout << num << " ";
                }
                cout << "]" << endl << endl;
            } 
        }
        break;

//         If the user enters 'A' or 'a' then you should prompt the user for an integer to add to the list
//          which you will add to the list and then display it was added. For example, if the user enters 5
//          You should display, "5 added".
//          Duplicate list entries are OK
        case 'A':
        case 'a':
        {
            int num;
            cout << "Enter an integer to add: ";
            cin >> num;

            numbers.push_back(num);
            cout << num << " added" << endl << endl;
        }
        break;

        /*If the user enters 'M' or 'm'  you should calculate the mean or average of the elements in the list and display it.
        If the list is empty you should display, "Unable to calculate the mean - no data"*/
        case 'M':
        case 'm':
        {
            int sum {0};
            double average {0};

            if (numbers.size()<1) {
                cout << "Unable to calculate the mean - no data";
            }
            else {
                for (size_t i = 0; i < numbers.size(); i++)
                {
                    sum += numbers.at(i);
                }
                average = static_cast<double>(sum)/numbers.size();
                cout << "The average is: " << average << endl << endl;
            }
        }
        break;

        /*If the user enters 'S' or 's' you should display the smallest element in the list.
For example, if the list contains [2 4 5 1],  you should display, "The smallest number is 1"
If the list is empty you should display, "Unable to determine the smallest number - list is empty"*/
        case 'S':
        case 's':
        {
            int mininmum {INT_MAX};

            if (numbers.size()<1) {
                cout << "Unable to determine the smallest number - list is empty";
            }
            else{
                for (size_t i {0}; i < numbers.size(); i++)
                {
                    if (numbers.at(i) < mininmum)
                    {
                        mininmum = numbers.at(i);
                    }
                }
                cout << "The smallest number is: " << mininmum << endl << endl;
            }
        }
        break;

        /*If the user enters 'L' or 'l' you should display the largest element in the list
For example, if the list contains [2 4 5 1], you should display, "The largest number is 5"
If the list is empty you should display, "Unable to determine the largest number - list is empty"*/
        case 'L':
        case 'l':
        {
            int maximum {0};
            if (numbers.size()<1) {
                cout << "Unable to determine the largest number - list is empty";
            }
            else{
                for (size_t i {0}; i < numbers.size(); i++)
                {
                    if (numbers.at(i) > maximum)
                    {
                        maximum = numbers.at(i);
                    }
                }
                cout << "The largest number is: " << maximum << endl << endl;
            }
        }
        break;

        /*If the user enters 'Q' or 'q' then you should display 'Goodbye" and the program should terminate.*/
        case 'Q':
        case 'q':
        {
            cout << "Goodbye" << endl;
        }
        break;

        // add option to clear the list.
        case 'C':
        case 'c':
        {
            numbers.clear();
            cout << "Numbers list cleared." << endl << endl;

        }
        break;

        /*If an illegal choice is made, you should display, "Unknown selection, please try again" and the menu options should be
        displayed again.*/
        default:
        {
            cout << "Unknown selection, please try again" << endl <<endl;
        }
            break;
        }
    } while (choice != 'Q' && choice != 'q');

    return 0;
}