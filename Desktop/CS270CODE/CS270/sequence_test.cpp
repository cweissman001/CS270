#include "sequence.hpp"
#include <gtest/gtest.h>

/*Write a test program "sequence_test.cpp" that will include the header file.  Without methods implemented yet, you won't be able to do much with it, but writing test cases for the various methods will help you understand their goals better.  Using Google Test, start with writing a test case for creating and checking the size of an empty sequence.  If you've done it correctly, "make testcompile" should report no errors. */

TEST(sequence, constructor){
	sequence();
	EXPECT_EQ("", sequence 1);
}

TEST(sequence, size)
	sequence.size();