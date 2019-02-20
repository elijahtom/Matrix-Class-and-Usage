//Elijah Cox, Texas A&M University
#include <iostream>
#include <cmath>
#include "MATRIXCLASS.h"
using namespace std;


int main() { //Establish a usage.cpp
	char choice;
	matrix mat1;
	matrix mat2;
	
	do {
		cout << endl;
		cout << "What would you like to do?" << endl;
		cout << "A - Add two matrices" << endl;
		cout << "S - Subtract two matrices" << endl;
		cout << "C - Multiple a matrix by a scalar" << endl;
		cout << "M - Multiply two matrices" << endl;
		cout << "D - Calculate the determinant of a matrix (limit 3x3)" << endl;
		cout << "T - Transpose a matrix" << endl;
		cout << "I - Calculate the inverse of a matrix (limit 3x3)" << endl;
		cout << "O - Determine if a matrix is orthogonal" << endl;
		cout << "J - Determine if a marix is idempotent" << endl;
		cout << "K - Determine if a matrix is involutary" << endl;
		cout << "Q - Quit" << endl << "Choice: ";
		cin >> choice;
		cout << endl;
		
		switch (choice){
		
		case 'A':
			mat1.matrix_loader();
			mat2.matrix_loader();
			mat1.sum_output(mat2,1);
			break;
		
		case 'S':
			mat1.matrix_loader();
			mat2.matrix_loader();
			mat1.sum_output(mat2,0);
			break;

		case 'C':
			mat1.matrix_loader();
			mat1.scalar_input();
			break;
		
		case 'M':
			mat1.matrix_loader();
			mat2.matrix_loader();
			mat1.multiply_output(mat2);
			break;

		case 'D':
			mat1.matrix_loader();
			mat1.matrix_determinant();
			break;
		
		case 'T':
			mat1.matrix_loader();
			mat1.transpose_output();
			break;

		case 'I':
			mat1.matrix_loader();
			mat1.inverse_output();
			break;

		case 'O':
			mat1.matrix_loader();
			mat1.matrix_ortho();
			break;

		case 'J':
			mat1.matrix_loader();
			mat1.matrix_idempotent();
			break;

		case 'K':
			mat1.matrix_loader();
			mat1.matrix_involutory();
			break;

		default:
			cout << endl;
			break;
		}
	} while (choice != 'Q');
	return 0;
}







