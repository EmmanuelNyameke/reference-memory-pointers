// Implementation file
#include "multiplication.h"

Multiplication::Multiplication(int size) : size(size){
    if (size > 10){
        this -> size = 10;
    } else if(size < 1){
        this->size = 1;
    }
}

void Multiplication::displayTable() const {
    for (int i = 1; i <= size; ++i){
        printRow(i);
    }
}

void Multiplication::printRow(int row) const{
    for (int j = 1; j <= size; ++j){
        cout << row * j << "\t";
    }
    cout << endl;
}