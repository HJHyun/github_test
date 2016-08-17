// HelloWorld.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include<iostream>
#include <vector>

std::vector<std::vector<std::vector<float>>> create3D(size_t dimX, size_t dimY, size_t dimZ) {
	std::vector< std::vector< std::vector <float>>> array3D;
	array3D.resize(dimX);
	for (int i = 0; i < dimX; i++) {
		array3D[i].resize(dimY);
		for (int j = 0; j < dimY; j++) {
			array3D[i][j].resize(dimZ);
		}
	}
	return array3D;
}

void arr1Dto3D(size_t dimX, size_t dimY, size_t dimZ, std::vector<float> array1D) {
	std::vector< std::vector< std::vector <float>>> array3D = create3D(dimX, dimY, dimZ);
	for (int i = 0; i < dimX; i++) {
		for (int j = 0; j < dimY; j++) {
			for (int k = 0; k < dimZ; k++) {
				array3D[i][j][k] = array1D[i*dimY*dimZ + j*dimZ + k];
				std::cout << "array[" << i <<"][" << j <<"][" << k << "]: " << array3D[i][j][k] << std::endl;
			}
		}
	}
}


int main()
{
	std::cout << "Hello World" << std::endl;

	/*std::vector <float> array1D(27,0);
	for (int i = 0; i < 27; i++) {
		if (i < 9) { array1D[i] = i + 1; }
		else if (i < 18) { array1D[i] = i + 2; }
		else { array1D[i] = i + 3; }
	}*/

	std::vector <float> array1D(6, 0);
	for (int i = 0; i < 6; i++) {
		array1D[i] = i + 1;
	}

	arr1Dto3D(2, 1, 3, array1D);
	arr1Dto3D(1, 2, 3, array1D);

    return 0;
}

