#include <iostream>
#include <vector>
using namespace std;

/* 
    === Composition ===
    Motivation 
    Treat object and composition of the objects in the same manner,
    i.e, have a common API

*/

//abstraciton
struct Shape{
    virtual void draw() = 0;
};

//instance
struct Circle : Shape{
    void draw() override {
        cout << "Drawing a circle" << endl;
    }
};

//composition
struct GroupOfCircles : Shape{
    vector<Shape*> objs;

    void draw() override {
        for(auto& obj : objs){
            obj->draw();
        }
    }
};

int main(){
    Circle c, c1, c2;
    GroupOfCircles g;
    g.objs.push_back(&c1);
    g.objs.push_back(&c2);

    g.draw();
}
