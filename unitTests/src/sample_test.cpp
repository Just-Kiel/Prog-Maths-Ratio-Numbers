#include <gtest/gtest.h>

// #include <random>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

#include <ctime>
#include <cstdlib>

#include "Ratio.hpp"

/////////////////////////////////////////////////////
// constructors

TEST (RatioConstructor, defaultConstructor) { 
	std::srand((unsigned int) (std::time(nullptr))); // use current time as seed for random generator

	// generate random data
    int numerator = std::rand();
    unsigned int denominator = std::rand();

	// build the corresponding Ratio
	Ratio r(numerator, denominator);

    // check if basic ratio PGCD is 1
	ASSERT_EQ (std::gcd(r.getNumerator(), r.getDenominator()), 1);
}

TEST (RatioConstructor, copyConstructor) {    
    std::srand((unsigned int) (std::time(nullptr))); // use current time as seed for random generator

	// generate random data
    int numerator = std::rand();
    unsigned int denominator = std::rand();

	// build the corresponding Ratio
	Ratio r(numerator, denominator);

    Ratio rCopy(r);
	ASSERT_EQ (r.getDenominator(), rCopy.getDenominator());
	ASSERT_EQ (r.getNumerator(), rCopy.getNumerator());
}

/////////////////////////////////////////////////////
// variables

TEST (RatioVariables, infiniteVar) { 
	Ratio inf = Ratio::infinity();
    // check if basic ratio numerator
	ASSERT_EQ (inf.getNumerator(), 1);
    // check if basic ratio denominator
	ASSERT_EQ (inf.getDenominator(), 0);
}

/////////////////////////////////////////////////////
// informations

TEST (RatioInformation, irreductible){
	// run many times the same test with different values
	for(int run=0; run<100; ++run){

		std::srand((unsigned int) (std::time(nullptr))); // use current time as seed for random generator

        // generate random data
        int numerator = std::rand();
        unsigned int denominator = std::rand();

		// build the corresponding Ratio
		Ratio r(numerator, denominator);

        int pgcd = std::gcd(r.getNumerator(), r.getDenominator());

        if(pgcd =! 1){
            r.convertToIrreductible(pgcd);
        }

		ASSERT_EQ (std::gcd(r.getNumerator(), r.getDenominator()), 1);
	}
}

//operators
//sum test
TEST(RatioOperator, sum){
    Ratio r1(1,2);
    Ratio r2(2,3);
    Ratio r3(7,6);
    Ratio r4=r1+r2;

    ASSERT_EQ(r4.getNumerator(),r3.getNumerator());
    ASSERT_EQ(r4.getDenominator(),r3.getDenominator());
}

//subtraction test
TEST(RatioOperator, subtraction){
    Ratio r1(1,2);
    Ratio r2(2,3);
    Ratio r3(-1,6);
    Ratio r4=r1-r2;

    ASSERT_EQ(r4.getNumerator(),r3.getNumerator());
    ASSERT_EQ(r4.getDenominator(),r3.getDenominator());
}

//product test
TEST(RatioOperator, product){
    Ratio r1(1,2);
    Ratio r2(2,3);
    Ratio r3(2,6);
    Ratio r4=r1*r2;

    ASSERT_EQ(r4.getNumerator(),r3.getNumerator());
    ASSERT_EQ(r4.getDenominator(),r3.getDenominator());
}

//inverse test
TEST(RatioOperator, inverse){
    Ratio r1(1,2);
    Ratio r2(2,1);
    Ratio r3=r1.invert();

    ASSERT_EQ(r3.getNumerator(),r2.getNumerator());
    ASSERT_EQ(r3.getDenominator(),r2.getDenominator());
}

//division test
TEST(RatioOperator, division){
    Ratio r1(1,2);
    Ratio r2(2,3);
    Ratio r3(3,4);
    Ratio r4=r1/r2;

    ASSERT_EQ(r4.getNumerator(),r3.getNumerator());
    ASSERT_EQ(r4.getDenominator(),r3.getDenominator());
}

//pow test
TEST(RatioOperator, ratioPow){
    Ratio r1(1,2);
    int p=2;
    Ratio r2(1,4);
    Ratio r3=r1.ratioPow(p);

    ASSERT_EQ(r3.getNumerator(),r2.getNumerator());
    ASSERT_EQ(r3.getDenominator(),r2.getDenominator());

}


// Unary Minus Test
TEST(RatioOperator, UnaryMinus){
    Ratio r1(1,2);
    Ratio r2(-1,2);
    r1 = -r1;

    ASSERT_EQ(r1.getNumerator(),r2.getNumerator());
    ASSERT_EQ(r1.getDenominator(),r2.getDenominator());
}

// Absolute Value Test
TEST(RatioOperator, AbsoluteValue){
    Ratio r1(-1,2);
    Ratio r2(1,2);
    r1 = r1.abs();

    ASSERT_EQ(r1.getNumerator(),r2.getNumerator());
    ASSERT_EQ(r1.getDenominator(),r2.getDenominator());
}

// Entire Part Test
TEST(RatioOperator, EntirePart){
    Ratio r1(-1,2);
    int entireR1 = r1.getEntirePart();

    ASSERT_EQ(entireR1,0);
}
//////////////////////////////////////////////////////
// comparisons
TEST(RatioComparison, Equal){
    Ratio r1(-1,2);
    Ratio r2(r1);

    ASSERT_EQ(r1==r2,true);
    ASSERT_EQ(r1.getNumerator(),r2.getNumerator());
    ASSERT_EQ(r1.getDenominator(),r2.getDenominator());
}

TEST(RatioComparison, NotEqual){
    Ratio r1(-1,2);
    Ratio r2(-r1);

    ASSERT_EQ(r1!=r2,true);
}

TEST(RatioComparison, Less){
    Ratio r1(1,2);
    Ratio r2(-1,2);

    ASSERT_EQ(r2<r1,true);
}

TEST(RatioComparison, Greater){
    Ratio r1(1,2);
    Ratio r2(-1,2);

    ASSERT_EQ(r1>r2,true);
}

/////////////////////////////////////////////////////
// exceptions

TEST (RatioException, defaultConstructorExceptionMessage) {
	const std::string expectedException = "Ratio::Ratio(numerator, denominator): invalid denominator, can't be 0";

	// check the exception message
    try{
		Ratio r(1, 0);
    }
    catch(const std::exception &e){
        EXPECT_TRUE( std::string(e.what()).find(expectedException) == 0);
    }
}

/////////////////////////////////////////////////////
// We run all unit tests here
int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}