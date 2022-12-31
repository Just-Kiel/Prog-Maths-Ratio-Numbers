#pragma once
#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <string>

#include <stdexcept>  // special exceptions
#include <type_traits>
#include <numeric>

// Doxygen menu
/// \version 1.0
/// \mainpage
/// \image html logoIMAC.png
/// \tableofcontents
/// \section introduction_sec What for?
/// Ratio is a super tool. Permits to have infinite decimal into easy to represent number.
/// \section install_bigsec How to install
/// \subsection dependencies_sec Dependencies
/// \li nothing else
/// \li Doxygen (if you want the documentation)
/// \subsection install_sec Install with cmake (Linux)
/// \li go to main dir
/// \li mkdir build
/// \li cd build
/// \li cmake ..
/// \li make
/// \li make html
/// \li The documentation is located in ratioLib/doc/html/index.html
/// \subsection install_sec Install with cmake (Windows with Visual Studio Code)
/// \li Open Project into Visual Studio Code
/// \li Select html instead of ALL_BUILD
/// \li Build with CMake Tools
/// \section credits_sec Made by
/// \li Aurore LAFAURIE
/// \li Sarah N'GOTTA

/// \namespace IMAC
/// \brief namespace used for class Ratio
namespace IMAC{

    /// \class Ratio
    /// \brief class defining a ratio for mathematic operations.
    class Ratio
    {
    private:
        int m_numerator;
        unsigned int m_denominator;

        ///////// methods
        /// @brief Calculate PGCD (important to know if we have a rational number)
        /// @return Value of PGCD between numerator and denominator
        const int getPGCD();

    public:
        /// @brief Default Constructor
        /// @param numerator is by default 0
        /// @param denominator is by default 1
        Ratio(const int numerator = 0, const unsigned int denominator = 1);

        /// @brief Copy Constructor
        /// @param r is the ratio to copy
        Ratio(const Ratio& r);

        /// @brief Constructor by value
        /// @param v is the value to convert
        template <typename T>
        Ratio(const T& v);

        /// \brief destructor
        ~Ratio() = default;

        /// @brief Getter of denominator
        /// @return unsigned int of denominator
        inline unsigned int getDenominator() const {
            return m_denominator;
        }
        
        /// @brief Getter of numerator
        /// @return int of numerator
        inline int getNumerator() const {
            return m_numerator;
        }

        /// @brief Display operator of ratio
        /// @param os : recognize an ostream object on the left and return a reference to the original ostream object os
        /// @param r : ratio to display with to the operator <<
        friend std::ostream& operator<<(std::ostream& os, const Ratio &r) ;

        /// @brief If PGCD is not 1, need to divide each by PGCD to obtain rational number
        const void convertToIrreducible(const int pgcd);

        /// @brief Permit to have infinity in rational number
        /// @param sign the sign of infinity
        /// @return Infinity in Ratio (1/0)
        static const Ratio infinity(const int& sign = 1);

        /// @brief Permit to have PI in rational number
        /// @return PI in Ratio (103993/33102) with 9 decimals
        static const Ratio pi();


        //////// Comparison Operators
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

        

        //Sum Operator
        /// @brief Sum Operator
        /// @param r the ratio to add to the first one
        /// @return Value of the sum of the 2 ratio (the result is a ratio)
        Ratio operator+(const Ratio &r) const;

        //Sum Operator
        /// @brief Sum Operator Templated
        template <typename T>
        Ratio operator+(const T &value) const;

        //Subtraction Operator
        /// @brief Subtraction Operator
        /// @param r the ratio to subtract to the first one
        /// @return Value of the subtraction of the 2 ratio (the result is a ratio)
        Ratio operator-(const Ratio&r) const;
        
        //Subtraction Operator
        /// @brief Subtraction Operator Templated
        template <typename T>
        Ratio operator-(const T &value) const;

