#include <iostream>
#include <cstdint>
#include <string>
using namespace std;


enum SensorType { LIDAR, RADAR, CAMERA };


class SensorArray {
private:
    int sensor_id;
    SensorType type;
    double* temperature_readings;
    int num_readings;

    static double global_max_temperature;

public:
      SensorArray(int id, SensorType t, const double* readings, int n)
        : sensor_id(id), type(t), num_readings(n) 
    {

        temperature_readings = new double[num_readings];

       
        for (int i = 0; i < num_readings; i++) {
            temperature_readings[i] = readings[i];
            if (temperature_readings[i] > global_max_temperature) {
                global_max_temperature = temperature_readings[i];
            }
        }
    }

   
    ~SensorArray() {
        delete[] temperature_readings;
    }


    double getMaxTemperature() const {
        double maxTemp = temperature_readings[0];
        for (int i = 1; i < num_readings; i++) {
            if (temperature_readings[i] > maxTemp) {
                maxTemp = temperature_readings[i];
            }
        }
        return maxTemp;
    }

    
    void printSensorInfo() const {
        cout << "Sensor ID: " << sensor_id
             << " | Type: " << sensorTypeToString(type)
             << " | Max Temp: " << getMaxTemperature() << "°C" << endl;
    }

  
    static double getGlobalMaxTemperature() {
        return global_max_temperature;
    }

    
    static const char* sensorTypeToString(SensorType t) {
        switch (t) {
            case LIDAR: return "LIDAR";
            case RADAR: return "RADAR";
            case CAMERA: return "CAMERA";
            default: return "UNKNOWN";
        }
    }

    friend void printSensor(const SensorArray& s);
};



double SensorArray::global_max_temperature = -1.0; 


void printSensor(const SensorArray& s) {
    s.printSensorInfo();
}

void printAllSensors(const SensorArray* arr, int size) {
    cout << "\n--- All Sensors Info ---\n";
    for (int i = 0; i < size; i++) {
        printSensor(arr[i]);
    }
}


int main() {
   
    double lidar_readings[3]  = {35.5, 36.1, 34.9};
    double radar_readings[3]  = {39.0, 38.7, 39.3};
    double camera_readings[3] = {30.2, 31.0, 30.5};

   
    int size = 3;
    SensorArray* sensors = new SensorArray[size]{
        SensorArray(801, LIDAR, lidar_readings, 3),
        SensorArray(802, RADAR, radar_readings, 3),
        SensorArray(803, CAMERA, camera_readings, 3)
    };

   
    printAllSensors(sensors, size);


    cout << "\n🌡️ Global Maximum Temperature Recorded: "
         << SensorArray::getGlobalMaxTemperature() << "°C" << endl;

   
    delete[] sensors;

    return 0;
}
