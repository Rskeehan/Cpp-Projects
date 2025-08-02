#include <iostream>

using namespace std;

int factorial(int num);

int main(int argc, const char** argv) {

    int inputNum;
    int factorializedNum;
    
    cout << "Input number to factorialize: ";

    cin >> inputNum;

    if (inputNum < 0) {
        cout << "Error: Factorial is not defined for negative numbers." << endl;
        return 1;
    }

    factorializedNum = factorial(inputNum);

    cout << "The factorial of " << inputNum << " is " << factorializedNum; 

    return 0;
}

int factorial(int num)
{
    int numfactorial{};

    if (num == 1)
    {
        return 1;
    }
    
    numfactorial = num * factorial(num-1);
    
    return numfactorial;
}
