#include <gtest/gtest.h>

// #include <random>
#include <vector>
#include <string>
#include <algorithm>

#include <ctime>
#include <cstdlib>

#include "Ratio.hpp"
#include "Variables.hpp"
#include "../include/side_functions.hpp"

/////////////////////////////////////////////////////
// constructors

TEST (RatioConstructor, defaultConstructor) { 
	std::srand(std::time(nullptr)); // use current time as seed for random generator

	// generate random data
    int numerator = std::rand();
    unsigned int denominator = std::rand();

	// build the corresponding VectorD
	Ratio r(numerator, denominator);

    // check if basic ratio PGCD is 1
	ASSERT_EQ (r.getPGCD(), 1);
}

TEST (RatioConstructor, copyConstructor) {    
    std::srand(std::time(nullptr)); // use current time as seed for random generator

	// generate random data
    int numerator = std::rand();
    unsigned int denominator = std::rand();

	// build the corresponding VectorD
	Ratio r(numerator, denominator);

    Ratio rCopy(r);
	ASSERT_EQ (r.getDenominator(), rCopy.getDenominator());
	ASSERT_EQ (r.getNumerator(), rCopy.getNumerator());
}

/////////////////////////////////////////////////////
// variables

TEST (RatioVariables, zeroVar) { 
    // check if basic ratio numerator
	ASSERT_EQ (zeroRatio.getNumerator(), 0);
    // check if basic ratio denominator
	ASSERT_EQ (zeroRatio.getDenominator(), 1);
}

TEST (RatioVariables, infiniteVar) { 
    // check if basic ratio numerator
	ASSERT_EQ (infRatio.getNumerator(), 1);
    // check if basic ratio denominator
	ASSERT_EQ (infRatio.getDenominator(), 0);
}

/////////////////////////////////////////////////////
// informations

// NOTE : this test doesn't seem really useful but we have the method
TEST (RatioInformation, pgcd){
	// run many times the same test with different values
	for(int run=0; run<100; ++run){

		std::srand(std::time(nullptr)); // use current time as seed for random generator

        // generate random data
        int numerator = std::rand();
        unsigned int denominator = std::rand();

		// build the corresponding Ratio
		Ratio r(numerator, denominator);

		ASSERT_EQ (r.getPGCD(), gcd(r.getNumerator(),r.getDenominator()));
	}
}

TEST (RatioInformation, irreductible){
	// run many times the same test with different values
	for(int run=0; run<100; ++run){

		std::srand(std::time(nullptr)); // use current time as seed for random generator

        // generate random data
        int numerator = std::rand();
        unsigned int denominator = std::rand();

		// build the corresponding Ratio
		Ratio r(numerator, denominator);

        int pgcd = r.getPGCD();

        if(pgcd =! 1){
            r.convertToIrreductible(pgcd);
        }

		ASSERT_EQ (r.getPGCD(), 1);
	}
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