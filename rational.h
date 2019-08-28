/****************************************************************************
 * 
 * File:rational.h
 * Author : Amenyo Folitse
 * Purpose: Creates rational numbers abstraction and 
 * overloads basic arithmetic operators.
 * 
 ****************************************************************************/
#ifndef RATIONAL_H
#define RATIONAL_H
#include <iostream>

/*
 * Models rational numbers as two int value, numerator and denominator.
 * Denominator is never zero or negative. When denominator is negative, the sign
 * of both the numerator and denominator are inverted to have Numerator positive
 * Usage : Rational r = Rational r1(2,3) + Rational r2(2,5).
 * 
 */
class Rational {
    public:
        /* 
         * Throws invalid_argument when the denominator is 0
         */
        Rational(int numerator = 0, int denominator = 1);
        ~Rational();
        
        /* Returns the numerator */
        int num() const {
            return numerator;
        }
         /* Returns the denominator */
        int denom() const {
            return denominator;
        };
        
        /* Returns the reciprocal of a rational number */
        Rational reciprocal() const;
        
        /* Reduces a rational number such that the greatest common divisor of 
         * the numerator and denominator is 1 
         */
        Rational& reduce ();
        
        /* Compound-assignment operator += overload */
        Rational& operator+=(const Rational& rhs);
        
        /* Compound-assignment operator -= overload */
        Rational& operator-=(const Rational& rhs);
        
        /* Compound-assignment operator *= overload */
        Rational& operator*=(const Rational& rhs);
        
        /* Compound-assignment operator /= overload */
        Rational& operator/=(const Rational& rhs);
        
     
    private:
        int numerator; 
        int denominator; 
       
        /* Computes the gcd of the numerator and the denominator of rational
         * number. The return value is then used to reduce the rational number.
         * a and b can be negative numbers. 
         */
        int gcd(int a , int b);
};

/* Addition operator + overload  */
Rational operator+(const Rational &lhs, const Rational &rhs);


/* Subtraction operator - overload */
Rational operator-(const Rational &lhs, const Rational &rhs);


/* Multiplication operator * overloads * */
Rational operator*(const Rational &lhs, const Rational &rhs);


/* Division operator / overloads   */
Rational operator/(const Rational &lhs, const Rational &rhs);


/* output stream <<  overloads  */
std::ostream& operator<<(std::ostream& os  , const Rational& r);


#endif /* RATIONAL_H */

