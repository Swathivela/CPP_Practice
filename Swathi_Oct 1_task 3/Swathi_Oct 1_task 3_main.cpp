#include "Quadrilateral.h"
#include <iostream>
using namespace std;

int main() {
    // 1. Create objects
    Square sq({5,5,5,5}, {90,90,90,90});
    Rectangle rect({6,4,6,4}, {90,90,90,90});
    Parallelogram para({6,4,6,4}, {110,70,110,70});
    Trapezoid trap({6,5,4,3}, {100,80,100,80});
    Quadrilateral quad({3,4,5,6}, {90,90,90,90});

    // 2. Polymorphism
    Quadrilateral* shapes[5] = {&sq, &rect, &para, &trap, &quad};

    for (auto s : shapes) {
        cout << *s << endl;
        cout << "Valid? " << (s->isValid() ? "Yes" : "No") << endl;
        cout << "Area: " << s->area() << " | Perimeter: " << (*s)() << endl;
        cout << "----------------------------------" << endl;
    }

    // 3. Compare Rectangle and Square
    cout << "Rectangle == Square? " << (rect == sq ? "Yes" : "No") << endl;

    // 4. Convert to float (area)
    float sqArea = float(sq);
    cout << "Square area (float cast): " << sqArea << endl;

    return 0;
}
