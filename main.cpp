/**************************************************************************
 * 
 * File: main.cpp
 * Author: Amenyo Folitse
 * Purpose: Entry point of rational.cpp .
 * Compilation:
 * g++  -std=c++14 -Wall -Werror  rational.cpp main.cpp -o rational  

 ****************************************************************************/

#include <cstdlib>
#include <iterator>
#include "rational.h"
#include <iostream>


int main(int argc, char** argv) {
    
    Rational r1;
    Rational r2(2, 5);
    Rational r3(-6,-2);
   
    std::cout << "OK" << std::endl;
    
    return 0;
}

