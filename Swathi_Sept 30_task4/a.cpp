//Sentinel-Controlled Sum

//Task: Keep reading numbers, add positives, stop when a negative is entered, print sum.
#include <iostream>
using namespace std;

int main() {
    int N;      // Input number
    int SUM = 0; // Initialize sum to 0

    cout << "Enter numbers to sum (enter a negative number to stop):" << endl;

    while (true) {
        cin >> N;            // Read N
        if (N < 0) break;    // If N is negative, end loop
        SUM += N;            // Add N to SUM
    }

    cout << "The sum is: " << SUM << endl;

    return 0;
}

