#include <iostream>
#include <cmath>
using namespace std;

#include "MATRIXCLASS.h"

void matrix::matrix_output(double arr[30][30], int a = 0, int b = 0) {
	
	if (a == 0 && b == 0) {  //Different a,b cases in order to condense every output to this function 
		a = n;                //Base case
		b = m;
	}
	
	if (a != 0 && b == 0) {  //Multiplication case
		b = m;
	}

	if (a == 1 && b == 1) { //Transpose case
		a = m;
		b = n;
	}

	cout << endl;
	for (int i = 0; i < b; ++i) {  //Output structure
		for (int j = 0; j < a; ++j) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl << endl; //formatting
}

void matrix::scalar_input() { //Prompts for scalar, passes it to scalar_multiple and then to the output function
	double multiple = 0;
	
	cout << "Multiply the matrix by what number?" << endl;
	cin >> multiple;
	
	scalar_multiple(multiple);
	
	cout << endl << "The resultant matrix is: " << endl << endl;
	
	matrix_output(matrix_array);
}

void matrix::scalar_multiple(double multiple) { //Base function for scalar multiplication
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			matrix_array[i][j] = multiple * matrix_array[i][j];
		}
	}
}

void matrix::matrix_involutory() { //Checks for the matrix being involutory
	int count = 0;
	
	matrix_multiply(*this);
	
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (matrix_product[i][j] == 0 && i != j) { //I found it easier to just simply compare diagonal and nondiagonal elements instead of generating an nxn identity matrix
				++count;
			}
			if (matrix_product[i][j] == 1 && i == j) {
				++count;
			}
		}
	}
	if (count == m * n) {    //If all of the matrix elements match, success
		cout << "Involutory matrix." << endl;
	}
	else {
		cout << "Non-involutory matrix." << endl;
	}
}

void matrix::matrix_idempotent() { //checks for idempotency
	int count = 0;
	matrix_multiply(*this); //used *this to self reference the object in order to square it
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {

			if (matrix_product[i][j] == matrix_array[i][j]) { //Compares the products
				++count;
			}

		}
	}
	if (count == m * n) {    //If all of the matrix elements match, success
		cout << "Idempotent matrix." << endl;
	}
	else {
		cout << "Non-idempotent matrix." << endl;
	}
}

double matrix::det2x2(int a, int b, int c, int d, int e, int f, int g, int h) { //Simplifies determinant and inverse calculations by lessening the amount I have to type
	return (matrix_array[a][b] * matrix_array[g][h] - matrix_array[c][d] * matrix_array[e][f]);
}

void matrix::matrix_loader() {	 //Simple matrix loader
	cout << "What are the dimensions of your matrix?" << endl;
	cout << "M:";
	cin >> m;
	cout << "N:";
	cin >> n;

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << "Value " << (i*n + j + 1) << ":";
			cin >> matrix_array[i][j];
		}
	}
	cout << "Your matrix is:" << endl;
	
	matrix_output(matrix_array);
}

void matrix::inverse_output() {
	if (m != n) {
		cout << "Error: M and N must be equal." << endl;
		return;
	}
	if (m == 2) {
		determinant = det2x2(0, 0, 0, 1, 1, 0, 1, 1); //Pre calculates the determinant in order to prevent invalid outputs (if not, two contradictory messages could be printed)
		if (determinant) {
			cout << "The inverted matrix is: " << endl;
			matrix_inverse();
			matrix_output(matrix_invert);
		}
	}
	if (m == 3) {
		determinant = matrix_array[0][0] * det2x2(1, 1, 1, 2, 2, 1, 2, 2) - matrix_array[0][1] * det2x2(1, 0, 1, 2, 2, 0, 2, 2) + matrix_array[0][2] * det2x2(1, 0, 1, 1, 2, 0, 2, 1);
		if (determinant) {
			cout << "The inverted matrix is: " << endl;
			matrix_inverse();
			matrix_output(matrix_invert); 
		}
	}
	if (m > 4) {
		cout << "Error: Inverse calculator allows up to 3x3 matrices." << endl;
		return;
	}
	if (determinant == 0) {
		cout << "Error: Singular matrix." << endl;
	}
}

