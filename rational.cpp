/*****************************************************************************
 * 
 * File: rational.cpp
 * Author : Amenyo K. Folitse
 * Description: Implements rational numbers class and 
 * its basic arithmetic operations.
 * 
 * build with :
 * g++  -std=c++14 -Wall -Werror  rational.cpp -o rational.o  
 * 
 *****************************************************************************/

#include "rational.h"
#include <iostream>
#include <stdexcept>

Rational::Rational(int num , int denom) {    
    if (denom == 0) {
        throw std::invalid_argument ("Denominator shall be non-zero");
    }
    if (denom < 0) {
        this->denominator = - denom;
        this->numerator = - num;
    } else {
        this->numerator = num;
        this->denominator = denom;
    }   
}

Rational::~Rational (){};

/* Recursive helper function implementation */
int Rational::gcd(int a, int b) {
    if (b == 0) {
       return a; 
    } else
       return gcd(b, a % b);
}

Rational Rational::reciprocal() const {
    return Rational(this->denominator,this->numerator);
}

Rational&  Rational::reduce (){
    int GCD = 0;
    if ((this->numerator == 0) && (this->denominator != 1)) { 
        this->denominator = 1;
     } else {
        GCD = this->gcd(abs(this->denominator),abs(this->numerator));
        this->numerator /= GCD;
        this->denominator /= GCD;     
     }
    return *this;// return the object itself.   
}

Rational& Rational::operator+=(const Rational &rhs){
   this->numerator = this->numerator * rhs.denom() + 
           this->denominator * rhs.num();
   this->denominator *= rhs.denominator;
   return (*this).reduce(); 
}
 
Rational & Rational::operator-=(const Rational &rhs){
   this->numerator = this->numerator * rhs.denom() -
            this->denominator * rhs.num();
   this->denominator *= rhs.denominator;
   return (*this).reduce(); 
}

Rational & Rational::operator*=(const Rational &rhs){
   this->numerator *= rhs.num();
   this->denominator *= rhs.denominator;
   return (*this).reduce(); 
}

Rational & Rational::operator/=(const Rational &rhs){
    return this->operator*=(rhs.reciprocal());
 }
Rational operator+ (const Rational &lhs,const Rational &rhs) {
    return Rational( lhs.num() * rhs.denom() + 
            lhs.denom() * rhs.num(), lhs.denom() * rhs.denom()).reduce();
}

Rational operator- (const Rational &lhs,const Rational &rhs) {
    return Rational ( lhs.num() * rhs.denom() - lhs.denom() * rhs.num(), 
            lhs.denom() * rhs.denom()).reduce(); 
}

Rational operator* (const Rational &lhs,const Rational &rhs) {
    return Rational ( lhs.num() * rhs.num() ,
            lhs.denom() * rhs.denom()).reduce(); 
}

Rational operator/ (const Rational &lhs,const Rational &rhs) {
    return Rational ( lhs.num() * rhs.denom() , 
            lhs.denom() * rhs.num()).reduce(); 
}

std::ostream& operator<<(std::ostream& os,const Rational& r){
    return (r.denom() == 1) ? os << r.num() : os << r.num() << "/" << r.denom();

}
  


