#include <iostream>
#include <array>
using namespace std;

const size_t arraySize{5};

// Recursive function to print the array
void printArray(const array<int, arraySize>& arr, size_t start, size_t end) {
    // Base case: stop when start equals end
    if (start == end) {
        return;
    }
    // Print current element
    cout << arr[start] << " ";

    // Recursive call to process the next element
    printArray(arr, start + 1, end);
}

int main() {
    array<int, arraySize> data{10, 20, 30, 40, 50};

    cout << "Array elements: ";
    printArray(data, 0, data.size()); // print from index 0 to size
    cout << endl;

    return 0;
}
