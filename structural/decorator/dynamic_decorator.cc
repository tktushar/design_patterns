#include <iostream>
#include <memory>
#include <sstream>
#include <string>

using namespace std;

/*
    === Decorator ==
    
    Motivation
    ----------
    We want to add additional functionality to an object. 
    
    But remeber the Open Close Principle, we don't want to 
    modify the class itself. We also want to follow 'separation
    of concerns'

    Types :
    ------
    Aggregation : Keep a pointer/reference to the object in a new class
                  and do stuff with it. This is dynamic approach.

*/

class Shape{
public:
    virtual string str() const = 0;
};

class Circle : Shape{
public:
    float radius;
    Circle () {};
    Circle (float radius) : radius(radius) {};

    string str() const override {
        ostringstream oss;
        oss << "A circle of radius " << radius << endl;
        return oss.str();
    }
};

class Square : public Shape{
public:
    float side;
    Square () {};
    Square (float side) : side(side) {};

    string str() const override {
        ostringstream oss;
        oss << "A square of side " << side;
        return oss.str();
    }
};

// Inherit base shape but decorate it dynamically
class TransparentShape : public Shape{
public:
    Shape& shape;
    int transparency;

    TransparentShape(Shape& shape, int transparency) : shape{shape},
        transparency{transparency} {};

    string str() const override {
        ostringstream oss;
        oss << shape.str() << " has " << static_cast<float>(transparency) << " transparency"; 
        return oss.str();
    }
};

// Inherit base shape but decorate it dynamically
class ColorShape : public Shape{
public:
    Shape& shape;
    string color;

    ColorShape(Shape& shape, string color) : shape{shape},
        color{color} {};

    string str() const override {
        ostringstream oss;
        oss << shape.str() << " has " << color << " color"; 
        return oss.str();
    }
};


int main(){
    Square s{10};
    cout << s.str() << endl;

    TransparentShape trans_square{s, 12};
    cout << trans_square.str() << endl;

    ColorShape color_square{trans_square, "red"};
    cout << color_square.str() << endl;

    return 0;
}



