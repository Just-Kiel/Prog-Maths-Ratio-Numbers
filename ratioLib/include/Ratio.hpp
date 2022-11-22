#include <iostream>

class Ratio
{
private:
    int m_numerator;
    unsigned int m_denominator;

public:
    Ratio(const int numerator = 0, const unsigned int denominator = 1);
    Ratio(const Ratio& r);

    inline unsigned int getDenominator() const {
		return m_denominator;
	}
    
    inline unsigned int getNumerator() const {
		return m_numerator;
	}
    
    /// @brief Calculate PGCD (important to know if we have a rational number)
    /// @return Value of PGCD between numerator and denominator
    /// @todo Check if can be inline or not
    const int getPGCD();

    /// @brief If PGCD is not 1, need to divide each by PGCD to obtain rational number
    /// @todo Check if can be inline or not because idk
    const void convertToIrreductible(const int pgcd);
};