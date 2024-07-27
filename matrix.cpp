// Implementation file
/* We have implemented all member functions declared in the interface file.
*/
#include "matrix.h"
// Constructor: creates a matrix in the heap
Matrix::Matrix(int r, int c):rowSize(r), colSize(c){
    ptr = new int* [rowSize];
    for(int i = 0; i < rowSize; i++){
        ptr[i] = new int [colSize];
    }
}

// Destructor: deletes memory locations in the heap
Matrix::~Matrix(){
    for (int i = 0; i < rowSize; i++){
        delete [] ptr[i];
    }
}

// The setup fills the cells with random values between 1 and 5.
void Matrix::setup(){
    for(int i = 0; i < rowSize; i++){
        for(int j = 0; j < colSize; j++){
            ptr[i][j] = rand() % 5 + 1;
        }
    }
}

// The add function adds second to the host and creates result
void Matrix::add(const Matrix& second, Matrix& result) const {
    assert(second.rowSize == rowSize && second.colSize == colSize);
    assert(result.rowSize == rowSize && result.colSize == colSize);
    for(int i = 0; i < rowSize; i++){
        for (int j = 0; j < second.colSize; j++){
            result.ptr[i][j] = ptr[i][j] + second.ptr[i][j];
        }
    }
}

// The subtract function subtracts second from host.
void Matrix::subtract(const Matrix& second, Matrix& result) const {
    assert(second.rowSize == rowSize && second.colSize == colSize);
    assert(result.rowSize == rowSize && result.colSize == colSize);
    for(int i = 0; i < rowSize; i++){
        for(int j = 0; j < second.colSize; j++){
            result.ptr[i][j] = ptr[i][j] + second.ptr[i][j];
        }
    }
}

// The multiply function multiplies second by host.
void Matrix::multiply(const Matrix& second, Matrix& result) const {
    assert(colSize == second.rowSize);
    assert(result.rowSize == rowSize);
    assert(result.colSize == second.colSize);
    for(int i = 0; i < rowSize; i++){
        for(int j = 0; j < second.colSize; j++){
            result.ptr[i][j] = 0;
            for(int k = 0; k < colSize; k++){
                result.ptr[i][j] += ptr[i][k] * second.ptr[j][k]; 
            }
        }
    }
}

// The print function prints the values of cells.
void Matrix::print() const {
    for (int i = 0; i < rowSize; i++){
        for (int j = 0; j < colSize; i++){
            cout << setw(5) << ptr[i][j];
        }
        cout << endl;
    }
    cout << endl;
}