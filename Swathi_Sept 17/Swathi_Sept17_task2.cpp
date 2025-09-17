#include <iostream>
#include <cstdint>
#include <limits>
using namespace std;

class TrackedVehicle {
private:
    uint32_t vehicle_id;
    float speed;         
    float distance;  
    
    static float min_recorded_distance;
    static int vehicle_count;

public:
  
    TrackedVehicle(uint32_t id = 0, float spd = 0.0f, float dist = 0.0f)
        : vehicle_id(id), speed(spd), distance(dist) {
       
        if (dist < min_recorded_distance) {
            min_recorded_distance = dist;
        }
       
        vehicle_count++;
    }

  
    void display() const {
        cout << "Vehicle ID: " << vehicle_id
             << " | Speed: " << speed << " km/h"
             << " | Distance: " << distance << " m" << endl;
    }


    const TrackedVehicle* compareDistance(const TrackedVehicle& other) const {
        if (this->distance <= other.distance) {
            return this;  
        } else {
            return &other;
        }
    }

    
    static float getMinRecordedDistance() {
        return min_recorded_distance;
    }

    static int getVehicleCount() {
        return vehicle_count;
    }

   
    float getDistance() const {
        return distance;
    }

    uint32_t getID() const {
        return vehicle_id;
    }

  
    float getSpeed() const {
        return speed;
    }
};


float TrackedVehicle::min_recorded_distance = numeric_limits<float>::max();
int TrackedVehicle::vehicle_count = 0;


void findLeadVehicle(TrackedVehicle* arr, uint32_t size, const TrackedVehicle*& lead) {
    if (size == 0 || arr == nullptr) {
        lead = nullptr;
        return;
    }

    lead = &arr[0]; 
    for (uint32_t i = 1; i < size; ++i) {
        if (arr[i].getDistance() < lead->getDistance()) {
            lead = &arr[i];
        }
    }
}


void printTrackedVehicle(const TrackedVehicle& vehicle) {
    vehicle.display();
}

void printLeadVehicle(const TrackedVehicle* lead) {
    if (lead != nullptr) {
        cout << "\nLead Vehicle Detected:" << endl;
        lead->display();
    } else {
        cout << "No lead vehicle found!" << endl;
    }
}


int main() {
    uint32_t size = 4;


    TrackedVehicle* vehicles = new TrackedVehicle[size]{
        TrackedVehicle(501, 80.0f, 60.0f),
        TrackedVehicle(502, 78.0f, 45.0f),
        TrackedVehicle(503, 85.0f, 100.0f),
        TrackedVehicle(504, 76.0f, 40.0f)
    };

    
    cout << "All Tracked Vehicles:" << endl;
    for (uint32_t i = 0; i < size; ++i) {
        printTrackedVehicle(vehicles[i]);
    }

   
    const TrackedVehicle* lead = nullptr;
    findLeadVehicle(vehicles, size, lead);

  
    printLeadVehicle(lead);


    cout << "\nMinimum Recorded Distance: " 
         << TrackedVehicle::getMinRecordedDistance() << " m" << endl;
    cout << "Total Vehicles Tracked: " 
         << TrackedVehicle::getVehicleCount() << endl;

 
    delete[] vehicles;

    return 0;
}
