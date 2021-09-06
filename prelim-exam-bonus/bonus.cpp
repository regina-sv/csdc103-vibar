// Filename     : bonus.cpp
// Description  : reads a non-negative integer n and a decimal digit d from the 
//                standard input and displays "FOUND" if the digit d is among the 
//                digits in n or "NOT FOUND" otherwise.
// Author       : Regina Juliane Vibar
// Honor Code   : I have not asked nor given any aunthorized help
//                in completing this exercise

#include <iostream>
#include <string>
using namespace std; 

// function to check if d is found in n
bool contains_digit(int n, int d) {
    bool hasDigit;
    // convert values to string 
    string str_n = to_string(n);
    string str_d = to_string(d);
    // find the value of str_d if present in str_n
    size_t found = str_n.find(str_d);

    // found will be the value of constant npos when find fails
    // Otherwise its a successful match
    if (found != string::npos) { 
        hasDigit = true;
    } else {
        hasDigit = false; 
    }

    return hasDigit; // return value (true/ false)
}

int main() {
    int T; // number of test cases 
    int n,d; // t-lines 
    size_t found; 

    cin >> T; 
    // loop to get T inputs of t-lines
    for (int i = 1; i <= T; i++) {
        cin >> n >> d; 
        // found will get the value of the called function
        found = contains_digit(n, d); 
        if (found) {
            cout << "CASE " << i << ": FOUND" << endl; 
        } else {
            cout << "CASE " << i << ": NOT FOUND" << endl; 
        }
    }

    return 0;
}
