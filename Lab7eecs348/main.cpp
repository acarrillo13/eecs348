#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdexcept>

using namespace std;

class Matrix {
public:
    int matrix_size;
    double** matrix_data;

    Matrix(int size = 0) : matrix_size(size) {
        matrix_data = new double*[matrix_size];
        for (int i = 0; i < matrix_size; ++i) {
            matrix_data[i] = new double[matrix_size];
        }
    }

    Matrix& operator=(const Matrix& other) {
        if (this == &other) {
            return *this;
        }

        for (int i = 0; i < matrix_size; ++i) {
            delete[] matrix_data[i];
        }
        delete[] matrix_data;

        matrix_size = other.matrix_size;

        matrix_data = new double*[matrix_size];
        for (int i = 0; i < matrix_size; ++i) {
            matrix_data[i] = new double[matrix_size];
            for (int j = 0; j < matrix_size; ++j) {
                matrix_data[i][j] = other.matrix_data[i][j];
            }
        }

        return *this;
    }

    ~Matrix() {
        for (int i = 0; i < matrix_size; ++i) {
            delete[] matrix_data[i];
        }
        delete[] matrix_data;
    }
};

void read_matrix_from_file(const string& file_name, Matrix& matrix_1, Matrix& matrix_2) {
    ifstream file(file_name);
    if (!file) { //check valid file
        throw runtime_error("File could not be opened.");
    }
    
    int size;
    file >> size; // read first line
    matrix_1 = Matrix(size); // initialize both matrices
    matrix_2 = Matrix(size);

    // Read data for the first matrix
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            file >> matrix_1.matrix_data[i][j];
        }
    }

    // Read data for the second matrix
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            file >> matrix_2.matrix_data[i][j];
        }
    }

    file.close();
}

void print_matrix(const Matrix& matrix) { //basic print for matrix
    for (int i = 0; i < matrix.matrix_size; ++i) {
        for (int j = 0; j < matrix.matrix_size; ++j) {
            cout << setw(8) << matrix.matrix_data[i][j] << " ";
        }
        cout << endl;
    }
}

Matrix add_matrices(const Matrix& matrix_1, const Matrix& matrix_2) { //adds two matrices
    Matrix result(matrix_1.matrix_size);
    for (int i = 0; i < matrix_1.matrix_size; ++i) {
        for (int j = 0; j < matrix_1.matrix_size; ++j) {
            result.matrix_data[i][j] = matrix_1.matrix_data[i][j] + matrix_2.matrix_data[i][j];
        }
    }
    return result;
}

Matrix multiply_matrices(const Matrix& matrix_1, const Matrix& matrix_2) {//multiply's each index of the matrices and then returns a matrix
    Matrix result(matrix_1.matrix_size);
    for (int i = 0; i < matrix_1.matrix_size; ++i) {
        for (int j = 0; j < matrix_1.matrix_size; ++j) {
            result.matrix_data[i][j] = 0;
            for (int k = 0; k < matrix_1.matrix_size; ++k) {
                result.matrix_data[i][j] += matrix_1.matrix_data[i][k] * matrix_2.matrix_data[k][j];
            }
        }
    }
    return result;
}

Matrix operator+(const Matrix& matrix_1, const Matrix& matrix_2) { //overloads the + operator 
    return add_matrices(matrix_1, matrix_2);
}

Matrix operator*(const Matrix& matrix_1, const Matrix& matrix_2) {//overloads the * operator
    return multiply_matrices(matrix_1, matrix_2);
}

void get_diagonal_sum(const Matrix& matrix) {//sum of 
    double sum = 0;
    for (int i = 0; i < matrix.matrix_size; ++i) {
        sum += matrix.matrix_data[i][i];
    }
    cout << sum << endl;
}

void swap_matrix_row(Matrix& matrix, int row1, int row2) {//swaps the two rows of the inputed matriceies
    if (row1 < 0 || row2 < 0 || row1 >= matrix.matrix_size || row2 >= matrix.matrix_size) {
        cerr << "Invalid row indices" << endl;
        return;
    }
    for (int j = 0; j < matrix.matrix_size; ++j) {
        swap(matrix.matrix_data[row1][j], matrix.matrix_data[row2][j]);
    }
}

int main(int argc, char* argv[]) {
    Matrix matrix_1, matrix_2;
    read_matrix_from_file("matrix.txt", matrix_1, matrix_2);
    
    cout << "Matrix 1:" << endl;
    print_matrix(matrix_1);
    cout << "Matrix 2:" << endl;
    print_matrix(matrix_2);

    cout << "Addition result:" << endl;
    Matrix add_result = matrix_1 + matrix_2;
    print_matrix(add_result);

    cout << "Multiplication result:" << endl;
    Matrix multiply_result = matrix_1 * matrix_2;
    print_matrix(multiply_result);

    cout << "Diagonal sum of Matrix 1:" << endl;
    get_diagonal_sum(matrix_1);

    cout << "Swapping rows 0 and 1 in Matrix 1:" << endl;
    swap_matrix_row(matrix_1, 0, 1);
    print_matrix(matrix_1);
    
    return 0;
}
