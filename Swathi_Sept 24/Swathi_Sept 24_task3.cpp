Step 1: Name Class (Improved with Default Constructor)
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
    // Default constructor
    Name() : firstName(""), middleName(""), lastName(""), salutation("") {}

    // Parameterized constructor
    Name(const string& sal, const string& fName, const string& mName, const string& lName)
        : salutation(sal), firstName(fName), middleName(mName), lastName(lName) {}

    // Setters
    void setFirstName(const string& fName) { firstName = fName; }
    void setMiddleName(const string& mName) { middleName = mName; }
    void setLastName(const string& lName) { lastName = lName; }
    void setSalutation(const string& sal) { salutation = sal; }

    // Getters
    string getFirstName() const { return firstName; }
    string getMiddleName() const { return middleName; }
    string getLastName() const { return lastName; }
    string getSalutation() const { return salutation; }

    // Utility
    string toString() const {
        return salutation + " " + lastName + ", " + firstName + " " + middleName;
    }
};

Step 2: Date Class (Simplified from Deitel Example)
class Date {
private:
    int month;
    int day;
    int year;

public:
    // Default constructor
    Date() : month(1), day(1), year(2000) {}

    // Parameterized constructor
    Date(int m, int d, int y) {
        setDate(m, d, y);
    }

    void setDate(int m, int d, int y) {
        month = (m >= 1 && m <= 12) ? m : 1;
        day = (d >= 1 && d <= 31) ? d : 1;
        year = (y >= 1900) ? y : 2000;
    }

    string toString() const {
        return to_string(month) + "/" + to_string(day) + "/" + to_string(year);
    }
};

Step 3: Student Class Using Composition
class Student {
private:
    Name name;          // Composition: uses Name object
    char sex;
    Date dateOfBirth;   // Composition: uses Date object
    string registrationNumber;
    string email;

public:
    // Constructor
    Student(const Name& n, char s, const Date& dob,
            const string& regNo, const string& mail)
        : name(n), sex(s), dateOfBirth(dob),
          registrationNumber(regNo), email(mail) {}

    // Setters
    void setName(const Name& n) { name = n; }
    void setSex(char s) { sex = s; }
    void setDateOfBirth(const Date& dob) { dateOfBirth = dob; }
    void setRegistrationNumber(const string& regNo) { registrationNumber = regNo; }
    void setEmail(const string& mail) { email = mail; }

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

Step 4: Example Usage
int main() {
    Name n1("Mr.", "John", "Michael", "Doe");
    Date dob1(5, 15, 2000);
    Student s1(n1, 'M', dob1, "REG12345", "john.doe@email.com");

    s1.displayStudent();

    cout << "\nUpdating Email...\n";
    s1.setEmail("john.doe@university.edu");
    cout << "Updated Email: " << s1.getEmail() << endl;

    return 0;
}