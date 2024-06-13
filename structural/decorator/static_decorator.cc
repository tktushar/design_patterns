#include <iostream>
#include <memory>
#include <sstream>
#include <string>

using namespace std;


template <typename T>
class ShapeDecorator : public T {
public:
    ShapeDecorator(const T& shape) : T(shape) {}

    string str() const override {
        ostringstream oss;
        oss << T::str();
        return oss.str();
    }
};

class Circle {
public:
    float radius;
    Circle() {}
    Circle(float radius) : radius(radius) {}

    string str() const {
        ostringstream oss;
        oss << "A circle of radius " << radius << endl;
        return oss.str();
    }
};

class Square {
public:
    float side;
    Square() {}
    Square(float side) : side(side) {}

    string str() const {
        ostringstream oss;
        oss << "A square of side " << side;
        return oss.str();
    }
};

using TransparentCircle = ShapeDecorator<Circle>;
using TransparentSquare = ShapeDecorator<Square>;

int main() {
    Square s{10};
    cout << s.str() << endl;

    TransparentSquare trans_square{s};
    cout << trans_square.str() << endl;

    return 0;
}
