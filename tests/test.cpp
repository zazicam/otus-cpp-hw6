#include "gtest/gtest.h"
#include "sstream"

#include "../mymatrix.hpp"

TEST(mt1, test1)
{
	Matrix<int, -1> matrix; 
	ASSERT_EQ(matrix.size(), 0); 
}

TEST(mt2, test1)
{
	Matrix<int, -1> matrix; 
	auto a = matrix[0][0];
	ASSERT_EQ(a, -1);
	ASSERT_EQ(matrix.size(), 0);
}

TEST(mt3, test1)
{
	Matrix<int, -1> matrix; 
	matrix[100][100] = 3;
	matrix[100][100] = -1;
	matrix[100][100] = 314;
	ASSERT_EQ(matrix[100][100], 314);
	ASSERT_EQ(matrix.size(), 1);
}


TEST(mt4, test1)
{
	Matrix<int, -1> matrix; 
	matrix[100][100] = 3;
	matrix[100][100] = -1;
	matrix[100][100] = 314;
	std::stringstream ss;
	for(auto c: matrix){
		int x;
		int y;
		int v;
		std::tie(x, y, v) = c;
		ss << x << y << v << " ";
	}
	ASSERT_TRUE(ss.str()=="100100314 ");
}

TEST(mt5, test1)
{
	Matrix<int, -1> matrix; 
	matrix[0][0] = 1;
	matrix[0][0] = 2;
	((matrix[0][1] = 3)=5)=6;
	matrix[0][2] = 4;

	std::stringstream ss;
	for(auto c: matrix){
		int x;
		int y;
		int v;
		std::tie(x, y, v) = c;
		ss << x << y << v << " ";
	} 
	ASSERT_TRUE(ss.str()=="002 016 024 ");
}

TEST(mt6, test1)
{
	Matrix<int, 0> matrix; 
	matrix[0][0] = 1;
	matrix[0][1] = 2;
	matrix[0][2] = 4;
	matrix[0][0] = 0;

	ASSERT_TRUE(matrix.size()==2);
}

