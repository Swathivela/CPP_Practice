#include <iostream>
#include <array>
using namespace std;

const size_t arraySize{7};

int main() {
    // initialize array with 7 elements
    array<int, arraySize> integers{10, 20, 30, 40, 50, 60, 70};

    cout << "Array elements before modification:\n";
    for (size_t i = 0; i < arraySize; ++i) {
        cout << integers[i] << " ";
    }
    cout << endl;

    // modify elements (multiply each by 2)
    for (size_t i = 0; i < arraySize; ++i) {
        integers[i] *= 2;
    }

    cout << "Array elements after modification:\n";
    for (size_t i = 0; i < arraySize; ++i) {
        cout << integers[i] << " ";
    }
    cout << endl;

    // sum elements
    int total{0};
    for (size_t i = 0; i < arraySize; ++i) {
        total += integers[i];
    }

    cout << "Total of array elements: " << total << endl;

    return 0;
}
