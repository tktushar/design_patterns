/*

                == Factory Method ==

    This pattern tries to mitigate problems with the constructor :  
    1. Constructor is not descriptive.
    2. Can't overload a constructor with same arguments but different names. 

    == How is it different from Builder ==
    This is meant as a wholesale creation pattern. Builder was more piecewise.

    == How do we solve the problem ==
    Have a private constructor, but provide methods that can variably initialise
    the object


*/
#include <iostream>
#include <cmath>

using namespace std;

class Point{

    Point(float x, float y) : x{x}, y{y} {} // private constructor

public:
    float x, y;
    
    // static function resides with the class and not with instances
    // notice that it returs a pointer to the Point object
    static Point NewCartesian(float x, float y){
        cout << "Creating a Cartesian Point" << endl;
        return {x,y};
    }

    static Point NewPolar(float r, float theta){
        cout << "Creating a Polar Point" << endl;
        return {r*cos(theta), r*sin(theta)};
    }

};


/*
    == Make a factory ==
    The above Point class is a good example of factory, but
    let's separate the concerns and create a PointFactory.

    But Point constructor is private. Should we add
    PointFactory as friend? No, that breaks the OCP. If
    we are okay with it, we can.

    Or Can we make everything public in Point. Depends
    if we are okay with it, because we exposed the constructor

*/
class PointFactory{

    PointFactory(float x, float y) : x{x}, y{y} {} // private constructor

public:
    float x, y;
    
    // static function resides with the class and not with instances
    // notice that it returs a pointer to the Point object
    static Point NewCartesian(float x, float y){
        cout << "Creating a Cartesian Point" << endl;
        return {x,y};
    }

    static Point NewPolar(float r, float theta){
        cout << "Creating a Polar Point" << endl;
        return {r*cos(theta), r*sin(theta)};
    }

};

int main(){
    // auto p = Point::NewPolar(2, 3.141);
    // auto x = Point::NewCartesian(2,2);

    auto p = PointFactory::NewPolar(2, 3.141);
    auto x = PointFactory::NewCartesian(2,2);

    return 0;
}
