// Liskov Substitution Principle




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

};

// calling process on square would set the width
void process(Rectangle& r){
    int w = r.getWidth();
    r.setHeight(10); // this will set both the width and height for square

    std::cout << "area with " << r.area() << std::endl; // this area is wrong for square
};

int main(){

    Rectangle r{4,2};
    Square s(2);

    process(s);

    return 0;
}