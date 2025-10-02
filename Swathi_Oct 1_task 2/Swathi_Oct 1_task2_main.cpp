#include "BatteryMonitor.h"
#include <iostream>
using namespace std;

int main() {
    // 1. Create two BatteryMonitor objects
    BatteryMonitor s1("SCT101", 300, 4.0, 5.0, true, 3); // 80% health
    BatteryMonitor s2("SCT202", 150, 3.5, 5.0, true, 2); // 70% health

    // 2. Populate trips
    s1[0] = 12; s1[1] = 18; s1[2] = 25;
    s2[0] = 10; s2[1] = 15;

    // 3. Display both
    cout << s1 << endl;
    cout << s2 << endl;

    // 4. Compare health
    cout << (s1 > s2 ? "s1 is healthier" : "s2 is healthier") << endl;

    // 5. Simulate 50 cycles degradation
    s1 += 50;
    cout << "After 50 cycles: " << s1 << endl;

    // 6. Check active status
    if (!s1) cout << "s1 is inactive" << endl;
    else cout << "s1 is active" << endl;

    // 7. Deep copy
    BatteryMonitor s3 = s2; // Copy constructor
    cout << "Copied s3 from s2: " << s3 << endl;

    BatteryMonitor s4("Temp", 0, 1.0, 1.0, false, 1);
    s4 = s1; // Assignment operator
    cout << "Assigned s4 from s1: " << s4 << endl;

    // 8. Destructor will be called automatically for all objects

    return 0;
}
