#ifndef BATTERYMONITOR_H
#define BATTERYMONITOR_H

#include <iostream>
#include <string>

class BatteryMonitor {
private:
    std::string scooterID;
    int chargeCycles;
    float batteryCapacity;      // current capacity in kWh
    float originalCapacity;     // original capacity in kWh
    bool isActive;
    int* tripDistances;         // dynamically allocated array
    int tripCount;

public:
    // Constructor
    BatteryMonitor(std::string id, int cycles, float currCap,
                   float origCap, bool active, int trips);

    // Copy Constructor (deep copy)
    BatteryMonitor(const BatteryMonitor& other);

    // Assignment operator (deep copy with self-assignment check)
    BatteryMonitor& operator=(const BatteryMonitor& other);

    // Destructor
    ~BatteryMonitor();

    // Operator overloads
    bool operator>(const BatteryMonitor& other) const;
    bool operator<(const BatteryMonitor& other) const;
    BatteryMonitor& operator+=(int cycles);
    int& operator[](int index);
    bool operator!() const;
    friend std::ostream& operator<<(std::ostream& os, const BatteryMonitor& bm);

    // Utility
    float healthRatio() const;   // current/original capacity
};

#endif
