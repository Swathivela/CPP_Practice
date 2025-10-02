#include "BatteryMonitor.h"
#include <iostream>
using namespace std;

// Constructor
BatteryMonitor::BatteryMonitor(string id, int cycles, float currCap,
                               float origCap, bool active, int trips)
    : scooterID(id), chargeCycles(cycles),
      batteryCapacity(currCap), originalCapacity(origCap),
      isActive(active), tripCount(trips) 
{
    tripDistances = new int[tripCount]; // allocate memory
    for (int i = 0; i < tripCount; i++) {
        tripDistances[i] = 0; // initialize trips
    }
}

// Copy constructor (deep copy)
BatteryMonitor::BatteryMonitor(const BatteryMonitor& other) {
    scooterID = other.scooterID;
    chargeCycles = other.chargeCycles;
    batteryCapacity = other.batteryCapacity;
    originalCapacity = other.originalCapacity;
    isActive = other.isActive;
    tripCount = other.tripCount;

    tripDistances = new int[tripCount];
    for (int i = 0; i < tripCount; i++) {
        tripDistances[i] = other.tripDistances[i];
    }
}

// Assignment operator (deep copy)
BatteryMonitor& BatteryMonitor::operator=(const BatteryMonitor& other) {
    if (this != &other) { // self-assignment check
        delete[] tripDistances; // clean old memory

        scooterID = other.scooterID;
        chargeCycles = other.chargeCycles;
        batteryCapacity = other.batteryCapacity;
        originalCapacity = other.originalCapacity;
        isActive = other.isActive;
        tripCount = other.tripCount;

        tripDistances = new int[tripCount];
        for (int i = 0; i < tripCount; i++) {
            tripDistances[i] = other.tripDistances[i];
        }
    }
    return *this;
}

// Destructor
BatteryMonitor::~BatteryMonitor() {
    delete[] tripDistances;
}

// Relational operators
bool BatteryMonitor::operator>(const BatteryMonitor& other) const {
    return this->healthRatio() > other.healthRatio();
}
bool BatteryMonitor::operator<(const BatteryMonitor& other) const {
    return this->healthRatio() < other.healthRatio();
}

// += operator
BatteryMonitor& BatteryMonitor::operator+=(int cycles) {
    chargeCycles += cycles;
    batteryCapacity -= (0.01f * cycles); // simulate degradation
    if (batteryCapacity < 0) batteryCapacity = 0;
    return *this;
}

// [] operator
int& BatteryMonitor::operator[](int index) {
    if (index >= 0 && index < tripCount) {
        return tripDistances[index];
    } else {
        throw out_of_range("Trip index out of range");
    }
}

// ! operator
bool BatteryMonitor::operator!() const {
    return !isActive;
}

// << operator
ostream& operator<<(ostream& os, const BatteryMonitor& bm) {
    os << "Scooter ID: " << bm.scooterID
       << " | Charge Cycles: " << bm.chargeCycles
       << " | Battery Health: " << bm.healthRatio() * 100 << "%"
       << " | Status: " << (bm.isActive ? "Active" : "Inactive")
       << " | Trips: ";
    for (int i = 0; i < bm.tripCount; i++) {
        os << bm.tripDistances[i] << " ";
    }
    return os;
}

// Utility
float BatteryMonitor::healthRatio() const {
    return batteryCapacity / originalCapacity;
}
