/*For greater control over how an array can be used, we can create an array class. Design a class named Array with the data members capacity, size, and arr (a pointer that points to the first element of the array in the heap). Also design a member function named insert that adds elements to the end of the array, and 
a function named print that prints the element of the array. Test your program with different lists of array elements. */
#include <iostream>
using namespace std;
class Array{
    private:
           int capacity;
           int size;
           int* arr;
           void resize(){
            // Double the capacity if size exceeds current capacity
            capacity *= 2;
            int* newArr = new int[capacity];
            for(int i = 0; i < size; ++i){
                newArr[i] = arr[i];
            }
            delete[] arr;
            arr = newArr;
           }
    public:
          // Constructor
          Array(int initCapacity = 10) : capacity(initCapacity), size(0) {
            arr = new int[capacity];
          }
          // Destructor
          ~Array(){
            delete[] arr;
          }
          // Inserting element at the end of the array
          void insert(int element){
            if(size ==  capacity){
                resize();
            }
            arr[size++] = element;
          }
          // Printing elements of the array
          void print() const {
            for(int i = 0; i < size; ++i){
                cout << arr[i] << " ";
            }
            cout << endl;
          }
          // Getting the current size of the array
          int getSize() const {
            return size;
          }
          // Getting the current capacity of the array
          int getCapacity() const {
            return capacity;
          }
};


int main(){
    Array arr;
    // Testing with different lists of array elements
    arr.insert(1);
    arr.insert(2);
    arr.insert(3);
    arr.print();
    arr.insert(4);
    arr.insert(5);
    arr.insert(6);
    arr.print();
    arr.insert(7);
    arr.insert(8);
    arr.insert(9);
    arr.insert(10);
    arr.insert(11);
    arr.print();
    cout << "Size: " << arr.getSize() << endl;
    cout << "Capacity: " << arr.getCapacity() << endl;
    return 0;
}