a) Declare and initialize the array
const int SIZE = 10;
double numbers[SIZE] = {0.0, 1.1, 2.2, 3.3, 4.4,
                        5.5, 6.6, 7.7, 8.8, 9.9};

b) Declare a pointer
double* nPtr;

c) Print elements using array subscript notation
for (int i = 0; i < SIZE; i++) {
    cout << fixed << setprecision(1) << numbers[i] << " ";
}
cout << endl;

d) Assign starting address of array to pointer
nPtr = numbers;        // array name is address of first element
nPtr = &numbers[0];    // equivalent way

e) Print elements using pointer/offset notation with nPtr
for (int i = 0; i < SIZE; i++) {
    cout << fixed << setprecision(1) << *(nPtr + i) << " ";
}
cout << endl;

f) Print elements using pointer/offset notation with array name
for (int i = 0; i < SIZE; i++) {
    cout << fixed << setprecision(1) << *(numbers + i) << " ";
}
cout << endl;

g) Print elements using pointer/subscript notation with nPtr
for (int i = 0; i < SIZE; i++) {
    cout << fixed << setprecision(1) << nPtr[i] << " ";
}
cout << endl;

h) Refer to the 4th element (numbers[3])
numbers[3];        // array subscript notation
*(numbers + 3);    // pointer/offset notation with array name
nPtr[3];           // pointer/subscript notation with nPtr
*(nPtr + 3);       // pointer/offset notation with nPtr

i) nPtr + 8 (nPtr points to beginning)

Each double = 8 bytes.

So nPtr + 8 means 8 elements ahead = address of numbers[8].

📍 Address:

1002500 + (8 * 8) = 1002500 + 64 = 1002564


Value stored: numbers[8] = 8.8.

j) If nPtr = &numbers[5], then nPtr -= 4

&numbers[5] address =

1002500 + (5 * 8) = 1002500 + 40 = 1002540


After nPtr -= 4, it points to numbers[1].

📍 Address:

1002500 + (1 * 8) = 1002508


Value stored: numbers[1] = 1.1.