        //Product Operator
        /// @brief Product Operator
        /// @param r the ratio to multiply to the first one
        /// @return Value of the product of the 2 ratio (the result is a ratio)
        Ratio operator*(const Ratio &r) const;
        
        //Product Operator
        /// @brief Product of a ratio and a real
        /// @param value is the real
        /// @return Ratio product of two
        template <typename T>
        Ratio operator*(const T &value) const{
            static_assert(std::is_arithmetic_v<T>, "Ratio::operator*(value): invalid type of typename, should be a number, can't be a string or a char");
            const Ratio rValue(value);
            return (*this)*rValue;
        }

        //Inverse Operator
        /// @brief Inverse Operator
        /// @return Value of the inverse of the ratio (the result is a ratio)
        Ratio invert() const;

        //Division Operator
        /// @brief Division Operator
        /// @param r the ratio to divide to the first one
        /// @return Value of the division of the 2 ratio (the result is a ratio)
        Ratio operator/(const Ratio &r) const;
        
        //Division Operator
        /// @brief Division Operator Templated
        template <typename T>
        Ratio operator/(const T &value) const;

        //Pow Operator
        /// @brief Pow Operator
        /// @param p is the power's degree
        /// @return Value of the ratio at power p (the result is a ratio)
        Ratio ratioPow(const int& p) const;

        /// @brief Pow Operator Variadic
        /// @param p is the power's degree
        /// @return Value of the ratio at power p (the result is a ratio)
        template <typename ... Args>
        Ratio ratioPow(const int p, const Args ...args) const;

        Ratio ratioPow(const Ratio& p) const;

        //SQRT Operator
        /// @brief SQRT Operator
        /// @return Result of the square root of the ratio
        Ratio ratioSqrt() const;
        
        /// @brief Unary Minus Operator
        /// @return Current Ratio with m_numerator with opposite sign
        Ratio operator-() const;

        /// @brief Absolute Value
        /// @return Current Ratio with m_numerator with positive sign
        Ratio abs() const;

        /// @brief Permit to have the entire part of the Ratio
        /// @return Entire part of the Ratio
        int getEntirePart() const;


        /// @brief Sum Operator by reference
        /// @param r the ratio to add
        /// @return Value of the sum of the 2 values (the result is a ratio)
        Ratio & operator+=(const Ratio &r);
        
        /// @brief Sum Operator Templated by reference
        template <typename T>
        Ratio & operator+=(const T &value);

        /// @brief Subtraction Operator by reference
        /// @param r the ratio to subtract to the first one
        /// @return Value of the subtraction of the 2 ratio (the result is a ratio)
        Ratio & operator-=(const Ratio &r);

        /// @brief Subtraction Operator Templated by reference
        template <typename T>
        Ratio & operator-=(const T &value);

        /// @brief Product Operator by reference
        /// @param r the ratio to multiply to the first one
        /// @return Value of the product of the 2 ratio (the result is a ratio)
        Ratio & operator*=(const Ratio &r);

        /// @brief Product Operator Templated by reference
        template <typename T>
        Ratio & operator*=(const T &value);

        /// @brief Division Operator by reference
        /// @param r the ratio to divide to the first one
        /// @return Value of the division of the 2 ratio (the result is a ratio)
        Ratio & operator/=(const Ratio &r);

        /// @brief Division Operator Templated by reference
        template <typename T>
        Ratio & operator/=(const T &value);
        
        /// @brief Convert Rational Number to Real Number
        /// @param ratio the ratio to convert
        /// @return Real number of the type wanted
        template <typename T>
        friend T convertRatioToReal(const Ratio& ratio);

        /// Trigonometry operations
        // cos
        /// @brief Cosinus of a ratio
        /// @param ratio is the ratio to use 
        /// @return Ratio approximation value of cosinus
        friend Ratio cos(const Ratio& ratio);

        // sin
        /// @brief Sinus of a ratio
        /// @param ratio is the ratio to use
        /// @return Ratio approximation value of sinus
        friend Ratio sin(const Ratio& ratio);
        
