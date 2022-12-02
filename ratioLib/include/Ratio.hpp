#pragma once
#include <iostream>

class Ratio
{
private:
    int m_numerator;
    unsigned int m_denominator;

    ///////// methods
    /// @brief Calculate PGCD (important to know if we have a rational number)
    /// @return Value of PGCD between numerator and denominator
    /// @todo Check if can be inline or not
    const int getPGCD();

public:
    Ratio(const int numerator = 0, const unsigned int denominator = 1);
    Ratio(const Ratio& r);

    inline unsigned int getDenominator() const {
		return m_denominator;
	}
    
    inline unsigned int getNumerator() const {
		return m_numerator;
	}

    /// @brief If PGCD is not 1, need to divide each by PGCD to obtain rational number
    /// @todo Check if can be inline or not because idk
    const void convertToIrreductible(const int pgcd);

    /// @brief Permit to have infinity in rational number
    /// @return Infinity in Ratio (1/0)
    static const Ratio infinity();

    /// @brief Permit to have PI in rational number
    /// @return PI in Ratio (103993/33102) with 9 decimals
    static const Ratio pi();

    //Sum Operator
    Ratio operator+(const Ratio &r) const;
};