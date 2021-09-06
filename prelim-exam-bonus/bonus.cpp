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

bool contains_digit(int n, int d) {
    bool hasDigit;
    string str_n = to_string(n);
    string str_d = to_string(d);
    size_t found = str_n.find(str_d);

    if (found != string::npos) {
        hasDigit = true;
    } else {
        hasDigit = false; 
    }

    return hasDigit;
}

int main() {
    int T; 
    int n,d;
    size_t found;

    cin >> T; 
    for (int i = 1; i <= T; i++) {
        cin >> n >> d; 
        found = contains_digit(n, d); 
        if (found) {
            cout << "CASE " << i << ": FOUND" << endl; 
        } else {
             cout << "CASE " << i << ": NOT FOUND" << endl; 
        }
    }

    return 0;
}
