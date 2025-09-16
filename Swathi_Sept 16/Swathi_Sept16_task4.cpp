#include <iostream>
using namespace std;

class RadarSignal {
private:
    int num_channels;
    float* signal_strength;

public:

    RadarSignal(int n, const float* signals) : num_channels(n) {
        signal_strength = new float[num_channels];
        for (int i = 0; i < num_channels; i++) {
            signal_strength[i] = signals[i];
        }
    }

    
    ~RadarSignal() {
        delete[] signal_strength;
    }

    
    float averageSignal() const {
        float sum = 0.0f;
        for (int i = 0; i < num_channels; i++) {
            sum += signal_strength[i];
        }
        return sum / num_channels;
    }


    void boostSignalByValue(RadarSignal obj) {
        for (int i = 0; i < obj.num_channels; i++) {
            obj.signal_strength[i] += 5.0f;
        }
        cout << "[Inside boostSignalByValue] Temporary object signals boosted." << endl;
    }

  
    void boostSignalByReference(RadarSignal& obj) {
        for (int i = 0; i < obj.num_channels; i++) {
            obj.signal_strength[i] += 5.0f;
        }
        cout << "[Inside boostSignalByReference] Original object signals boosted." << endl;
    }


    int getNumChannels() const { return num_channels; }
    float getSignal(int i) const { return signal_strength[i]; }
};
void printRadarSignal(const RadarSignal& radar) {
    cout << "Radar Signal Strengths: ";
    for (int i = 0; i < radar.getNumChannels(); i++) {
        cout << radar.getSignal(i) << " ";
    }
    cout << endl;
}


RadarSignal* createRadarSignalHeap(int num, float* signals) {
    return new RadarSignal(num, signals);
}


int main() {
   
    int num_channels = 4;
    float signals[4] = {55.5f, 48.2f, 60.1f, 52.6f};

   
    RadarSignal* radar = createRadarSignalHeap(num_channels, signals);

    cout << "Initial Radar Signals:" << endl;
    printRadarSignal(*radar);
    cout << "Average Signal Strength: " << radar->averageSignal() << endl << endl;

   
    cout << "Calling boostSignalByValue..." << endl;
    radar->boostSignalByValue(*radar);
    cout << "After boostSignalByValue (original object unchanged):" << endl;
    printRadarSignal(*radar);
    cout << "Average Signal Strength: " << radar->averageSignal() << endl << endl;

    cout << "Calling boostSignalByReference..." << endl;
    radar->boostSignalByReference(*radar);
    cout << "After boostSignalByReference (original object updated):" << endl;
    printRadarSignal(*radar);
    cout << "Average Signal Strength: " << radar->averageSignal() << endl << endl;

  
    delete radar;
    cout << "Heap object deleted successfully." << endl;

    return 0;
}
