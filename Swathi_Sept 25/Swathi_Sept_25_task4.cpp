#include <iostream>
#include <string>
#include <sstream>
using namespace std;

// Enum for flight states
enum class FlightStatus {
    PARKED, TAXIING, WAITING_TAKEOFF, TAKING_OFF, CLIMBING,
    CRUISING, CHANGING_ALTITUDE, DESCENDING, LANDING, LANDED
};

// Helper function to convert status to string
string statusToString(FlightStatus status) {
    switch (status) {
        case FlightStatus::PARKED: return "Parked at gate";
        case FlightStatus::TAXIING: return "Taxiing";
        case FlightStatus::WAITING_TAKEOFF: return "Waiting for takeoff";
        case FlightStatus::TAKING_OFF: return "Taking off";
        case FlightStatus::CLIMBING: return "Climbing";
        case FlightStatus::CRUISING: return "Cruising";
        case FlightStatus::CHANGING_ALTITUDE: return "Changing altitude";
        case FlightStatus::DESCENDING: return "Descending";
        case FlightStatus::LANDING: return "Landing";
        case FlightStatus::LANDED: return "Landed";
        default: return "Unknown";
    }
}

// Flight class
class Flight {
private:
    string airline;
    string flightNumber;
    string makeModel;
    string origin;
    string destination;
    int currentAltitude;
    int newAltitude;
    int airSpeed;
    int direction;
    string departureTime;
    string arrivalTime;
    FlightStatus status;

public:
    // Constructor
    Flight(string air, string fNum, string model,
           string orig, string dest, int altitude,
           int speed, int dir, string dep, string arr,
           FlightStatus stat = FlightStatus::PARKED)
        : airline(air), flightNumber(fNum), makeModel(model),
          origin(orig), destination(dest), currentAltitude(altitude),
          newAltitude(altitude), airSpeed(speed), direction(dir),
          departureTime(dep), arrivalTime(arr), status(stat) {}

    // Change altitude
    void changeAltitude(int targetAltitude) {
        cout << airline << " " << flightNumber
             << " changing altitude from " << currentAltitude
             << " to " << targetAltitude << " feet.\n";
        status = FlightStatus::CHANGING_ALTITUDE;
        newAltitude = targetAltitude;
        currentAltitude = targetAltitude;
    }

    // Reduce speed
    void reduceSpeed(int newSpeed) {
        cout << airline << " " << flightNumber
             << " reducing speed from " << airSpeed
             << " to " << newSpeed << " knots.\n";
        airSpeed = newSpeed;
    }

    // Begin landing approach
    void beginLandingApproach() {
        cout << airline << " " << flightNumber
             << " beginning landing approach at " << currentAltitude
             << " feet.\n";
        status = FlightStatus::LANDING;
    }

    // toString
    string toString() const {
        stringstream ss;
        ss << airline << " " << flightNumber << " | "
           << "Model: " << makeModel << " | "
           << "From " << origin << " to " << destination << " | "
           << "Altitude: " << currentAltitude << " ft | "
           << "Speed: " << airSpeed << " knots | "
           << "Direction: " << direction << " deg | "
           << "Status: " << statusToString(status);
        return ss.str();
    }
};

// Driver
int main() {
    cout << "===== AirTrafficControlSimulator =====\n";

    // Create 3 flights
    Flight flight1("Delta", "DL123", "Boeing 737", "ATL", "LAX",
                   0, 0, 0, "08:00", "11:00", FlightStatus::PARKED);
    Flight flight2("United", "UA456", "Airbus A320", "ORD", "SFO",
                   5000, 250, 90, "09:00", "12:30", FlightStatus::CLIMBING);
    Flight flight3("American", "AA789", "Boeing 777", "JFK", "MIA",
                   20000, 450, 180, "07:30", "10:30", FlightStatus::CRUISING);

    // Interact with flights
    cout << flight1.toString() << "\n";
    flight1.changeAltitude(1000);
    cout << flight1.toString() << "\n\n";

    cout << flight2.toString() << "\n";
    flight2.changeAltitude(10000);
    flight2.reduceSpeed(220);
    cout << flight2.toString() << "\n\n";

    cout << flight3.toString() << "\n";
    flight3.beginLandingApproach();
    flight3.changeAltitude(12000);
    cout << flight3.toString() << "\n";

    return 0;
}
