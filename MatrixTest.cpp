#include "gtest/gtest.h"
#include "Matrix.h"
#include "RandomGenerator.h"
#include "IStreamGenerator.h"
#include "ConcreteExercise1.h"
#include "ConcreteExercise2.h"
#include "ConcreteExercise3.h"
#include <sstream>

namespace algebra {


	TEST(GeneratorTest, RandomGeneratorRange) 
	{
		RandomGenerator gen;
		for (int i = 0; i < 10; ++i) {
			int val = gen.generate();
			EXPECT_GE(val, -1000);
			EXPECT_LE(val, 1000);
		}
	}

	TEST(GeneratorTest, IStreamGeneratorReadsCorrectly) 
	{
		std::stringstream ss("10 20 30");
		IStreamGenerator gen(ss);
		EXPECT_EQ(gen.generate(), 10);
		EXPECT_EQ(gen.generate(), 20);
		EXPECT_EQ(gen.generate(), 30);
	}


	TEST(MatrixTest, BasicOperations) 
	{
		Matrix<int> m(3);
		m[0] = 1; m[1] = 2; m[2] = 3;

		EXPECT_EQ(m.getSize(), 3);
		EXPECT_EQ(m[0], 1);
		EXPECT_EQ(m[1], 2);
		EXPECT_EQ(m[2], 3);
	}

	TEST(MatrixTest, CopyAndMove) 
	{
		Matrix<int> m1(2);
		m1[0] = 10; m1[1] = 20;

		Matrix<int> m2 = m1;
		EXPECT_EQ(m2[0], 10);
		EXPECT_EQ(m2[1], 20);

		Matrix<int> m3 = std::move(m1);
		EXPECT_EQ(m3[0], 10);
		EXPECT_EQ(m3[1], 20);
		EXPECT_EQ(m1.getSize(), 0);
	}

	TEST(MatrixTest, OutOfBoundsThrows) 
	{
		Matrix<int> m(2);
		EXPECT_THROW(m[2], std::out_of_range);
		EXPECT_THROW(m[10], std::out_of_range);
	}

	TEST(MatrixTest, FillWorks) {
		Matrix<int> m(5);
		RandomGenerator gen;
		m.fill(gen);

		for (size_t i = 0; i < m.getSize(); ++i) {
			EXPECT_GE(m[i], -1000);
			EXPECT_LE(m[i], 1000);
		}
	}

	TEST(ConcreteExercise1Test, TaskSetsFirstToZeroIfDivisibleBy5) 
	{
		Matrix<int> m(3);
		m[0] = 15; 
		m[1] = 7;
		m[2] = 9;

		RandomGenerator gen;
		ConcreteExercise1<int> ex(m, gen);
		ex.task();

		EXPECT_EQ(ex.getMatrix()[0], 0);
		EXPECT_EQ(ex.getMatrix()[1], 7);
		EXPECT_EQ(ex.getMatrix()[2], 9);
	}

	TEST(ConcreteExercise1Test, TaskNoChangeIfNotDivisibleBy5) 
	{
		Matrix<int> m(3);
		m[0] = 17;  
		m[1] = 7;
		m[2] = 9;

		RandomGenerator gen;
		ConcreteExercise1<int> ex(m, gen);
		ex.task();

		EXPECT_EQ(ex.getMatrix()[0], 17);
	}

	class ConcreteExercise2Test : public ::testing::Test 
	{
	protected:
		void SetUp() override { origCin = std::cin.rdbuf(); }
		void TearDown() override { std::cin.rdbuf(origCin); }
		std::streambuf* origCin;
	};

	TEST_F(ConcreteExercise2Test, TaskAddsKWhenOddAndFirstDigitMatches) 
	{
		std::stringstream mockCin("5\n");
		std::cin.rdbuf(mockCin.rdbuf());

		Matrix<int> m(3);
		m[0] = 51; 
		m[1] = 24;  
		m[2] = 37;  

		RandomGenerator gen;
		ConcreteExercise2<int> ex(m, gen);
		ex.task();

		EXPECT_EQ(ex.getMatrix().getSize(), 4);
		EXPECT_EQ(ex.getMatrix()[1], 5);  
	}

