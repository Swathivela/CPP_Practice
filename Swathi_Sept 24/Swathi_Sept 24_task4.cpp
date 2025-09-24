Name Class (with validation)
#include <iostream>
#include <string>
#include <stdexcept> // for invalid_argument
using namespace std;

class Name {
private:
    string firstName;
    string middleName;
    string lastName;
    string salutation;

public:
    // Default constructor
    Name() : firstName(""), middleName(""), lastName(""), salutation("") {}

    // Parameterized constructor
    Name(const string& sal, const string& fName, const string& mName, const string& lName) {
        setSalutation(sal);
        setFirstName(fName);
        setMiddleName(mName);
        setLastName(lName);
    }

    // Setters with validation
    void setFirstName(const string& fName) {
        if (fName.empty()) throw invalid_argument("First name cannot be empty.");
        firstName = fName;
    }
    void setMiddleName(const string& mName) {
        if (mName.empty()) throw invalid_argument("Middle name cannot be empty.");
        middleName = mName;
    }
    void setLastName(const string& lName) {
        if (lName.empty()) throw invalid_argument("Last name cannot be empty.");
        lastName = lName;
    }
    void setSalutation(const string& sal) {
        if (sal.empty()) throw invalid_argument("Salutation cannot be empty.");
        salutation = sal;
    }

    // Getters
    string getFirstName() const { return firstName; }
    string getMiddleName() const { return middleName; }
    string getLastName() const { return lastName; }
    string getSalutation() const { return salutation; }

    string toString() const {
        return salutation + " " + lastName + ", " + firstName + " " + middleName;
    }
};

Date Class (with validation)
class Date {
private:
    int month;
    int day;
    int year;

public:
    Date() : month(1), day(1), year(2000) {}

    Date(int m, int d, int y) {
        setDate(m, d, y);
    }

    void setDate(int m, int d, int y) {
        if (m < 1 || m > 12) throw invalid_argument("Month must be between 1 and 12.");
        if (d < 1 || d > 31) throw invalid_argument("Day must be between 1 and 31.");
        if (y < 1900 || y > 2100) throw invalid_argument("Year must be between 1900 and 2100.");
        month = m;
        day = d;
        year = y;
    }

    string toString() const {
        return to_string(month) + "/" + to_string(day) + "/" + to_string(year);
    }
};

Student Class (with validation and exceptions)
class Student {
private:
    Name name;
    char sex;
    Date dateOfBirth;
    string registrationNumber;
    string email;

public:
    // Constructor
    Student(const Name& n, char s, const Date& dob,
            const string& regNo, const string& mail) {
        setName(n);
        setSex(s);
        setDateOfBirth(dob);
        setRegistrationNumber(regNo);
        setEmail(mail);
    }

    // Setters with validation
    void setName(const Name& n) { name = n; }

    void setSex(char s) {
        if (s != 'M' && s != 'F')
            throw invalid_argument("Sex must be 'M' or 'F'.");
        sex = s;
    }

    void setDateOfBirth(const Date& dob) { dateOfBirth = dob; }

    void setRegistrationNumber(const string& regNo) {
        if (regNo.empty()) throw invalid_argument("Registration number cannot be empty.");
        registrationNumber = regNo;
    }

    void setEmail(const string& mail) {
        if (mail.empty()) throw invalid_argument("Email cannot be empty.");
        if (mail.find('@') == string::npos)
            throw invalid_argument("Email must contain '@'.");
        email = mail;
    }

    // Getters
    Name getName() const { return name; }
    char getSex() const { return sex; }
    Date getDateOfBirth() const { return dateOfBirth; }
    string getRegistrationNumber() const { return registrationNumber; }
    string getEmail() const { return email; }

    // Display
    void displayStudent() const {
        cout << "Student Info:\n";
        cout << "Name: " << name.toString() << endl;
        cout << "Sex: " << sex << endl;
        cout << "Date of Birth: " << dateOfBirth.toString() << endl;
        cout << "Registration No: " << registrationNumber << endl;
        cout << "Email: " << email << endl;
    }
};


int main() {
    try {
        Name n1("Mr.", "John", "Michael", "Doe");
        Date dob1(5, 15, 2000);
        Student s1(n1, 'M', dob1, "REG12345", "john.doe@email.com");
        s1.displayStudent();

        cout << "\nTrying invalid email...\n";
        s1.setEmail("invalidEmail"); // This will throw
    }
    catch (const invalid_argument& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}