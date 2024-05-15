// Liskov Substitution Principle

/*
        == Liskov says ==
        Derived class should be sustitute-able at any place
        where a base class is used.

*/

/* In this case using a factory method would help.
   A factory for square and rectangle 
*/

#include <iostream>

// rectangle class with height and width
class Rectangle {
protected:
    int height; 
    int width;

public:
    Rectangle(int height, int width) : 
        width(width), height(height) {}

    virtual void setHeight(int height){
        std::cout << "setheight1 called with " << height << std::endl;
        height = height;
    }

    virtual void setWidth(int width){
       width = width;
    }

    virtual int getWidth(){
        return width;
    }

    int area (){
        std::cout << "height " << height << " width " << width <<std::endl;
        return width*height;
    }
};

class Square : public Rectangle {
public:
    Square(int size) : Rectangle(size, size) {}

    void setHeight (int height) override{
        std::cout << "setheight2 called with " << height << std::endl;
        this->width  = height;
        this->height = height;
    }

    // same with setWidth, i.e, set both width and height

};

// calling process on square would set the width
void process(Rectangle& r){
    int w = r.getWidth();
    r.setHeight(10); // this will set both the width and height for square

    std::cout << "expected area is " << w*10 <<std::endl;
    std::cout << "area with " << r.area() << std::endl; 
    // expected and clculated area will differ when using a Square class
    // because both width and height got changed. This is a violation
    // of Liskov's principle.
};

int main(){

    Rectangle r{4,2};
    Square s(2);

    process(s);

    return 0;
}