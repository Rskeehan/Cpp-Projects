#include <vector>
#include <iostream>
using namespace std;

//---- Write code that uses a for loop to calculate the sum of the odd integers from 1 to 15, inclusive. The final result should be stored in an integer variable named sum .

/*******************************************************
Given a vector of integers named vec that is provided for you, find the sum of the product of all pairs of vector elements.
You should declare an integer variable named result  and store the final product in this variable.

For example, given the vector  vec  to be {1, 2 , 3} , the possible pairs are (1,2), (1,3), and (2,3) . 
So the result would be (1*2) + (1*3) + (2*3)  which is 11 .

Another example:
Given the vector vec  to be {2, 4, 6, 8} , the possible pairs are (2,4), (2,6), (2,8), (4,6), (4,8), and (6,8) .
So the result would be (2*4) + (2*6) + (2*8) + (4*6) + (4*8) + (6*8) which is 140 .

If the vector is empty or has only 1  element then the result  should be 0 .
 * *****************************************************/

int calculate_pairs(vector<int> vec) {
    int result{0};
    int runningSum {0};
    
    if (vec.size() <= 1){
        result = 0;
        return result;
    }
    
    // cout << "The input vector is:\n";
    // for (size_t k {0}; k<= vec.size(); k++) cout << vec.at(k) << " ";
    // cout << endl;
    
    for (size_t i {0}; i < vec.size(); i++){
        for (size_t j {0}; j < vec.size(); j++){
            if (i < j) {
                runningSum += vec.at(i)*vec.at(j);
                // std::cout << vec.at(i) << " * "<< vec.at(j) << " = " << vec.at(i)*vec.at(j) << " for a running sum of: " << runningSum << endl;
            }
        }
    }
    result = runningSum;

    return result;
}

int main() {
    vector<int> vec{2, 4, 6, 8};
    int result {0};
    
    // make a vector of vectors to test the function
    vector<vector<int>> test_vectors = {
        {1, 2, 3},
        {2, 4, 6, 8},
        {},
        {5},
        {10, 20, 30, 40}
    };

    for (const auto& test_vec : test_vectors) {
        int res = calculate_pairs(test_vec);
        cout << "For vector {";
        for (const auto& val : test_vec) {
            cout << val << " ";
        }
        cout << "} the result is: " << res << endl;
    }


    return 0;
}