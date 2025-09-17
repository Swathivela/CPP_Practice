#include <iostream>
#include <cstdint>
using namespace std;

class Pedestrian {
private:
    uint32_t pedestrian_id;
    float distance_from_vehicle;

public:
    Pedestrian(uint32_t id = 0, float distance = 0.0f)
        : pedestrian_id(id), distance_from_vehicle(distance) {}

    void updateDistance(float newDistance) {
        distance_from_vehicle = newDistance;
    }

    float getDistance() const {
        return distance_from_vehicle;
    }

    uint32_t getID() const {
        return pedestrian_id;
    }
};


void printPedestrianInfo(const Pedestrian& ped) {
    cout << "Pedestrian ID: " << ped.getID()
         << " | Distance: " << ped.getDistance() << " m" << endl;
}

void findClosestPedestrian(Pedestrian* array, uint32_t size, const Pedestrian*& closest) {
    if (size == 0) {
        closest = nullptr;
        return;
    }

    closest = &array[0];
    for (uint32_t i = 1; i < size; i++) {
        if (array[i].getDistance() < closest->getDistance()) {
            closest = &array[i];
        }
    }
}

void printClosestPedestrian(const Pedestrian* closest) {
    if (closest) {
        cout << "Closest Pedestrian -> ID: " << closest->getID()
             << " | Distance: " << closest->getDistance() << " m" << endl;
    } else {
        cout << "No pedestrian detected!" << endl;
    }
}


int main() {
    
    Pedestrian* arr = new Pedestrian[3] {
        {101, 12.4f},
        {102, 8.7f},
        {103, 15.1f}
    };


    cout << "All Pedestrians:\n";
    for (int i = 0; i < 3; i++) {
        printPedestrianInfo(arr[i]);
    }

  
    const Pedestrian* closest = nullptr;
    findClosestPedestrian(arr, 3, closest);

    cout << "\n";
    printClosestPedestrian(closest);

   
    delete[] arr;

    return 0;
}

