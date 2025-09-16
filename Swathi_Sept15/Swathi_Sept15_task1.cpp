#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

class FleetVehicle {
private:
    int vehicleID;
    float fuelLevel;
    double distanceTravelled;
    char status;        
    bool isAvailable;
    string driverName;

public:
    FleetVehicle()
        : vehicleID(0), fuelLevel(50.0), distanceTravelled(0.0),
          status('A'), isAvailable(true), driverName("Unassigned") {}

    
    FleetVehicle(int id, float fuel, double dist, char stat, bool avail, string driver)
        : vehicleID(id), fuelLevel(fuel), distanceTravelled(dist),
          status(stat), isAvailable(avail), driverName(driver) {}

    FleetVehicle() {
        cout << "Destructor called for vehicle ID: " << vehicleID << endl;
    }

    int getVehicleID() const { return vehicleID; }
    float getFuelLevel() const { return fuelLevel; }
    double getDistanceTravelled() const { return distanceTravelled; }
    char getStatus() const { return status; }
    bool getAvailability() const { return isAvailable; }
    string getDriverName() const { return driverName; }

    void setVehicleID(int id) { vehicleID = id; }
    void setFuelLevel(float fuel) { fuelLevel = fuel; }
    void setDistanceTravelled(double dist) { distanceTravelled = dist; }
    void setStatus(char stat) { status = stat; }
    void setAvailability(bool avail) { isAvailable = avail; }
    void setDriverName(string name) { driverName = name; }

    void updateStatus() {
        if (fuelLevel < 10.0 || !isAvailable)
            status = 'I';
        else
            status = 'A';
    }

    void displayInfo() const {
        cout << "\n--- Vehicle Info ---" << endl;
        cout << "Vehicle ID: " << vehicleID << endl;
        cout << "Driver: " << driverName << endl;
        cout << "Fuel Level: " << fuelLevel << " L" << endl;
        cout << "Distance Travelled: " << distanceTravelled << " km" << endl;
        cout << "Status: " << (status == 'A' ? "Active" : "Inactive") << endl;
        cout << "Available: " << (isAvailable ? "Yes" : "No") << endl;
        cout << "--------------------" << endl;
    }
};


void assignDriver(FleetVehicle &vehicle, string name) {
    vehicle.setDriverName(name);
    cout << "Driver assigned: " << vehicle.getDriverName() << endl;
}

void refuelVehicle(FleetVehicle &vehicle, float fuelAmount) {
    if (fuelAmount <= 0) {
        throw invalid_argument("Fuel amount must be positive!");
    }
    vehicle.setFuelLevel(vehicle.getFuelLevel() + fuelAmount);
    cout << "Vehicle ID " << vehicle.getVehicleID()
         << " refueled by " << fuelAmount << " liters." << endl;
}

int main()
 {
    const int SIZE = 3;
    FleetVehicle *vehicles[SIZE];

    vehicles[0] = new FleetVehicle(101, 45.5, 120.0, 'A', true, "Raj");
    vehicles[1] = new FleetVehicle(102, 8.0, 300.0, 'A', true, "Priya");
    vehicles[2] = new FleetVehicle(); // default constructor

    int choice, index;
    bool running = true;

    while (running) {
        cout << "\n====== Fleet Vehicle Monitoring Menu ======" << endl;
        cout << "1. Add Vehicle Details" << endl;
        cout << "2. Assign Driver" << endl;
        cout << "3. Refuel Vehicle" << endl;
        cout << "4. Update Status" << endl;
        cout << "5. Display Vehicle Info" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int id; float fuel; double dist; char stat; bool avail; string driver;
            cout << "Enter Vehicle ID: "; cin >> id;
            cout << "Enter Fuel Level: "; cin >> fuel;
            cout << "Enter Distance Travelled: "; cin >> dist;
            cout << "Enter Status (A/I): "; cin >> stat;
            cout << "Enter Availability (1 = Yes, 0 = No): "; cin >> avail;
            cout << "Enter Driver Name: "; cin >> driver;
            cout << "Select index (0-2): "; cin >> index;
            delete vehicles[index]; // delete old
            vehicles[index] = new FleetVehicle(id, fuel, dist, stat, avail, driver);
            break;
        }
        case 2: {
            cout << "Enter index (0-2): "; cin >> index;
            string name;
            cout << "Enter Driver Name: ";
            cin >> name;
            assignDriver(*vehicles[index], name);
            break;
        }
        case 3: {
            cout << "Enter index (0-2): "; cin >> index;
            float fuel;
            cout << "Enter fuel amount to add: "; cin >> fuel;
            try {
                refuelVehicle(*vehicles[index], fuel);
            } catch (const exception &e) {
                cout << "Error: " << e.what() << endl;
            }
            break;
        }
        case 4: {
            cout << "Enter index (0-2): "; cin >> index;
            vehicles[index]->updateStatus();
            cout << "Status updated successfully." << endl;
            break;
        }
        case 5: {
            cout << "Enter index (0-2): "; cin >> index;
            vehicles[index]->displayInfo();
            break;
        }
        case 6:
            running = false;
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    }
    for (int i = 0; i < SIZE; i++) {
        delete vehicles[i];
    }

    return 0;
}