        // tan
        /// @brief Tangent of a ratio
        /// @param ratio is the ratio to use
        /// @return Ratio approximation value of tangent
        friend Ratio tan(const Ratio& ratio);

        /// Exponential and Logarithm
        /// @brief Exponential of a value templated
        /// @param value is the value to use
        /// @return Ratio approximation value of exponential
        template <typename T>
        friend Ratio exp(const T& value);

        /// @brief Exponential of a ratio
        /// @param ratio is the value to use
        /// @return Ratio approximation value of exponential
        friend Ratio exp(const Ratio& ratio);

        /// @brief Logarithm of a value templated
        /// @param value is the value to use
        /// @return Ratio approximation value of logarithm
        template <typename T>
        friend Ratio log(const T& value);

        /// @brief Logarithm of a ratio
        /// @param ratio is the value to use
        /// @return Ratio approximation value of logarithm
        friend Ratio log(const Ratio& ratio);
    };

    /// @brief Product of a real and a ratio
    /// @param value is real value to multiply
    /// @param r is Ratio to multiply
    /// @return Ratio product of two
    template <typename T>
    Ratio operator*(const T value, const Ratio &r){
        static_assert(std::is_arithmetic_v<T>, "Ratio::operator*(value, ratio): invalid type of typename, should be a number, can't be a string or a char");

        return r*value;
    }

    /// @brief Convert real to Rational number
    /// @param v the real to convert
    /// @param nb_iter the number of iterations (6 because to get almost 10 decimals of PI, need 6 iterations)
    /// @return Rational Number
    template <typename V>
    Ratio convertRealToRatio(const V& v, const int& nb_iter = 6){
        static_assert(std::is_arithmetic_v<V>, "convertRealToRatio(value, nb_iter): invalid type of parameter, value should be a number, can't be a string or a char");

        Ratio result;

        // if int, directly good constructor
        if(std::is_integral_v<V>) return Ratio(v);

        if(v == static_cast<V>(0)) return Ratio();

        if(nb_iter == 0) return Ratio();

        if(v < static_cast<V>(0)) return -(convertRealToRatio(std::abs(v), nb_iter));

        if(v < static_cast<V>(1)){
            return (convertRealToRatio(static_cast<V>(1)/std::abs(v), nb_iter)).invert();
        }

        if(v >= static_cast<V>(1)){
            const int q = (int) std::abs(v);

            return Ratio(q, 1)+ convertRealToRatio(v-q, nb_iter-1);
        }
    }

    template <typename T>
    Ratio::Ratio(const T& v): m_numerator(convertRealToRatio(v).m_numerator), m_denominator(convertRealToRatio(v).m_denominator){
        // if (typeid(v) == typeid(std::string) || typeid(v) == typeid(char))
        //     throw std::domain_error("Ratio::Ratio(value): invalid type of parameter, should be a number, can't be a string or a char");
        static_assert(std::is_arithmetic_v<T>, "Ratio::Ratio(value): invalid type of parameter, should be a number, can't be a string or a char");

        const int pgcd = getPGCD();
        if(pgcd != 1)
            convertToIrreducible(pgcd);
    }

    template <typename T>
    T convertRatioToReal(const Ratio& ratio){
        static_assert(std::is_arithmetic_v<T>, "T convertRatioToReal(ratio): invalid type of typename, should be a number, can't be a string or a char");
        return static_cast<T>(ratio.m_numerator)/static_cast<T>(ratio.m_denominator);
    }


    // Simple Math Operators
    template <typename T>
    Ratio Ratio::operator+(const T &value) const{
        static_assert(std::is_arithmetic_v<T>, "Ratio::operator+(value): invalid type of typename, should be a number, can't be a string or a char");

        Ratio rVal = convertRealToRatio(value);

        return (*this) + rVal;
    }

