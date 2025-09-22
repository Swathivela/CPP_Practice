#include <iostream>
using namespace std;

class Date {
private:
    int month;
    int day;
    int year;

public:
    // Constructor with validation for month
    Date(int m, int d, int y) {
        if (m >= 1 && m <= 12) {
            month = m;
        } else {
            month = 1;  // default if invalid
        }
        day = d;
        year = y;
    }

    // Setters
    void setMonth(int m) {
        if (m >= 1 && m <= 12) {
            month = m;
        } else {
            month = 1; // default
        }
    }
    void setDay(int d) { day = d; }
    void setYear(int y) { year = y; }

    // Getters
    int getMonth() const { return month; }
    int getDay() const { return day; }
    int getYear() const { return year; }

    // Display function
    void displayDate() const {
        cout << month << "/" << day << "/" << year << endl;
    }
};

// Test program
int main() {
    // Create Date object with valid month
    Date date1(9, 22, 2025);
    cout << "Initial Date: ";
    date1.displayDate();

    // Create Date object with invalid month
    Date date2(15, 10, 2024);  // month invalid → should default to 1
    cout << "Date with invalid month: ";
    date2.displayDate();

    // Update date using setters
    date2.setMonth(12);
    date2.setDay(25);
    date2.setYear(2023);

    cout << "Updated Date: ";
    date2.displayDate();

    return 0;
}
