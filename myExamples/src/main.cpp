// Here, we include the lib we need.
#include <iostream>
#include "Ratio.hpp"

// Main program with our functions and operators usecases
int main(int argc, char const *argv[])
{

    //How to create a ratio ?
    /* When a ratio is created, the program check if the chosen number is a ratio and if yes, it verify if its form is 
    irreductible. If it's not, the program convert the ratio to its irreductible form. 
    Here,the ratio 12/24 becomes the ratio 1/2 */

    Ratio r1(12,24);
   //std::cout<<"My Ratio r1 is : "<<r1<<std::endl;

    //How to get the numerator and the denominator of a ratio ?

    std::cout<<"My r1 Ratio's numerator is : "<<r1.getNumerator()<<std::endl;
    std::cout<<"My r1 Ratio's denominator is : "<<r1.getDenominator()<<std::endl;


    //Convert real to ratio ?
    //
    //
    //
    //

    //Creation of a new ratio to use the following operations

    Ratio r2(2,3);

    //How to sum 2 ratio ?
   // std::cout<<"r1+r2 = "<<r1+r2<<std::endl;

    //How to substract 2 ratio ?
   // std::cout<<"r1-r2 = "<<r1-r2<<std::endl;

    //How to do the product of 2 ratio ?
   // std::cout<<"r1*r2 = "<<r1*r2<<std::endl;

    //How to divise 2 ratio ?
   // std::cout<<"r1/r2 = "<<r1/r2<<std::endl;

    //How to do the inverse of a ratio ?
   // std::cout<<"1/r1 = "<<r1.invert()<<std::endl;

    //How to use the function power with ratio ?
   // std::cout << "r1^2 = " <<r1.ratioPow(2)<<std::endl;

    //How to use the SQR function ?

    return 0;
}
