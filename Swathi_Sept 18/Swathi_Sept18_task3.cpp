#include <iostream>
#include <string>
using namespace std;


enum SatelliteStatus {
    OPERATIONAL,
    MAINTENANCE,
    DECOMMISSIONED
};
class SatelliteData {
private:
    int satellite_id;
    int num_antennas;
    float* signal_strength;
    float orbital_altitude;
    SatelliteStatus status;

    static int active_satellites; 
public:
   
    SatelliteData(int id, int antennas, const float* signals, float altitude, SatelliteStatus stat)
        : satellite_id(id), num_antennas(antennas), orbital_altitude(altitude), status(stat) {
        signal_strength = new float[num_antennas];
        for (int i = 0; i < num_antennas; i++) {
            signal_strength[i] = signals[i];
        }
        active_satellites++;
    }

    
    SatelliteData(const SatelliteData& other)
        : satellite_id(other.satellite_id),
          num_antennas(other.num_antennas),
          orbital_altitude(other.orbital_altitude),
          status(other.status) {
        signal_strength = new float[num_antennas];
        for (int i = 0; i < num_antennas; i++) {
            signal_strength[i] = other.signal_strength[i];
        }
        active_satellites++;
    }

 
    ~SatelliteData() {
        delete[] signal_strength;
        active_satellites--;
    }

  
    float getAverageSignalStrength() const {
        float sum = 0;
        for (int i = 0; i < num_antennas; i++) {
            sum += signal_strength[i];
        }
        return (num_antennas > 0) ? sum / num_antennas : 0.0f;
    }

   
    void boostSignal(float factor) {
        for (int i = 0; i < num_antennas; i++) {
            signal_strength[i] *= factor;
        }
    }

 
    void boostSignal(float factor, float threshold) {
        for (int i = 0; i < num_antennas; i++) {
            if (signal_strength[i] < threshold) {
                signal_strength[i] *= factor;
            }
        }
    }


    void setStatus(SatelliteStatus new_status) {
        status = new_status;
    }

   
    string getStatusString() const {
        switch (status) {
            case OPERATIONAL: return "Operational";
            case MAINTENANCE: return "Maintenance";
            case DECOMMISSIONED: return "Decommissioned";
            default: return "Unknown";
        }
    }


    int getId() const { return satellite_id; }
    float getAltitude() const { return orbital_altitude; }
    int getNumAntennas() const { return num_antennas; }
    const float* getSignals() const { return signal_strength; }

   
    static int getActiveSatelliteCount() {
        return active_satellites;
    }
};

int SatelliteData::active_satellites = 0;




void printSatelliteData(const SatelliteData& sd) {
    cout << "Satellite ID: " << sd.getId() << endl;
    cout << "Orbital Altitude: " << sd.getAltitude() << " km" << endl;
    cout << "Signal Strengths: ";
    for (int i = 0; i < sd.getNumAntennas(); i++) {
        cout << sd.getSignals()[i] << " ";
    }
    cout << endl;
    cout << "Status: " << sd.getStatusString() << endl << endl;
}


bool compareAltitude(const SatelliteData& s1, const SatelliteData& s2) {
    return s1.getAltitude() > s2.getAltitude();
}


void cloneSatellite(const SatelliteData& source, SatelliteData*& target) {
    target = new SatelliteData(source); 
}

void printActiveSatelliteCount() {
    cout << "Active Satellites: " << SatelliteData::getActiveSatelliteCount() << endl;
}


void updateStatusIfWeak(SatelliteData& sd, float confidence_threshold) {
    if (sd.getAverageSignalStrength() < confidence_threshold) {
        sd.setStatus(MAINTENANCE);
    }
}


int main() {
    
    float signals1[] = {78.5f, 80.2f, 79.0f};
    float signals2[] = {75.0f, 76.5f};

    SatelliteData s1(101, 3, signals1, 550.0f, OPERATIONAL);
    SatelliteData s2(102, 2, signals2, 600.0f, MAINTENANCE);

    cout << "--- Initial Satellite Data ---" << endl;
    printSatelliteData(s1);
    printSatelliteData(s2);

  
    s1.boostSignal(1.1f); 
    s2.boostSignal(1.2f, 76.0f);
    cout << "--- After Boosting Signals ---" << endl;
    printSatelliteData(s1);
    printSatelliteData(s2);

  
    cout << "Satellite with Higher Altitude: "
         << (compareAltitude(s1, s2) ? "Satellite 1" : "Satellite 2") << endl << endl;


    SatelliteData* clonedSatellite = nullptr;
    cloneSatellite(s1, clonedSatellite);

    cout << "--- Cloned Satellite ---" << endl;
    printSatelliteData(*clonedSatellite);

   
    updateStatusIfWeak(s2, 77.0f);
    cout << "--- After Status Update ---" << endl;
    printSatelliteData(s2);

   
    printActiveSatelliteCount();

 
    delete clonedSatellite;

    cout << "--- After Deleting Cloned Satellite ---" << endl;
    printActiveSatelliteCount();

    return 0;
}
