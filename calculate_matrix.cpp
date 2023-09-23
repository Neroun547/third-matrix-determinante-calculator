#include <iostream>

double calculateDoubleMatrixDeterminante(double (*numbers)[2]);
double calculateTripleMatrixDeterminante(double (*numbers)[3]);


int main() {
	double matrix[3][3];


	std::cout << "Write first matrix row: ";
	std::cin >> matrix[0][0] >> matrix[0][1] >> matrix[0][2];

	std::cout << "Write second matrix row: ";
	std::cin >> matrix[1][0] >> matrix[1][1] >> matrix[1][2];

	
	std::cout << "Write third  matrix row: ";
        std::cin >> matrix[2][0] >> matrix[2][1] >> matrix[2][2];

	double result = calculateTripleMatrixDeterminante(matrix);
	
	std::cout << result << std::endl;

	return 0;	
}

double calculateDoubleMatrixDeterminante(double (*numbers)[2]) {
	return (numbers[0][0] * numbers[1][1]) - (numbers[0][1] * numbers[1][0]);
}

double calculateTripleMatrixDeterminante(double (*numbers)[3]) {
	double matrix1[2][2] = {
		{ numbers[1][1], numbers[1][2] }, 
		{ numbers[2][1], numbers[2][2] }
	};
	double matrix2[2][2] = {
		{ numbers[1][0], numbers[1][2] },
		{ numbers[2][0], numbers[2][2] }
	};
	double matrix3[2][2] = {
		{ numbers[1][0], numbers[1][1] },
		{ numbers[2][0], numbers[2][1] }
	};
	return (numbers[0][0] * calculateDoubleMatrixDeterminante(matrix1)) - (numbers[0][1] * calculateDoubleMatrixDeterminante(matrix2)) + (numbers[0][2] * calculateDoubleMatrixDeterminante(matrix3)); 
}


