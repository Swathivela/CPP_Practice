#include <iostream>
#include <string>
using namespace std;

class Name {
private:
    string firstName;
    string middleName;
    string lastName;
    string salutation;

public:
    // Constructor
    Name(const string& sal, const string& last, const string& first, const string& middle)
        : salutation(sal), lastName(last), firstName(first), middleName(middle) {}

    // Setters
    void setFirstName(const string& first) { firstName = first; }
    void setMiddleName(const string& middle) { middleName = middle; }
    void setLastName(const string& last) { lastName = last; }
    void setSalutation(const string& sal) { salutation = sal; }

    // Getters
    string getFirstName() const { return firstName; }
    string getMiddleName() const { return middleName; }
    string getLastName() const { return lastName; }
    string getSalutation() const { return salutation; }

    // toString function
    string toString() const {
        return salutation + " " + lastName + ", " + firstName + " " + middleName;
    }
};

// Test the Name class
int main() {
    Name person("Dr.", "Smith", "John", "Michael");

    cout << "Full Name: " << person.toString() << endl;

    // Update fields
    person.setSalutation("Mr.");
    person.setFirstName("James");
    person.setMiddleName("Robert");
    person.setLastName("Johnson");

    cout << "Updated Name: " << person.toString() << endl;

    return 0;
}
