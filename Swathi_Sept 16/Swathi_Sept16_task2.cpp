#include <iostream>
using namespace std;


class ObjectDistance {
private:
    float radar_distance;
    float camera_distance;

public:
  
    ObjectDistance(float radar, float camera)
        : radar_distance(radar), camera_distance(camera) {}

   
    void adjustDistancesByValue(ObjectDistance obj) {
        obj.radar_distance += 5.0f;
        obj.camera_distance += 5.0f;
        cout << "[Inside adjustDistancesByValue] Adjusted values: "
             << "Radar: " << obj.radar_distance
             << ", Camera: " << obj.camera_distance << endl;
    }

   
    void adjustDistancesByReference(ObjectDistance& obj) {
        obj.radar_distance += 5.0f;
        obj.camera_distance += 5.0f;
        cout << "[Inside adjustDistancesByReference] Values updated in original object." << endl;
    }

    
    float getRadarDistance() const { return radar_distance; }
    float getCameraDistance() const { return camera_distance; }
};

void printObjectDistance(const ObjectDistance& obj) {
    cout << "Radar Distance: " << obj.getRadarDistance()
         << ", Camera Distance: " << obj.getCameraDistance() << endl;
}


ObjectDistance* createObjectDistanceOnHeap(float radar, float camera) {
    return new ObjectDistance(radar, camera);
}


int main() {
    // Create object on heap
    ObjectDistance* obj = createObjectDistanceOnHeap(35.5f, 34.8f);

    cout << "Initial Object Distances:" << endl;
    printObjectDistance(*obj);
    cout << endl;

   
    cout << "Calling adjustDistancesByValue..." << endl;
    obj->adjustDistancesByValue(*obj);
    cout << "After adjustDistancesByValue (original object unchanged):" << endl;
    printObjectDistance(*obj);
    cout << endl;

    cout << "Calling adjustDistancesByReference..." << endl;
    obj->adjustDistancesByReference(*obj);
    cout << "After adjustDistancesByReference (original object updated):" << endl;
    printObjectDistance(*obj);
    cout << endl;


    delete obj;
    cout << "Heap object deleted successfully." << endl;

    return 0;
}
