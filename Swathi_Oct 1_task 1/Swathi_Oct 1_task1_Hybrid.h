#ifndef HYBRIDVEHICLE_H
#define HYBRIDVEHICLE_H

#include <iostream>
#include <string>
using namespace std;

class HybridVehicle {
private:
    string modelName;
    float electricKm;
    float gasolineKm;
    float gasolineUsed;
    int trips[10];
    int tripCount;

public:
    // Constructor
    HybridVehicle(string name = "", float eKm = 0, float gKm = 0, float gUsed = 0);

    // Copy Constructor
    HybridVehicle(const HybridVehicle& other);

    // Assignment Operator
    HybridVehicle& operator=(const HybridVehicle& other);

    // Operator Overloads
    HybridVehicle operator+(const HybridVehicle& other) const;
    bool operator==(const HybridVehicle& other) const;
    HybridVehicle& operator++(); // prefix
    int& operator[](int index);
    float operator()() const;
    operator float() const;

    // Friend for stream insertion
    friend ostream& operator<<(ostream& os, const HybridVehicle& v);
};

#endif
