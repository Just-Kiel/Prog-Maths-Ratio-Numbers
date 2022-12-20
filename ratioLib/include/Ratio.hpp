#pragma once
#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <string>

#include <stdexcept>  // special exceptions
#include <type_traits>

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

    template <typename T>
    Ratio(const T& v): m_numerator(convertRealToRatio(v).m_numerator), m_denominator(convertRealToRatio(v).m_denominator){
        // if (typeid(v) == typeid(std::string) || typeid(v) == typeid(char))
        //     throw std::domain_error("Ratio::Ratio(value): invalid type of parameter, should be a number, can't be a string or a char");
        static_assert(std::is_arithmetic_v<T>, "Ratio::Ratio(value): invalid type of parameter, should be a number, can't be a string or a char");
    }

    inline unsigned int getDenominator() const {
		return m_denominator;
	}
    
    inline int getNumerator() const {
		return m_numerator;
	}

    /// @brief If PGCD is not 1, need to divide each by PGCD to obtain rational number
    /// @todo Check if can be inline or not because idk
    const void convertToIrreducible(const int pgcd);

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
    //Pow Operator
    Ratio ratioPow(const int p) const;

    //SQRT Operator

    /// @brief Product of a ratio and a real
    /// @param value is the real
    /// @return Ratio product of two
    template <typename T>
    Ratio operator*(const T &value) const{
        const Ratio rValue(value);
        return (*this)*rValue;
    }
    
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

/// @brief Product of a real and a ratio
/// @param value is real value to multiply
/// @param r is Ratio to multiply
/// @return Ratio product of two
template <typename T>
Ratio operator*(const T value, const Ratio &r){
    return r*value;
}

/// @brief Convert real to Rational number
/// @param v the real to convert
/// @return Rational Number
template <typename V>
Ratio convertRealToRatio(const V& v, const int& nb_iter = 150){
    // TODO negatif

    static_assert(std::is_arithmetic_v<V>, "convertRealToRatio(value, nb_iter): invalid type of parameter, value should be a number, can't be a string or a char");

    Ratio result;

    // if int, directly good constructor
    if(std::is_integral_v<V>) return Ratio(v);

    if(v == static_cast<V>(0)) return Ratio();

    if(nb_iter == 0) return Ratio();

    if(v < static_cast<V>(1)) return (convertRealToRatio(static_cast<V>(1)/v, nb_iter)).invert();

    if(v >= static_cast<V>(1)){
        const int q = (int) v;

        return Ratio(q, 1)+ convertRealToRatio(v-q, nb_iter-1);
    }
}