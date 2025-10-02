#include "HybridVehicle.h"
#include <iomanip>
#include <stdexcept>

// Constructor
HybridVehicle::HybridVehicle(string name, float eKm, float gKm, float gUsed)
    : modelName(name), electricKm(eKm), gasolineKm(gKm), gasolineUsed(gUsed), tripCount(0) {
    for (int i = 0; i < 10; i++) trips[i] = 0;
}

// Copy Constructor
HybridVehicle::HybridVehicle(const HybridVehicle& other) {
    modelName = other.modelName;
    electricKm = other.electricKm;
    gasolineKm = other.gasolineKm;
    gasolineUsed = other.gasolineUsed;
    tripCount = other.tripCount;
    for (int i = 0; i < 10; i++) {
        trips[i] = other.trips[i];
    }
}

// Assignment Operator
HybridVehicle& HybridVehicle::operator=(const HybridVehicle& other) {
    if (this != &other) {
        modelName = other.modelName;
        electricKm = other.electricKm;
        gasolineKm = other.gasolineKm;
        gasolineUsed = other.gasolineUsed;
        tripCount = other.tripCount;
        for (int i = 0; i < 10; i++) {
            trips[i] = other.trips[i];
        }
    }
    return *this;
}

// + operator: combine usage
HybridVehicle HybridVehicle::operator+(const HybridVehicle& other) const {
    HybridVehicle result("Combined");
    result.electricKm = this->electricKm + other.electricKm;
    result.gasolineKm = this->gasolineKm + other.gasolineKm;
    result.gasolineUsed = this->gasolineUsed + other.gasolineUsed;

    result.tripCount = min(this->tripCount + other.tripCount, 10);
    for (int i = 0; i < this->tripCount && i < 10; i++)
        result.trips[i] = this->trips[i];
    for (int i = 0; i < other.tripCount && i + this->tripCount < 10; i++)
        result.trips[i + this->tripCount] = other.trips[i];

    return result;
}

// == operator: compare efficiency
bool HybridVehicle::operator==(const HybridVehicle& other) const {
    return float(*this) == float(other);
}

// ++ operator: add dummy trip
HybridVehicle& HybridVehicle::operator++() {
    if (tripCount < 10) {
        trips[tripCount++] = 10; // dummy trip
    }
    return *this;
}

// [] operator: access trip
int& HybridVehicle::operator[](int index) {
    if (index >= 0 && index < 10) {
        if (index >= tripCount) tripCount = index + 1;
        return trips[index];
    }
    throw out_of_range("Invalid trip index");
}

// () operator: total distance
float HybridVehicle::operator()() const {
    return electricKm + gasolineKm;
}

// float() conversion: efficiency
HybridVehicle::operator float() const {
    if (gasolineUsed == 0) return 0.0f;
    return gasolineKm / gasolineUsed;
}

// << operator: print details
ostream& operator<<(ostream& os, const HybridVehicle& v) {
    os << "Model: " << v.modelName
       << " | Electric Km: " << v.electricKm
       << " | Gasoline Km: " << v.gasolineKm
       << " | Fuel Used: " << v.gasolineUsed
       << " | Efficiency: " << fixed << setprecision(2) << float(v) << " km/L"
       << " | Trips: ";
    for (int i = 0; i < v.tripCount; i++) os << v.trips[i] << " ";
    return os;
}
