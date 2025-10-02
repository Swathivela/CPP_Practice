#include "Student.h"

// ========== Base Student ==========
Student::Student(const string& n, const string& id, const string& dept)
    : name(n), studentID(id), department(dept) {}

void Student::displayInfo() const {
    cout << "Name: " << name
         << ", ID: " << studentID
         << ", Department: " << department << endl;
}

// ========== Undergraduate ==========
UndergraduateStudent::UndergraduateStudent(const string& n, const string& id, const string& dept,
                                           int yr, int credits)
    : Student(n, id, dept), year(yr), creditsEarned(credits) {}

void UndergraduateStudent::displayInfo() const {
    Student::displayInfo();
    cout << "Year: " << year << ", Credits: " << creditsEarned << endl;
}

Freshman::Freshman(const string& n, const string& id, const string& dept,
                   int yr, int credits)
    : UndergraduateStudent(n, id, dept, yr, credits) {}
void Freshman::displayInfo() const {
    UndergraduateStudent::displayInfo();
}

Sophomore::Sophomore(const string& n, const string& id, const string& dept,
                     int yr, int credits)
    : UndergraduateStudent(n, id, dept, yr, credits) {}
void Sophomore::displayInfo() const {
    UndergraduateStudent::displayInfo();
}

Junior::Junior(const string& n, const string& id, const string& dept,
               int yr, int credits)
    : UndergraduateStudent(n, id, dept, yr, credits) {}
void Junior::displayInfo() const {
    UndergraduateStudent::displayInfo();
}

Senior::Senior(const string& n, const string& id, const string& dept,
               int yr, int credits)
    : UndergraduateStudent(n, id, dept, yr, credits) {}
void Senior::displayInfo() const {
    UndergraduateStudent::displayInfo();
}

HonorsSenior::HonorsSenior(const string& n, const string& id, const string& dept,
                           int yr, int credits, const string& thesis)
    : Senior(n, id, dept, yr, credits), thesisTitle(thesis) {}
void HonorsSenior::displayInfo() const {
    Senior::displayInfo();
    cout << "Thesis Title: " << thesisTitle << endl;
}

ExchangeSenior::ExchangeSenior(const string& n, const string& id, const string& dept,
                               int yr, int credits, const string& homeUni)
    : Senior(n, id, dept, yr, credits), homeUniversity(homeUni) {}
void ExchangeSenior::displayInfo() const {
    Senior::displayInfo();
    cout << "Home University: " << homeUniversity << endl;
}

// ========== Graduate ==========
GraduateStudent::GraduateStudent(const string& n, const string& id, const string& dept,
                                 const string& adv)
    : Student(n, id, dept), advisor(adv) {}

void GraduateStudent::displayInfo() const {
    Student::displayInfo();
    cout << "Advisor: " << advisor << endl;
}

ThesisMastersStudent::ThesisMastersStudent(const string& n, const string& id, const string& dept,
                                           const string& adv, const string& thesis)
    : GraduateStudent(n, id, dept, adv), thesisTitle(thesis) {}
void ThesisMastersStudent::displayInfo() const {
    GraduateStudent::displayInfo();
    cout << "Thesis: " << thesisTitle << endl;
}

NonThesisMastersStudent::NonThesisMastersStudent(const string& n, const string& id, const string& dept,
                                                 const string& adv, const string& project)
    : GraduateStudent(n, id, dept, adv), projectTitle(project) {}
void NonThesisMastersStudent::displayInfo() const {
    GraduateStudent::displayInfo();
    cout << "Project: " << projectTitle << endl;
}

DoctoralStudent::DoctoralStudent(const string& n, const string& id, const string& dept,
                                 const string& adv, const string& dissertation, int yrs)
    : GraduateStudent(n, id, dept, adv), dissertationTitle(dissertation), yearsInProgram(yrs) {}
void DoctoralStudent::displayInfo() const {
    GraduateStudent::displayInfo();
    cout << "Dissertation: " << dissertationTitle
         << ", Years in Program: " << yearsInProgram << endl;
}

PhDCandidate::PhDCandidate(const string& n, const string& id, const string& dept,
                           const string& adv, const string& dissertation, int yrs)
    : DoctoralStudent(n, id, dept, adv, dissertation, yrs) {}
void PhDCandidate::displayInfo() const {
    DoctoralStudent::displayInfo();
}

PostDocFellow::PostDocFellow(const string& n, const string& id, const string& dept,
                             const string& adv, const string& grant)
    : GraduateStudent(n, id, dept, adv), researchGrant(grant) {}
void PostDocFellow::displayInfo() const {
    GraduateStudent::displayInfo();
    cout << "Research Grant: " << researchGrant << endl;
}
