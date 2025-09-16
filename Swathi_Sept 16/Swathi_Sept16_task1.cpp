#include <iostream>
using namespace std;

class LaneBoundary {
private:
    float curvature;
    int lane_id;

public:
    LaneBoundary(float c, int id) : curvature(c), lane_id(id) {}

    float getCurvature() const {
        return curvature;
    }

    int getLaneId() const {
        return lane_id;
    }

    bool compareCurvature(const LaneBoundary& other) const {
        return this->curvature > other.curvature;
    }

    void display() const {
        cout << "Lane ID: " << lane_id
             << ", Curvature: " << curvature << endl;
    }
};
bool isCurvatureGreater(const LaneBoundary& lane1, const LaneBoundary& lane2) {
    return lane1.getCurvature() > lane2.getCurvature();
}

void printLaneComparison(const LaneBoundary& lane1, const LaneBoundary& lane2) {
    if (lane1.getCurvature() > lane2.getCurvature()) {
        cout << "Lane " << lane1.getLaneId() << " has greater curvature." << endl;
    } else if (lane1.getCurvature() < lane2.getCurvature()) {
        cout << "Lane " << lane2.getLaneId() << " has greater curvature." << endl;
    } else {
        cout << "Both lanes have equal curvature." << endl;
    }
}


int main() {
    // Sample data
    LaneBoundary lane1(0.015, 1);
    LaneBoundary lane2(0.023, 2);

    cout << "Lane Details:" << endl;
    lane1.display();
    lane2.display();
    cout << endl;

    if (lane1.compareCurvature(lane2)) {
        cout << "[Member Function] Lane " << lane1.getLaneId()
             << " has greater curvature than Lane " << lane2.getLaneId() << "." << endl;
    } else if (lane2.compareCurvature(lane1)) {
        cout << "[Member Function] Lane " << lane2.getLaneId()
             << " has greater curvature than Lane " << lane1.getLaneId() << "." << endl;
    } else {
        cout << "[Member Function] Both lanes have equal curvature." << endl;
    }

    
    cout << endl << "[Global Function] ";
    printLaneComparison(lane1, lane2);

    return 0;
}
