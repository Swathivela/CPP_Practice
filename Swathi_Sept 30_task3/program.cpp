#include <iostream>
using namespace std;

int main() {
    // =========================
    // Exercise: Array and Pointer
    // =========================

    // a) Declare an array
    const int SIZE = 5;
    unsigned int values[SIZE] = {2, 4, 6, 8, 10};

    // b) Declare a pointer
    unsigned int *vPtr;

    // d) Assign array address to pointer (two ways)
    vPtr = values;       // array name as address
    // vPtr = &values[0]; // equivalent

    // c) Print with array subscript notation
    cout << "Array subscript notation: ";
    for (int i = 0; i < SIZE; i++)
        cout << values[i] << " ";
    cout << endl;

    // e) Print using pointer/offset notation with pointer
    cout << "Pointer/offset notation with pointer: ";
    for (int i = 0; i < SIZE; i++)
        cout << *(vPtr + i) << " ";
    cout << endl;

    // f) Print using pointer/offset notation with array name
    cout << "Pointer/offset notation with array name: ";
    for (int i = 0; i < SIZE; i++)
        cout << *(values + i) << " ";
    cout << endl;

    // g) Print using pointer subscript notation
    cout << "Pointer subscript notation: ";
    for (int i = 0; i < SIZE; i++)
        cout << vPtr[i] << " ";
    cout << endl;

    // h) Refer to the fifth element
    cout << "Fifth element using different methods:" << endl;
    cout << "Array subscript: " << values[4] << endl;
    cout << "Pointer/offset with array name: " << *(values + 4) << endl;
    cout << "Pointer subscript: " << vPtr[4] << endl;
    cout << "Pointer/offset with pointer variable: " << *(vPtr + 4) << endl;

    // i) Address vPtr + 3
    cout << "Address of vPtr + 3 (simulated): 1002506" << endl;
    cout << "Value at that location: " << values[3] << endl;

    // j) If vPtr points to values[4], then vPtr -= 4
    vPtr = &values[4]; // point to fifth element
    vPtr -= 4;         // move back 4 elements → points to values[0]
    cout << "After vPtr -= 4:" << endl;
    cout << "New address (simulated): 1002500" << endl;
    cout << "Value at that location: " << *vPtr << endl;

    return 0;
}
