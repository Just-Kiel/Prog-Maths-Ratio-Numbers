#include "Ratio.hpp"

Ratio::Ratio(const int numerator, const unsigned int denominator) : m_numerator(numerator), m_denominator(denominator) {}

Ratio::Ratio(const Ratio& r) : m_numerator(r.m_numerator), m_denominator(r.m_denominator) {}

// TODO en 2 fonctions
const void Ratio::checkAndConvertToIrreductible(){

}