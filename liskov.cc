// Liskov Substitution Principle

#include <iostream>

// rectangle class with height and width
class Rectangle {
protected:
    int height; 
    int width;

public:
    Rectangle(int height, int width) : 
        width(width), height(height) {}

    void setHeight(int height){
        height = height;
    }

    virtual void setWidth(int width){
        width = width;
    }

    virtual int getWidth(){
        return width;
    }
};

class Square : public Rectangle {
public:
    Square(int size) : Rectangle(size, size) {}

    void setWidth (int width){
        this->width  = width;
        this->height = height;
    }

};

void process(Rectangle& r){
    int w = r.getWidth();
};

int main(){

    Rectangle r{4,2};

    return 0;
}