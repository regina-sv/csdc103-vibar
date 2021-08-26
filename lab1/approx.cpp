// Filename        : approx.cpp
// Description     : This source file contains the implementation of the 
//                   function to approximate the value of PI.
// Author          : Regina Juliane Vibar
// Honor Code      : I have not asked nor given any aunthorized help
//                   in completing this exercise.

#include "approx.h"
#include <math.h>
#include <iomanip>

long double approx_pi(int n) {
    long double pi = 0; 
        for (long int i = 1; i <= n; i++) { 
            pi += (long double) pow(-1, i+1 )/(2 * i-1); 
        } 
    return (pi *= 4);
}