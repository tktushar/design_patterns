/* Factory Pattern : GoF */

/*
    This pattern tries to mitigate problems with the constructor :  
    1. Constructor is not descriptive.
    2. Can't overload a constructor with same arguments but different names. 
       (don't think about **args, that sucks, lol!)

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
        return {x,y};
    }

    static Point NewPolar(float r, float theta){
        return {r*cos(theta), r*sin(theta)};
    }

};

int main(){
    auto p = Point::NewPolar(2, 3.141);
    auto x = Point::NewCartesian(2,2);
    return 0;
}
