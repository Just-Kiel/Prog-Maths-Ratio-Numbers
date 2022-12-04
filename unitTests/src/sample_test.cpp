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

//product test
TEST(RatioOperator, product){
    Ratio r1(1,2);
    Ratio r2(2,3);
    Ratio r3(2,6);
    Ratio r4=r1*r2;

    ASSERT_EQ(r4.getNumerator(),r3.getNumerator());
    ASSERT_EQ(r4.getDenominator(),r3.getDenominator());

}


/////////////////////////////////////////////////////
// arithmetic

// TEST (VectorDArithmetic, plus) {

// 	const size_t maxSize = 1000;  // max size of the tested vectors
// 	std::mt19937 generator(0);
// 	std::uniform_int_distribution<int> uniformIntDistribution(1,maxSize);
// 	std::uniform_real_distribution<double> uniformDistributionValue(-int(maxSize),maxSize);
// 	auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};

// 	// run many times the same test with different values
// 	for(int run=0; run<100; ++run){

// 		// define a vector dimension
// 		const size_t dim = uniformIntDistribution(generator);

// 		// generate random data
// 		std::vector<double> data1(dim), data2(dim);
// 		std::generate(data1.begin(), data1.end(), gen);
// 		std::generate(data2.begin(), data2.end(), gen);

// 		// build the corresponding VectorD
// 		VectorD vec1(dim), vec2(dim), vec3(dim);
// 		for(size_t i=0; i<dim; ++i){
// 			vec1[i] = data1[i];
// 			vec2[i] = data2[i];
// 		}

// 		vec3 = vec1 + vec2;
// 		ASSERT_EQ (vec3.size(), dim);

// 		for(size_t i=0; i<dim; ++i){
// 	    	ASSERT_DOUBLE_EQ (vec3[i], data1[i] + data2[i]);    // EXPECT_DOUBLE_EQ would be fine too
// 		}
// 	}
// }


// TEST (VectorDArithmetic, minus) {

// 	const size_t maxSize = 1000;  // max size of the tested vectors
// 	std::mt19937 generator(0);
// 	std::uniform_int_distribution<int> uniformIntDistribution(1,maxSize);
// 	std::uniform_real_distribution<double> uniformDistributionValue(-int(maxSize),maxSize);
// 	auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};

// 	// run many times the same test with different values
// 	for(int run=0; run<100; ++run){

// 		// define a vector dimension
// 		const size_t dim = uniformIntDistribution(generator);

// 		// generate random data
// 		std::vector<double> data1(dim), data2(dim);
// 		std::generate(data1.begin(), data1.end(), gen);
// 		std::generate(data2.begin(), data2.end(), gen);

// 		// build the corresponding VectorD
// 		VectorD vec1(dim), vec2(dim), vec3(dim);
// 		for(size_t i=0; i<dim; ++i){
// 			vec1[i] = data1[i];
// 			vec2[i] = data2[i];
// 		}

// 		vec3 = vec1 - vec2;
// 		ASSERT_EQ (vec3.size(), dim);

// 		for(size_t i=0; i<dim; ++i){
// 	    	ASSERT_DOUBLE_EQ (vec3[i], data1[i] - data2[i]);  // EXPECT_DOUBLE_EQ would be fine too
// 		}
// 	}
// }

// TEST (VectorDArithmetic, dot) {
// 	const size_t maxSize = 1000;  // max size of the tested vectors
// 	std::mt19937 generator(0);
// 	std::uniform_int_distribution<int> uniformIntDistribution(1,maxSize);
// 	std::uniform_real_distribution<double> uniformDistributionValue(-int(maxSize),maxSize);
// 	auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};

// 	// run many times the same test with different values
// 	for(int run=0; run<100; ++run){

// 		// define a vector dimension
// 		const size_t dim = uniformIntDistribution(generator);

// 		// generate random data
// 		std::vector<double> data1(dim), data2(dim);
// 		std::generate(data1.begin(), data1.end(), gen);
// 		std::generate(data2.begin(), data2.end(), gen);

// 		// build the corresponding VectorD
// 		VectorD vec1(dim), vec2(dim);
// 		for(size_t i=0; i<dim; ++i){
// 			vec1[i] = data1[i];
// 			vec2[i] = data2[i];
// 		}

// 		double result = 0.0;
// 		for(size_t i=0; i<vec1.size(); ++i)
// 			result += vec1[i]*vec2[i];

// 		ASSERT_EQ (result, vec1.dot(vec2));
// 	}
// }

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