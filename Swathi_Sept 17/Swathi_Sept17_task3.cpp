#include <iostream>
#include <cstdint>
using namespace std;

class DetectedObject {
private:
    uint32_t object_id;
    float rel_speed;  
    float distance;   
public:
  
    DetectedObject(uint32_t id, float speed, float dist)
        : object_id(id), rel_speed(speed), distance(dist) {}

    
    void display() const {
        cout << "Object ID: " << object_id
             << " | RelSpeed: " << rel_speed
             << " | Distance: " << distance << endl;
    }


    bool isHigherRisk(const DetectedObject& other) const {
        return (this->distance < other.distance && this->rel_speed > other.rel_speed);
    }

   
    void updateValuesByValue(DetectedObject obj) {
        obj.rel_speed += 2;
        obj.distance -= 5;
        cout << "Inside updateValuesByValue (copy updated): ";
        obj.display();
    }

    
    void updateValuesByReference(DetectedObject& obj) {
        obj.rel_speed += 2;
        obj.distance -= 5;
    }
    float getRelSpeed() const { return rel_speed; }
    float getDistance() const { return distance; }
    uint32_t getId() const { return object_id; }
};


void findHighestRiskObject(DetectedObject* arr, uint32_t size, const DetectedObject*& riskObj) {
    if (size == 0) {
        riskObj = nullptr;
        return;
    }

    riskObj = &arr[0];  
    for (uint32_t i = 1; i < size; i++) {
        if (arr[i].isHigherRisk(*riskObj)) {
            riskObj = &arr[i];
        }
    }
}


void printDetectedObject(const DetectedObject& obj) {
    obj.display();
}

void printHighestRiskObject(const DetectedObject* obj) {
    if (obj) {
        cout << "\n⚠️ Highest Risk Object Detected:\n";
        obj->display();
    } else {
        cout << "\n⚠️ No high-risk object found.\n";
    }
}

void updateObjectValuesByValueGlobal(DetectedObject obj) {
    cout << "\nCalling update by Value...\n";
    obj.updateValuesByValue(obj);
}

void updateObjectValuesByReferenceGlobal(DetectedObject& obj) {
    cout << "\nCalling update by Reference...\n";
    obj.updateValuesByReference(obj);
}


int main() {
      
    uint32_t size = 3;
    DetectedObject* objects = new DetectedObject[size]{
        DetectedObject(701, 15, 55),
        DetectedObject(702, 20, 35),
        DetectedObject(703, 10, 30)
    };

    cout << "All Detected Objects:\n";
    for (uint32_t i = 0; i < size; i++) {
        printDetectedObject(objects[i]);
    }

    
    updateObjectValuesByValueGlobal(objects[0]);

   
    cout << "\nBefore Reference Update:\n";
    objects[1].display();
    updateObjectValuesByReferenceGlobal(objects[1]);
    cout << "After Reference Update:\n";
    objects[1].display();

  
    const DetectedObject* riskObj = nullptr;
    findHighestRiskObject(objects, size, riskObj);
    printHighestRiskObject(riskObj);

   
    delete[] objects;

    return 0;
}
