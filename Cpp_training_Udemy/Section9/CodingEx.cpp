#include <iostream>
using namespace std;

void can_you_drive(int age, bool has_car) {
    //----WRITE YOUR CODE BELOW THIS LINE----
    if (age >= 16) {
        if (has_car) { 
            cout << "Yes - you can drive!";
        }
        else{
            cout << "Sorry, you need to buy a car before you can drive!";
            }
        }
    else {
        int n {16 - age};
        std::cout << "Sorry, come back in "<< n << "years and be sure you own a car when you come back.";
        }
    }
    
    //----WRITE YOUR CODE ABOVE THIS LINE----