void matrix::matrix_inverse() { //Works
	if (m != n) {
		cout << "Error: M and N must be equal." << endl; //Reduncant error messages 
		return;
	}

	if (m == n) {
		if (m == 2) {
			determinant = det2x2(0, 0, 0, 1, 1, 0, 1, 1);   
			if (determinant) {
				matrix_invert[0][0] = (matrix_array[1][1]) / determinant;
				matrix_invert[0][1] = -1 * matrix_array[0][1] / determinant;
				matrix_invert[1][0] = -1 * matrix_array[1][0] / determinant;
				matrix_invert[1][1] = matrix_array[0][0] / determinant;
			}
		}
		if (m == 3) {

			determinant = matrix_array[0][0] * det2x2(1, 1, 1, 2, 2, 1, 2, 2) - matrix_array[0][1] * det2x2(1, 0, 1, 2, 2, 0, 2, 2) + matrix_array[0][2] * det2x2(1, 0, 1, 1, 2, 0, 2, 1);
			if (determinant) {
				matrix_invert[0][0] = det2x2(1, 1, 1, 2, 2, 1, 2, 2) / determinant;
				matrix_invert[0][1] = det2x2(0, 2, 0, 1, 2, 2, 2, 1) / determinant;
				matrix_invert[0][2] = det2x2(0, 1, 0, 2, 1, 1, 1, 2) / determinant;
				matrix_invert[1][0] = det2x2(1, 2, 1, 0, 2, 2, 2, 0) / determinant;
				matrix_invert[1][1] = det2x2(0, 0, 0, 2, 2, 0, 2, 2) / determinant;
				matrix_invert[1][2] = det2x2(0, 2, 0, 0, 1, 2, 1, 0) / determinant;
				matrix_invert[2][0] = det2x2(1, 0, 1, 1, 2, 0, 2, 1) / determinant; //I am currently playing with K maps (with i,j as inputs and one of the det inputs as an output) in order to reduce this structure into a for loop
				matrix_invert[2][1] = det2x2(0, 1, 0, 0, 2, 1, 2, 0) / determinant;
				matrix_invert[2][2] = det2x2(0, 0, 0, 1, 1, 0, 1, 1) / determinant;
			}
		}
		if (m > 4) {
			cout << "Error: Inverse calculator allows up to 3x3 matrices." << endl;
			return;
		}

	}

	if (determinant == 0) {
		cout << "Error: Singular matrix." << endl;  //Checks for singularity
	}
}

void matrix::transpose_output() { // Outputs transpose
	cout << "The transpose of your matrix is: " << endl << endl;
	matrix_transpose();
	matrix_output(matrix_trans,1,1);
}

void matrix::matrix_transpose() { //inner transpose array
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			matrix_trans[i][j] = matrix_array[j][i];
		}
	}
}

void matrix::matrix_adder(matrix object) { //Sums input arrays
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << matrix_array[i][j] + object.matrix_array[i][j] << " ";
		}
		cout << endl;
	}
}

void matrix::matrix_ortho() { // Checks orthogonality
	int count = 0;
	matrix_transpose(); //Establishes both matrices without output
	matrix_inverse();
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (abs(matrix_trans[i][j]) < abs(1.05*matrix_invert[i][j]) && abs(matrix_trans[i][j]) >= abs(.95*matrix_invert[i][j])) { //Due to the propagation of errors and the nature of orthogonal matrices to have irrationl components 
				++count;
			}
		}
	}
	cout << count << endl;

	if (count == m * n) {
		cout << "This matrix is orthogonal." << endl;
	}
	else {
		cout << "This matrix is not orthogonal." << endl;
	}
}

void matrix::sum_output(matrix object, int a) { 
	if (m == object.m && n == object.n){ //Checks for matching dimensions
		if (!a) {
			cout << "The difference of these matrices is: " << endl << endl;
			object.scalar_multiple(-1); //If subtraction option is chosen, multiplies the second array by negative 1 and adds them. This is done to reduce code redundancu
			matrix_adder(object);
		}
		if (a) {
			cout << "The sum of these matrices is: " << endl << endl;
			matrix_adder(object);
		}
	}
	else {
		cout << "Error: Dimension mismatch." << endl;
	}
}

void matrix::matrix_determinant() {
	determinant = 0; //Uses hard coded methods to calculate the determinants of 2x2 and 3x3 matrices. I am currently looking into linear algebra theory to find a more generalized way to do this, but i also recognize that above 3x3 is hardly necessitated
	if (m == n) {
		if (m == 2) {
			cout << "The determinant of your matrix is: ";
			determinant = det2x2(0, 0, 0, 1, 1, 0, 1, 1);
			cout << determinant << endl;
		}
		if (m == 3) {
			determinant = matrix_array[0][0] * det2x2(1, 1, 1, 2, 2, 1, 2, 2) - matrix_array[0][1] * det2x2(1, 0, 1, 2, 2, 0, 2, 2) + matrix_array[0][2] * det2x2(1, 0, 1, 1, 2, 0, 2, 1);
			cout << "The determinant of your matrix is: ";
			cout << determinant << endl;
		}
		if (m > 4) {
			cout << "Error: Determinant calculator allows up to 3x3 matrices." << endl;
		}
	}
	else {
		cout << "Error: M and N must be equal." << endl;
	}
}

void matrix::multiply_output(matrix object) {

	if (n == object.m) { //Output function if matrix multiplication is explicitly selected
		cout << "The product of these matrices is: " << endl << endl;
		matrix_multiply(object);
		matrix_output(matrix_product, object.n);
	}
	else {
		cout << "Error: Dimension mismatch." << endl;
		return;
	}
}

void matrix::matrix_multiply(matrix object) { //inner multiplication function
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			matrix_product[i][j] = 0; //initializes the product matrix
		}
	}
	if (n == object.m) { //checks for matrix multiplication conditional 
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < object.n; ++j) {
				for (int k = 0; k < n; ++k) {
					matrix_product[i][j] += matrix_array[i][k] * object.matrix_array[k][j];  //algorithmically determines the product matrix
				}
			}
		}
	}
	else {
		cout << "Error: Dimension mismatch." << endl;
		return;

	}
}
