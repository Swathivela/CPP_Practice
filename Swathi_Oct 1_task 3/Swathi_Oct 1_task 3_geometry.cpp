#include "Quadrilateral.h"
using namespace std;

// ===== Quadrilateral =====
Quadrilateral::Quadrilateral(initializer_list<float> s, initializer_list<float> a) {
    sides = new float[4];
    angles = new float[4];
    int i = 0;
    for (float val : s) sides[i++] = val;
    i = 0;
    for (float val : a) angles[i++] = val;
}

Quadrilateral::Quadrilateral(const Quadrilateral& other) {
    sides = new float[4];
    angles = new float[4];
    for (int i = 0; i < 4; i++) {
        sides[i] = other.sides[i];
        angles[i] = other.angles[i];
    }
}

Quadrilateral& Quadrilateral::operator=(const Quadrilateral& other) {
    if (this != &other) {
        delete[] sides;
        delete[] angles;
        sides = new float[4];
        angles = new float[4];
        for (int i = 0; i < 4; i++) {
            sides[i] = other.sides[i];
            angles[i] = other.angles[i];
        }
    }
    return *this;
}

Quadrilateral::~Quadrilateral() {
    delete[] sides;
    delete[] angles;
}

bool Quadrilateral::isValid() const {
    float sum = 0;
    for (int i = 0; i < 4; i++) sum += angles[i];
    return fabs(sum - 360.0) < 0.001;
}

bool Quadrilateral::operator==(const Quadrilateral& other) const {
    return fabs(this->area() - other.area()) < 0.001;
}

float Quadrilateral::operator()() const {
    return sides[0] + sides[1] + sides[2] + sides[3];
}

Quadrilateral::operator float() const {
    return this->area();
}

ostream& operator<<(ostream& os, const Quadrilateral& q) {
    os << q.typeName() << " | Sides: ";
    for (int i = 0; i < 4; i++) os << q.sides[i] << " ";
    os << "| Angles: ";
    for (int i = 0; i < 4; i++) os << q.angles[i] << " ";
    os << "| Area: " << q.area();
    return os;
}

// ===== Trapezoid =====
Trapezoid::Trapezoid(initializer_list<float> s, initializer_list<float> a) : Quadrilateral(s, a) {}

bool Trapezoid::isValid() const {
    return Quadrilateral::isValid(); // simplified
}

float Trapezoid::area() const {
    // Approx formula using average of parallel sides * height
    float base1 = sides[0], base2 = sides[2];
    float height = sides[1]; // assume simple height
    return ((base1 + base2) / 2) * height;
}

// ===== Parallelogram =====
Parallelogram::Parallelogram(initializer_list<float> s, initializer_list<float> a) : Trapezoid(s, a) {}

bool Parallelogram::isValid() const {
    return (sides[0] == sides[2] && sides[1] == sides[3]);
}

float Parallelogram::area() const {
    float base = sides[0], height = sides[1] * sin(angles[0] * M_PI / 180.0);
    return base * height;
}

// ===== Rectangle =====
Rectangle::Rectangle(initializer_list<float> s, initializer_list<float> a) : Parallelogram(s, a) {}

bool Rectangle::isValid() const {
    return Parallelogram::isValid() &&
           angles[0] == 90 && angles[1] == 90 && angles[2] == 90 && angles[3] == 90;
}

float Rectangle::area() const {
    return sides[0] * sides[1];
}

// ===== Square =====
Square::Square(initializer_list<float> s, initializer_list<float> a) : Rectangle(s, a) {}

bool Square::isValid() const {
    return Rectangle::isValid() && sides[0] == sides[1] && sides[1] == sides[2] && sides[2] == sides[3];
}

float Square::area() const {
    return sides[0] * sides[0];
}
