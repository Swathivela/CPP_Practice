//Largest of N Numbers

//Task: First input = COUNT. Then read COUNT numbers, find largest, print it.
#include <iostream>
using namespace std;

int main() {
    int COUNT;  // number of integers to read
    int N;      // current input
    int MAX;    // to track maximum

    cout << "Enter the number of integers: ";
    cin >> COUNT;

    if (COUNT <= 0) {
        cout << "No numbers to process." << endl;
        return 0;
    }

    // Read first number and initialize MAX
    cout << "Enter number 1: ";
    cin >> N;
    MAX = N;

    for (int i = 1; i < COUNT; i++) { // already read first number
        cout << "Enter number " << i + 1 << ": ";
        cin >> N;
        if (N > MAX) {
            MAX = N;
        }
    }

    cout << "Maximum value: " << MAX << endl;

    return 0;
}

