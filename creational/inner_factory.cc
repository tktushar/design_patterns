/*
        == Inner Factory ==
    

*/
#include <iostream>
#include <cmath>

using namespace std;

class Point{
public:
    static PointFactory;
    
private:

    Point(float x, float y) : x{x}, y{y} {} // private constructor

    // inner class has access to Point method
    class PointFactory{

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

    static PointFactory;
};


int main(){
    // auto p = Point::NewPolar(2, 3.141);
    // auto x = Point::NewCartesian(2,2);

    auto p = Point.PointFactory::NewCartesian(2,2);

    return 0;
}
