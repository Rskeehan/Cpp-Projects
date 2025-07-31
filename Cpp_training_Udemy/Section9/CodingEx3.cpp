#include <iostream>
using namespace std;

int main() {
    //---- Write code that uses a for loop to calculate the sum of the odd integers from 1 to 15, inclusive. The final result should be stored in an integer variable named sum .
    int sum {0};
    for(int i {1}; i <= 15; i++){
        if(i % 2 == 1) sum += i; // Check if the number is odd;
    }
    
    //---- WRITE YOUR CODE ABOVE THIS LINE
    //---- DO NOT MODIFY THE CODE BELOW
    cout << sum << endl;
    
    return 0;
}