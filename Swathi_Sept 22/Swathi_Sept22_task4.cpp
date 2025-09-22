#include <iostream>
#include <string>
#include <ctime>   // for getting current year
using namespace std;

class HealthProfile {
private:
    string firstName;
    string lastName;
    string gender;
    int birthMonth;
    int birthDay;
    int birthYear;
    double heightInInches;
    double weightInPounds;

public:
    // Constructor
    HealthProfile(string fName, string lName, string gen,
                  int month, int day, int year,
                  double height, double weight) {
        firstName = fName;
        lastName = lName;
        gender = gen;
        birthMonth = month;
        birthDay = day;
        birthYear = year;
        heightInInches = height;
        weightInPounds = weight;
    }

    // Setters
    void setFirstName(string fName) { firstName = fName; }
    void setLastName(string lName) { lastName = lName; }
    void setGender(string gen) { gender = gen; }
    void setBirthMonth(int month) { birthMonth = month; }
    void setBirthDay(int day) { birthDay = day; }
    void setBirthYear(int year) { birthYear = year; }
    void setHeight(double height) { heightInInches = height; }
    void setWeight(double weight) { weightInPounds = weight; }

    // Getters
    string getFirstName() const { return firstName; }
    string getLastName() const { return lastName; }
    string getGender() const { return gender; }
    int getBirthMonth() const { return birthMonth; }
    int getBirthDay() const { return birthDay; }
    int getBirthYear() const { return birthYear; }
    double getHeight() const { return heightInInches; }
    double getWeight() const { return weightInPounds; }

    // Calculate Age
    int getAge() const {
        time_t now = time(0);
        tm *ltm = localtime(&now);

        int currentYear = 1900 + ltm->tm_year;
        int currentMonth = 1 + ltm->tm_mon;
        int currentDay = ltm->tm_mday;

        int age = currentYear - birthYear;
        if (currentMonth < birthMonth ||
            (currentMonth == birthMonth && currentDay < birthDay)) {
            age--; // not had birthday yet this year
        }
        return age;
    }

    // Maximum Heart Rate
    int getMaxHeartRate() const {
        return 220 - getAge();
    }

    // Target Heart Rate Range (50–85% of max)
    void getTargetHeartRateRange(int &lower, int &upper) const {
        int maxHR = getMaxHeartRate();
        lower = static_cast<int>(maxHR * 0.50);
        upper = static_cast<int>(maxHR * 0.85);
    }

    // BMI
    double getBMI() const {
        return (weightInPounds * 703) / (heightInInches * heightInInches);
    }

    // Display BMI Chart
    static void displayBMIChart() {
        cout << "\nBMI VALUES\n";
        cout << "Underweight: less than 18.5\n";
        cout << "Normal:      between 18.5 and 24.9\n";
        cout << "Overweight:  between 25 and 29.9\n";
        cout << "Obese:       30 or greater\n";
    }
};

int main() {
    string fName, lName, gender;
    int month, day, year;
    double height, weight;

    // Input
    cout << "Enter first name: ";
    cin >> fName;
    cout << "Enter last name: ";
    cin >> lName;
    cout << "Enter gender: ";
    cin >> gender;
    cout << "Enter birth month (1-12): ";
    cin >> month;
    cout << "Enter birth day: ";
    cin >> day;
    cout << "Enter birth year: ";
    cin >> year;
    cout << "Enter height (in inches): ";
    cin >> height;
    cout << "Enter weight (in pounds): ";
    cin >> weight;

    // Create object
    HealthProfile person(fName, lName, gender, month, day, year, height, weight);

    // Output personal info
    cout << "\n--- Health Profile ---\n";
    cout << "Name: " << person.getFirstName() << " " << person.getLastName() << endl;
    cout << "Gender: " << person.getGender() << endl;
    cout << "Date of Birth: " << person.getBirthMonth() << "/"
         << person.getBirthDay() << "/" << person.getBirthYear() << endl;
    cout << "Height (inches): " << person.getHeight() << endl;
    cout << "Weight (pounds): " << person.getWeight() << endl;

    // Output calculations
    cout << "\nAge: " << person.getAge() << " years" << endl;
    cout << "BMI: " << person.getBMI() << endl;
    cout << "Maximum Heart Rate: " << person.getMaxHeartRate() << endl;

    int lower, upper;
    person.getTargetHeartRateRange(lower, upper);
    cout << "Target Heart Rate Range: " << lower << " - " << upper << endl;

    // Show BMI chart
    HealthProfile::displayBMIChart();

    return 0;
}