    /// @brief Sum of a real and a ratio
    /// @param value is real value to add
    /// @param r is Ratio to add
    /// @return Ratio sum of two
    template <typename T>
    Ratio operator+(const T value, const Ratio &r){
        static_assert(std::is_arithmetic_v<T>, "Ratio::operator+(value, ratio): invalid type of typename, should be a number, can't be a string or a char");

        return r+value;
    }

    template <typename T>
    Ratio Ratio::operator-(const T &value) const{
        static_assert(std::is_arithmetic_v<T>, "Ratio::operator-(value): invalid type of typename, should be a number, can't be a string or a char");

        Ratio rVal = convertRealToRatio(value);

        return (*this) - rVal;
    }

    /// @brief Subtraction of a real and a ratio
    /// @param value is real value to subtract
    /// @param r is Ratio to subtract
    /// @return Ratio Subtraction of two
    template <typename T>
    Ratio operator-(const T value, const Ratio &r){
        static_assert(std::is_arithmetic_v<T>, "Ratio::operator-(value, ratio): invalid type of typename, should be a number, can't be a string or a char");

        return (-r)-(-value);
    }

    template <typename T>
    Ratio Ratio::operator/(const T &value) const{
        static_assert(std::is_arithmetic_v<T>, "Ratio::operator-(value): invalid type of typename, should be a number, can't be a string or a char");

        Ratio rVal = convertRealToRatio(value);

        return (*this) / rVal;
    }

    /// @brief Division of a real and a ratio
    /// @param value is real value to divide
    /// @param r is Ratio to divide
    /// @return Ratio Division of two
    template <typename T>
    Ratio operator/(const T value, const Ratio &r){
        static_assert(std::is_arithmetic_v<T>, "Ratio::operator/(value, ratio): invalid type of typename, should be a number, can't be a string or a char");

        Ratio rVal = convertRealToRatio(value);
        return rVal/r;
    }

    template <typename T>
    Ratio& Ratio::operator+=(const T &value){
        static_assert(std::is_arithmetic_v<T>, "Ratio::operator+=(value): invalid type of typename, should be a number, can't be a string or a char");

        Ratio rVal = convertRealToRatio(value);

        return (*this) += rVal;
    }

    template <typename T>
    Ratio& Ratio::operator-=(const T &value){
        static_assert(std::is_arithmetic_v<T>, "Ratio::operator-=(value): invalid type of typename, should be a number, can't be a string or a char");

        Ratio rVal = convertRealToRatio(value);

        return (*this) -= rVal;
    }

    template <typename T>
    Ratio& Ratio::operator*=(const T &value){
        static_assert(std::is_arithmetic_v<T>, "Ratio::operator*=(value): invalid type of typename, should be a number, can't be a string or a char");

        Ratio rVal = convertRealToRatio(value);

        return (*this) *= rVal;
    }

    template <typename T>
    Ratio& Ratio::operator/=(const T &value){
        static_assert(std::is_arithmetic_v<T>, "Ratio::operator/=(value): invalid type of typename, should be a number, can't be a string or a char");

        Ratio rVal = convertRealToRatio(value);

        return (*this) /= rVal;
    }


    // Pow Variadic
    template <typename ... Args>
    Ratio Ratio::ratioPow(const int p, const Args ...args) const{
        return this->ratioPow(p).ratioPow(args...);
    }

    /// Exp and log
    template <typename T>
    Ratio exp(const T& value){
        static_assert(std::is_arithmetic_v<T>, "exp(value): invalid type of parameter, value should be a number, can't be a string or a char");

        return Ratio(std::exp(value));
    }

    template <typename T>
    Ratio log(const T& value){
        static_assert(std::is_arithmetic_v<T>, "log(value): invalid type of parameter, value should be a number, can't be a string or a char");

        if (value <= static_cast<T>(0))
            throw std::domain_error("log(value): invalid type of parameter, should be positive");

        return Ratio(std::log(value));
    }
}