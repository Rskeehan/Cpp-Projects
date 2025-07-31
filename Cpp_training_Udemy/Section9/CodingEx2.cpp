#include <iostream>
#include <vector>
using namespace std;

int count_numbers(const vector<int> &vec)
{
    //---- WRITE YOUR CODE BELOW THIS LINE----

    // Initialize the index and count variables
    size_t count{0};
    const int sentinel{-99};

    // Loop through the vector until you find the sentinel value
    // or reach the end of the vector

    while (count < vec.size() && vec[count] != sentinel)
        count++;

    //---- WRITE YOUR CODE ABOVE THIS LINE----
    //---- DO NOT MODIFY THE CODE BELOW THIS LINE-----
    return static_cast<int>(count);
}

int main()
{
    // Initialize a vector with some integers
    vector<int> vec = {1, 2, 3, 4, 5, -99}; // -99 is the sentinel value
    int count = count_numbers(vec);
    cout << "Count of numbers before sentinel: " << count << endl;
    return 0;
}