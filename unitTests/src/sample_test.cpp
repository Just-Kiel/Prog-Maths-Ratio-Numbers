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

    Ratio r6 = r1 + 3;
    ASSERT_EQ(r6 == Ratio(7,2), true);

    Ratio r7 = r1 + 3 + r1;
    ASSERT_EQ(r7 == Ratio(8,2), true);

    Ratio r8 = 3 + r1;
    ASSERT_EQ(r8 == Ratio(7,2), true);
}

//subtraction test
TEST(RatioOperator, subtraction){
    Ratio r1(1,2);
    Ratio r2(2,3);
    Ratio r3(-1,6);
    Ratio r4=r1-r2;

    ASSERT_EQ(r4.getNumerator(),r3.getNumerator());
    ASSERT_EQ(r4.getDenominator(),r3.getDenominator());

    // test on special cases
    Ratio inf = Ratio::infinity();
    Ratio r5 = inf - inf;
    ASSERT_EQ(r5 == 0, true);

    Ratio r6 = inf - r1;
    ASSERT_EQ(r6 == inf, true);

    Ratio r7 = r1 - inf;
    ASSERT_EQ(r7 == -inf, true);
}

//product test
TEST(RatioOperator, product){
    Ratio r1(1,2);
    Ratio r2(2,3);
    Ratio r3(2,6);
    Ratio r4=r1*r2;

    ASSERT_EQ(r4.getNumerator(),r3.getNumerator());
    ASSERT_EQ(r4.getDenominator(),r3.getDenominator());

    // test on special cases
    Ratio inf = Ratio::infinity();
    Ratio r5 = inf * inf;
    ASSERT_EQ(r5 == inf, true);

    Ratio r6 = inf * r1;
    ASSERT_EQ(r6 == inf, true);

    Ratio r7 = r1 * inf;
    ASSERT_EQ(r7 == inf, true);

    Ratio r9 = -r1;
    Ratio r10 = r9 * inf;
    ASSERT_EQ(r10 == -inf, true);

    Ratio r11 = inf * r9;
    ASSERT_EQ(r11 == -inf, true);

    Ratio zero = Ratio();
    Ratio r8 = r1 * zero;

    ASSERT_EQ(r8 == zero, true);
}

//product T value test
TEST(RatioOperator, productTValue){
    Ratio r1(1,2);
    Ratio r2(1,4);
    Ratio r3=r1*0.5;

    ASSERT_EQ(r2.getNumerator(),r3.getNumerator());
    ASSERT_EQ(r2.getDenominator(),r3.getDenominator());

    // test on special cases
    Ratio inf = Ratio::infinity();
    Ratio r5 = inf * 0.5;
    ASSERT_EQ(r5 == inf, true);

    Ratio r7 = inf * -1;
    ASSERT_EQ(r7 == -inf, true);

    Ratio zero = Ratio();
    Ratio r6 = zero * 0.5;

    ASSERT_EQ(r6 == zero, true);
}

//product T value and ratio test
TEST(RatioOperator, productTValueRatio){
    Ratio r1(1,2);
    Ratio r2(1,4);
    Ratio r3=0.5*r1;

    ASSERT_EQ(r2.getNumerator(),r3.getNumerator());
    ASSERT_EQ(r2.getDenominator(),r3.getDenominator());

    // test on special cases
    Ratio inf = Ratio::infinity();
    Ratio r5 = 0.5 * inf;
    ASSERT_EQ(r5 == inf, true);

    Ratio r7 = -1 * inf;
    ASSERT_EQ(r7 == -inf, true);

    Ratio zero = Ratio();
    Ratio r6 = 0.5 * zero;

    ASSERT_EQ(r6 == zero, true);
}

//inverse test
TEST(RatioOperator, inverse){
    Ratio r1(1,2);
    Ratio r2(2,1);
    Ratio r3=r1.invert();

    ASSERT_EQ(r3.getNumerator(),r2.getNumerator());
    ASSERT_EQ(r3.getDenominator(),r2.getDenominator());

    // test on special cases
    Ratio inf = Ratio::infinity();
    Ratio zero = Ratio();

    Ratio r5 = inf.invert();
    ASSERT_EQ(r5 == zero, true);

    Ratio r6 = zero.invert();
    ASSERT_EQ(r6 == inf, true);
}

//division test
TEST(RatioOperator, division){
    Ratio r1(1,2);
    Ratio r2(2,3);
    Ratio r3(3,4);
    Ratio r4=r1/r2;

    ASSERT_EQ(r4.getNumerator(),r3.getNumerator());
    ASSERT_EQ(r4.getDenominator(),r3.getDenominator());

    // test on special cases
    Ratio inf = Ratio::infinity();
    Ratio r6 = inf / r1;
    ASSERT_EQ(r6 == inf, true);

    Ratio r8 = -r1;
    Ratio r9 = inf / r8;
    ASSERT_EQ(r9 == -inf, true);

    Ratio r7 = r1 / inf;
    ASSERT_EQ(r7 == 0, true);
}

