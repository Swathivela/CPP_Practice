#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string firstName;
    string middleName;
    string lastName;
    char sex;
    int yearOfBirth;
    string registrationNumber;
    string email;

public:
    // Constructor
    Student(const string& fName, const string& mName, const string& lName,
            char s, int yob, const string& regNo, const string& mail)
        : firstName(fName), middleName(mName), lastName(lName),
          sex(s), yearOfBirth(yob), registrationNumber(regNo), email(mail) {}

    // Setters
    void setFirstName(const string& fName) { firstName = fName; }
    void setMiddleName(const string& mName) { middleName = mName; }
    void setLastName(const string& lName) { lastName = lName; }
    void setSex(char s) { sex = s; }
    void setYearOfBirth(int yob) { yearOfBirth = yob; }
    void setRegistrationNumber(const string& regNo) { registrationNumber = regNo; }
    void setEmail(const string& mail) { email = mail; }

    // Getters
    string getFirstName() const { return firstName; }
    string getMiddleName() const { return middleName; }
    string getLastName() const { return lastName; }
    char getSex() const { return sex; }
    int getYearOfBirth() const { return yearOfBirth; }
    string getRegistrationNumber() const { return registrationNumber; }
    string getEmail() const { return email; }

    // Utility function to display student info
    void displayStudent() const {
        cout << "Student Info:\n";
        cout << "Name: " << firstName << " " << middleName << " " << lastName << endl;
        cout << "Sex: " << sex << endl;
        cout << "Year of Birth: " << yearOfBirth << endl;
        cout << "Registration No: " << registrationNumber << endl;
        cout << "Email: " << email << endl;
    }
};

// Example usage
int main() {
    Student s1("John", "Michael", "Doe", 'M', 2000, "REG12345", "john.doe@email.com");

    s1.displayStudent();

    cout << "\nUpdating email...\n";
    s1.setEmail("john.doe@university.edu");
    cout << "Updated Email: " << s1.getEmail() << endl;

    return 0;
}