	TEST_F(ConcreteExercise2Test, TaskNoChangeWhenNoMatches) 
	{
		std::stringstream mockCin("9\n");
		std::cin.rdbuf(mockCin.rdbuf());

		Matrix<int> m(2);
		m[0] = 13; 
		m[1] = 24; 

		RandomGenerator gen;
		ConcreteExercise2<int> ex(m, gen);
		ex.task();

		EXPECT_EQ(ex.getMatrix().getSize(), 2);
	}

	TEST(ConcreteExercise3Test, TaskMultipliesByIndexAndZerosEnds) 
	{
		Matrix<int> m(4);
		m[0] = 2;
		m[1] = 3;
		m[2] = 4;
		m[3] = 5;

		RandomGenerator gen;
		ConcreteExercise3<int> ex(m, gen);
		ex.task();

		EXPECT_EQ(ex.getMatrix()[0], 0);   
		EXPECT_EQ(ex.getMatrix()[1], 6);   
		EXPECT_EQ(ex.getMatrix()[2], 12);
		EXPECT_EQ(ex.getMatrix()[3], 0);  
	}

	TEST(ConcreteExercise3Test, TaskSingleElement) 
	{
		Matrix<int> m(1);
		m[0] = 42;

		RandomGenerator gen;
		ConcreteExercise3<int> ex(m, gen);
		ex.task();

		EXPECT_EQ(ex.getMatrix()[0], 0);
	}

	TEST(IntegrationTest, AllExercisesWorkTogether) 
	{
		Matrix<int> m(4);
		m[0] = 10; 
		m[1] = 37; 
		m[2] = 42;  
		m[3] = 8;   

		RandomGenerator gen;

		ConcreteExercise1<int> ex1(m, gen);
		ex1.task();
		EXPECT_EQ(ex1.getMatrix()[0], 0);

		std::stringstream mockCin("3\n");
		std::cin.rdbuf(mockCin.rdbuf());

		ConcreteExercise2<int> ex2(m, gen);
		ex2.task();
		EXPECT_GT(ex2.getMatrix().getSize(), m.getSize());

		ConcreteExercise3<int> ex3(m, gen);
		ex3.task();
		EXPECT_EQ(ex3.getMatrix()[0], 0);
		EXPECT_EQ(ex3.getMatrix()[ex3.getMatrix().getSize() - 1], 0);

		std::cin.rdbuf(origCin);
	}

	TEST(EdgeCasesTest, EmptyMatrix) 
	{
		Matrix<int> m(0);
		RandomGenerator gen;

		ConcreteExercise1<int> ex1(m, gen);
		ConcreteExercise2<int> ex2(m, gen);
		ConcreteExercise3<int> ex3(m, gen);

		EXPECT_NO_THROW(ex1.task());
		EXPECT_NO_THROW(ex2.task());
		EXPECT_NO_THROW(ex3.task());

		EXPECT_EQ(ex1.getMatrix().getSize(), 0);
		EXPECT_EQ(ex2.getMatrix().getSize(), 0);
		EXPECT_EQ(ex3.getMatrix().getSize(), 0);
	}

	TEST(EdgeCasesTest, NegativeNumbers) 
	{
		Matrix<int> m(3);
		m[0] = -25; 
		m[1] = -13;  
		m[2] = -42;  

		RandomGenerator gen;

		ConcreteExercise1<int> ex1(m, gen);
		ex1.task();
		EXPECT_EQ(ex1.getMatrix()[0], 0);

		ConcreteExercise3<int> ex3(m, gen);
		ex3.task();
		EXPECT_EQ(ex3.getMatrix()[0], 0);
		EXPECT_EQ(ex3.getMatrix()[2], 0);
	}

}

int main(int argc, char** argv) 
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();

}
