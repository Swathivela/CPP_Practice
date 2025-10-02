#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// ================= Base Class =================
class Student {
protected:
    string name;
    string studentID;
    string department;

public:
    Student(const string& n, const string& id, const string& dept);
    virtual ~Student() {}

    virtual void displayInfo() const;
    virtual string getLevel() const { return "Student"; }
};

// ================= Undergraduate =================
class UndergraduateStudent : public Student {
protected:
    int year;
    int creditsEarned;

public:
    UndergraduateStudent(const string& n, const string& id, const string& dept,
                         int yr, int credits);
    void displayInfo() const override;
    string getLevel() const override { return "Undergraduate"; }
};

// -------- Freshman
class Freshman : public UndergraduateStudent {
public:
    Freshman(const string& n, const string& id, const string& dept,
             int yr, int credits);
    void displayInfo() const override;
    string getLevel() const override { return "Freshman"; }
};

// -------- Sophomore
class Sophomore : public UndergraduateStudent {
public:
    Sophomore(const string& n, const string& id, const string& dept,
              int yr, int credits);
    void displayInfo() const override;
    string getLevel() const override { return "Sophomore"; }
};

// -------- Junior
class Junior : public UndergraduateStudent {
public:
    Junior(const string& n, const string& id, const string& dept,
           int yr, int credits);
    void displayInfo() const override;
    string getLevel() const override { return "Junior"; }
};

// -------- Senior
class Senior : public UndergraduateStudent {
public:
    Senior(const string& n, const string& id, const string& dept,
           int yr, int credits);
    void displayInfo() const override;
    string getLevel() const override { return "Senior"; }
};

// -------- HonorsSenior
class HonorsSenior : public Senior {
    string thesisTitle;
public:
    HonorsSenior(const string& n, const string& id, const string& dept,
                 int yr, int credits, const string& thesis);
    void displayInfo() const override;
    string getLevel() const override { return "HonorsSenior"; }
};

// -------- ExchangeSenior
class ExchangeSenior : public Senior {
    string homeUniversity;
public:
    ExchangeSenior(const string& n, const string& id, const string& dept,
                   int yr, int credits, const string& homeUni);
    void displayInfo() const override;
    string getLevel() const override { return "ExchangeSenior"; }
};

// ================= Graduate =================
class GraduateStudent : public Student {
protected:
    string advisor;
public:
    GraduateStudent(const string& n, const string& id, const string& dept,
                    const string& adv);
    void displayInfo() const override;
    string getLevel() const override { return "Graduate"; }
};

// -------- ThesisMastersStudent
class ThesisMastersStudent : public GraduateStudent {
    string thesisTitle;
public:
    ThesisMastersStudent(const string& n, const string& id, const string& dept,
                         const string& adv, const string& thesis);
    void displayInfo() const override;
    string getLevel() const override { return "ThesisMastersStudent"; }
};

// -------- NonThesisMastersStudent
class NonThesisMastersStudent : public GraduateStudent {
    string projectTitle;
public:
    NonThesisMastersStudent(const string& n, const string& id, const string& dept,
                            const string& adv, const string& project);
    void displayInfo() const override;
    string getLevel() const override { return "NonThesisMastersStudent"; }
};

// -------- DoctoralStudent
class DoctoralStudent : public GraduateStudent {
protected:
    string dissertationTitle;
    int yearsInProgram;
public:
    DoctoralStudent(const string& n, const string& id, const string& dept,
                    const string& adv, const string& dissertation, int yrs);
    void displayInfo() const override;
    string getLevel() const override { return "DoctoralStudent"; }
};

// -------- PhDCandidate
class PhDCandidate : public DoctoralStudent {
public:
    PhDCandidate(const string& n, const string& id, const string& dept,
                 const string& adv, const string& dissertation, int yrs);
    void displayInfo() const override;
    string getLevel() const override { return "PhDCandidate"; }
};

// -------- PostDocFellow
class PostDocFellow : public GraduateStudent {
    string researchGrant;
public:
    PostDocFellow(const string& n, const string& id, const string& dept,
                  const string& adv, const string& grant);
    void displayInfo() const override;
    string getLevel() const override { return "PostDocFellow"; }
};

#endif
