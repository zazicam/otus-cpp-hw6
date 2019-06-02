//---------------------------------------------------------------------------

#include "mymatrix.cpp"

#include <iostream>
#include <string>
#include <cassert>

int main()
{
/*
	Matrix<int, -1> matrix; 
	assert(matrix.size() == 0); 
	auto a = matrix[0][0];
	assert(a == -1);
	assert(matrix.size() == 0);
	matrix[100][100] = 3;
	matrix[100][100] = -1;
	matrix[100][100] = 314;
	assert(matrix[100][100] == 314);
	assert(matrix.size() == 1);

	for(auto c: matrix){
		int x;
		int y;
		int v;
		std::tie(x, y, v) = c;
		std::cout << x << y << v << std::endl;
	}

	matrix[0][0] = 1;
	matrix[0][0] = 2;
	((matrix[0][1] = 3)=5)=6;
	matrix[0][2] = 4;

	for(auto c: matrix){
		int x;
		int y;
		int v;
		std::tie(x, y, v) = c;
		std::cout << x << y << v << std::endl;
	}
*/


	Matrix<int, 0> matrix;
	for (int i = 0; i < 10; i++) {
		matrix[i][i]=i;
		matrix[i][9-i]=i;
	}
	for (int i = 1; i <= 8; i++) {
		for (int j = 1; j <= 8; j++) {
			std::cout<<matrix[i][j]<<" ";
		}
		std::cout<<std::endl;
	}

	std::cout<<matrix.size()<<std::endl;	

	for(auto c: matrix){
		int x;
		int y;
		int v;
		std::tie(x, y, v) = c;
		std::cout << x <<" " << y <<" "<< v << std::endl;
	}

}
