#include "HybridVehicle.h"
#include <iostream>
using namespace std;

int main() {
    // 1. Create two HybridVehicle objects with sample data
    HybridVehicle v1("Prius", 120.5, 80.0, 4.5);
    HybridVehicle v2("Volt", 100.0, 90.0, 5.0);

    // Add trips
    v1[0] = 50; v1[1] = 60;
    v2[0] = 70; v2[1] = 40;

    // 2. Display both
    cout << "Vehicle 1: " << v1 << endl;
    cout << "Vehicle 2: " << v2 << endl;

    // 3. Combine vehicles
    HybridVehicle v3 = v1 + v2;
    cout << "Combined Vehicle: " << v3 << endl;

    // 4. Compare efficiency
    cout << "Are v1 and v2 equally efficient? " << (v1 == v2 ? "Yes" : "No") << endl;

    // 5. Simulate new trip
    ++v1;
    cout << "After new trip (v1): " << v1 << endl;

    // 6. Access a trip
    cout << "v2 trip[1] = " << v2[1] << " km" << endl;

    // 7. Get total distance
    cout << "Total distance of v1: " << v1() << " km" << endl;

    // 8. Get efficiency
    cout << "Efficiency of v2: " << float(v2) << " km/L" << endl;

    // 9. Deep copy test
    HybridVehicle v4;
    v4 = v1;
    cout << "Copied Vehicle v4: " << v4 << endl;

    return 0;
}
