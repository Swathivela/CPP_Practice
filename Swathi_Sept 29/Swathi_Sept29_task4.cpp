#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>
using namespace std;

// Function prototypes
void moveTortoise(int* pos);
void moveHare(int* pos);
void printRace(const int& tortoisePos, const int& harePos);

int main() {
    srand(static_cast<unsigned>(time(0)));

    int tortoisePos = 1;
    int harePos = 1;

    cout << "BANG !!!!!\n";
    cout << "AND THEY'RE OFF !!!!!\n";

    // Race loop
    while (true) {
        moveTortoise(&tortoisePos);
        moveHare(&harePos);

        // Clamp positions to >= 1
        if (tortoisePos < 1) tortoisePos = 1;
        if (harePos < 1) harePos = 1;

        // Print race track
        printRace(tortoisePos, harePos);

        // Check for winner
        if (tortoisePos >= 70 && harePos >= 70) {
            cout << "\nIt's a tie. (But favor the Tortoise!)\n";
            break;
        }
        else if (tortoisePos >= 70) {
            cout << "\nTORTOISE WINS!!! YAY!!!\n";
            break;
        }
        else if (harePos >= 70) {
            cout << "\nHare wins. Yuch.\n";
            break;
        }

        // Delay to simulate real-time race
        this_thread::sleep_for(chrono::milliseconds(300));
    }

    return 0;
}

// Move Tortoise according to rules
void moveTortoise(int* pos) {
    int i = rand() % 10 + 1; // random [1,10]
    if (i >= 1 && i <= 5)       *pos += 3;   // Fast plod
    else if (i == 6 || i == 7)  *pos -= 6;   // Slip
    else                        *pos += 1;   // Slow plod
}

// Move Hare according to rules
void moveHare(int* pos) {
    int i = rand() % 10 + 1; // random [1,10]
    if (i == 1 || i == 2)           *pos += 0;   // Sleep
    else if (i == 3 || i == 4)      *pos += 9;   // Big hop
    else if (i == 5)                *pos -= 12;  // Big slip
    else if (i >= 6 && i <= 8)      *pos += 1;   // Small hop
    else                            *pos -= 2;   // Small slip
}

// Print race track
void printRace(const int& tortoisePos, const int& harePos) {
    for (int i = 1; i <= 70; i++) {
        if (i == tortoisePos && i == harePos) {
            cout << "OUCH!!!";
            i += 5; // Skip ahead since OUCH!!! takes 6 chars
        }
        else if (i == tortoisePos) {
            cout << "T";
        }
        else if (i == harePos) {
            cout << "H";
        }
        else {
            cout << " ";
        }
    }
    cout << endl;
}
