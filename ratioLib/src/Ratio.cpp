#include "../include/Ratio.hpp"

#include <numeric>

Ratio::Ratio(const int numerator, const unsigned int denominator) : m_numerator(numerator), m_denominator(denominator) {
    if(denominator == 0)
        throw std::logic_error("Ratio::Ratio(numerator, denominator): invalid denominator, can't be 0");

    const int pgcd = getPGCD();
    if(pgcd != 1)
        convertToIrreducible(pgcd);
}

Ratio::Ratio(const Ratio& r) : m_numerator(r.m_numerator), m_denominator(r.m_denominator) {}

const int Ratio::getPGCD(){
    // Need C++ 17 to have GCD available
    return std::gcd(m_numerator, m_denominator);
}

const void Ratio::convertToIrreducible(const int pgcd){
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
    newRatio.convertToIrreducible(newRatio.getPGCD());
    return newRatio;
}

//Subtraction Operator
Ratio Ratio::operator-(const Ratio&r) const
{
    Ratio newRatio = (*this)+(-r);

    // Check PGCD = 1 and convert if needed
    newRatio.convertToIrreducible(newRatio.getPGCD());
    return newRatio;
}


//Product Operator
Ratio Ratio::operator*(const Ratio &r) const
{
    Ratio newRatio;
    newRatio.m_numerator=(this->m_numerator)*(r.m_numerator);
    newRatio.m_denominator=(this->m_denominator)*(r.m_denominator);

    // Check PGCD = 1 and convert if needed
    newRatio.convertToIrreducible(newRatio.getPGCD());
    return newRatio;
}

//Inverse Operator
Ratio Ratio::invert() const
{
    if(*(this) == infinity()) return Ratio();
    if(*(this) == Ratio()) return infinity();

    Ratio newRatio;
    newRatio.m_numerator=(this->m_denominator);
    newRatio.m_denominator=(this->m_numerator);

    // Check PGCD = 1 and convert if needed
    newRatio.convertToIrreducible(newRatio.getPGCD());
    return newRatio;

}

//Division Operator
Ratio Ratio::operator/(const Ratio &r) const
{
    //basic code
    // Ratio newRatio;
    // newRatio.m_numerator=(this->m_numerator)*(r.m_denominator);
    // newRatio.m_denominator=(this->m_denominator)*(r.m_numerator);

    //using inverse operator
    Ratio newRatio=(*this) * r.invert();

    // Check PGCD = 1 and convert if needed
    newRatio.convertToIrreducible(newRatio.getPGCD());
    return newRatio;
}

    //Pow Operator
    Ratio Ratio::ratioPow(const int p) const
    {
    Ratio newRatio;
    newRatio.m_numerator=pow((this->m_numerator),p);
    newRatio.m_denominator=pow((this->m_denominator),p);

    // Check PGCD = 1 and convert if needed
    newRatio.convertToIrreducible(newRatio.getPGCD());
    return newRatio;
}

//SQRT Operator
Ratio Ratio::ratioSqrt() const
{
    //Ratio newRatio=(*this).ratioPow(1/2);
    Ratio newRatio;
    newRatio.m_numerator=sqrt(this->m_numerator);
    newRatio.m_denominator=sqrt(this->m_denominator);

    // Check PGCD = 1 and convert if needed
    newRatio.convertToIrreducible(newRatio.getPGCD());
    return newRatio;
}

//Display Operator
std::ostream& operator<<(std::ostream& os, const Ratio &r)
{
    os<<r.m_numerator<<'/'<<r.m_denominator;
    return os;
}


// Unary Minus Operator
Ratio Ratio::operator-() const{
    return Ratio(-m_numerator, m_denominator);
}

// Absolute Value
Ratio Ratio::abs() const{
    return Ratio(std::abs(m_numerator), m_denominator);
}

// Entire Part
int Ratio::getEntirePart() const{
    return m_numerator/static_cast<int>(m_denominator);
}

bool operator== (const Ratio& r1, const Ratio& r2){
    return (r1.m_numerator == r2.m_numerator) && (r1.m_denominator == r2.m_denominator);
}

bool operator!= (const Ratio& r1, const Ratio& r2){
    return (r1.m_numerator != r2.m_numerator) || (r1.m_denominator != r2.m_denominator);
}

bool operator< (const Ratio& r1, const Ratio& r2){
    // no need to compare denominators because by multiplying they are the same
    return (r1.m_numerator*static_cast<int>(r2.m_denominator) < static_cast<int>(r1.m_denominator)*r2.m_numerator);
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