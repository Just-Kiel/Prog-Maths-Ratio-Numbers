#include <iostream>

class Ratio
{
private:
    int m_numerator;
    unsigned int m_denominator;

public:
    Ratio(const int numerator = 0, const unsigned int denominator = 1);
    Ratio(const Ratio& r);

    // TODO PGCD a et b doit être égal à 1 avec std::gcd
    /// \brief Calculate PGCD, if PGCD = 1 ok, if not divide each by PGCD
    /// \todo Check if can be inline or not because idk
    const void checkAndConvertToIrreductible();
};