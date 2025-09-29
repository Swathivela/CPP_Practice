float number1 = 7.3, number2;
char* ptr;
char s1[100] = "Hello", s2[100] = "World";
a) Declare fPtr as a pointer to double

double* fPtr;

b) Assign the address of number1 to fPtr
(since number1 is float, we need cast to double* to match type)

fPtr = (double*)&number1;
c) Print the value of the object pointed to by fPtr

cout << *fPtr << endl;
d) Assign the value of the object pointed to by fPtr to number2

number2 = *fPtr;
e) Print the value of number2

cout << number2 << endl;
f) Print the address of number1
cout << &number1 << endl;
g) Print the address stored in fPtr

cout << fPtr << endl;