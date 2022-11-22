#include "Ratio.hpp"

#include <numeric>

#include <stdexcept>  // special exceptions
#include <string>     // for exceptions

Ratio::Ratio(const int numerator, const unsigned int denominator) : m_numerator(numerator), m_denominator(denominator) {
    if(denominator == 0)
        throw std::logic_error("Ratio::Ratio(numerator, denominator): invalid denominator, can't be 0");
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