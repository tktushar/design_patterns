#include <iostream>

// Adaptee class
class LegacyRectangle {
public:
    void drawRectangle(int x1, int y1, int x2, int y2) {
        std::cout << "LegacyRectangle: drawRectangle(" << x1 << ", " << y1 << ", " << x2 << ", " << y2 << ")" << std::endl;
    }
};

// Target interface
class Rectangle {
public:
    virtual void draw(int x, int y, int width, int height) = 0;
};

// Adapter class
class RectangleAdapter : public Rectangle {
private:
    LegacyRectangle legacyRectangle;

public:
    void draw(int x, int y, int width, int height) override {
        int x1 = x;
        int y1 = y;
        int x2 = x + width;
        int y2 = y + height;
        legacyRectangle.drawRectangle(x1, y1, x2, y2);
    }
};

// Client code
int main() {
    Rectangle* rectangle = new RectangleAdapter();
    rectangle->draw(10, 20, 30, 40);
    delete rectangle;

    return 0;
}
