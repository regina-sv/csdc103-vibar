// Filename        : main.cpp
// Description     : This program tests the implementation of the 
//                   function to approximate the value of PI.
// Author          : Regina Juliane Vibar
// Honor Code      : I have not asked nor given any aunthorized help
//                   in completing this exercise.

#include <iostream>
#include "approx.h"
#include <iomanip>

using namespace std;

int main(){
    
    int test_cases = 0; 
    int n = 0;
    long double pi = 0;

    cin >> test_cases;
    for (int k = 1; k <= test_cases; k++) {
        cin >> n; 
        pi = approx_pi(n); 
        cout << "CASE " << k << ": " << fixed << setprecision(15) << pi << endl; 
    }

    
    return 0;
}