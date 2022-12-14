#include "../include/Ratio.hpp"
using namespace IMAC;

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

const Ratio Ratio::infinity(const int& sign){
    Ratio r;
    r.m_numerator = (sign > 0) ? 1 : -1;
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
    if(*(this) == Ratio::infinity()){
        if (r == Ratio::infinity())
        {
            return Ratio();
        }
        return Ratio::infinity();
    }

    if (r == Ratio::infinity()) return -Ratio::infinity();

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
    newRatio.m_numerator= (this->m_numerator < 0) ?  -(this->m_denominator) : (this->m_denominator);
    newRatio.m_denominator= std::abs((this->m_numerator));

    // Check PGCD = 1 and convert if needed
    newRatio.convertToIrreducible(newRatio.getPGCD());
    return newRatio;

}

//Division Operator
Ratio Ratio::operator/(const Ratio &r) const
{
    if (r == Ratio())
        throw std::invalid_argument("Ratio Ratio::operator/(ratio): cannot be divide by 0");
        
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
Ratio Ratio::ratioPow(const int& p) const
{
    Ratio newRatio;
    if(p>=0){
        newRatio.m_numerator=pow((this->m_numerator),p);
        newRatio.m_denominator=pow((this->m_denominator),p);
    } else {
        newRatio.m_numerator=pow(static_cast<int>(this->m_denominator),-p);
        newRatio.m_denominator=pow((this->m_numerator),-p);
    }

    // Check PGCD = 1 and convert if needed
    newRatio.convertToIrreducible(newRatio.getPGCD());
    return newRatio;
}

Ratio Ratio::ratioPow(const Ratio& p) const{
    int entirePart = p.getEntirePart();

    Ratio result(*this);
    
    if(entirePart != 0) result = this->ratioPow(entirePart);

    float decimal = convertRatioToReal<float>(p) - entirePart;

     
    result = convertRealToRatio<float>(std::powf(convertRatioToReal<float>(result),decimal));

    return result;
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
std::ostream& IMAC::operator<<(std::ostream& os, const Ratio &r)
{
    os << r.m_numerator << '/' << r.m_denominator << " or real form is " << convertRatioToReal<double>(r);
    return os;
}


// Unary Minus Operator
Ratio Ratio::operator-() const{
    if(*(this) == Ratio::infinity()) return Ratio::infinity(-1);
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

Ratio& Ratio::operator+=(const Ratio &r){
    *(this) = *(this) + r;
    return *(this);
}

Ratio& Ratio::operator-=(const Ratio &r){
    *(this) = *(this) - r;
    return *(this);
}

Ratio& Ratio::operator*=(const Ratio &r){
    *(this) = *(this) * r;
    return *(this);
}

Ratio& Ratio::operator/=(const Ratio &r){
    *(this) = *(this) / r;
    return *(this);
}

bool IMAC::operator== (const Ratio& r1, const Ratio& r2){
    return (r1.m_numerator == r2.m_numerator) && (r1.m_denominator == r2.m_denominator);
}

bool IMAC::operator!= (const Ratio& r1, const Ratio& r2){
    return (r1.m_numerator != r2.m_numerator) || (r1.m_denominator != r2.m_denominator);
}

bool IMAC::operator< (const Ratio& r1, const Ratio& r2){
    // no need to compare denominators because by multiplying they are the same
    return (r1.m_numerator*static_cast<int>(r2.m_denominator) < static_cast<int>(r1.m_denominator)*r2.m_numerator);
}

bool IMAC::operator> (const Ratio& r1, const Ratio& r2){
    return (r2 < r1);
}

bool IMAC::operator<= (const Ratio& r1, const Ratio& r2){
    return !(r1 > r2);
}

bool IMAC::operator>= (const Ratio& r1, const Ratio& r2){
    return !(r1<r2);
}



// Trigonometry Operations
Ratio IMAC::cos(const Ratio& ratio){
    // is approximate
    float realRatio = convertRatioToReal<float>(ratio);

    float cosValue = std::cosf(realRatio);

    return convertRealToRatio<float>(cosValue);
}

Ratio IMAC::sin(const Ratio& ratio){
    // is approximate
    float realRatio = convertRatioToReal<float>(ratio);

    float sinValue = std::sinf(realRatio);

    return convertRealToRatio<float>(sinValue);
}

Ratio IMAC::tan(const Ratio& ratio){
    return sin(ratio)/cos(ratio);
}

/// Exp and log
Ratio IMAC::exp(const Ratio& ratio){
    return exp(convertRatioToReal<float>(ratio));
}

Ratio IMAC::log(const Ratio& ratio){
    return log(convertRatioToReal<float>(ratio));
}