//pow test
TEST(RatioOperator, ratioPow){
    Ratio r1(1,2);
    Ratio r2(1,4);
    Ratio r3=r1.ratioPow(2);

    Ratio r7=r2.ratioPow(-1); 

    ASSERT_EQ(r3.getNumerator(),r2.getNumerator());
    ASSERT_EQ(r3.getDenominator(),r2.getDenominator());

    ASSERT_EQ(r7 == 4, true);

    Ratio r14 = r1.ratioPow(2, 2);
    
    ASSERT_EQ(r14 == Ratio(1, 16), true);

    // test on special cases
    Ratio inf = Ratio::infinity();
    Ratio r5 = inf.ratioPow(2);
    ASSERT_EQ(r5 == inf, true);

    Ratio zero = Ratio();
    Ratio r6 = zero.ratioPow(2);
    ASSERT_EQ(r6 == zero, true);
}

//sqrt test
TEST(RatioOperator, ratioSqrt){
    Ratio r1(1,4);
    Ratio r2(1,2);
    Ratio r3=r1.ratioSqrt();
/* doesn't work for non rational numbers (approx) ex : srqt(2)
    doesn't work when we made sqrt(primary number) or sqrt(A) where A is a number which can be decomposed
    in product of sqrt(primary number) 
    */
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

    Ratio inf = Ratio::infinity();
    Ratio minInf = -inf;
    ASSERT_EQ(-inf.getNumerator(),minInf.getNumerator());
    ASSERT_EQ(-inf.getDenominator(),minInf.getDenominator());
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

//sum test by reference
TEST(RatioOperator, sumByRef){
    Ratio r1(1,2);
    Ratio r2(2,3);
    Ratio r3(7,6);

    r1 += r2;

    ASSERT_EQ(r1 == r3, true);

    r2 += 1;
    ASSERT_EQ(r2 == Ratio(5,3), true);
}
//////////////////////////////////////////////////////
// comparisons
TEST(RatioComparison, Equal){
    Ratio r1(-1,2);
    Ratio r2(r1);

    ASSERT_EQ(r1==r2,true);
    ASSERT_EQ(r1.getNumerator(),r2.getNumerator());
    ASSERT_EQ(r1.getDenominator(),r2.getDenominator());

    ASSERT_EQ(Ratio(5, 2)==2.5,true);
    ASSERT_EQ(2.5==Ratio(5, 2),true);
}

TEST(RatioComparison, NotEqual){
    Ratio r1(-1,2);
    Ratio r2(-r1);

    ASSERT_EQ(r1!=r2,true);

    ASSERT_EQ(Ratio(3, 2)!=2.5,true);
    ASSERT_EQ(0.5!=Ratio(3, 2),true);
}

TEST(RatioComparison, Less){
    Ratio r1(1,2);
    Ratio r2(-1,2);

    ASSERT_EQ(r2<r1,true);


    ASSERT_EQ(r2<3.8,true);
    ASSERT_EQ(-4.7<r1,true);
}

TEST(RatioComparison, Greater){
    Ratio r1(1,2);
    Ratio r2(-1,2);

    ASSERT_EQ(r1>r2,true);    

    ASSERT_EQ(3>r2,true);
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

//////////////////////////////////////////////////////
// trigonometry operations
TEST(RatioTrigonometry, Cosinus){
    Ratio r1 = cos(Ratio());

    ASSERT_EQ(r1 == 1,true);
    
    Ratio r2 = cos(Ratio::pi()/3);

    ASSERT_NEAR(convertRatioToReal<float>(r2),0.5, 0.01);

    Ratio r3 = cos(Ratio::pi()/2);
    
    ASSERT_NEAR(convertRatioToReal<float>(r3),0, 0.01);
    
    Ratio r4 = cos(Ratio::pi());
    
    ASSERT_NEAR(convertRatioToReal<float>(r4),-1, 0.01);

    Ratio r5 = cos(Ratio::pi()/6);
    
    ASSERT_NEAR(convertRatioToReal<float>(r5),0.86, 0.01);

    Ratio r6 = cos(Ratio::pi()*5/6);
    
    ASSERT_NEAR(convertRatioToReal<float>(r6),-0.86, 0.01);
}

TEST(RatioTrigonometry, Sinus){
    Ratio r1 = sin(Ratio());

    ASSERT_EQ(r1 == 0,true);
    
    Ratio r2 = sin(Ratio::pi()/3);

    ASSERT_NEAR(convertRatioToReal<float>(r2),0.86, 0.01);

    Ratio r3 = sin(Ratio::pi()/2);
    
    ASSERT_NEAR(convertRatioToReal<float>(r3),1, 0.01);
    
    Ratio r4 = sin(Ratio::pi());
    
    ASSERT_NEAR(convertRatioToReal<float>(r4),0, 0.01);

    Ratio r5 = sin(Ratio::pi()/6);
    
    ASSERT_NEAR(convertRatioToReal<float>(r5),0.5, 0.01);

    Ratio r6 = sin(Ratio::pi()*5/6);
    
    ASSERT_NEAR(convertRatioToReal<float>(r6),0.5, 0.01);
}

TEST(RatioTrigonometry, Tangent){
    Ratio r1 = tan(Ratio());

    ASSERT_EQ(r1 == 0,true);
    
    Ratio r2 = tan(Ratio::pi()/6);

    ASSERT_NEAR(convertRatioToReal<float>(r2),0.57, 0.01);
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