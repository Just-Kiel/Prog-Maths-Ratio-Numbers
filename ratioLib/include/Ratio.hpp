#pragma once
#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>

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
    
    inline int getNumerator() const {
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
    //Subtraction Operator
    Ratio operator-(const Ratio&r) const;
    //Product Operator
    Ratio operator*(const Ratio &r) const;
    //Inverse Operator
    Ratio invert() const;
    //Division Operator
    Ratio operator/(const Ratio &r) const;

    // /// @brief Product of a ratio and a real
    // /// @param value is the real
    // /// @return Ratio product of two
    // template <typename T>
    // Ratio operator*(const T &value) const{
    //     // TODO when algorithm will be done
    // }
    
    /// @brief Unary Minus Operator
    /// @return Current Ratio with m_numerator with opposite sign
    Ratio operator-() const;

    /// @brief Absolute Value
    /// @return Current Ratio with m_numerator with positive sign
    Ratio abs() const;

    /// @brief Permit to have the entire part of the Ratio
    /// @return Entire part of the Ratio
    int getEntirePart() const;

    /// @brief Equal Comparison Operator
    /// @param r1 the first ratio
    /// @param r2 the second ratio to compare
    /// @return Boolean if equal or not
    friend bool operator== (const Ratio& r1, const Ratio& r2);

    /// @brief Not Equal Comparison Operator
    /// @param r1 the first ratio
    /// @param r2 the second ratio to compare
    /// @return Boolean if equal or not
    friend bool operator!= (const Ratio& r1, const Ratio& r2);

    /// @brief Inferior Comparison Operator
    /// @param r1 the first ratio
    /// @param r2 the second ratio to compare
    /// @return Boolean if inferior or not
    friend bool operator< (const Ratio& r1, const Ratio& r2);

    /// @brief Superior Comparison Operator
    /// @param r1 the first ratio
    /// @param r2 the second ratio to compare
    /// @return Boolean if superior or not
    friend bool operator> (const Ratio& r1, const Ratio& r2);

    /// @brief Inferior or Equal Comparison Operator
    /// @param r1 the first ratio
    /// @param r2 the second ratio to compare
    /// @return Boolean if inferior or equal or not
    friend bool operator<= (const Ratio& r1, const Ratio& r2);

    /// @brief Superior or Equal Comparison Operator
    /// @param r1 the first ratio
    /// @param r2 the second ratio to compare
    /// @return Boolean if superior or equal or not
    friend bool operator>= (const Ratio& r1, const Ratio& r2);
};

// TODO when algorithm will be done
// template <typename T>
// Ratio Ratio::operator*(const T value, const Ratio &r);