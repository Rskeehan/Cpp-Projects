#include <vector>
#include <iostream>
using namespace std;

//---- Write code that uses a for loop to calculate the sum of the odd integers from 1 to 15, inclusive. The final result should be stored in an integer variable named sum .

/*******************************************************
 * This function should use a do while loop to iterate over
 * the automatically provided vector (vec) of characters looking
 * for the first occurrence of a lowercase English vowel ('a','e','i','o','u').
 *
 * If a vowel is found, you should display to cout:
 *
 * "Vowel found: " followed by the vowel that was found.
 *
 * If no vowel is found in the vector, then you should display to cout:
 *
 * "No vowel was found"
 *
 * For example, below are several examples of vectors and what your output should be:
 *
 * {'f','r','a','n','k'}    Vowel found: a
 * {'F','R','A','N','K'}    No vowel was found
 * {'h','e','l','l','o'}    Vowel found: e
 * {}                       No vowel was found
 * {'x','y','z','o'}        Vowel found: o
 *
 * Please do NOT add std::endl or '\n' to your output statement.
 * *****************************************************/

void find_first_vowel(const std::vector<char> &vec)
{
    if (vec.empty()) {
        cout << "No vowel was found"; 
        return;
    }

    
    int i {0};
    do
    {
        switch (vec.at(i))
        {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u': {
            cout << "Vowel found: " << vec.at(i);
            return;
        }
        default:
            break;
        }
        i++;
    } while (i < vec.size());

    cout << "No vowel was found";
    return;
}

int main()

{
    std::vector<std::vector<char>> test_vectors = {
        {'f', 'r', 'n', 'k'},
        {'f', 'r', 'a', 'n', 'k'},
        {'F', 'R', 'A', 'N', 'K'},
        {'h', 'e', 'l', 'l', 'o'},
        {},
        {'x', 'y', 'z', 'o'},
        {'b', 'c', 'd', 'u', 'a'}};

    for (const auto &vec : test_vectors)
    {
        std::cout << "{";
        for (size_t i = 0; i < vec.size(); ++i)
        {
            std::cout << "'" << vec[i] << "'";
            if (i != vec.size() - 1)
                std::cout << ",";
        }
        std::cout << "}  ";
        find_first_vowel(vec);
        std::cout << std::endl; // For readability between test cases
    }

    return 0;
}