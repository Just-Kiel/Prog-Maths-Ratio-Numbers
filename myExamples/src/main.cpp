// Here, we include the lib we need.
#include <iostream>
#include "Ratio.hpp"

using namespace IMAC;

// Main program with our functions and operators use cases
int main(int argc, char const *argv[])
{

    //How to create a ratio ?
    /* When a ratio is created, the program check if the chosen number is a ratio and if yes, it verify if its form is 
    irreducible. If it's not, the program convert the ratio to its irreducible form. 
    Here,the ratio 12/24 becomes the ratio 1/2 */

    Ratio r1(12,24);
    Ratio r2(2,3);
    std::cout<<"My Ratio r1 is : "<<r1<<std::endl;

    //How to get the numerator and the denominator of a ratio ?

    std::cout<<"My r1 Ratio's numerator is : "<<r1.getNumerator()<<std::endl;
    std::cout<<"My r1 Ratio's denominator is : "<<r1.getDenominator()<<std::endl;

    std::cout<<"My Ratio r2 is : "<<r1<<std::endl;

    //Convert real to ratio ?
    Ratio r3(0.25);
    // or
    Ratio r4 = convertRealToRatio<float>(0.25f);

    // Convert ratio to real ?
    float val4 = convertRatioToReal<float>(r4);

    // How to make unary minus on a ratio ?
    std::cout<<"Unary Minus : - ("<<r1<<") = "<<-r1<<std::endl;

    // How to have absolute value of a ratio ?
    std::cout<<"Absolute Value : ||("<<r1<<")|| = "<<r1.abs()<<std::endl;

    // How to get entire part of a ratio ?
    std::cout<<"Entire part of ("<<r1<<") = "<<r1.getEntirePart()<<std::endl;

    //How to sum a ratio and a ratio or another type of value ?
    std::cout<<"Sum : ("<<r1<<") + ("<<r2<<") = "<<r1+r2<<std::endl;

    //How to subtract a ratio and a ratio or another type of value ?
    std::cout<<"Subtraction : ("<<r1<<") - ("<<r2<<") = "<<r1-r2<<std::endl;

    //How to do the product of a ratio and a ratio or another type of value ?
    std::cout<<"Product : ("<<r1<<") * ("<<r2<<") = "<<r1*r2<<std::endl;

    //How to divide a ratio and a ratio or another type of value ?
    std::cout<<"Division : ("<<r1<<") / ("<<r2<<") = "<<r1/r2<<std::endl;

    //How to do the inverse of a ratio ?
    std::cout<<"Inverse : 1/("<<r1<<") = "<<r1.invert()<<std::endl;

    //How to use the function power with ratio ?
    std::cout<<"Power : ("<<r1<<")^"<<2<<" = "<<r1.ratioPow(2)<<std::endl;
    // also possible to do several pow chained
    std::cout<<"Several Powers : (("<<r1<<")^2)^2 = "<<r1.ratioPow(2,2)<<std::endl;
    // also possible with ratio
    std::cout<<"Power with ratio exponent : ("<<r1<<")^1/2 = "<<r1.ratioPow(Ratio(1, 2))<<std::endl;

    //How to use the SQRT function ?
    std::cout<<"Squared Root of ("<<r3<<") = "<<r3.ratioSqrt()<<std::endl;

    // How to compare ratio and other value (ratio or real number) ?
    if (r1 == 0.5) std::cout << "The equality r1 == 0.5 is proved." << std::endl;
    if (r1 != 1.5) std::cout << "The equality r1 != 1.5 is proved." << std::endl;
    if (r1 < 0.8) std::cout << "The equality r1 < 0.8 is proved." << std::endl;
    if (r1 <= 0.8) std::cout << "The equality r1 <= 0.8 is proved." << std::endl;
    if (r1 > 0.3) std::cout << "The equality r1 > 0.3 is proved." << std::endl;
    if (r1 >= 0.3) std::cout << "The equality r1 >= 0.3 is proved." << std::endl;

    // How to math assign value a ratio ?
    r3 += 0.25; 
    std::cout<<"My Ratio r3 is : "<<r3<<std::endl;
    
    r3 -= 0.25;
    std::cout<<"My Ratio r3 is : "<<r3<<std::endl;

    r3 *=2;
    std::cout<<"My Ratio r3 is : "<<r3<<std::endl;
    
    r3 /=2;
    std::cout<<"My Ratio r3 is : "<<r3<<std::endl;



    // How to do trigonometry operations ?
    std::cout<<"Cos of (PI/6) = "<<cos(Ratio::pi()/6)<<std::endl;
    std::cout<<"Sin of (PI/6) = "<<sin(Ratio::pi()/6)<<std::endl;
    std::cout<<"Tan of (PI/6) = "<<tan(Ratio::pi()/6)<<std::endl;

    // How to obtain an exponential or a logarithm in ratio ?
    std::cout<<"Exponential of (1) = "<<exp(Ratio(1))<<std::endl;
    // Approximation due to conversion to float
    std::cout<<"Logarithm of line above = "<<log(exp(Ratio(1)))<<std::endl;

    return 0;
}
