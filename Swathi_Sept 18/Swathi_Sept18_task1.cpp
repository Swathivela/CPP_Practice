#include <iostream>
#include <iomanip>
using namespace std;

class VehicleStatus {
private:
    int num_wheels;
    float* wheel_speed;
    int num_temps;
    float* engine_temp;

public:
    
    VehicleStatus(int wheels, const float* speeds, int temps, const float* temps_data)
        : num_wheels(wheels), num_temps(temps) 
    {

        wheel_speed = new float[num_wheels];
        for (int i = 0; i < num_wheels; i++) {
            wheel_speed[i] = speeds[i];
        }


        engine_temp = new float[num_temps];
        for (int i = 0; i < num_temps; i++) {
            engine_temp[i] = temps_data[i];
        }
    }

 
    ~VehicleStatus() {
        delete[] wheel_speed;
        delete[] engine_temp;
    }


        float averageWheelSpeed() const {
        float sum = 0.0f;
        for (int i = 0; i < num_wheels; i++) {
            sum += wheel_speed[i];
        }
        return (num_wheels > 0) ? sum / num_wheels : 0.0f;
    }

   
    float maxEngineTemp() const {
        float maxTemp = engine_temp[0];
        for (int i = 1; i < num_temps; i++) {
            if (engine_temp[i] > maxTemp)
                maxTemp = engine_temp[i];
        }
        return maxTemp;
    }
    bool isWheelSpeedHigher(const VehicleStatus& other) const {
        float maxSpeedThis = wheel_speed[0];
        for (int i = 1; i < num_wheels; i++) {
            if (wheel_speed[i] > maxSpeedThis)
                maxSpeedThis = wheel_speed[i];
        }

        float maxSpeedOther = other.wheel_speed[0];
        for (int i = 1; i < other.num_wheels; i++) {
            if (other.wheel_speed[i] > maxSpeedOther)
                maxSpeedOther = other.wheel_speed[i];
        }

        return maxSpeedThis > maxSpeedOther;
    }

    
    friend void printVehicleStatus(const VehicleStatus& vs);
    friend bool compareWheelSpeedGlobal(const VehicleStatus& vs1, const VehicleStatus& vs2);
};


void printVehicleStatus(const VehicleStatus& vs) {
    cout << "Wheel Speeds: ";
    for (int i = 0; i < vs.num_wheels; i++) {
        cout << fixed << setprecision(1) << vs.wheel_speed[i] << " ";
    }
    cout << "\nEngine Temperatures: ";
    for (int i = 0; i < vs.num_temps; i++) {
        cout << fixed << setprecision(1) << vs.engine_temp[i] << " ";
    }
    cout << "\nAverage Wheel Speed: " << vs.averageWheelSpeed();
    cout << "\nMax Engine Temp: " << vs.maxEngineTemp() << "\n\n";
}


bool compareWheelSpeedGlobal(const VehicleStatus& vs1, const VehicleStatus& vs2) {
    return vs1.isWheelSpeedHigher(vs2);
}


int main() {
    
    float wheels1[] = {55.5f, 56.6f, 57.2f, 55.9f};
    float temps1[]  = {90.5f, 88.9f};

    float wheels2[] = {50.0f, 51.2f, 49.8f, 50.4f};
    float temps2[]  = {92.0f, 89.5f};

  
    VehicleStatus v1(4, wheels1, 2, temps1);
    VehicleStatus v2(4, wheels2, 2, temps2);

   
    cout << "Vehicle 1 Status:\n";
    printVehicleStatus(v1);

    cout << "Vehicle 2 Status:\n";
    printVehicleStatus(v2);

    
    cout << "Member Function Comparison: ";
    if (v1.isWheelSpeedHigher(v2))
        cout << "Vehicle 1 has higher max wheel speed.\n";
    else
        cout << "Vehicle 2 has higher or equal max wheel speed.\n";


    cout << "Global Function Comparison: ";
    if (compareWheelSpeedGlobal(v1, v2))
        cout << "Vehicle 1 has higher max wheel speed.\n";
    else
        cout << "Vehicle 2 has higher or equal max wheel speed.\n";

    return 0;
}
