#include "../include/Ratio.hpp"

#include <numeric>

#include <stdexcept>  // special exceptions
#include <string>     // for exceptions

Ratio::Ratio(const int numerator, const unsigned int denominator) : m_numerator(numerator), m_denominator(denominator) {
    if(denominator == 0)
        throw std::logic_error("Ratio::Ratio(numerator, denominator): invalid denominator, can't be 0");

    const int pgcd = getPGCD();
    if(pgcd != 1)
        convertToIrreductible(pgcd);
}

Ratio::Ratio(const Ratio& r) : m_numerator(r.m_numerator), m_denominator(r.m_denominator) {}

const int Ratio::getPGCD(){
    // Need C++ 17 to have GCD available
    return std::gcd(m_numerator, m_denominator);
}

const void Ratio::convertToIrreductible(const int pgcd){
    m_numerator = m_numerator/pgcd;
    m_denominator = m_denominator/pgcd;
}

const Ratio Ratio::infinity(){
    Ratio r;
    r.m_numerator = 1;
    r.m_denominator = 0;
    return r;
}

const Ratio Ratio::pi(){
    return Ratio(103993, 33102);
}


//Sum Operator
Ratio Ratio::operator+(const Ratio &r) const
{
    Ratio newRatio;
    newRatio.m_numerator=(this->m_numerator*r.m_denominator)+(r.m_numerator*this->m_denominator);
    newRatio.m_denominator=(this->m_denominator*r.m_denominator);

    // Check PGCD = 1 and convert if needed
    newRatio.convertToIrreductible(newRatio.getPGCD());
    return newRatio;
}


//Product Operator
Ratio Ratio::operator*(const Ratio &r) const
{
    Ratio newRatio;
    newRatio.m_numerator=(this->m_numerator)*(r.m_numerator);
    newRatio.m_denominator=(this->m_denominator)*(r.m_denominator);

    // Check PGCD = 1 and convert if needed
    newRatio.convertToIrreductible(newRatio.getPGCD());
    return newRatio;
}

// Unary Minus Operator
Ratio Ratio::operator-() const{
    return Ratio(-m_numerator, m_denominator);
}

// Absolute Value
Ratio Ratio::abs() const{
    return Ratio(std::abs(m_numerator), m_denominator);
}

bool operator== (const Ratio& r1, const Ratio& r2){
    return (r1.m_numerator == r2.m_numerator) && (r1.m_denominator == r2.m_denominator);
}

bool operator!= (const Ratio& r1, const Ratio& r2){
    return (r1.m_numerator != r2.m_numerator) || (r1.m_denominator != r2.m_denominator);
}

bool operator< (const Ratio& r1, const Ratio& r2){
    // no need to compare denominators because by multiplying they are the same
    return (r1.m_numerator*r2.m_denominator < r1.m_denominator*r2.m_numerator);
}

bool operator> (const Ratio& r1, const Ratio& r2){
    return (r2 < r1);
}

bool operator<= (const Ratio& r1, const Ratio& r2){
    return !(r1 > r2);
}

bool operator>= (const Ratio& r1, const Ratio& r2){
    return !(r1<r2);
}