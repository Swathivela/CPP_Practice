#ifndef QUADRILATERAL_H
#define QUADRILATERAL_H

#include <iostream>
#include <initializer_list>
#include <cmath>
#include <string>

class Quadrilateral {
protected:
    float* sides;   // dynamically allocated array of 4 sides
    float* angles;  // dynamically allocated array of 4 angles

public:
    // Constructor
    Quadrilateral(std::initializer_list<float> s, std::initializer_list<float> a);

    // Copy constructor
    Quadrilateral(const Quadrilateral& other);

    // Assignment operator
    Quadrilateral& operator=(const Quadrilateral& other);

    // Destructor
    virtual ~Quadrilateral();

    // Virtual methods
    virtual bool isValid() const;
    virtual float area() const { return 0; }
    virtual std::string typeName() const { return "Quadrilateral"; }

    // Operator overloads
    bool operator==(const Quadrilateral& other) const;
    float operator()() const;   // perimeter
    operator float() const;     // area
    friend std::ostream& operator<<(std::ostream& os, const Quadrilateral& q);
};

class Trapezoid : public Quadrilateral {
public:
    Trapezoid(std::initializer_list<float> s, std::initializer_list<float> a);
    bool isValid() const override;
    float area() const override;
    std::string typeName() const override { return "Trapezoid"; }
};

class Parallelogram : public Trapezoid {
public:
    Parallelogram(std::initializer_list<float> s, std::initializer_list<float> a);
    bool isValid() const override;
    float area() const override;
    std::string typeName() const override { return "Parallelogram"; }
};

class Rectangle : public Parallelogram {
public:
    Rectangle(std::initializer_list<float> s, std::initializer_list<float> a);
    bool isValid() const override;
    float area() const override;
    std::string typeName() const override { return "Rectangle"; }
};

class Square : public Rectangle {
public:
    Square(std::initializer_list<float> s, std::initializer_list<float> a);
    bool isValid() const override;
    float area() const override;
    std::string typeName() const override { return "Square"; }
};

#endif
