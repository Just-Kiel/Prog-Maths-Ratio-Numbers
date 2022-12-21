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

TEST (RatioInformation, irreducible){
	// run many times the same test with different values
	for(int run=0; run<100; ++run){

		std::srand((unsigned int) (std::time(nullptr))); // use current time as seed for random generator

        // generate random data
        int numerator = std::rand();
        unsigned int denominator = std::rand();

		// build the corresponding Ratio
		Ratio r(numerator, denominator);

        int pgcd = std::gcd(r.getNumerator(), r.getDenominator());

        if(pgcd != 1){
            r.convertToIrreducible(pgcd);
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

    // test on special cases
    Ratio inf = Ratio::infinity();
    Ratio supInf = r1 + inf;

    ASSERT_EQ(inf == supInf, true);

    Ratio zero = Ratio();
    Ratio r5 = r1 + zero;

    ASSERT_EQ(r5 == r1, true);
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

//product T value test
TEST(RatioOperator, productTValue){
    Ratio r1(1,2);
    Ratio r2(1,4);
    Ratio r3=r1*0.5;

    ASSERT_EQ(r2.getNumerator(),r3.getNumerator());
    ASSERT_EQ(r2.getDenominator(),r3.getDenominator());
}

//product T value and ratio test
TEST(RatioOperator, productTValueRatio){
    Ratio r1(1,2);
    Ratio r2(1,4);
    Ratio r3=0.5*r1;

    ASSERT_EQ(r2.getNumerator(),r3.getNumerator());
    ASSERT_EQ(r2.getDenominator(),r3.getDenominator());
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

//sqrt test
// TEST(RatioOperator, sqrt){
    
// }

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
// conversion real to ratio
TEST(RatioConversion, RealToRatio){
    Ratio r1 = convertRealToRatio(0.5);
    Ratio r2(1,2);

    ASSERT_EQ(r1 == r2,true);


    Ratio rI = convertRealToRatio(2);
    Ratio rI2(2, 1);
    ASSERT_EQ(rI == rI2,true);

    Ratio r3 = convertRealToRatio(-0.5);
    Ratio r4(-1,2);

    ASSERT_EQ(r3.getNumerator(),r4.getNumerator());
    ASSERT_EQ(r3.getDenominator(),r4.getDenominator());

    Ratio rPI = convertRealToRatio(3.14159265301, 6);
    Ratio PI = Ratio::pi();

    ASSERT_EQ(rPI.getNumerator(),PI.getNumerator());
    ASSERT_EQ(rPI.getDenominator(),PI.getDenominator());
}

// conversion ratio to real
TEST(RatioConversion, RatioToReal){
    Ratio r1(1, 2);

    float v1 = convertRatioToReal<float>(r1);

    ASSERT_EQ(v1 == 0.5f,true);

    // int test
    Ratio r2(3, 1);

    int v2 = convertRatioToReal<int>(r2);

    ASSERT_EQ(v2 == 3,true);
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