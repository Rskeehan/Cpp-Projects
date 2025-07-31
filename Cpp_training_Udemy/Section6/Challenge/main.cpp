
// Section 6
// Challenge

/* 
    Frank's Carpet Cleaning Service
    Charges:
        $25 per small room
        $35 per large room
    Sales tax rate is 6%
    Estimates are valid for 30 days

    Prompt the user for the number of small and large rooms they would like cleaned
    and provide an estimate such as:
     
Estimate for carpet cleaning service
Number of small rooms: 3
Number of large rooms: 1
Price per small room: $25
Price per large room: $35
Cost : $110
Tax: $6.6
===============================
Total estimate: $116.6
This estimate is valid for 30 days
*/

#include <iostream>

using namespace std;

int main() {
    int small_rooms{0};
    int large_rooms{0};
    const double small_room_price{25.0};
    const double large_room_price{35.0};
    const double tax_rate{0.06};
    double cost {0};
    const int estimate_valid_days{30};


    cout << "Welcome to Frank's Carpet Cleaning Service" << endl;
    cout << "How many small rooms would you like cleaned?: ";
    cin >> small_rooms;
    cout << "/nHow many large rooms would you like cleaned?: ";
    cin >> large_rooms;
    cost = (small_rooms*small_room_price + large_rooms*large_room_price)*(1+tax_rate);
    cout << "The total cosst for cleaning is: $" << cost << endl;
    cout << "This estimate is valid for " << estimate_valid_days << " days" << endl;
    cout << "Thank you for choosing Frank's Carpet Cleaning Service" << endl;

    cout << endl;
    return 0;
}

