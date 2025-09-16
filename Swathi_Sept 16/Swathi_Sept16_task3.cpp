#include <iostream>
using namespace std;

class CameraConfig {
private:
    int num_modes;
    int* resolution_width;
    int* resolution_height;

public:
  
    CameraConfig(int n, const int* widths, const int* heights)
        : num_modes(n) {
        resolution_width = new int[num_modes];
        resolution_height = new int[num_modes];

        for (int i = 0; i < num_modes; i++) {
            resolution_width[i] = widths[i];
            resolution_height[i] = heights[i];
        }
    }

   
    CameraConfig(const CameraConfig& other) {
        num_modes = other.num_modes;
        resolution_width = new int[num_modes];
        resolution_height = new int[num_modes];

        for (int i = 0; i < num_modes; i++) {
            resolution_width[i] = other.resolution_width[i];
            resolution_height[i] = other.resolution_height[i];
        }
    }

    
    ~CameraConfig() {
        delete[] resolution_width;
        delete[] resolution_height;
    }

   
    void printConfig() const {
        cout << "Camera Configurations:" << endl;
        for (int i = 0; i < num_modes; i++) {
            cout << "Mode " << i
                 << " -> Resolution: " << resolution_width[i]
                 << " x " << resolution_height[i] << endl;
        }
    }

   
    bool isHigherResolution(int mode1, int mode2) const {
        int res1 = this->resolution_width[mode1] * this->resolution_height[mode1];
        int res2 = this->resolution_width[mode2] * this->resolution_height[mode2];
        return res1 > res2;
    }


    int getNumModes() const { return num_modes; }
    int getWidth(int mode) const { return resolution_width[mode]; }
    int getHeight(int mode) const { return resolution_height[mode]; }
};


void printCameraConfig(const CameraConfig& config) {
    config.printConfig();
}


bool globalCompareResolution(const CameraConfig& config, int m1, int m2) {
    return config.isHigherResolution(m1, m2);
}


int main() {
    
    int widths[3] = {1920, 1280, 3840};
    int heights[3] = {1080, 2160, 2160};

    CameraConfig config(3, widths, heights);

   
    printCameraConfig(config);
    cout << endl;

    cout << "[Member Function] Comparing Mode 0 and Mode 2:" << endl;
    if (config.isHigherResolution(0, 2)) {
        cout << "Mode 0 has higher resolution than Mode 2." << endl;
    } else if (config.isHigherResolution(2, 0)) {
        cout << "Mode 2 has higher resolution than Mode 0." << endl;
    } else {
        cout << "Mode 0 and Mode 2 have equal resolution." << endl;
    }
    cout << endl;

    
    cout << "[Global Function] Comparing Mode 0 and Mode 2:" << endl;
    if (globalCompareResolution(config, 0, 2)) {
        cout << "Mode 0 has higher resolution than Mode 2." << endl;
    } else if (globalCompareResolution(config, 2, 0)) {
        cout << "Mode 2 has higher resolution than Mode 0." << endl;
    } else {
        cout << "Mode 0 and Mode 2 have equal resolution." << endl;
    }

    return 0;
}
