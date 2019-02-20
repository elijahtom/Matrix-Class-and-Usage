#ifndef MATRIXCLASS_H
#define MATRIXCLASS_H

#include <cmath>
using namespace std;

class matrix {
	double determinant;
	double matrix_invert[30][30];
	double matrix_trans[30][30];
	void matrix_output(double arr[30][30], int, int);
	void matrix_inverse();
	void matrix_multiply(matrix object);
	void matrix_transpose();
	void scalar_multiple(double);
	double det2x2(int, int, int, int, int, int, int, int);
	void matrix_adder(matrix object);
public:	
	int m, n;
	double matrix_array[30][30];
	double matrix_product[30][30];
	void matrix_loader();
	void matrix_determinant();
	void matrix_ortho();
	void matrix_involutory();
	void matrix_idempotent();
	void multiply_output(matrix object);
	void transpose_output();
	void sum_output(matrix object, int);
	void scalar_input();
	void inverse_output();
};
#endif

