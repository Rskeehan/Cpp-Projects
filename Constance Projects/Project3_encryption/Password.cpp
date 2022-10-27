#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <vector>

using namespace std;

bool isValidPassword(string password) //method to test length of password for validity
{
    bool isValid;
    if (password.length()<12) // checks if password is less than 12 chars in length and returns error if so.
    {
        cout << "The password must be at least 12 characters long. and is "<< password.length()<< "chars long." << endl;
        isValid = false;
    }
    else
    {
        isValid = true;
    }
    return isValid;
}

bool isValidKey(int key) //method to test if key is valid
{
    bool isValid;
    if (1 <= key <= 20) // checks if key is between 1 and 20 (inclusive). returns and error if not.
    {
        isValid = true;
    }
    else
    {
        cout << "The key must be between 1 and 20, you entered is " << key << "." << endl;
        isValid = false;
    }    
    return isValid;
}

string encrypt(string pword, int key) //method to encrypt the password by the key value.
{
    string encryptedPassword = "";// init encryptedpassword variable

    for (int i = 0; i < pword.length() ; i++) //iterate through the length of password, and shift the char value by key value
    {
        encryptedPassword+=(pword[i]-'!'+key)%'~'+'!'; //calculate encrypted password by building it up by character of (pword+key-'!')/'~'
        // to get remainder of shifted value, then adding back '!' to get the true encrypted value.
    }
    return encryptedPassword; // get encrypted password out of this method
}

int main() 
{
    //initialize password variable and key
    string password;
    int key;

    //initialize bools for data input validation
    bool isValidP = false, isValidK = false;

    //loop so long as password is invalid. initialize check is invalid
    while (isValidP == false)
    {
        //prompt for password
        cout << "Write your password: " << endl;
        cin >> password;

        //check if password is valid
        isValidP = isValidPassword(password);
        //cout << " I Got Here. The password must be at least 12 characters long. and is "<< password.length()<< " chars long."<< isValidP << endl;
    }

    //loop so long as key is invalid. initialize check is invalid to kick it off.
    while (isValidK == false)
    {
        //prompt for key
        cout << "Write your key: " << endl;
        cin >> key;
        
        //check if key is valid
        isValidK = isValidKey(key);
        //cout << "the key is " << key << "and is " << isValidK << endl; FOR DEBUGGING
    }
    string encryptedPassword = ""; // init encrypted password string for building.
    encryptedPassword = encrypt(password, key); // get encrypted version of password;

    //Print results
    cout << "Your password is "<< password << ". The encrypted version of your password is " << encryptedPassword << 
            " with a key of " << key << "." << endl; 

    return EXIT_SUCCESS;
}