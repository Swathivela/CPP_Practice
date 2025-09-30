//Counter-Controlled Average

//Task: Read 7 numbers, compute average, print.
#include <iostream>
using namespace std;

int main() {
    const int TOTAL_NUMBERS = 7; // number of inputs
    int N;                        // input number
    int SUM = 0;                  // initialize sum
    double AVG;                   // average

    cout << "Enter " << TOTAL_NUMBERS << " numbers:" << endl;

    for (int COUNTER = 0; COUNTER < TOTAL_NUMBERS; COUNTER++) {
        cin >> N;        // read number
        SUM += N;        // add to sum
    }

    AVG = static_cast<double>(SUM) / TOTAL_NUMBERS; // calculate average

    cout << "Average: " << AVG << endl;

    return 0;
}

