#include "Student.h"
#include <vector>
#include <typeinfo>

int main() {
    vector<Student*> students;

    // Create objects with sample data
    students.push_back(new Freshman("Amit", "UG101", "Computer Science", 1, 15));
    students.push_back(new HonorsSenior("Neha", "UG401", "Physics", 4, 120, "Quantum Entanglement Thesis"));
    students.push_back(new ExchangeSenior("Luca", "UG402", "Mechanical", 4, 110, "Politecnico di Milano"));
    students.push_back(new ThesisMastersStudent("Priya", "GR201", "Electrical", "Dr. Rao", "Smart Grid Optimization"));
    students.push_back(new NonThesisMastersStudent("Raj", "GR202", "Civil", "Dr. Mehta", "Bridge Load Simulation"));
    students.push_back(new PhDCandidate("Sneha", "GR301", "Biotech", "Dr. Kapoor", "Gene Editing Ethics", 3));
    students.push_back(new PostDocFellow("Dr. Tanmay", "GR401", "AI Research", "Dr. Bose", "DARPA Grant"));

    // Polymorphic display
    for (auto s : students) {
        cout << "======================" << endl;
        s->displayInfo();
        cout << "Level: " << s->getLevel() << endl;
    }

    // Cleanup
    for (auto s : students) {
        delete s;
    }

    return 0;
}
