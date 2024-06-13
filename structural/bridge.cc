#include <iostream>
using namespace std;

/*
    ====== Bridge Pattern ===============
    Motivation : 
    a. Same as PImpl, divide the bussiness logic into various
       class heirarchies which can be developed independently
    b. Main abstraction gets a reference to the implementation.
    c. It can delegate its function calls to the reference.
    d. This avoids state space explosion

*/
// abstract class that can render a circle
struct Renderer{
    virtual void render_circle(float x, float y) = 0;
};

struct Shape{
    Shape(Renderer& r) : ren{r} {};

    virtual void draw() = 0;
    Renderer &ren;
};

// concrete classes
struct Circle : Shape{
    Circle(Renderer& ren, float x, float y, float r) : Shape(ren), x{x}, y{y}, r{r} {};
    float x, y, r;

    void draw() override{
        ren.render_circle(x, y);
    }
};

struct RendererA : Renderer{
    void render_circle(float x, float y){
        cout << "Rendering a round cicle using renderer A" << endl;
    }
};

struct RendererB : Renderer{
    void render_circle(float x, float y){
        cout << "Rendering a round cicle using renderer B" << endl;
    }
};

int main(){
    RendererA ren;
    Circle c{ren, 1, 1, 2};
    c.draw();
}
