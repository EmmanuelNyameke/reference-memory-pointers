// Application file
#include "multiplication.h"

int main(){
    int size;
    cout << "Enter the size of the multiplication table(up to 10): ";
    cin >> size;
    Multiplication multiplication(size);
    multiplication.displayTable();
    return 0;
}