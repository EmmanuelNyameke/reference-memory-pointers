/*In object-oriented programming, we can always create a class for the problem to be solved and let the user instantiate objects from the class and use them. Define a class that creates a multiplication table of any size up to 10. Then use an application program to instantiate any multiplication table.*/
// Interface file
#ifndef MULTIPLICATION_H
#define MULTIPLICATION_H
#include <iostream>
using namespace std;
class Multiplication {
    private:
           int size;
           void printRow(int row) const;
    public:
          Multiplication(int size);
          void displayTable() const;
};
#endif