#include <iostream>
#include <string>
using namespace std;

class MotorVehicle {
private:
    string make;
    string fuelType;
    int yearOfManufacture;
    string color;
    int engineCapacity;

public:
    // Constructor
    MotorVehicle(string mk, string fuel, int year, string clr, int capacity) {
        make = mk;
        fuelType = fuel;
        yearOfManufacture = year;
        color = clr;
        engineCapacity = capacity;
    }

    // Setters
    void setMake(string mk) { make = mk; }
    void setFuelType(string fuel) { fuelType = fuel; }
    void setYearOfManufacture(int year) { yearOfManufacture = year; }
    void setColor(string clr) { color = clr; }
    void setEngineCapacity(int capacity) { engineCapacity = capacity; }

    // Getters
    string getMake() const { return make; }
    string getFuelType() const { return fuelType; }
    int getYearOfManufacture() const { return yearOfManufacture; }
    string getColor() const { return color; }
    int getEngineCapacity() const { return engineCapacity; }

    // Display function
    void displayCarDetails() const {
        cout << "Make: " << make << endl;
        cout << "Fuel Type: " << fuelType << endl;
        cout << "Year of Manufacture: " << yearOfManufacture << endl;
        cout << "Color: " << color << endl;
        cout << "Engine Capacity: " << engineCapacity << " cc" << endl;
    }
};

// Test Program
int main() {
    // Create a MotorVehicle object
    MotorVehicle car1("Toyota", "Petrol", 2020, "Red", 1800);

    cout << "Initial Car Details:" << endl;
    car1.displayCarDetails();

    cout << "\nUpdating Car Details...\n" << endl;

    // Update values using setters
    car1.setMake("Honda");
    car1.setFuelType("Diesel");
    car1.setYearOfManufacture(2022);
    car1.setColor("Blue");
    car1.setEngineCapacity(2000);

    // Display updated values
    cout << "Updated Car Details:" << endl;
    car1.displayCarDetails();

    return 0;
}
